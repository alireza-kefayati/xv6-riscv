#include "kernel/types.h"
#include "user/user.h"
int main(){
  settickets(100);
  if(fork() == 0) {
    for(volatile int i=0; i<1000000000; i++);
    printf("Child (100 tickets) finished.\n");
    exit(0);
  } else {
    settickets(10);
    wait(0);
    printf("Parent (10 tickets) finished.\n");
  }
  exit(0);
}
