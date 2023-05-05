#include <stdio.h>
#include <stdlib.h>
#include "student.h"

//Question 1 definitions and prototypes
char *my_strcat(const char * const str1, const char * const str2);


//Question 2 definitions and prototypes
student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list, int size);

void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);