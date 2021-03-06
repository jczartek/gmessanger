/* test-receive-obj-a.h
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

#ifndef TEST_RECEIVER_OBJ_A_H
#define TEST_RECEIVER_OBJ_A_H

#include <glib-object.h>

G_BEGIN_DECLS

#define TEST_TYPE_RECEIVER_OBJ_A (test_receiver_obj_a_get_type())

G_DECLARE_FINAL_TYPE (TestReceiverObjA, test_receiver_obj_a, TEST, RECEIVER_OBJ_A, GObject)

TestReceiverObjA *test_receiver_obj_a_new (void);

G_END_DECLS

#endif /* TEST_RECEIVER_OBJ_A_H */

