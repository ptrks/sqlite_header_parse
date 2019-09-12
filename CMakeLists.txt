
cmake_minimum_required(VERSION 3.5)

project(sqlite_header_parse_example)

set(SOURCES
	example.c
	sqlite_header.h
	)

add_executable(sqlite_header_parse_example ${SOURCES})