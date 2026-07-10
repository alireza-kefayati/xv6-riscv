#include "kernel/types.h"
#include "user/user.h"
int main(int argc, char *argv[]){
  if(argc != 3){ printf("Usage: chpri [pid] [priority]\n"); exit(1); }
  int pid = atoi(argv[1]);
  int pr = atoi(argv[2]);
  if(setpriority(pid, pr) < 0) printf("chpri: Error!\n");
  else printf("Priority for PID %d changed to %d.\n", pid, pr);
  exit(0);
}

