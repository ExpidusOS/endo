
AM_CPPFLAGS =								\
	-I$(top_srcdir)							\
	-DG_LOG_DOMAIN=\"endo-tests\"

TESTS =									\
	test-endo-noop							\
	test-endo-string

check_PROGRAMS =							\
	test-endo-noop							\
	test-endo-string							\
	test-endo-icon-chooser-dialog

test_endo_noop_SOURCES =							\
	test-endo-noop.c

test_endo_noop_CFLAGS =                                                 \
	$(GTK_CFLAGS)                                                  \
	$(LIBEXPIDUS1UTIL_CFLAGS)

test_endo_noop_DEPENDENCIES =						\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

test_endo_noop_LDADD =							\
	$(GLIB_LIBS)							\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

test_endo_string_SOURCES =						\
	test-endo-string.c

test_endo_string_CFLAGS =                                               \
	$(GTK_CFLAGS)                                                  \
	$(LIBEXPIDUS1UTIL_CFLAGS)

test_endo_string_DEPENDENCIES =						\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

test_endo_string_LDADD =							\
	$(GLIB_LIBS)							\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

test_endo_icon_chooser_dialog_SOURCES =					\
	test-endo-icon-chooser-dialog.c

test_endo_icon_chooser_dialog_DEPENDENCIES =				\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

test_endo_icon_chooser_dialog_CFLAGS =					\
	$(GTK_CFLAGS)							\
	$(LIBEXPIDUS1UTIL_CFLAGS)

test_endo_icon_chooser_dialog_LDADD =					\
	$(GTK_LIBS)							\
	$(top_builddir)/endo/libendo-$(LIBENDO_VERSION_API).la

clean-local:
	rm -f *.core core core.*

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
