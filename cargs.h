#ifndef __CARGS__H_
#define __CARGS__H_

#include <stdbool.h>
#include <stdio.h>

typedef enum {
    CargsFlag,
    CargsVal,
} CargsType;

typedef struct {
    const char *opt_name;
    CargsType   opt_type;
    char        opt_val[1024];
    bool        opt_flag;
} CargsDesc;

int cargs_argv(int *argc, char ***argv, const char *opt_name, char *opt_val, size_t len);
int cargs_flag(int *argc, char ***argv, const char *opt_name);
void cargs_process(int *argc, char ***argv, CargsDesc *args);

#define CARGS_GET(desc, index, var) var = (((desc)[index].opt_flag ? (desc)[index].opt_val : NULL))

#endif
