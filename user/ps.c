#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pinfo.h"

#define MAX_PROC 64

int main(int argc, char *argv[]) {
  struct pinfo info[MAX_PROC];
  if(getpinfo(info) < 0) {
    printf("ps: failed\n");
    exit(1);
  }
  
  char *states[] = {"UNUSED", "USED", "SLEEP", "RUNBLE", "RUNNING", "ZOMBIE"};
  printf("PID\tSTATE\tPRIO\tTICKETS\n");
  
  for(int i = 0; i < MAX_PROC; i++) {
    if(info[i].pid == 0) break;
    printf("%d\t%s\t%d\t%d\n", info[i].pid, states[info[i].state], info[i].priority, info[i].tickets);
  }
  exit(0);
}
