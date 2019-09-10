#ifndef SQLITE_HEADER_PARSE_H
#define SQLITE_HEADER_PARSE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

const uint8_t HEADER_SIZE_BYTES = 100;

typedef enum {
	NO_ERROR=0, 
	FILE_IO_ERROR, 
	INVALID_HEADER_LEN, 
	INVALID_HEADER_STRING
} ParseError;

typedef struct SqliteHeaderData {
	unsigned char header_str[16];
	uint16_t page_size_bytes;
	unsigned char file_format_write_version;
	unsigned char file_format_read_version;
	unsigned char reserved_space_bytes;
	unsigned char max_embedded_payload_frac;
	unsigned char min_embedded_payload_frac;
	unsigned char leaf_payload_frac;
	uint32_t file_change_counter;
	uint32_t database_size_pages;
	uint32_t first_freelist_trunk_page;
	uint32_t total_freelist_pages;
	uint32_t schema_cookie;
	uint32_t schema_format_number;
	uint32_t default_page_cache_size_bytes;
	uint32_t largest_b_tree_page_number;
	uint32_t database_text_encoding;
	uint32_t user_version;
	uint32_t incremental_vaccum_mode;
	uint32_t application_id;
	uint32_t version_valid_for;
	uint32_t sqlite_version;
} SqliteHeaderData;

static ParseError 
get_header_information(const char *database_file, struct SqliteHeaderData *d) {
	
	FILE *fp;
	size_t bytes_read = 0;
	unsigned char rh[HEADER_SIZE_BYTES];
	
	fp = fopen(database_file, "rb");

	if (fp == NULL)
		return FILE_IO_ERROR;
	
	bytes_read = fread(rh, sizeof(unsigned char), HEADER_SIZE_BYTES, fp);
	fclose(fp);
	
	if (bytes_read != HEADER_SIZE_BYTES)
		return INVALID_HEADER_LEN;

	memcpy(d->header_str, rh, 16);

	if (strcmp(d->header_str, "SQLite format 3") != 0)
		return INVALID_HEADER_STRING;
	
	d->page_size_bytes = (rh[16] << 8) | rh[17];
	d->file_format_write_version = rh[18];
	d->file_format_read_version = rh[19];
	d->reserved_space_bytes = rh[20];
	d->max_embedded_payload_frac = rh[21];
	d->min_embedded_payload_frac = rh[22];
	d->leaf_payload_frac = rh[23];

	d->file_change_counter = 
		(rh[24] << 24) | 
		(rh[25] << 16) | 
		(rh[26] << 8)  | 
		(rh[27] << 0);

 	d->database_size_pages =
 		(rh[28] << 24) | 
		(rh[29] << 16) | 
		(rh[30] << 8)  | 
		(rh[31] << 0);

	d->first_freelist_trunk_page = 
		(rh[32] << 24) | 
		(rh[33] << 16) | 
		(rh[34] << 8)  | 
		(rh[35] << 0);

	d->total_freelist_pages =
		(rh[36] << 24) | 
		(rh[37] << 16) | 
		(rh[38] << 8)  | 
		(rh[39] << 0);

	d->schema_cookie =
		(rh[40] << 24) | 
		(rh[41] << 16) | 
		(rh[42] << 8)  | 
		(rh[43] << 0);

	d->schema_format_number =
		(rh[44] << 24) | 
		(rh[45] << 16) | 
		(rh[46] << 8)  | 
		(rh[47] << 0);

	d->default_page_cache_size_bytes =
		(rh[48] << 24) | 
		(rh[49] << 16) | 
		(rh[50] << 8)  | 
		(rh[51] << 0);

	d->largest_b_tree_page_number =
		(rh[52] << 24) | 
		(rh[53] << 16) | 
		(rh[54] << 8)  | 
		(rh[55] << 0);

	d->database_text_encoding =
		(rh[56] << 24) | 
		(rh[57] << 16) | 
		(rh[58] << 8)  | 
		(rh[59] << 0);

	d->user_version =
		(rh[60] << 24) | 
		(rh[61] << 16) | 
		(rh[62] << 8)  | 
		(rh[63] << 0);

	d-> incremental_vaccum_mode = 
		(rh[64] << 24) | 
		(rh[65] << 16) | 
		(rh[66] << 8)  | 
		(rh[67] << 0);

	d->application_id = 
		(rh[68] << 24) | 
		(rh[69] << 16) | 
		(rh[70] << 8)  | 
		(rh[71] << 0);

	d->version_valid_for =
		(rh[92] << 24) | 
		(rh[93] << 16) | 
		(rh[94] << 8)  | 
		(rh[95] << 0);

	d->sqlite_version =
		(rh[96] << 24) | 
		(rh[97] << 16) | 
		(rh[98] << 8)  | 
		(rh[99] << 0);

	return NO_ERROR;

}

#endif
