/* 
 * Windows Search database export functions
 *
 * Copyright (c) 2010, Joachim Metz <jbmetz@users.sourceforge.net>
 * Copyright (C) 2009, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _WINDOWS_SEARCH_H )
#define _WINDOWS_SEARCH_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include <liberror.h>

/* If libtool DLL support is enabled set LIBESEDB_DLL_IMPORT
 * before including libesedb_extern.h
 */
#if defined( _WIN32 ) && defined( DLL_EXPORT )
#define LIBESEDB_DLL_EXPORT
#endif

#include <libesedb.h>

#if defined( __cplusplus )
extern "C" {
#endif

int windows_search_decode(
     uint8_t *data,
     size_t data_size,
     uint8_t *encoded_data,
     size_t encoded_data_size,
     liberror_error_t **error );

int windows_search_get_utf16_string_uncompressed_data_size(
     uint8_t *compressed_data,
     size_t compressed_data_size,
     size_t *uncompressed_data_size,
     liberror_error_t **error );

int windows_search_decompress_utf16_string(
     uint8_t *uncompressed_data,
     size_t uncompressed_data_size,
     uint8_t *compressed_data,
     size_t compressed_data_size,
     liberror_error_t **error );

int windows_search_export_compressed_string_value(
     uint8_t *value_data,
     size_t value_data_size,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_value_32bit(
     libesedb_record_t *record,
     int record_value_entry,
     uint8_t byte_order,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_value_64bit(
     libesedb_record_t *record,
     int record_value_entry,
     uint8_t byte_order,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_value_filetime(
     libesedb_record_t *record,
     int record_value_entry,
     uint8_t byte_order,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_value_compressed_string(
     libesedb_record_t *record,
     int record_value_entry,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_value_utf16_string(
     libesedb_record_t *record,
     int record_value_entry,
     uint8_t byte_order,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_systemindex_0a(
     libesedb_record_t *record,
     FILE *table_file_stream,
     liberror_error_t **error );

int windows_search_export_record_systemindex_gthr(
     libesedb_record_t *record,
     FILE *table_file_stream,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

