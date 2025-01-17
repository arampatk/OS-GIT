
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For fork() and getpid()
int main() {
    pid_t pid1, pid2, pid3;

    // First fork
    pid1 = fork();
    
    if (pid1 == 0) {
        // Inside the first child process
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Inside the parent process
        // Second fork
        pid2 = fork();
if (pid2 == 0) {
            // Inside the second child process
            printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            // Inside the parent process
            // Third fork
            pid3 = fork();
  
            if (pid3 == 0) {
                // Inside the third child process
                printf("Child 3: PID = %d, Parent PID = %d\n", getpid(), getppid());
            } else {
                // Inside the parent process
                // Wait for all child processes to finish (optional)
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("Parent: PID = %d\n", getpid());
            }
        }
}
	return 0;
}
