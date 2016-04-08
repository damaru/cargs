# cargs
minimal commandline arguments processing


Obtain argument values using <pre> cargs_argv </pre>:

	if (cargs_argv(&argc, &argv, "-c", val, 1024)) {
		printf("-c option provided and value is %s\n", val);
	} else {
		printf("-c option not provided\n");
	}

Obtain flags using <pre> cargs_flag </pre>:

	if (cargs_flag(&argc, &argv, "-n")) {
		printf("-n flag provided\n");
	} else {
		printf("-n flag not provided\n");
	}

Bulk processing using <pre> carg_process </pre> :

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

