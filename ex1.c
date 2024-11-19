#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 

 // command should be : gcc -g -pthread ex1.c -o ex1

void    *routine() 
{
    printf("test\n");
    // usleep(300);
    printf("Ending thread\n");
}

 int    main(int ac, char **av)
 {
    pthread_t   t1, t2;
    printf("this is before the create\n");
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
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