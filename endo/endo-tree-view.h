/*-
 * Copyright (c) 2004-2006 Benedikt Meurer <benny@expidus.org>
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

#ifndef __ENDO_TREE_VIEW_H__
#define __ENDO_TREE_VIEW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EndoTreeViewPrivate EndoTreeViewPrivate;
typedef struct _EndoTreeViewClass   EndoTreeViewClass;
typedef struct _EndoTreeView        EndoTreeView;

#define ENDO_TYPE_TREE_VIEW            (endo_tree_view_get_type ())
#define ENDO_TREE_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_TREE_VIEW, EndoTreeView))
#define ENDO_TREE_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_TREE_VIEW, EndoTreeViewClass))
#define ENDO_IS_TREE_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_TREE_VIEW))
#define ENDO_IS_TREE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_TREE_VIEW))
#define ENDO_TREE_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_TREE_VIEW, EndoTreeViewClass))

struct _EndoTreeViewClass
{
  /*< private >*/
  GtkTreeViewClass __parent__;

  /*< private >*/
  void (*reserved1) (void);
  void (*reserved2) (void);
  void (*reserved3) (void);
  void (*reserved4) (void);
  void (*reserved5) (void);
  void (*reserved6) (void);
  void (*reserved7) (void);
  void (*reserved8) (void);
};

/**
 * EndoTreeView:
 *
 * The #EndoIconView struct contains only private fields and should
 * not be directly accessed.
 **/
struct _EndoTreeView
{
  /*< private >*/
  GtkTreeView __parent__;

  /*< private >*/
  EndoTreeViewPrivate *priv;
};

GType      endo_tree_view_get_type                 (void) G_GNUC_CONST;

GtkWidget *endo_tree_view_new                      (void) G_GNUC_MALLOC;

gboolean   endo_tree_view_get_single_click         (const EndoTreeView *tree_view);
void       endo_tree_view_set_single_click         (EndoTreeView       *tree_view,
                                                   gboolean           single_click);

guint      endo_tree_view_get_single_click_timeout (const EndoTreeView *tree_view);
void       endo_tree_view_set_single_click_timeout (EndoTreeView       *tree_view,
                                                   guint              single_click_timeout);

G_END_DECLS

#endif /* !__ENDO_TREE_VIEW_H__ */
