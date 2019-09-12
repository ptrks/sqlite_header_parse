
#include <stdio.h>
#include "sqlite_header.h"

int main()
{

	struct SqliteHeaderData sqlite_data;

	ParseError e = sqlite_header_parse("test.db", &sqlite_data);
	
	if (e == NO_ERROR) {
		printf("Header string from database: %s", sqlite_data.header_str);
	}

	return 0;
}
