/* g-messanger.h
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

#ifndef G_MESSANGER_H
#define G_MESSANGER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define G_TYPE_MESSANGER (g_messanger_get_type())

G_DECLARE_DERIVABLE_TYPE (GMessanger, g_messanger, G, MESSANGER, GObject)

struct _GMessangerClass
{
  GObjectClass parent;
};

GMessanger *g_messanger_new                   (void);
void        g_messanger_send_msg              (GMessanger   *self,
                                               GObject      *sender,
                                               const gchar  *receiver,
                                               gint          pattern,
                                               const GValue *data);
gboolean    g_messanger_register_object       (GMessanger   *self,
                                               GObject      *registered_object,
                                               const gchar  *id);
void        g_messanger_force_register_object (GMessanger   *self,
                                               GObject      *registered_object,
                                               const gchar  *id);

G_END_DECLS

#endif /* G_MESSANGER_H */

