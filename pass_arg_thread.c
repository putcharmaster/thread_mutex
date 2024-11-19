#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg){
    // sleep(1);
    int index = *(int*)arg;
    printf("%d ", primes[index]);
    // printf("%d \n", index);
    free(arg);

}

int main(int ac, char **av){
    pthread_t th[10];
    int i;

    for (i = 0; i < 10; i++){
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a))
            perror("Failed to create thread");
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL))
            perror("Failed to join thread");
    }
    
    printf("\n");
    return 0;
}