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

#ifndef __ENDO_DIE_EDITOR_H__
#define __ENDO_DIE_EDITOR_H__

#include <endo-desktop-item-edit/endo-die-enum-types.h>

G_BEGIN_DECLS;

typedef struct _EndoDieEditorClass EndoDieEditorClass;
typedef struct _EndoDieEditor      EndoDieEditor;

#define ENDO_DIE_TYPE_EDITOR             (endo_die_editor_get_type ())
#define ENDO_DIE_EDITOR(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_DIE_TYPE_EDITOR, EndoDieEditor))
#define ENDO_DIE_EDITOR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_DIE_TYPE_EDITOR, EndoDieEditorClass))
#define ENDO_DIE_IS_EDITOR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_DIE_TYPE_EDITOR))
#define ENDO_DIE_IS_EDITOR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_DIE_TYPE_EDITOR))
#define ENDO_DIE_EDITOR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_DIE_TYPE_EDITOR, EndoDieEditorClass))

GType             endo_die_editor_get_type     (void) G_GNUC_CONST;

GtkWidget        *endo_die_editor_new          (void) G_GNUC_MALLOC;

gboolean          endo_die_editor_get_complete (EndoDieEditor     *editor);

EndoDieEditorMode  endo_die_editor_get_mode     (EndoDieEditor     *editor);
void              endo_die_editor_set_mode     (EndoDieEditor     *editor,
                                               EndoDieEditorMode  mode);

const gchar      *endo_die_editor_get_name     (EndoDieEditor     *editor);
void              endo_die_editor_set_name     (EndoDieEditor     *editor,
                                               const gchar      *name);

const gchar      *endo_die_editor_get_comment  (EndoDieEditor     *editor);
void              endo_die_editor_set_comment  (EndoDieEditor     *editor,
                                               const gchar      *comment);

const gchar      *endo_die_editor_get_command  (EndoDieEditor     *editor);
void              endo_die_editor_set_command  (EndoDieEditor     *editor,
                                               const gchar      *command);

const gchar      *endo_die_editor_get_url      (EndoDieEditor     *editor);
void              endo_die_editor_set_url      (EndoDieEditor     *editor,
                                               const gchar      *url);

const gchar      *endo_die_editor_get_path     (EndoDieEditor     *editor);
void              endo_die_editor_set_path     (EndoDieEditor     *editor,
                                               const gchar      *path);

const gchar      *endo_die_editor_get_icon     (EndoDieEditor     *editor);
void              endo_die_editor_set_icon     (EndoDieEditor     *editor,
                                               const gchar      *icon);

gboolean          endo_die_editor_get_snotify  (EndoDieEditor     *editor);
void              endo_die_editor_set_snotify  (EndoDieEditor     *editor,
                                               gboolean          snotify);

gboolean          endo_die_editor_get_terminal (EndoDieEditor     *editor);
void              endo_die_editor_set_terminal (EndoDieEditor     *editor,
                                               gboolean          terminal);

G_END_DECLS;

#endif /* !__ENDO_DIE_EDITOR_H__ */
