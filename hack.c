#define _GNU_SOURCE
#include <sys/uio.h>
#include <stdio.h>


void print_bytes(char* buffer, ssize_t len){
  for (int i = 0; i < len; ++i){
    printf("%X ", buffer[i] & 0xFF);
  }
  printf("\n");
}

int main(void){

   int nbytes = 4;
   pid_t pid = 10675;  

   struct iovec local[1];
   struct iovec remote[1];

   char buf[nbytes];
   ssize_t nread;           /* PID of remote process */

   local[0].iov_base = buf;
   local[0].iov_len = nbytes;

   remote[0].iov_base = (void *) 0x5565d15ea000+0x201014;
   remote[0].iov_len = nbytes;

   nread = process_vm_readv(pid, local, 1, remote, 1, 0);

   printf("%li bytes read\n", nread);

   print_bytes(buf,sizeof(buf)/sizeof(char));

   buf[0] = 0x39;
   buf[1] = 0x05;
   buf[3] = 0x00;
   buf[4] = 0x00;
//539
   nread = process_vm_writev(pid, local, 1, remote, 1, 0);

   printf("%li bytes written to %p\n", nread,(void *) 0x5593f73a5000+0x201014);

   print_bytes(buf,sizeof(buf)/sizeof(char));
}




/*
$ pgrep structloop
10675

$ sudo head -n 1 /proc/10675/maps
5565d15ea000-5565d15eb000 r-xp 00000000 08:02 14028202                   /home/frosty/Desktop/structloop

$ sudo cat /proc/10675/maps | grep "heap"
5565d32ca000-5565d32eb000 rw-p 00000000 00:00 0                          [heap]

$ gcc hack.c -o hack && sudo ./hack
4 bytes read
39 5 0 0 
4 bytes written to 0x5593f75a6014
39 5 0 0 

*/