#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    // Create first child process
    pid1 = fork();
    if (pid1 == -1) {
        perror("Failed to fork");
        return 1;
    }

    if (pid1 == 0) {
        // First child process
        printf("First child, PID = %d\n", getpid());
        sleep(1); // Sleep for 1 second
        printf("First child, PID = %d, waking up\n", getpid());
    } else {
        // Parent process
        // Create second child process
        pid2 = fork();
        if (pid2 == -1) {
            perror("Failed to fork");
            return 1;
        }

        if (pid2 == 0) {
            // Second child process
            printf("Second child, PID = %d\n", getpid());
            sleep(1); // Sleep for 1 second
            printf("Second child, PID = %d, waking up\n", getpid());
        } else {
            // Parent process
            printf("Parent, PID = %d\n", getpid());
            sleep(1); // Sleep for 1 second
            printf("Parent, PID = %d, waking up\n", getpid());
        }
    }

    return 0;
}