/* vi:set et ai sw=2 sts=2 ts=2: */
/*-
 * Copyright (c) 2009 Jannis Pohlmann <jannis@expidus.org>
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
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#if !defined (ENDO_INSIDE_ENDO_H) && !defined (ENDO_COMPILATION)
#error "Only <endo/endo.h> can be included directly, this file may disappear or change contents."
#endif

#ifndef __ENDO_SIMPLE_JOB_H__
#define __ENDO_SIMPLE_JOB_H__

#include <endo/endo-job.h>

G_BEGIN_DECLS

/**
 * EndoSimpleJobFunc:
 * @job            : an #EndoJob.
 * @param_values   : a #GValueArray of the #GValue<!---->s passed to
 *                   endo_simple_job_launch().
 * @error          : return location for errors.
 *
 * Used by the #EndoSimpleJob to process the @job. See endo_simple_job_launch()
 * for further details.
 *
 * Returns: %TRUE on success, %FALSE in case of an error.
 **/
typedef gboolean (*EndoSimpleJobFunc) (EndoJob      *job,
                                      GValueArray *param_values,
                                      GError     **error);


#define ENDO_TYPE_SIMPLE_JOB            (endo_simple_job_get_type ())
#define ENDO_SIMPLE_JOB(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_SIMPLE_JOB, EndoSimpleJob))
#define ENDO_SIMPLE_JOB_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_SIMPLE_JOB, EndoSimpleJobClass))
#define ENDO_IS_SIMPLE_JOB(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_SIMPLE_JOB))
#define ENDO_IS_SIMPLE_JOB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_SIMPLE_JOB))
#define ENDO_SIMPLE_JOB_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_SIMPLE_JOB, EndoSimpleJobClass))

typedef struct _EndoSimpleJobClass EndoSimpleJobClass;
typedef struct _EndoSimpleJob      EndoSimpleJob;

GType   endo_simple_job_get_type (void) G_GNUC_CONST;

EndoJob *endo_simple_job_launch   (EndoSimpleJobFunc func,
                                 guint            n_param_values,
                                 ...) G_GNUC_MALLOC G_GNUC_WARN_UNUSED_RESULT;

G_END_DECLS

#endif /* !__ENDO_SIMPLE_JOB_H__ */
