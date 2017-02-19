/* g-receiver.h
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
#ifndef G_RECEIVER_H
#define G_RECEIVER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define G_TYPE_RECEIVER (g_receiver_get_type ())

G_DECLARE_INTERFACE (GReceiver, g_receiver, G, RECEIVER, GObject)

struct _GReceiverInterface
{
  GTypeInterface parent;

  void (*receive) (GReceiver    *self,
                   GObject      *sender,
                   gint          pattern,
                   const GValue *data);
};


void g_receiver_receive (GReceiver    *self,
                         GObject      *sender,
                         gint          pattern,
                         const GValue *data);

G_END_DECLS

#endif /* G_RECEIVER_H */
