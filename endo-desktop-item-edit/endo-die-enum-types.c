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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <endo-desktop-item-edit/endo-die-enum-types.h>



GType
endo_die_editor_mode_get_type (void)
{
  static GType type = G_TYPE_INVALID;

  if (G_UNLIKELY (type == G_TYPE_INVALID))
    {
      static const GEnumValue values[] =
      {
        { ENDO_DIE_EDITOR_MODE_APPLICATION, "ENDO_DIE_EDITOR_MODE_APPLICATION", "Application", },
        { ENDO_DIE_EDITOR_MODE_LINK,        "ENDO_DIE_EDITOR_MODE_LINK",        "Link",        },
        { ENDO_DIE_EDITOR_MODE_DIRECTORY,   "ENDO_DIE_EDITOR_MODE_DIRECTORY",   "Directory",   },
        { 0,                               NULL,                              NULL,          },
      };

      type = g_enum_register_static (I_("EndoDieEditorMode"), values);
    }

  return type;
}

