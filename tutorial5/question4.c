#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t l;

float total_grade = 0;

int main(void)
{
  int num_students = 10;
  int error;
  int j = 0;

  float grade[num_students];

  pthread_t t1[num_students];

  for (int i=0; i<num_students; i++)
  {
    printf("Grade:\n");
    scanf("%f", &grade[i]);
  }


  while(j < num_students)
  {
    error = pthread_create(&t1[j], NULL, class_total, & grade[j]);

    if(error == 0)
    {
      j++;
    }
  }

  for (int i=0; i < num_students; i++)
  {
    pthread_join(t1[i], NULL);
  }

  printf("Total: %.2f\n", total_grade);

  pthread_mutex_destroy(& l);
}

void class_total(void* grade)
{
  pthread_mutex_lock(& l);

  float *grades = grade;
  total_grade += *grades;

  pthread_mutex_unlock(& l);
}
