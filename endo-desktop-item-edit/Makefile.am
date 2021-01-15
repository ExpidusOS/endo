
AM_CPPFLAGS = 								\
	-I$(top_builddir)						\
	-I$(top_srcdir)							\
	-DBINDIR=\"$(bindir)\"						\
	-DDATADIR=\"$(datadir)\"					\
	-DG_LOG_DOMAIN=\"endo-desktop-item-edit\"			\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"

bin_PROGRAMS =								\
	endo-desktop-item-edit

endo_desktop_item_edit_SOURCES =						\
	endo-die-command-entry.c						\
	endo-die-command-entry.h						\
	endo-die-command-model.c						\
	endo-die-command-model.h						\
	endo-die-desktop-model.c						\
	endo-die-desktop-model.h						\
	endo-die-editor.c						\
	endo-die-editor.h						\
	endo-die-enum-types.c						\
	endo-die-enum-types.h						\
	endo-die-utils.c							\
	endo-die-utils.h							\
	main.c

endo_desktop_item_edit_CFLAGS =						\
	$(GTK_CFLAGS)							\
	$(GTHREAD_CFLAGS)						\
	$(LIBEXPIDUS1UTIL_CFLAGS)						\
	$(GIO_CFLAGS)							\
	$(LIBEXPIDUS1UI_CFLAGS)

endo_desktop_item_edit_LDFLAGS =						\
	-no-undefined

endo_desktop_item_edit_DEPENDENCIES =					\
	$(top_builddir)/endo/libendo-2.la

endo_desktop_item_edit_LDADD =						\
	$(GTK_LIBS)							\
	$(GTHREAD_LIBS)							\
	$(LIBEXPIDUS1UTIL_LIBS)						\
	$(GIO_LIBS)							\
	$(LIBEXPIDUS1UI_LIBS)						\
	$(top_builddir)/endo/libendo-2.la

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
