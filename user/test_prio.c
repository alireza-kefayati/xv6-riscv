#include "kernel/types.h"
#include "user/user.h"
int main() {
  printf("Starting Priority Test...\n");
  if(fork() == 0) {
    setpriority(getpid(), 10);
    printf("Child 1 (Priority 10) started...\n");
    for(volatile int i=0; i<1000000000; i++);
    printf("Child 1 finished.\n");
    exit(0);
  }
  if(fork() == 0) {
    setpriority(getpid(), 90);
    printf("Child 2 (Priority 90) started...\n");
    for(volatile int i=0; i<1000000000; i++);
    printf("Child 2 finished.\n");
    exit(0);
  }
  wait(0); wait(0);
  exit(0);
}
