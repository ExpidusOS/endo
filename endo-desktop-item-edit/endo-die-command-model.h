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

#ifndef __ENDO_DIE_COMMAND_MODEL_H__
#define __ENDO_DIE_COMMAND_MODEL_H__

#include <endo/endo.h>

G_BEGIN_DECLS;

typedef struct _EndoDieCommandModelClass EndoDieCommandModelClass;
typedef struct _EndoDieCommandModel      EndoDieCommandModel;

#define ENDO_DIE_TYPE_COMMAND_MODEL            (endo_die_command_model_get_type ())
#define ENDO_DIE_COMMAND_MODEL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_DIE_TYPE_COMMAND_MODEL, EndoDieCommandModel))
#define ENDO_DIE_COMMAND_MODEL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_DIE_TYPE_COMMAND_MODEL, EndoDieCommandModelClass))
#define ENDO_DIE_IS_COMMAND_MODEL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_DIE_TYPE_COMMAND_MODEL))
#define ENDO_DIE_IS_COMMAND_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_DIE_TYPE_COMMAND_MODEL))
#define ENDO_DIE_COMMAND_MODEL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_DIE_TYPE_COMMAND_MODEL, EndoDieCommandModelClass))

/**
 * EndoDieCommandModelColumn:
 * @ENDO_DIE_COMMAND_MODEL_COLUMN_NAME : the column with the file name.
 *
 * The columns provided by the #EndoDieCommandModel.
 **/
typedef enum /*< enum >*/
{
  ENDO_DIE_COMMAND_MODEL_COLUMN_NAME,
  ENDO_DIE_COMMAND_MODEL_N_COLUMNS,
} EndoDieCommandModelColumn;

GType               endo_die_command_model_get_type (void) G_GNUC_CONST;

EndoDieCommandModel *endo_die_command_model_new      (void) G_GNUC_MALLOC;

G_END_DECLS;

#endif /* !__ENDO_DIE_COMMAND_MODEL_H__ */
