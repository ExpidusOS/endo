/*-
 * Copyright (c) 2006 Benedikt Meurer <benny@expidus.org>.
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

#ifndef __ENDO_DIE_DESKTOP_MODEL_H__
#define __ENDO_DIE_DESKTOP_MODEL_H__

#include <endo/endo.h>

G_BEGIN_DECLS;

typedef struct _EndoDieDesktopModelClass EndoDieDesktopModelClass;
typedef struct _EndoDieDesktopModel      EndoDieDesktopModel;

#define ENDO_DIE_TYPE_DESKTOP_MODEL            (endo_die_desktop_model_get_type ())
#define ENDO_DIE_DESKTOP_MODEL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_DIE_TYPE_DESKTOP_MODEL, EndoDieDesktopModel))
#define ENDO_DIE_DESKTOP_MODEL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_DIE_TYPE_DESKTOP_MODEL, EndoDieDesktopModelClass))
#define ENDO_DIE_IS_DESKTOP_MODEL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_DIE_TYPE_DESKTOP_MODEL))
#define ENDO_DIE_IS_DESKTOP_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_DIE_TYPE_DESKTOP_MODEL))
#define ENDO_DIE_DESKTOP_MODEL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_DIE_TYPE_DESKTOP_MODEL, EndoDieDesktopModelClass))

/**
 * EndoDieDesktopModelColumn:
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_ABSTRACT : the column with the markup text for the renderer.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_COMMAND  : the column with the application command.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_COMMENT  : the column with the application comment.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_ICON     : the column with the application icon.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_NAME     : the column with the application name.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_SNOTIFY  : the column with the applications StartupNotify setting.
 * @ENDO_DIE_DESKTOP_MODEL_COLUMN_TERMINAL : the column with the applications Terminal setting.
 *
 * The columns provided by the #EndoDieDesktopModel.
 **/
typedef enum /*< enum >*/
{
  ENDO_DIE_DESKTOP_MODEL_COLUMN_ABSTRACT,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_COMMAND,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_COMMENT,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_ICON,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_NAME,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_SNOTIFY,
  ENDO_DIE_DESKTOP_MODEL_COLUMN_TERMINAL,
  ENDO_DIE_DESKTOP_MODEL_N_COLUMNS,
} EndoDieDesktopModelColumn;

GType               endo_die_desktop_model_get_type    (void) G_GNUC_CONST;

EndoDieDesktopModel *endo_die_desktop_model_new         (void) G_GNUC_MALLOC;

gboolean            endo_die_desktop_model_match_func  (GtkEntryCompletion *completion,
                                                       const gchar        *key,
                                                       GtkTreeIter        *iter,
                                                       gpointer            user_data);

G_END_DECLS;

#endif /* !__ENDO_DIE_DESKTOP_MODEL_H__ */
