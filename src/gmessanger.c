/* g-messanger.c
 *
 * Copyright (C) 2017 Jakub Czartek <kuba@linux.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gmessanger.h>
#include <greceiver.h>

typedef struct
{
  GHashTable *objs;
} GMessangerPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GMessanger, g_messanger, G_TYPE_OBJECT)

static void
g_messanger_finalize (GObject *object)
{
  G_OBJECT_CLASS (g_messanger_parent_class)->finalize (object);
}

static void
g_messanger_class_init (GMessangerClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = g_messanger_finalize;
}

static void
g_messanger_init (GMessanger *self)
{
  GMessangerPrivate *priv = g_messanger_get_instance_private (self);

  priv->objs = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_object_unref);
}

GMessanger *
g_messanger_new (void)
{
  return g_object_new (G_TYPE_MESSANGER, NULL);
}

void
g_messanger_send_msg (GMessanger   *self,
                      GObject      *sender,
                      const gchar  *receiver,
                      gint          pattern,
                      const GValue *data)
{
  GReceiver *r;
  GMessangerPrivate *priv;
  g_return_if_fail (G_IS_MESSANGER (self));
  g_return_if_fail ((G_IS_OBJECT (self)) && receiver != NULL);

  priv = g_messanger_get_instance_private (self);

  if (!g_hash_table_contains (priv->objs, receiver))
    {
      g_warning ("%s: %s is not registered!", G_STRFUNC, receiver);
      return;
    }

  r = g_hash_table_lookup (priv->objs, receiver);

  g_receiver_receive (r, sender, pattern, data);
}

gboolean
g_messanger_register_object (GMessanger  *self,
                             GObject     *registered_object,
                             const gchar *id)
{
  GMessangerPrivate *priv;

  g_return_val_if_fail (G_IS_MESSANGER (self), FALSE);
  g_return_val_if_fail (G_IS_RECEIVER (registered_object), FALSE);
  g_return_val_if_fail (id != NULL, FALSE);

  priv = g_messanger_get_instance_private (self);

  if (g_hash_table_contains (priv->objs, id))
    {
      g_warning ("%s: cannot register object!", G_STRFUNC);
      return FALSE;
    }

  g_hash_table_insert (priv->objs,
                       g_strdup (id),
                       g_object_ref (registered_object));

  return TRUE;
}

void
g_messanger_force_register_object (GMessanger  *self,
                                   GObject     *registered_object,
                                   const gchar *id)
{
}

