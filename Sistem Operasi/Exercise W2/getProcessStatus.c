#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char command[50];

    // Get the ID of the current process (the shell running this program)
    pid_t pid = getpid();

    // Construct the command to get process details from 'ps'
    // Output will include the process state
    sprintf(command, "ps -o pid,stat,cmd -p %d", pid);

    printf("Fetching state for PID: %d\n", pid);
    // Execute the command using system()
    system(command);

    return 0;
}
