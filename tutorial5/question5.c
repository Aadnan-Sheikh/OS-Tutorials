#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int num_students = 10;

float grade[10];

float total_grade = 0;
float total_bellcurve = 0;

pthread_barrier_t b;
pthread_mutex_t l;

int main(void)
{
  int error;
  pthread_t t1;

  pthread_barrier_init(& b, NULL, 2);
  pthread_create(& t1, NULL, read, NULL);
  pthread_barrier_wait(& b);

  int j = 0;
  pthread_t t2[num_students];

  while(j < num_students)
  {

    error = pthread_create(& t2[j], NULL, save, & grade[j]);

    if(error == 0)
    {
      j++;
    }
  }

  pthread_barrier_destroy(& b);
  pthread_join(t1, NULL);

  for (int i=0; i < num_students; i++)
  {
      pthread_join(t2[i], NULL);
  }

  float grade_average = total_grade/num_students;
  float bell_average = total_bellcurve/num_students;

  printf("Before: Total = %.2f Average = %.2f\n", total_grade, grade_average);
  printf("After: Total = %.2f Average = %.2f\n", total_bellcurve, bell_average);

  pthread_mutex_destroy(& l);
}

void save(void* grade)
{
  pthread_mutex_lock(&l);

  float* grades = grade;
  total_grade += *grades;

  float bell_cureved_grade = *grades*1.50f;
  total_bellcurve += bell_cureved_grade;

  FILE *file;
  file = fopen("bellcurve.txt", "a");
  fprintf(file, "%.2f\n", bell_cureved_grade);

  fclose(file);

  pthread_mutex_unlock(&l);

}

void read()
{
  FILE *file;
  file = fopen("grades.txt", "r");

  for (int i=0; i < num_students; i++)
  {
    fscanf(file,"%f",& grade[i]);
  }

  fclose(file);
  pthread_barrier_wait(& b);
}
