/* 

dummy_loop.c

Dylan Murphy-Mancini, OCT 2016

Prints a random number to the console every two seconds. It is an
example program -- meant to be modified via DLL injection or other means.

Running:
$ gcc dummy_loop.c -o dummy_loop
$ ./dummy_loop 

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

	int n = 100;

	int  *ip;        /* pointer variable declaration */

    ip = &n;  /* store address of var in pointer variable*/


	while(1){
		printf("Integer: %i\n", *ip);
		sleep(2);
	}

	return 0;
}
