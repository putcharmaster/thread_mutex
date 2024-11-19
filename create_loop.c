#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 
int mails = 0;
pthread_mutex_t mutex;
// int lock = 0;

void    *routine()
{
    for(int i = 0; i  < 1000000; i++)
    {
       pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
        
}

int    main(int ac, char **av)
 {
    int i;
    pthread_t   th[8];
    pthread_mutex_init(&mutex, NULL);

    for(i = 0; i < 8 ; i++)
    {
        if (pthread_create(th + i, NULL, &routine, NULL))
        // if (pthread_create(&th[i], NULL, &routine, NULL))
            return 1;
        printf("Thread %d has started\n", i);
        
    }
    for(i = 0; i < 8 ; i++){
        if (pthread_join(th[i], NULL))
            return 3;
        printf("Thread %d has finished execution\n", i);

    }
    // in the same forloop both pthread_create and join doesnt do
    // the job simultanously.  therefore we must create two forloops for each


    // printf("this is after the join before ending the program\n");

    pthread_mutex_destroy(&mutex);
    printf("number of mails: %d\n", mails);
    return 0;
 }


/*
 int    main(int ac, char **av)
 {
    int i;
    pthread_t   th[4];
    pthread_mutex_init(&mutex, NULL);

    for(i = 0; i < 4 ; i++)
    {
        if (pthread_create(th + i, NULL, &routine, NULL))
        // if (pthread_create(&th[i], NULL, &routine, NULL))
            return 1;
        printf("Thread %d has started\n", i);
        if (pthread_join(th[i], NULL))
            return 3;
        printf("Thread %d has finished execution\n", i);

    }
    // in the same forloop both pthread_create and join doesnt do
    // the job simultanously.  therefore we must create two forloops for each


    // printf("this is after the join before ending the program\n");

    pthread_mutex_destroy(&mutex);
    printf("number of mails: %d\n", mails);
    return 0;
 }

 */