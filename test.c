#include "cargs.h"
#include <stdio.h>

CargsDesc args[6] = {
    { "-a", CargsVal, "aval" },
    { "-b", CargsVal, "bval" },
    { "-c", CargsVal, "cval" },
    { "-d", CargsVal, "dval" },
    { "-v", CargsFlag },
    { NULL }
};

int main(int argc, char **argv)
{
    char val[1024];
    int i;

    if (cargs_argv(&argc, &argv, "-c", val, 1024))
        printf("-c option provided and opt_val is %s\n", val);
    else
        printf("-c option not provided\n");

    if (cargs_flag(&argc, &argv, "-n"))
        printf("-n flag provided\n");
    else
        printf("-n flag not provided\n");

    cargs_process(&argc, &argv, args);

    for (i = 0; args[i].opt_name; i++)
        printf("option: %s opt_val: %s %s\n", args[i].opt_name, args[i].opt_val,
               args[i].opt_flag ? "was set" : "");

    printf("remaining args:\n");
    for (i = 0; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);
}
