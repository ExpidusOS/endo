/*-
 * Copyright (c) 2006 Benedikt Meurer <benny@expidus.org>
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

#ifndef __ENDO_THUMBNAIL_PREVIEW_H__
#define __ENDO_THUMBNAIL_PREVIEW_H__

#include <endo/endo-config.h>

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EndoThumbnailPreviewClass EndoThumbnailPreviewClass;
typedef struct _EndoThumbnailPreview      EndoThumbnailPreview;

#define ENDO_TYPE_THUMBNAIL_PREVIEW            (endo_thumbnail_preview_get_type ())
#define ENDO_THUMBNAIL_PREVIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_THUMBNAIL_PREVIEW, EndoThumbnailPreview))
#define ENDO_THUMBNAIL_PREVIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_THUMBNAIL_PREVIEW, EndoThumbnailPreviewClass))
#define ENDO_IS_THUMBNAIL_PREVIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_THUMBNAIL_PREVIEW))
#define ENDO_IS_THUMBNAIL_PREVIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_THUMBNAIL_PREVIEW))
#define ENDO_THUMBNAIL_PREVIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_THUMBNAIL_PREVIEW, EndoThumbnailPreviewClass))

G_GNUC_INTERNAL GType      endo_thumbnail_preview_get_type  (void) G_GNUC_CONST;

G_GNUC_INTERNAL GtkWidget *_endo_thumbnail_preview_new      (void) G_GNUC_MALLOC G_GNUC_WARN_UNUSED_RESULT;

G_GNUC_INTERNAL void       _endo_thumbnail_preview_set_uri  (EndoThumbnailPreview *thumbnail_preview,
                                                            const gchar         *uri);

G_END_DECLS

#endif /* !__ENDO_THUMBNAIL_PREVIEW_H__ */
