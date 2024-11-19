#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
 
int mails = 0;
void    *routine()
{
    for(int i = 0; i  < 1000000; i++)
        mails++;
}


 int    main(int ac, char **av)
 {
    pthread_t   t1, t2, t3;
    // printf("this is before the create\n");
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return 2;
  if (pthread_create(&t3, NULL, &routine, NULL) != 0)
        return 33;


    // printf("this is between create and join\n");
    if (pthread_join(t1, NULL))
        return 3;
    if (pthread_join(t2, NULL))
        return 4;
    if (pthread_join(t3, NULL))
        return 44;
    // printf("this is after the join before ending the program\n");

    printf("number of mails: %d\n", mails);
    return 0;
 }