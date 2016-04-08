#include "cargs.h"
#include <stdio.h>

CargDesc args[6] = {
	{ "-a", CargVal, "aval" },
	{ "-b", CargVal, "bval" },
	{ "-c", CargVal, "cval" },
	{ "-d", CargVal, "dval" },
	{ "-v", CargFlag },
	{ NULL }
};

int main(int argc, char** argv)
{
	char val[1024];
	int i;

	if (cargs_argv(&argc, &argv, "-c", val, 1024)) {
		printf("-c option provided and value is %s\n", val);
	} else {
		printf("-c option not provided\n");
	}

	if (cargs_flag(&argc, &argv, "-n")) {
		printf("-n flag provided\n");
	} else {
		printf("-n flag not provided\n");
	}

	carg_process(&argc, &argv, args);

	for (i = 0; args[i].optname; i++) {
		printf("option: %s value: %s %s\n", args[i].optname, args[i].value, args[i].flag ? "was set" : "");
	}

	printf("remaining args:\n");
	for (i = 0; i < argc; i++) {
		printf("%d: %s\n", i, argv[i]);
	}
}
