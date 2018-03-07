#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int main(void)
{
  pthread_t t1[5];
  float grade[5];

  for (int i=0; i<5; i++)
  {
      printf("Grade:\n");
      scanf("%f", & grade[i]);
  }

  for (int i=0; i<5; i++)
  {
      pthread_create(& t1[i], NULL, bellcurve, & grade[i]);
      pthread_join(t1[i], NULL);
  }
}


void bellcurve(void* grade)
{
  float *grades = grade;
  float bcurve_grade = *grades * 1.50;
  printf("\nGrade after Bell Curve: %.2f\n", bcurve_grade);
}
