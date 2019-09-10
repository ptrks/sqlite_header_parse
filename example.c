
#include <stdio.h>
#include "sqlite_header.h"

int main()
{

	struct SqliteHeaderData sqlite_data;

	ParseError e = get_header_information("test.db", &sqlite_data);
	
	if (e == NO_ERROR) {
		printf("Header string from database: %s", sqlite_data.header_str);
	}

	return 0;
}
