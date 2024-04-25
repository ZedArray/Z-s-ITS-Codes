#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // Create a new process

    if (pid == -1) {
        // If fork() returns -1, an error occurred
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process:\n");
        execlp("ls", "ls", NULL); // Replace the child process with "ls"
        // If execlp is successful, we should never reach this next line
        perror("execlp"); // If execlp() fails
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        if (waitpid(pid, &status, 0) == -1) {
            // Wait for the child to finish and check for errors
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            // Check if the child terminated normally
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            // Check if the child was terminated by a signal
            printf("Child terminated by signal %d\n", WTERMSIG(status));
        }
    }

    return EXIT_SUCCESS;
}
