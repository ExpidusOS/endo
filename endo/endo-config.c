/*-
 * Copyright (c) 2004 os-cillation e.K.
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <endo/endo-config.h>
#include <endo/endo-alias.h>

/**
 * SECTION: endo-config
 * @title: Version Information
 * @short_description: Variables and macros to check the endo version
 * @include: endo/endo.h
 *
 * Endo provides version information, primarily useful in configure for
 * builds that have a configure script. Applications may use it to
 * check if a certain feature is available in the version of libendo
 * they are being built against or being linked with.
 **/

/**
 * endo_major_version:
 *
 * The major version number of the endo library (e.g. in endo 1.2.3 this is 1).
 *
 * This variable is in the library, and therefore represents the endo
 * library you have linked against. Contrast with the #ENDO_MAJOR_VERSION
 * macro, which represents the major version of the libendo headers you
 * have included.
 **/
const guint endo_major_version = ENDO_MAJOR_VERSION;

/**
 * endo_minor_version:
 *
 * The minor version number of the endo library (e.g. in endo 1.2.3 this is 2).
 *
 * This variable is in the library, and therefore represents the endo
 * library you have linked against. Contrast with the #ENDO_MINOR_VERSION
 * macro, which represents the minor version of the libendo headers you
 * have included.
 **/
const guint endo_minor_version = ENDO_MINOR_VERSION;

/**
 * endo_micro_version:
 *
 * The micro version number of the endo library (e.g. in endo 1.2.3 this is 3).
 *
 * This variable is in the library, and therefore represents the endo
 * library you have linked against. Contrast with the #ENDO_MICRO_VERSION
 * macro, which represents the micro version of the libendo headers you
 * have included.
 **/
const guint endo_micro_version = ENDO_MICRO_VERSION;



/**
 * endo_check_version:
 * @required_major : the required major version.
 * @required_minor : the required minor version.
 * @required_micro : the required micro version.
 *
 * Checks that the <systemitem class="library">endo</systemitem> library
 * in use is compatible with the given version. Generally you would pass in
 * the constants #ENDO_MAJOR_VERSION, #ENDO_MINOR_VERSION and #ENDO_MICRO_VERSION
 * as the three arguments to this function; that produces
 * a check that the library in use is compatible with the version of
 * <systemitem class="library">endo</systemitem> the application was
 * compiled against.
 *
 * <example>
 * <title>Checking the runtime version of the endo library</title>
 * <programlisting>
 * const gchar *mismatch;
 * mismatch = endo_check_version (ENDO_VERSION_MAJOR,
 *                               ENDO_VERSION_MINOR,
 *                               ENDO_VERSION_MICRO);
 * if (G_UNLIKELY (mismatch != NULL))
 *   g_error ("Version mismatch: %<!---->s", mismatch);
 * </programlisting>
 * </example>
 *
 * Returns: %NULL if the library is compatible with the given version,
 *          or a string describing the version mismatch. The returned
 *          string is owned by the library and must not be freed or
 *          modified by the caller.
 *
 * Since: 0.3.1
 **/
const gchar*
endo_check_version (guint required_major,
                   guint required_minor,
                   guint required_micro)
{
  return NULL;
}



#define __ENDO_CONFIG_C__
#include <endo/endo-aliasdef.c>
