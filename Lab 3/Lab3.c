#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

    //Pointer variable that will be returned
    char *z = NULL;

    //Initializing variables
    int a;
	int b;

	//Calculates the length of both strings and assigns them to variables a and b
    a=strlen(str1);
    b=strlen(str2);
    //Allocates memory based on null character and length of a and b
    z=(char *)calloc(a + b + 1,sizeof(char));
    //For loop that iterates through each element of phrase a
    for(int i=0;i<a;i++){
    	//Adds str1 element into new array z
        z[i]=str1[i];
    }
    //For loop that iterates through each element of phrase b
    for(int i=0;i<b;i++){
    	//Adds str2 elements into array z after phrase a has been added
        z[a+i]=str2[i];
    }
    //Adds the NULL character to the end of array
    z[a+b+1]="\0";


    //Returns array z
    return z;

}

student **create_class_list(char *filename, int *sizePtr){

	//Initialize variables
	int i;
    student **class_list;
    //Open file with data
    FILE * inputFile=fopen(filename,"r");
    //Scans the file and allocates memory wherever is needed
    fscanf(inputFile,"%d",sizePtr);
    class_list=calloc(*sizePtr,sizeof(student));
    //For loop to iterate until it goes through all data
    for(i=0;i<*sizePtr;i++){
    	//Allocates memory
        class_list[i]=calloc(1,sizeof(student));
        //Scans the file to pull student id, first name, and last name and create the class list
        fscanf(inputFile,"%d", &(class_list[i]->student_id));
        fscanf(inputFile,"%s", (class_list[i]->first_name));
        fscanf(inputFile,"%s", (class_list[i]->last_name));
    }
    //Closes the file once it has iterated through all students
    fclose(inputFile);

    // finally return the created class list
    return class_list;
}

int find(int idNo, student **list, int size){

	//For loop that iterates through all students in the list
    for(int j=0;j<size;j++){
    		//Checks to see if a students ID is idNo
            if(list[j]->student_id==idNo){
                return j;
            }
        }
    	//If not, the function returns -1
        return -1;
}

void input_grades(char *filename, student **list, int size){

	//Opens file with grade data
    FILE*gradesFile=fopen(filename,"r");
    //Initialize variables
    int i;
    int StudentID = 0;
    //For loop that iterates through all students in the list
    for(i=0;i<size;i++){
    	//Scans the grade for each student and adjusts the StudentID
        fscanf(gradesFile,"%d",&StudentID);
        int index=find(StudentID,list,size);
        //Adds project 1 grade and project 2 grade to the list
        fscanf(gradesFile,"%d",&(list[index]->project1_grade));
        fscanf(gradesFile,"%d",&(list[index]->project2_grade));

    }
    //Closes the file
    fclose(gradesFile);

}

void compute_final_course_grades(student **list, int size){

	//Initialize variables
	int i;
	//For loop that goes through all students
    for(i=0;i<size;i++){
    		//computes final grade by getting the average of both project grades
            list[i]->final_grade=((double)list[i]->project1_grade+(double)list[i]->project2_grade)/2.0;
        }
}

void output_final_course_grades(char *filename, student **list, int size){

	//Initialize variables
	int i;
	//Open file
    FILE *outputfile=fopen(filename, "w");
    //Checks to see amount of students to iterate through
    fprintf(outputfile,"%d\n",size );
    //For loop that iterates until all students have been checked
    for(i=0;i<size;i++){
    	//Each line prints the Students ID, followed by grade
        fprintf(outputfile,"%d %f\n",list[i]->student_id,list[i]->final_grade );

    }
    //Closes file
    fclose(outputfile);

}

void withdraw(int idNo, student **list, int* sizePtr){

	//Calls find function
    int ind = find(idNo, list, *sizePtr);
    //If student ID equals to idNo, the student would be removed
    if(ind == -1){
    	//Message to inform the user a student has been removed
        printf("The Student ID does not exist");
    }
    else{
    	//removes studentID and information from the file
        free(list[ind]);
        //Initialize variable
        int i;
        //For loop that iterates through the file
        for(i = ind + 1; i<*sizePtr; i++){
        	//Shifts all positions of data to the left
            list[i-1]=list[i];
        }
        *sizePtr -= 1;
    }
}

void destroy_list(student **list, int *sizePtr){

	//Initialize variables
    int i;
    //For loop that iterates through the file
    for(i=0; i < *sizePtr; i++){
    	//Clears memory for every data in the file
        free(list[i]);
    }
    free(list);
    *sizePtr = 0;

}