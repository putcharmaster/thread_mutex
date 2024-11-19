#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 

 // command should be : gcc -g -pthread ex1.c -o ex1

// void    *routine() 
// {
//     printf("test\n");
//     printf("process id %d\n", getpid());
//     // usleep(300);
//     printf("Ending thread\n");
// }
int x = 2;


void    *routine()
{
    x = 100;
    sleep(2);
    printf("Value of x: %d\n", x);
}

void    *routine2()
{ 
    sleep(2);
    printf("Value of x: %d\n", x);
}

 int    main(int ac, char **av)
 {
    pthread_t   t1, t2;
    printf("this is before the create\n");
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
        return 2;

    // printf("this is without join\n"); 
    //without pthread_join, program terminatesbfore the threads have completed
    //their work.  ex) it doesnt print Ending thread because it didn' wait

    printf("this is between create and join\n");
    if (pthread_join(t1, NULL))
        return 3;
    if (pthread_join(t2, NULL))
        return 4;
    printf("this is after the join before ending the program\n");

    return 0;
 }


/*thread 1 and 2 share the same process,
that's why whatever it's modified in the thread 1, thread 2 will have the same value*/
 

/*
Real-Life Example:
Imagine you’re baking cookies:

You ask two friends (threads) to bake cookies for you (pthread_create).
You don’t want to leave the kitchen until they both finish baking (pthread_join).
If one friend never shows up, you get an error (e.g., return 3 or return 4).


What Happens in Your Program:
The main program creates two threads (t1 and t2).
Each thread runs the routine() function (printing "test" and "Ending thread").
The main program waits for t1 and t2 to finish using pthread_join().
Only after both threads finish, the program exits successfully.*/