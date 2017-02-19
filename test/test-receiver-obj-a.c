/* test-receive-obj-a.c
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

#include "test-receiver-obj-a.h"
#include <greceiver.h>

static void test_receiver_obj_a_init_interface (GReceiverInterface *iface);

struct _TestReceiverObjA
{
  GObject parent_instance;
};

G_DEFINE_TYPE_WITH_CODE (TestReceiverObjA, test_receiver_obj_a, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (G_TYPE_RECEIVER,
                                                test_receiver_obj_a_init_interface))

static void
test_receiver_obj_a_class_init (TestReceiverObjAClass *klass)
{
}

static void
test_receiver_obj_a_init (TestReceiverObjA *self)
{
}

TestReceiverObjA *
test_receiver_obj_a_new (void)
{
  return g_object_new (TEST_TYPE_RECEIVER_OBJ_A, NULL);
}

static void
test_receiver_obj_a_receive (GReceiver    *receiver,
                             GObject      *sender,
                             gint          pattern,
                             const GValue *data)
{
}


static void
test_receiver_obj_a_init_interface (GReceiverInterface *iface)
{
  iface->receive = test_receiver_obj_a_receive;
}
