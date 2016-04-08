#include <stdio.h>
#include <string.h>
#include "cargs.h"

/* process argument with value */
int cargs_argv(int* argc, char*** argv, const char* optname, char* value, size_t len)
{
	int i;

	for (i = 0; i < *argc; i++) {
		if (strcmp((*argv)[i], optname) == 0) {
			if ((*argv)[i + 1] != NULL) {
				/* option flag and value provided */
				strncpy(value, (*argv)[i + 1], len);
				value[len - 1] = '\0'; //null terminate
				for (; (*argv)[i + 2]; i++) {
					(*argv)[i] = (*argv)[i + 2];
				}
				*argc -= 2;
				return 1;
			} else {
				/* option flag provided, but value not provided */
				*value = '\0';
				*argc -= 1;
				return true;
			}
		}
	}
	return false;
}

/* process a flag */
int cargs_flag(int* argc, char*** argv, const char* optname)
{
	int i;

	for (i = 0; i < *argc; i++) {
		if (strcmp((*argv)[i], optname) == 0) {
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

void carg_process(int* argc, char*** argv, CargDesc* args)
{
	int i;

	for (i = 0; args[i].optname; i++) {
		switch (args[i].type) {
			case CargVal:
				args[i].flag = cargs_argv(argc, argv, args[i].optname, args[i].value, sizeof(args[i].value));
				break;
			case CargFlag:
				args[i].flag = cargs_flag(argc, argv, args[i].optname);
				break;
		}
	}
}
