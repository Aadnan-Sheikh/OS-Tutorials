#define _XOPEN_SOURCE 600
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define FIVE 5

int* moving_sum[5];
pthread_barrier_t barr;
sem_t sem;

struct numInd
{
   int num;
   int index;
} numInd;

void *Factorial(void *arg)
{
    struct numInd str;
    str = *(struct numInd*)arg;

    int fact = 1;
    for(int i = str.num; i > 0; i--)
    {
        if(str.num == 0)
        {
            break;
        }
        fact = fact * i;
    }



    int rc = pthread_barrier_wait(&barr);

    if (str.index > 0){

        while (1==1)
        {
            sem_wait(&sem);
            if (*moving_sum[str.index - 1] > 0)
            {
                *moving_sum[str.index] = fact + *moving_sum[str.index - 1];
                sem_post(&sem);
                break;
            }
            sem_post(&sem);
        }


    }
    else
    {
        *moving_sum[str.index] = fact;
    }
    return 0;
}


int main (int argc, char *argv[]){

    pthread_t *pth[FIVE];
    struct numInd test[FIVE];

    pthread_barrier_init(&barr,NULL,5);

    sem_init(&sem, 0, 1);

    for(int i = 0; i < 5; i++){
        moving_sum[i] = (int*)malloc(sizeof(int));
        *moving_sum[i] = 0;
    }

    printf("Please input 5 numbers.\n");

    for(int i = 0; i < 5; i++){
        scanf("%d", &test[i].num);
        test[i].index = i;
    }

    for(int i = 0;i<5;i++){
        pthread_create(&pth[i],NULL,Factorial,(void *) &test[i]);
    }

    for(int i = 0;i<FIVE;i++){
        pthread_join(*pth[i],0);
    }

    printf("---moving_sum contents---\n");
    for (int i = 0; i < 5; i++) {
        printf("index %d = %d\n", i, *moving_sum[i]);
    }

    sem_destroy(&sem);
    pthread_barrier_destroy(&barr);

    for(int i = 0;i<5;i++){
      free(moving_sum[i]);
    }

    return 0;
}
