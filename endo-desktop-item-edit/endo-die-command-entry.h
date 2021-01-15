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

#ifndef __ENDO_DIE_COMMAND_ENTRY_H__
#define __ENDO_DIE_COMMAND_ENTRY_H__

#include <endo/endo.h>

G_BEGIN_DECLS;

typedef struct _EndoDieCommandEntryClass EndoDieCommandEntryClass;
typedef struct _EndoDieCommandEntry      EndoDieCommandEntry;

#define ENDO_DIE_TYPE_COMMAND_ENTRY            (endo_die_command_entry_get_type ())
#define ENDO_DIE_COMMAND_ENTRY(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_DIE_TYPE_COMMAND_ENTRY, EndoDieCommandEntry))
#define ENDO_DIE_COMMAND_ENTRY_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_DIE_TYPE_COMMAND_ENTRY, EndoDieCommandEntryClass))
#define ENDO_DIE_IS_COMMAND_ENTRY(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_DIE_TYPE_COMMAND_ENTRY))
#define ENDO_DIE_IS_COMMAND_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_DIE_TYPE_COMMAND_ENTRY))
#define ENDO_DIE_COMMAND_ENTRY_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_DIE_TYPE_COMMAND_ENTRY, EndoDieCommandEntryClass))

GType        endo_die_command_entry_get_type (void) G_GNUC_CONST;

GtkWidget   *endo_die_command_entry_new      (void) G_GNUC_MALLOC;

const gchar *endo_die_command_entry_get_text (EndoDieCommandEntry *command_entry);
void         endo_die_command_entry_set_text (EndoDieCommandEntry *command_entry,
                                             const gchar        *text);

G_END_DECLS;

#endif /* !__ENDO_DIE_COMMAND_ENTRY_H__ */
