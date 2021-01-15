/*-
 * Copyright (c) 2004-2006  os-cillation e.K.
 * Copyright (c) 2002,2004  Anders Carlsson <andersca@gnu.org>
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

#if !defined (ENDO_INSIDE_ENDO_H) && !defined (ENDO_COMPILATION)
#error "Only <endo/endo.h> can be included directly, this file may disappear or change contents."
#endif

#ifndef __ENDO_ICON_VIEW_H__
#define __ENDO_ICON_VIEW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EndoIconViewPrivate    EndoIconViewPrivate;
typedef struct _EndoIconViewClass      EndoIconViewClass;
typedef struct _EndoIconView           EndoIconView;

#define ENDO_TYPE_ICON_VIEW            (endo_icon_view_get_type ())
#define ENDO_ICON_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_ICON_VIEW, EndoIconView))
#define ENDO_ICON_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_ICON_VIEW, EndoIconViewClass))
#define ENDO_IS_ICON_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_ICON_VIEW))
#define ENDO_IS_ICON_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_ICON_VIEW))
#define ENDO_ICON_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_ICON_VIEW, EndoIconViewClass))

/**
 * EndoIconViewForeachFunc:
 * @icon_view : an #EndoIconView.
 * @path      : the current path.
 * @user_data : the user data supplied to endo_icon_view_selected_foreach().
 *
 * Callback function prototype, invoked for every selected path in the
 * @icon_view. See endo_icon_view_selected_foreach() for details.
 **/
typedef void (*EndoIconViewForeachFunc) (EndoIconView *icon_view,
                                        GtkTreePath *path,
                                        gpointer     user_data);

/**
 * EndoIconViewSearchEqualFunc:
 * @model       : the #GtkTreeModel being searched.
 * @column      : the search column set by endo_icon_view_set_search_column().
 * @key         : the key string to compare with.
 * @iter        : the #GtkTreeIter of the current item.
 * @search_data : user data from endo_icon_view_set_search_equal_func().
 *
 * A function used for checking whether a row in @model matches a search key string
 * entered by the user. Note the return value is reversed from what you would normally
 * expect, though it has some similarity to strcmp() returning 0 for equal strings.
 *
 * Returns: %FALSE if the row matches, %TRUE otherwise.
 **/
typedef gboolean (*EndoIconViewSearchEqualFunc) (GtkTreeModel *model,
                                                gint          column,
                                                const gchar  *key,
                                                GtkTreeIter  *iter,
                                                gpointer      search_data);

/**
 * EndoIconViewSearchPositionFunc:
 * @icon_view     : an #EndoIconView.
 * @search_dialog : the search dialog window to place.
 * @user_data     : user data from endo_icon_view_set_search_position_func().
 *
 * A function used to place the @search_dialog for the @icon_view.
 **/
typedef void (*EndoIconViewSearchPositionFunc) (EndoIconView *icon_view,
                                               GtkWidget   *search_dialog,
                                               gpointer     user_data);

/**
 * EndoIconViewDropPosition:
 * @ENDO_ICON_VIEW_NO_DROP    : no drop indicator.
 * @ENDO_ICON_VIEW_DROP_INTO  : drop indicator on an item.
 * @ENDO_ICON_VIEW_DROP_LEFT  : drop indicator on the left of an item.
 * @ENDO_ICON_VIEW_DROP_RIGHT : drop indicator on the right of an item.
 * @ENDO_ICON_VIEW_DROP_ABOVE : drop indicator above an item.
 * @ENDO_ICON_VIEW_DROP_BELOW : drop indicator below an item.
 *
 * Specifies whether to display the drop indicator,
 * i.e. where to drop into the icon view.
 **/
typedef enum
{
  ENDO_ICON_VIEW_NO_DROP,
  ENDO_ICON_VIEW_DROP_INTO,
  ENDO_ICON_VIEW_DROP_LEFT,
  ENDO_ICON_VIEW_DROP_RIGHT,
  ENDO_ICON_VIEW_DROP_ABOVE,
  ENDO_ICON_VIEW_DROP_BELOW
} EndoIconViewDropPosition;

/**
 * EndoIconViewLayoutMode:
 * @ENDO_ICON_VIEW_LAYOUT_ROWS : layout items in rows.
 * @ENDO_ICON_VIEW_LAYOUT_COLS : layout items in columns.
 *
 * Specifies the layouting mode of an #EndoIconView. @ENDO_ICON_VIEW_LAYOUT_ROWS
 * is the default, which lays out items vertically in rows from top to bottom.
 * @ENDO_ICON_VIEW_LAYOUT_COLS lays out items horizontally in columns from left
 * to right.
 **/
typedef enum
{
  ENDO_ICON_VIEW_LAYOUT_ROWS,
  ENDO_ICON_VIEW_LAYOUT_COLS
} EndoIconViewLayoutMode;

/**
 * EndoIconView:
 *
 * #EndoIconView provides an alternative view on a list model.
 * It displays the model as a grid of icons with labels. Like
 * #GtkTreeView, it allows to select one or multiple items
 * (depending on the selection mode, see endo_icon_view_set_selection_mode()).
 * In addition to selection with the arrow keys, #EndoIconView supports
 * rubberband selection, which is controlled by dragging the pointer.
 **/
struct _EndoIconView
{
  GtkContainer        __parent__;

  /*< private >*/
  EndoIconViewPrivate *priv;
};

struct _EndoIconViewClass
{
  GtkContainerClass __parent__;

  /* virtual methods */
  void     (*set_scroll_adjustments)    (EndoIconView     *icon_view,
                                         GtkAdjustment   *hadjustment,
                                         GtkAdjustment   *vadjustment);

  /* signals */
  void     (*item_activated)            (EndoIconView     *icon_view,
                                         GtkTreePath     *path);
  void     (*selection_changed)         (EndoIconView     *icon_view);

  /* Key binding signals */
  void     (*select_all)                (EndoIconView    *icon_view);
  void     (*unselect_all)              (EndoIconView    *icon_view);
  void     (*select_cursor_item)        (EndoIconView    *icon_view);
  void     (*toggle_cursor_item)        (EndoIconView    *icon_view);
  gboolean (*move_cursor)               (EndoIconView    *icon_view,
                                         GtkMovementStep step,
                                         gint            count);
  gboolean (*activate_cursor_item)      (EndoIconView    *icon_view);
  gboolean (*start_interactive_search)  (EndoIconView    *icon_view);

  /*< private >*/
  void (*reserved0) (void);
  void (*reserved1) (void);
  void (*reserved2) (void);
  void (*reserved3) (void);
  void (*reserved4) (void);
  void (*reserved5) (void);
  void (*reserved6) (void);
  void (*reserved7) (void);
  void (*reserved8) (void);
  void (*reserved9) (void);
};

GType                 endo_icon_view_get_type                  (void) G_GNUC_CONST;

GtkWidget            *endo_icon_view_new                       (void);
GtkWidget            *endo_icon_view_new_with_model            (GtkTreeModel             *model);

GtkTreeModel         *endo_icon_view_get_model                 (const EndoIconView        *icon_view);
void                  endo_icon_view_set_model                 (EndoIconView              *icon_view,
                                                               GtkTreeModel             *model);

GtkOrientation        endo_icon_view_get_orientation           (const EndoIconView        *icon_view);
void                  endo_icon_view_set_orientation           (EndoIconView              *icon_view,
                                                               GtkOrientation            orientation);

gint                  endo_icon_view_get_columns               (const EndoIconView        *icon_view);
void                  endo_icon_view_set_columns               (EndoIconView              *icon_view,
                                                               gint                      columns);

gint                  endo_icon_view_get_item_width            (const EndoIconView        *icon_view);
void                  endo_icon_view_set_item_width            (EndoIconView              *icon_view,
                                                               gint                      item_width);

gint                  endo_icon_view_get_spacing               (const EndoIconView        *icon_view);
void                  endo_icon_view_set_spacing               (EndoIconView              *icon_view,
                                                               gint                      spacing);

gint                  endo_icon_view_get_row_spacing           (const EndoIconView        *icon_view);
void                  endo_icon_view_set_row_spacing           (EndoIconView              *icon_view,
                                                               gint                      row_spacing);

gint                  endo_icon_view_get_column_spacing        (const EndoIconView        *icon_view);
void                  endo_icon_view_set_column_spacing        (EndoIconView              *icon_view,
                                                               gint                      column_spacing);

gint                  endo_icon_view_get_margin                (const EndoIconView        *icon_view);
void                  endo_icon_view_set_margin                (EndoIconView              *icon_view,
                                                               gint                      margin);

GtkSelectionMode      endo_icon_view_get_selection_mode        (const EndoIconView        *icon_view);
void                  endo_icon_view_set_selection_mode        (EndoIconView              *icon_view,
                                                               GtkSelectionMode          mode);

EndoIconViewLayoutMode endo_icon_view_get_layout_mode           (const EndoIconView        *icon_view);
void                  endo_icon_view_set_layout_mode           (EndoIconView              *icon_view,
                                                               EndoIconViewLayoutMode     layout_mode);

gboolean              endo_icon_view_get_single_click          (const EndoIconView        *icon_view);
void                  endo_icon_view_set_single_click          (EndoIconView              *icon_view,
                                                               gboolean                  single_click);

guint                 endo_icon_view_get_single_click_timeout  (const EndoIconView        *icon_view);
void                  endo_icon_view_set_single_click_timeout  (EndoIconView              *icon_view,
                                                               guint                     single_click_timeout);

void                  endo_icon_view_widget_to_icon_coords     (const EndoIconView        *icon_view,
                                                               gint                      wx,
                                                               gint                      wy,
                                                               gint                     *ix,
                                                               gint                     *iy);
void                  endo_icon_view_icon_to_widget_coords     (const EndoIconView        *icon_view,
                                                               gint                      ix,
                                                               gint                      iy,
                                                               gint                     *wx,
                                                               gint                     *wy);

GtkTreePath          *endo_icon_view_get_path_at_pos           (const EndoIconView        *icon_view,
                                                               gint                      x,
                                                               gint                      y);
gboolean              endo_icon_view_get_item_at_pos           (const EndoIconView        *icon_view,
                                                               gint                      x,
                                                               gint                      y,
                                                               GtkTreePath             **path,
                                                               GtkCellRenderer         **cell);

gboolean              endo_icon_view_get_visible_range         (const EndoIconView        *icon_view,
                                                               GtkTreePath             **start_path,
                                                               GtkTreePath             **end_path);

void                  endo_icon_view_selected_foreach          (EndoIconView              *icon_view,
                                                               EndoIconViewForeachFunc    func,
                                                               gpointer                  data);
void                  endo_icon_view_select_path               (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);
void                  endo_icon_view_unselect_path             (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);
gboolean              endo_icon_view_path_is_selected          (const EndoIconView        *icon_view,
                                                               GtkTreePath              *path);
GList                *endo_icon_view_get_selected_items        (const EndoIconView        *icon_view);
void                  endo_icon_view_select_all                (EndoIconView              *icon_view);
void                  endo_icon_view_unselect_all              (EndoIconView              *icon_view);
void                  endo_icon_view_selection_invert          (EndoIconView              *icon_view);
void                  endo_icon_view_item_activated            (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);

gint                  endo_icon_view_get_item_column           (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);
gint                  endo_icon_view_get_item_row              (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);

gboolean              endo_icon_view_get_cursor                (const EndoIconView        *icon_view,
                                                               GtkTreePath             **path,
                                                               GtkCellRenderer         **cell);
void                  endo_icon_view_set_cursor                (EndoIconView              *icon_view,
                                                               GtkTreePath              *path,
                                                               GtkCellRenderer          *cell,
                                                               gboolean                  start_editing);

void                  endo_icon_view_scroll_to_path            (EndoIconView              *icon_view,
                                                               GtkTreePath              *path,
                                                               gboolean                  use_align,
                                                               gfloat                    row_align,
                                                               gfloat                    col_align);

/* Drag-and-Drop support */
void                  endo_icon_view_enable_model_drag_source  (EndoIconView              *icon_view,
                                                               GdkModifierType           start_button_mask,
                                                               const GtkTargetEntry     *targets,
                                                               gint                      n_targets,
                                                               GdkDragAction             actions);
void                  endo_icon_view_enable_model_drag_dest    (EndoIconView              *icon_view,
                                                               const GtkTargetEntry     *targets,
                                                               gint                      n_targets,
                                                               GdkDragAction             actions);
void                  endo_icon_view_unset_model_drag_source   (EndoIconView              *icon_view);
void                  endo_icon_view_unset_model_drag_dest     (EndoIconView              *icon_view);
void                  endo_icon_view_set_reorderable           (EndoIconView              *icon_view,
                                                               gboolean                  reorderable);
gboolean              endo_icon_view_get_reorderable           (EndoIconView              *icon_view);


/* These are useful to implement your own custom stuff. */
void                  endo_icon_view_set_drag_dest_item        (EndoIconView              *icon_view,
                                                               GtkTreePath              *path,
                                                               EndoIconViewDropPosition   pos);
void                  endo_icon_view_get_drag_dest_item        (EndoIconView              *icon_view,
                                                               GtkTreePath             **path,
                                                               EndoIconViewDropPosition  *pos);
gboolean              endo_icon_view_get_dest_item_at_pos      (EndoIconView              *icon_view,
                                                               gint                      drag_x,
                                                               gint                      drag_y,
                                                               GtkTreePath             **path,
                                                               EndoIconViewDropPosition  *pos);
cairo_surface_t      *endo_icon_view_create_drag_icon          (EndoIconView              *icon_view,
                                                               GtkTreePath              *path);


/* Interactive search support */
gboolean                      endo_icon_view_get_enable_search         (const EndoIconView            *icon_view);
void                          endo_icon_view_set_enable_search         (EndoIconView                  *icon_view,
                                                                       gboolean                      enable_search);
gint                          endo_icon_view_get_search_column         (const EndoIconView            *icon_view);
void                          endo_icon_view_set_search_column         (EndoIconView                  *icon_view,
                                                                       gint                          search_column);
EndoIconViewSearchEqualFunc    endo_icon_view_get_search_equal_func     (const EndoIconView            *icon_view);
void                          endo_icon_view_set_search_equal_func     (EndoIconView                  *icon_view,
                                                                       EndoIconViewSearchEqualFunc    search_equal_func,
                                                                       gpointer                      search_equal_data,
                                                                       GDestroyNotify                search_equal_destroy);
EndoIconViewSearchPositionFunc endo_icon_view_get_search_position_func  (const EndoIconView            *icon_view);
void                          endo_icon_view_set_search_position_func  (EndoIconView                  *icon_view,
                                                                       EndoIconViewSearchPositionFunc search_position_func,
                                                                       gpointer                      search_position_data,
                                                                       GDestroyNotify                search_position_destroy);

G_END_DECLS

#endif /* __ENDO_ICON_VIEW_H__ */
