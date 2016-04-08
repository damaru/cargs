
#ifndef __CARGS__H_
#define __CARGS__H_

#include <stdbool.h>
#include <stdio.h>

typedef enum {
	CargFlag,
	CargVal,
} CargType;

typedef struct {
	const char* optname;
	CargType type;
	char value[1024];
	bool flag;
} CargDesc;

int cargs_argv(int* argc, char*** argv, const char* optname, char* optval, size_t len);
int cargs_flag(int* argc, char*** argv, const char* optname);
void carg_process(int* argc, char*** argv, CargDesc* args);

#endif
