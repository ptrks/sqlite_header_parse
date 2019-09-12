# SQLite Header Parse
Simple C header only library for parsing information from SQLite database headers.

---
### Overview
SQLite database files have quite a bit of information contained within their header. While plenty of SQLite wrapper libraries exist, I've found myself rewriting these header parsing operations several times - so I decided to put together a tiny reusable library. 

The best place to find information on the official header file definition is the [SQLite documentation](https://www.sqlite.org/fileformat.html) - but I will provide some basic information below.

---

### Usage

Include `sqlite_header.h` in your code, then simply create a `SqliteHeaderData` object and pass it along with the path to the database file to `sqlite_header_parse`. An error enumeration is used to communicate if the parse was successful or not. If sucesful, all header attributes can be found in the struct as members.

The table below maps the naming of header properties from the offical SQLite documentation to the names of the resulting struct. 

| Structure member name | SQLite Description |
| ------------- | ------------- |
| `header_str` | The header string: "SQLite format 3\000"  |
| `page_size_bytes` | The database page size in bytes. Must be a power of two between 512 and 32768 inclusive, or the value 1 representing a page size of 65536. |
| `file_format_write_version` | File format write version. 1 for legacy; 2 for WAL.  |
| `file_format_read_version` | 	File format read version. 1 for legacy; 2 for WAL.  |
| `reserved_space_bytes`  | Bytes of unused "reserved" space at the end of each page. Usually 0. |
| `max_embedded_payload_frac` | 	Maximum embedded payload fraction. Must be 64. |
| `min_embedded_payload_frac` | Minimum embedded payload fraction. Must be 32.  |
| `leaf_payload_frac` | Leaf payload fraction. Must be 32.  |
| `file_change_counter`  | File change counter. |
| `database_size_pages`  | Size of the database file in pages. The "in-header database size". |
| `first_freelist_trunk_page`  | Page number of the first freelist trunk page. |
| `total_freelist_pages` | 	Total number of freelist pages. |
| `schema_cookie`  |	The schema cookie. |
| `schema_format_number`  | The schema format number. Supported schema formats are 1, 2, 3, and 4.|
| `default_page_cache_size_bytes`  | Default page cache size. |
| `largest_b_tree_page_number`  | The page number of the largest root b-tree page when in auto-vacuum or incremental-vacuum modes, or zero otherwise. |
| `database_text_encoding`  | The database text encoding. A value of 1 means UTF-8. A value of 2 means UTF-16le. A value of 3 means UTF-16be. |
| `user_version`  | 	The "user version" as read and set by the user_version pragma. |
| `incremental_vaccum_mode`  | True (non-zero) for incremental-vacuum mode. False (zero) otherwise. |
| `application_id` | The "Application ID" set by PRAGMA application_id.l  |
| `version_valid_for`  | The version-valid-for number. |
| `sqlite_version`  | SQLITE_VERSION_NUMBER |

---
### Building and running

Building the example can be done manually or with the provided `CMakeLists.txt` file. 

#### Build & run steps
* `git clone https://github.com/patrick--/sqlite_header_parse.git`
* `cd sqlite_header_parse`
* `mkdir build`
* `cd build`
* `cmake ..`
* ` make `
* `./sqlite_header_parse_example`
