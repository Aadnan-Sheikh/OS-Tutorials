#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct student
{
  char name[100];
  char student_id[100];
  float grade;
} student;


int main(void)
{
  int num_students = 5;
  pthread_t t1[num_students];
  struct student students[num_students];

  for (int i=0; i<num_students; i++)
  {
      printf("Name:\n");
      scanf("%s", students[i].name);

      printf("ID:\n");
      scanf("%s", students[i].student_id);

      printf("Grade:\n");
      scanf("%f", & students[i].grade);
  }

  for (int i=0; i<num_students; i++)
  {
      pthread_create(& t1[i], NULL, bellcurve, & students[i]);
      pthread_join(t1[i], NULL);
  }
}


void bellcurve(void* student)
{
  struct student* stud = student;
  float bcurve_grade = stud->grade*1.50f;
  printf("\nGrade after Bell Curve: %.2f\n", bcurve_grade);
}
