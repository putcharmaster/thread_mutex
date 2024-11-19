#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child: I'm going to sleep for 2 seconds.\n");
        sleep(2); // Simulate long task
        printf("Child: I'm done.\n");
        return 0;
    } else {
        // Parent process
        printf("Parent: Waiting for the child to finish...\n");
        wait(NULL); // Blocks until the child finishes
        printf("Parent: Child finished. Resuming parent process.\n");
    }

    return 0;
}
// int main(int ac, char **av)
// {
//     int pid = fork();
//     printf("%d is PID\n", pid);

//     if (pid == 0)
//         printf("this is child process.\n");

//     else if (pid == -1)
//         return 1;
//     // printf("this is annoying. i know nothing\n");
//     else{
//         wait(NULL);
//         printf("this is only for the parent pid.\n");
//         // wait(NULL);
//     }
//     // if (pid)
//         // wait(NULL);
//     return (0);
// }

/*
The (NULL) in wait(NULL) is used because the wait() function allows you to pass an optional pointer to an int. This pointer would store the exit status of the child process. If you don’t care about the exit status, you can simply pass NULL.

Signature of wait():
c
Copy code
pid_t wait(int *status);
What status Does:
The status pointer is where the child process's exit information is stored.
For example, if you pass a valid pointer to an integer, the wait() function will store details about how the child process ended (e.g., normal termination or signal).
If you don't need this information, you pass NULL to tell wait() to skip saving the exit status.*/

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main() {
//     int pid = fork();

//     if (pid == 0) {
//         // Child process
//         printf("Child: I am exiting with status 42.\n");
//         return 42; // Exit with a specific status
//     } else {
//         // Parent process
//         int status;
//         wait(&status); // Wait for child and get its status

//         if (WIFEXITED(status)) { // Check if child exited normally
//             printf("Parent: Child exited with status %d.\n", WEXITSTATUS(status));
//         }
//     }

//     return 0;
// }
