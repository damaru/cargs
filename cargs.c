#include <stdio.h>
#include <string.h>
#include "cargs.h"

/* process argument with opt_val */
int cargs_argv(int* argc, char*** argv, const char* opt_name, char* opt_val, size_t len)
{
	int i;

	for (i = 0; i < *argc; i++) {
		if (strcmp((*argv)[i], opt_name) == 0) {
			if ((*argv)[i + 1] != NULL) {
				/* option flag and opt_val provided */
				strncpy(opt_val, (*argv)[i + 1], len);
				opt_val[len - 1] = '\0'; //null terminate
				(*argv)[i] = NULL;
				(*argv)[i+1] = NULL;
				for (; (*argv)[i + 2]; i++) {
					(*argv)[i] = (*argv)[i + 2];
				}
				*argc -= 2;
				return true;
			} else {
				fprintf(stderr, "error: option %s expects a value\n", opt_name);
				/* option flag provided, but opt_val not provided */
				*opt_val = '\0';
				*argc -= 1;
				return false;
			}
		}
	}
	return false;
}

/* process a flag */
int cargs_flag(int* argc, char*** argv, const char* opt_name)
{
	int i;

	for (i = 0; i < *argc; i++) {
		if (strcmp((*argv)[i], opt_name) == 0) {
			for (; (*argv)[i + 1]; i++) {
				(*argv)[i] = (*argv)[i + 1];
			}
			(*argv)[i] = NULL;
			*argc -= 1;
			return true;
		}
	}
	return false;
}

void cargs_process(int* argc, char*** argv, CargsDesc* args)
{
	int i;

	for (i = 0; args[i].opt_name; i++) {
		switch (args[i].opt_type) {
			case CargsVal:
				args[i].opt_flag = cargs_argv(argc, argv, args[i].opt_name, args[i].opt_val, sizeof(args[i].opt_val));
				break;
			case CargsFlag:
				args[i].opt_flag = cargs_flag(argc, argv, args[i].opt_name);
				break;
		}
	}
}
