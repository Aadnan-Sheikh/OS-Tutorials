#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void hello_world();
void goodbye();

int main(void)
{
  srand(time(NULL));

  pthread_t t1, t2;

  //Create the threads
  pthread_create(& t1, NULL, & hello_world, NULL);
  pthread_create(& t2, NULL, & goodbye, NULL);

  //Join the threads
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}

void hello_world()
{
  sleep(rand() % 5);
  printf("hello world\n");
}

void goodbye()
{
  sleep(rand() % 5);
  printf("goodbye\n");
}
