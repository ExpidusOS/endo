
AM_CPPFLAGS = 								\
	-I$(top_srcdir)							\
	-DG_LOG_DOMAIN=\"endo-open\"					\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"

bin_PROGRAMS =								\
	endo-open

endo_open_SOURCES =							\
	main.c

endo_open_CFLAGS =							\
	$(GTK_CFLAGS)							\
	$(LIBEXPIDUS1UTIL_CFLAGS)						\
	$(GIO_CFLAGS)							\
	$(GIO_UNIX_CFLAGS)

endo_open_LDFLAGS =							\
	-no-undefined

endo_open_LDADD =							\
	$(GTK_LIBS)							\
	$(LIBEXPIDUS1UTIL_LIBS)						\
	$(GIO_LIBS)							\
	$(GIO_UNIX_LIBS)						\
	$(top_builddir)/endo/libendo-2.la

EXTRA_DIST =								\
	$(desktop_in_files)

DISTCLEANFILES =							\
	$(desktop_DATA)

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
