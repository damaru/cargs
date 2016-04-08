
all:libcargs.so test

libcargs.so: cargs.o 
	gcc -shared -o libcargs.so cargs.o

cargs.o: cargs.c cargs.h
	gcc -c -Wall -Werror -fpic cargs.c 

clean:
	@-rm -vf cargs.o libcargs.so test *.*~

test:libcargs.so test.c
	gcc -L$(PWD) test.c -o test -lcargs

indent:
	for f in *.[ch];do ./scripts/indent $$f; done

install:libcargs.so cargs.h
	cp libcargs.so /usr/local/lib/
	cp cargs.h /usr/local/include/


