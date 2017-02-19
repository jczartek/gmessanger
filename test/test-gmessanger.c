/* test-messanger.c
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

#include "test-receiver-obj-a.h"
#include "test-receiver-obj-b.h"

static void
test_messanger_singlenton (void)
{
  GMessanger *msger = NULL;
  GMessanger *msger1 = NULL;

  msger = g_messanger_new ();
  msger1 = g_messanger_new ();

  g_assert_true (msger == msger1);
  g_object_unref (msger1);
  g_object_unref (msger);
}

static void
test_messanger_simple_send_msg (void)
{
  GMessanger *msger = NULL;
  TestReceiverObjA *objA = NULL;
  TestReceiverObjB *objB = NULL;

  msger = g_messanger_new ();
  objA = test_receiver_obj_a_new ();
  objB = test_receiver_obj_b_new ();

  g_assert_true (g_messanger_register_object (msger, G_OBJECT (objA), "objA"));
  g_assert_true (g_messanger_register_object (msger, G_OBJECT (objB), "objB"));

  g_messanger_send_msg (msger, G_OBJECT (objA), "objB", 0, NULL);
  g_messanger_send_msg (msger, G_OBJECT (objB), "objA", 0 , NULL);

  g_object_unref (objA);
  g_object_unref (objB);
  g_object_unref (msger);
}


gint
main (gint   argc,
      gchar *argv[])
{
  g_test_init (&argc, &argv, NULL);

  g_test_add_func ("/test/messanger/singlenton", test_messanger_singlenton);
  g_test_add_func ("/test/messanger/simple/send/msg", test_messanger_simple_send_msg);

  g_test_run ();
  return 0;
}
