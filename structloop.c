/*
$ gcc -Og -o structloop structloop.c 
$ ./structloop 
*/

#include <stdio.h>
#include <unistd.h>
 
struct Books {
   int   book_id;
};
 
struct Books book;

int main( ) { 

   book.book_id = 80085;
   
   while(1){
      printf("Integer: %i\n", book.book_id);
      //printf("Integer: %p\n", &book);
      sleep(2);
   }

   return 0;
}