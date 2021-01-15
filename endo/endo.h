/*-
 * Copyright (c) 2004-2007 os-cillation e.K.
 *
 * Written by Benedikt Meurer <benny@expidus.org>.
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

#ifndef __ENDO_H__
#define __ENDO_H__

/* be sure to have i18n macros available and libintl.h included! */
#if defined(GETTEXT_PACKAGE)
#include <glib/gi18n-lib.h>
#else
#include <glib/gi18n.h>
#endif

#include <gtk/gtk.h>

#define ENDO_INSIDE_ENDO_H

#include <endo/endo-config.h>
#include <endo/endo-binding.h>
#include <endo/endo-enum-types.h>
#include <endo/endo-cell-renderer-icon.h>
#include <endo/endo-gdk-pixbuf-extensions.h>
#include <endo/endo-gobject-extensions.h>
#include <endo/endo-execute.h>
#include <endo/endo-job.h>
#include <endo/endo-simple-job.h>
#include <endo/endo-string.h>
#include <endo/endo-utils.h>
#include <endo/endo-gtk-extensions.h>
#include <endo/endo-icon-chooser-dialog.h>
#include <endo/endo-icon-view.h>
#include <endo/endo-tree-view.h>

#undef ENDO_INSIDE_ENDO_H

#endif /* !__ENDO_H__ */
