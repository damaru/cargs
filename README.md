# cargs
minimal commandline arguments processing



 if (cargs_argv(&argc, &argv, "-c", val, 1024)) {
 	printf("-c option provided and value is %s\n", val);
 } else {
 	printf("-c option not provided\n");
 }

 if (cargs_arg(&argc, &argv, "-n")) {
 	printf("-n flag provided\n");
 } else {
 	printf("-n flag not provided\n");
 }




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

