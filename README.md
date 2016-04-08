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
	   { "-a", CargsVal, "aval" },
	   { "-b", CargsVal, "bval" },
	   { "-c", CargsVal, "cval" },
	   { "-d", CargsVal, "dval" },
	   { "-v", CargsFlag },
	   { NULL }
	};
	
	cargs_process(&argc, &argv, args);
	
	for (i = 0; args[i].optname; i++) {
		printf("option: %s opt_val: %s %s\n", args[i].opt_name, args[i].opt_val, args[i].opt_flag ? "was set" : "");
	}

Note that if the specified option is found in the argv list, it is removed
from the list. Only the string values are returned. It is the responsibility
of the client to convert strings to apropriate C types.

