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

#ifndef __ENDO_JOB_H__
#define __ENDO_JOB_H__

#include <gio/gio.h>

G_BEGIN_DECLS

#define ENDO_TYPE_JOB            (endo_job_get_type ())
#define ENDO_JOB(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENDO_TYPE_JOB, EndoJob))
#define ENDO_JOB_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENDO_TYPE_JOB, EndoJobClass))
#define ENDO_IS_JOB(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENDO_TYPE_JOB))
#define ENDO_IS_JOB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENDO_TYPE_JOB)
#define ENDO_JOB_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENDO_TYPE_JOB, EndoJobClass))

typedef struct _EndoJobPrivate EndoJobPrivate;
typedef struct _EndoJobClass   EndoJobClass;
typedef struct _EndoJob        EndoJob;

struct _EndoJobClass
{
  GObjectClass __parent__;

  /* virtual methods */
  gboolean   (*execute)      (EndoJob      *job,
                              GError     **error);

  /* signals */
  void       (*error)        (EndoJob      *job,
                              GError      *error);
  void       (*finished)     (EndoJob      *job);
  void       (*info_message) (EndoJob      *job,
                              const gchar *message);
  void       (*percent)      (EndoJob      *job,
                              gdouble      percent);
};

/**
 * EndoJob:
 *
 * The #EndoJob struct contains only private fields and should not be
 * directly accessed.
 **/
struct _EndoJob
{
  GObject __parent__;

  /*< private >*/
  EndoJobPrivate *priv;
};

GType           endo_job_get_type               (void) G_GNUC_CONST;

EndoJob         *endo_job_launch                 (EndoJob        *job);
void            endo_job_cancel                 (EndoJob        *job);
gboolean        endo_job_is_cancelled           (const EndoJob  *job);
GCancellable   *endo_job_get_cancellable        (const EndoJob  *job);
gboolean        endo_job_set_error_if_cancelled (EndoJob        *job,
                                                GError       **error);
void            endo_job_emit                   (EndoJob        *job,
                                                guint          signal_id,
                                                GQuark         signal_detail,
                                                ...);
void            endo_job_info_message           (EndoJob        *job,
                                                const gchar   *format,
                                                ...);
void            endo_job_percent                (EndoJob        *job,
                                                gdouble        percent);
gboolean        endo_job_send_to_mainloop       (EndoJob        *job,
                                                GSourceFunc    func,
                                                gpointer       user_data,
                                                GDestroyNotify destroy_notify);

G_END_DECLS

#endif /* !__ENDO_JOB_H__ */
