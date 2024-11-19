#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void    *roll_dice(){
    int value = (rand() % 6 )+ 1;
    int *result = malloc(sizeof(int));
    *result = value;
    //  printf("%d\n", value);
    printf("Thread result: %p\n", result);
     return (void*)result;
}

int main(int ac, char **av){
    int *res;
    pthread_t th[3];
    srand(time(NULL));
    int i;
    for(i = 0; i < 3; i++)
    {
        if (pthread_create(&th[i], NULL, &roll_dice, NULL))
            return 1;
    }
    for(i = 0; i < 3; i++)
    {
        if (pthread_join(th[i], (void**)&res))
            return 2; 

    }
    
    printf("Result : %d\n", *res);
    free(res);
    return 0;
}