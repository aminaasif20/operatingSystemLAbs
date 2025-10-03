#include <stdio.h>
#include <unistd.h>
int main() {
printf("My PID: %d\n", getpid()); //use to get process ID
printf("My Parent PID: %d\n", getppid());
return 0;
}