/*-
 * Copyright (c) 2005-2006 Benedikt Meurer <benny@expidus.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#if !defined (ENDO_INSIDE_ENDO_H) && !defined (ENDO_COMPILATION)
#error "Only <endo/endo.h> can be included directly, this file may disappear or change contents."
#endif

#ifndef __ENDO_ICON_CHOOSER_DIALOG_H__
#define __ENDO_ICON_CHOOSER_DIALOG_H__

#include <endo/endo-config.h>

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EndoIconChooserDialogPrivate EndoIconChooserDialogPrivate;
typedef struct _EndoIconChooserDialogClass   EndoIconChooserDialogClass;
typedef struct _EndoIconChooserDialog        EndoIconChooserDialog;

#define ENDO_TYPE_ICON_CHOOSER_DIALOG            (endo_icon_chooser_dialog_get_type ())
#define ENDO_ICON_CHOOSER_DIALOG(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_ICON_CHOOSER_DIALOG, EndoIconChooserDialog))
#define ENDO_ICON_CHOOSER_DIALOG_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_ICON_CHOOSER_DIALOG, EndoIconChooserDialogClass))
#define ENDO_IS_ICON_CHOOSER_DIALOG(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_ICON_CHOOSER_DIALOG))
#define ENDO_IS_ICON_CHOOSER_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_ICON_CHOOSER_DIALOG))
#define ENDO_ICON_CHOOSER_DIALOG_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_ICON_CHOOSER_DIALOG, EndoIconChooserDialogClass))

struct _EndoIconChooserDialogClass
{
  /*< private >*/
  GtkDialogClass __parent__;

  /* reserved for future expansion */
  void (*reserved1) (void);
  void (*reserved2) (void);
  void (*reserved3) (void);
  void (*reserved4) (void);
  void (*reserved5) (void);
  void (*reserved6) (void);
};

/**
 * EndoIconChooserDialog:
 *
 * The #EndoIconChooserDialog class provides an easy to use dialog to ask
 * the user to select either a named icon from the selected icon theme,
 * or an image file from the local file system.
 **/
struct _EndoIconChooserDialog
{
  /*< private >*/
  GtkDialog __parent__;
};

GType      endo_icon_chooser_dialog_get_type (void) G_GNUC_CONST;

GtkWidget *endo_icon_chooser_dialog_new      (const gchar          *title,
                                             GtkWindow            *parent,
                                             const gchar          *first_button_text,
                                             ...) G_GNUC_MALLOC G_GNUC_NULL_TERMINATED G_GNUC_WARN_UNUSED_RESULT;

gchar     *endo_icon_chooser_dialog_get_icon (EndoIconChooserDialog *icon_chooser_dialog) G_GNUC_MALLOC G_GNUC_WARN_UNUSED_RESULT;
gboolean   endo_icon_chooser_dialog_set_icon (EndoIconChooserDialog *icon_chooser_dialog,
                                             const gchar          *icon);

G_END_DECLS

#endif /* !__ENDO_ICON_CHOOSER_DIALOG_H__ */
