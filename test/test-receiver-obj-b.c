/* test-receive-obj-b.c
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

#include "test-receiver-obj-b.h"
#include <greceiver.h>

static void test_receiver_obj_b_init_interface (GReceiverInterface *iface);

struct _TestReceiverObjB
{
  GObject parent_instance;
};

G_DEFINE_TYPE_WITH_CODE (TestReceiverObjB, test_receiver_obj_b, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (G_TYPE_RECEIVER,
                                                test_receiver_obj_b_init_interface))

static void
test_receiver_obj_b_class_init (TestReceiverObjBClass *klass)
{
}

static void
test_receiver_obj_b_init (TestReceiverObjB *self)
{
}

TestReceiverObjB *
test_receiver_obj_b_new (void)
{
  return g_object_new (TEST_TYPE_RECEIVER_OBJ_B, NULL);
}

static void
test_receiver_obj_b_receive (GReceiver    *receiver,
                             GObject      *sender,
                             gint          pattern,
                             const GValue *data)
{
}

static void
test_receiver_obj_b_init_interface (GReceiverInterface *iface)
{
  iface->receive = test_receiver_obj_b_receive;
}
