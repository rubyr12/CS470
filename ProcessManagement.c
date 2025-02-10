// Ruby Rosales
// Required headers
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    pid_t pid;
    int status;
    const int numChildren = 10;
    char *commands[][10] = {
        {"echo", "Hello Ruby", NULL},
        {"ls", "--sort=time", NULL},
        {"ps", "-f", NULL},
        {"date", NULL, NULL},
        {"mkdir", "LabDir", NULL},
        {"pwd", NULL, NULL},
        {"find", "-empty", NULL},
        {"touch", "ProcessManagement.c", NULL},
        {"cat", "ProcessManagement.c", NULL},
        {"whoami", NULL, NULL}
    };


    printf("Parent Process PID: %d\n", getpid());
    // Create 10 child processes
    for (int i = 0; i < numChildren; i++){
        pid = fork();
        // Error
        if (pid < 0){
            perror("Fork failed.");
            exit(EXIT_FAILURE);
        }
        // Execute command in child processes
        else if (pid == 0){
            printf("Child processes PID: %d - Executing commands: %s \n", getpid(), commands[i][0]);
            execvp(commands[i][0], commands[i]);
            perror("Exec failed.");
            exit(EXIT_FAILURE);
        }
    }
    printf("Print out history:\n");
    // Wait for child processes to finish in parent process
    while((pid = wait(&status)) > 0){
        printf("Child process with PID %d finished\n", pid);
    }
    return EXIT_SUCCESS;
}