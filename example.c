
#include <stdio.h>
#include <inttypes.h>
#include "sqlite_header.h"

int main()
{

	struct SqliteHeaderData s;

	ParseError e = sqlite_header_parse("../example_database.db", &s);
	
	if (e == NO_ERROR) {
		printf("Header string: %s\n", s.header_str);
		printf("Page size bytes: %" PRIu16 "\n" ,s.page_size_bytes);
		printf("File format write version: %u\n",s.file_format_write_version);
		printf("File format read version: %u\n",s.file_format_read_version);
		printf("Reserved space: %u\n",s.reserved_space_bytes);
		printf("Max embedded payload fraction: %u\n",s.max_embedded_payload_frac);
		printf("Min embedded payload fraction: %u\n",s.min_embedded_payload_frac);
		printf("Lead payload fraction: %u\n",s.leaf_payload_frac);
		printf("File change counter: %" PRIu32 "\n" ,s.file_change_counter);
		printf("Database size pages %" PRIu32 "\n" ,s.database_size_pages);
		printf("First freelist trunk page: %" PRIu32 "\n" ,s.first_freelist_trunk_page);
		printf("Total freelist pages: %" PRIu32 "\n" ,s.total_freelist_pages);
		printf("Schema cookie: %" PRIu32 "\n" ,s.schema_cookie);
		printf("Schema format number: %" PRIu32 "\n" ,s.schema_format_number);
		printf("Default page cache size bytes: %" PRIu32 "\n" ,s.default_page_cache_size_bytes);
		printf("Largest B tree page number: %" PRIu32 "\n" ,s.largest_b_tree_page_number);
		printf("Database text encoding: %" PRIu32 "\n" ,s.database_text_encoding);
		printf("User version: %" PRIu32 "\n" ,s.user_version);
		printf("Incremental vaccum mode: %" PRIu32 "\n" ,s.incremental_vaccum_mode);
		printf("Application id: %" PRIu32 "\n" ,s.application_id);
		printf("Version valid for: %" PRIu32 "\n" ,s.version_valid_for);
		printf("SQLite version: %" PRIu32 "\n" ,s.sqlite_version);
	}

	else {
		printf("Error: %d", e);
	}

	return 0;
}
