#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main(){
    pid_t child_id;

    child_id = fork();

    if (child_id < 0) {
        exit(EXIT_FAILURE);
    }

    if (child_id == 0) {
        char *argv[] = {"echo", "hello world!", NULL};
        execv("/bin/echo", argv);
    }
    else {
        char *argv[] = {"echo", "123", NULL};
        execv("/bin/cp", argv);
    }
    return 0;
}