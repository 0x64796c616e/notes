/*

notsorandom.c

Dylan Murphy-Mancini, OCT 2016

Contains a definition of the ran() function to use in overriding via LD_PRELOAD. Compile
as a shared library

Running:
$ gcc dummy_loop.c -o dummy_loop
$ ./dummy_loop 

*/

int rand(){
    return 42; //the most random number in the universe
}


/*
int printf(const char *format, ...){
	puts("Your unrandom number is 42");
	return 0;
}

gcc -Wall -fPIC -shared -o notsorandom.so notsorandom.c
LD_PRELOAD=./notsorandom.so ./dummy_loop
*/