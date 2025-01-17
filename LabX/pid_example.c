#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    int fd;

    // Open a file to write the PIDs
    fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        char buffer[50];

        // Write the parent's PID to the file
        snprintf(buffer, sizeof(buffer), "Parent PID: %d\n", getpid());
        write(fd, buffer, strlen(buffer));

        // Wait for the child process to finish
        wait(NULL);

        printf("Parent: PIDs have been written to pids.txt\n");
    } else { // Child process
        char buffer[50];

        // Write the child's PID to the file
        snprintf(buffer, sizeof(buffer), "Child PID: %d\n", getpid());
        write(fd, buffer, strlen(buffer));

        printf("Child: PIDs have been written to pids.txt\n");
    }

    // Close the file
    close(fd);

    return 0;
}
