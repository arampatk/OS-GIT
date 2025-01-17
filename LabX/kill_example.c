#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for the child process
void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        printf("Child: Received SIGUSR1 from parent!\n");
    }
}

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        printf("Parent: Sending SIGUSR1 to child...\n");

        // Wait briefly to ensure the child sets up its handler
        sleep(1);

        // Send SIGUSR1 signal to the child
        kill(pid, SIGUSR1);

        // Wait for the child process to finish
        wait(NULL);
        printf("Parent: Child process terminated.\n");
    } else { // Child process
        // Set up the signal handler
        signal(SIGUSR1, handle_signal);

        printf("Child: Waiting for SIGUSR1 signal...\n");

        // Pause to wait for a signal
        pause();

        printf("Child: Exiting.\n");
    }

    return 0;
}
