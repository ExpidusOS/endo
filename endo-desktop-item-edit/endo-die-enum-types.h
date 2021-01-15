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

#ifndef __ENDO_DIE_ENUM_TYPES_H__
#define __ENDO_DIE_ENUM_TYPES_H__

#include <endo/endo.h>

G_BEGIN_DECLS

#define ENDO_DIE_TYPE_EDITOR_MODE (endo_die_editor_mode_get_type ())

/**
 * EndoDieEditorMode:
 * @ENDO_DIE_EDITOR_MODE_APPLICATION : application launcher editing.
 * @ENDO_DIE_EDITOR_MODE_LINK        : link editing.
 * @ENDO_DIE_EDITOR_MODE_DIRECTORY   : menu directory editing.
 *
 * Editing mode for endo-desktop-item-edit
 *
 **/
typedef enum
{
  ENDO_DIE_EDITOR_MODE_APPLICATION,
  ENDO_DIE_EDITOR_MODE_LINK,
  ENDO_DIE_EDITOR_MODE_DIRECTORY
} EndoDieEditorMode;

GType endo_die_editor_mode_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* !__ENDO_DIE_ENUM_TYPES_H__ */
