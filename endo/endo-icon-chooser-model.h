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

#if !defined (ENDO_COMPILATION)
#error "Only <endo/endo.h> can be included directly, this file is not part of the public API."
#endif

#ifndef __ENDO_ICON_CHOOSER_MODEL_H__
#define __ENDO_ICON_CHOOSER_MODEL_H__

#include <endo/endo-config.h>

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EndoIconChooserModelClass EndoIconChooserModelClass;
typedef struct _EndoIconChooserModel      EndoIconChooserModel;

#define ENDO_TYPE_ICON_CHOOSER_MODEL             (endo_icon_chooser_model_get_type ())
#define ENDO_ICON_CHOOSER_MODEL(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_ICON_CHOOSER_MODEL, EndoIconChooserModel))
#define ENDO_ICON_CHOOSER_MODEL_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_ICON_CHOOSER_MODEL, EndoIconChooserModelClass))
#define ENDO_IS_ICON_CHOOSER_MODEL(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_ICON_CHOOSER_MODEL))
#define ENDO_IS_ICON_CHOOSER_MODEL_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_ICON_CHOOSER_MODEL))
#define ENDO_ICON_CHOOSER_MODEL_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_ICON_CHOOSER_MODEL, EndoIconChooserModelClass))

/**
 * EndoIconChooserContexts:
 *
 * The list of default contexts for the icon themes
 * according to the Icon Naming Spec, Version 0.7.
 **/
typedef enum
{
  /* the contexts provided by the model */
  ENDO_ICON_CHOOSER_CONTEXT_ACTIONS,
  ENDO_ICON_CHOOSER_CONTEXT_ANIMATIONS,
  ENDO_ICON_CHOOSER_CONTEXT_APPLICATIONS,
  ENDO_ICON_CHOOSER_CONTEXT_CATEGORIES,
  ENDO_ICON_CHOOSER_CONTEXT_DEVICES,
  ENDO_ICON_CHOOSER_CONTEXT_EMBLEMS,
  ENDO_ICON_CHOOSER_CONTEXT_EMOTES,
  ENDO_ICON_CHOOSER_CONTEXT_MIME_TYPES,
  ENDO_ICON_CHOOSER_CONTEXT_PLACES,
  ENDO_ICON_CHOOSER_CONTEXT_STATUS,
  ENDO_ICON_CHOOSER_CONTEXT_STOCK,
  ENDO_ICON_CHOOSER_CONTEXT_OTHER,
  ENDO_ICON_CHOOSER_N_CONTEXTS,

  /* not provided by the model (plus separators before them) */
  ENDO_ICON_CHOOSER_CONTEXT_ALL     = ENDO_ICON_CHOOSER_CONTEXT_OTHER + 2,
  ENDO_ICON_CHOOSER_CONTEXT_FILE    = ENDO_ICON_CHOOSER_CONTEXT_OTHER + 4,
  ENDO_ICON_CHOOSER_CONTEXT_NO_ICON = ENDO_ICON_CHOOSER_CONTEXT_OTHER + 6,
} EndoIconChooserContext;

/**
 * EndoIconChooserModelColumns:
 * @ENDO_ICON_CHOOSER_MODEL_COLUMN_CONTEXT      : the context of the icon.
 * @ENDO_ICON_CHOOSER_MODEL_COLUMN_ICON_NAME    : the name of the icon.
 * @ENDO_ICON_CHOOSER_MODEL_N_COLUMNS           : the number of columns.
 *
 * The columns provided by the #EndoIconChooserModel.
 **/
typedef enum
{
  ENDO_ICON_CHOOSER_MODEL_COLUMN_CONTEXT,
  ENDO_ICON_CHOOSER_MODEL_COLUMN_ICON_NAME,
  ENDO_ICON_CHOOSER_MODEL_N_COLUMNS,
} EndoIconChooserModelColumn;

G_GNUC_INTERNAL GType                  endo_icon_chooser_model_get_type                (void) G_GNUC_CONST;

G_GNUC_INTERNAL EndoIconChooserModel   *_endo_icon_chooser_model_get_for_widget         (GtkWidget           *widget) G_GNUC_WARN_UNUSED_RESULT;
G_GNUC_INTERNAL EndoIconChooserModel   *_endo_icon_chooser_model_get_for_icon_theme     (GtkIconTheme        *icon_theme) G_GNUC_WARN_UNUSED_RESULT;

G_GNUC_INTERNAL gboolean               _endo_icon_chooser_model_get_iter_for_icon_name (EndoIconChooserModel *model,
                                                                                       GtkTreeIter         *iter,
                                                                                       const gchar         *icon_name);

G_END_DECLS

#endif /* !__ENDO_ICON_CHOOSER_MODEL_H__ */
