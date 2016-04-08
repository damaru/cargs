# cargs

`cargs` is a minimal commandline arguments processing library. 

Obtain argument values using  `cargs_argv`:

	if (cargs_argv(&argc, &argv, "-c", val, 1024)) {
		printf("-c option provided and value is %s\n", val);
	} else {
		printf("-c option not provided\n");
	}

Obtain flags using `cargs_flag`:

	if (cargs_flag(&argc, &argv, "-n")) {
		printf("-n flag provided\n");
	} else {
		printf("-n flag not provided\n");
	}

Bulk processing using `carg_process`:

	CargDesc args[6] = {
	   { "-a", CargVal, "aval" },
	   { "-b", CargVal, "bval" },
	   { "-c", CargVal, "cval" },
	   { "-d", CargVal, "dval" },
	   { "-v", CargFlag },
	   { NULL }
	};
	
	carg_process(&argc, &argv, args);
	
	for (i = 0; args[i].optname; i++) {
	   printf("option: %s value: %s %s\n", args[i].optname, args[i].value, args[i].flag?"was set":"");
	}

Note that if the specified option is found in the argv list, it is removed
from the list. 

