/* g-receiver.c
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
#include <greceiver.h>

G_DEFINE_INTERFACE (GReceiver, g_receiver, G_TYPE_OBJECT)

static void
g_receiver_default_init (GReceiverInterface *iface)
{
}

void
g_receiver_receive (GReceiver    *self,
                    GObject      *sender,
                    gint          pattern,
                    const GValue *data)
{
  GReceiverInterface *iface;

  g_return_if_fail (G_IS_RECEIVER (self));
  g_return_if_fail (G_IS_OBJECT (sender));

  iface = G_RECEIVER_GET_IFACE (self);

  g_return_if_fail (iface->receive != NULL);
  iface->receive (self, sender, pattern, data);
}
