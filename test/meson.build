sources = ['test-gmessanger.c',
           'test-receiver-obj-a.h', 'test-receiver-obj-a.c',
           'test-receiver-obj-b.h', 'test-receiver-obj-b.c']

test_gmessanger = executable('test_gmessanger',
                             sources,
                             include_directories : inc,
                             dependencies : glib_dep,
                             link_with : libgmessanger)

test('libmessanger test', test_gmessanger)
