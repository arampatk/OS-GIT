#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pipefd[2]; // Array to hold the two ends of the pipe
    pid_t pid;
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        const char *message = "Hello from parent process!";
        printf("Parent: Sending message to child...\n");

        // Write the message to the pipe
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]); // Close the write end of the pipe
    } else { // Child process
        close(pipefd[1]); // Close the write end of the pipe

        // Read the message from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child: Received message: %s\n", buffer);

        close(pipefd[0]); // Close the read end of the pipe
    }

    return 0;
}
