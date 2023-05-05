#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size){
	//Initialize variables
    int i;
    //For loop to iterate through each component of the vectors
    for(i=0; i<size; i++){
    	//Calculation to add vectors
        vector3[i]= vector1[i]+vector2[i];
    }
}

double scalar_prod(double vector1[],double vector2[],int size){
	//Initializing variables
    double prod=0;
    int i;
    //For loop to iterate through each component of the vectors
    for(i=0;i<size;i++){
    	//Calculation to get the product of each component and sums it to overall total
        prod += (vector1[i]*vector2[i]);
    }
    return prod;
}

double norm2(double vector1[], int size){
	//Initializing variables
    double L2;
    //Norm calculation which utilizes the scalar_prod function above
    L2 = sqrt(scalar_prod(vector1,vector1,size));
    return L2;
}

int is_diag_dom(int mat[][N2]){

    //Initializing variables
	int isDiag=1;
	int i;
	int j;
	int sum;
	//For loop to iterate through each row of the matrix at a time
	for(i=0; i<N2;i++){
		//Resets sum to 0 after every row is checked
	    sum = 0;
	    //Iterates through each number in the row
	    for(j=0; j<N2;j++){
	    	//If statement that passes if the value is not part of the diagonal
	        if (j != i){
	        	//Adds the absolute value of the non-diagonal numbers to sum of row
	            sum += fabs(mat[i][j]);
	        }
	    }
	    //Checks to see if sum of non-diagonal values is higher than diagonal value
	    if (sum > fabs(mat[i][i])){
	    	//Sets check to 0, meaning the the matrix is not a diagonal dominant matrix
	        isDiag = 0;
	    }
	}
    return isDiag;
}

void diag_scan(int mat [][N3], int arr []){
	//Initializing Variables
    int i, j, element = 0, diag;
    //For loop that iterates after every diagonal
    for(diag=0; diag<(2*N3); diag++){
    	//Set j to 0 after every diagonal
        j=0;
        //For loop that increments through each diagonal
        for(i=diag;i>=0;i--){
        	//If i and j are within the matrix, the next diagonal will be added to the array
            if(i<N3&&j<N3){
                arr[element]=mat[i][j];
                //Element is incremented to occupy the next index in the array
                element++;
            }
            j++;
        }
    }
}

void letter_freq(const char word[], int freq[]){
	//Initialize variable
    int i;
    //For loop to set each element to 0
    for(i=0;i<26;i++){
        freq[i]=0;
    }
    //For loop that continues according to length of word
    for(i=0; i<strlen(word);i++){
    	//If statements to check what letter they are in both lower and upper case forms
        if(word[i]>=65 && word[i]<=90){
        	//Subtracts 65 to allow lower and upper case to share the same range
            freq[word[i]-65]++;
        }
        if(word[i]>=97 && word[i]<=122){
        	//Subtracts 65 to allow lower and upper case to share the same range
            freq[word[i]-97]++;
        }
    }
}

void string_copy(const char source[], char destination[], int n){
	//Initialize variables
    int i;
    //For loop that iterates through the array, taking in consideration the null character at the end
    for(i=0;i<n-1;i++){
    	//Copies the element from source array to destination array
        destination[i]=source[i];
    }
}

void efficient(const int source[], int val[], int pos[], int size){
	//Initializing variables
    int i, element=0;
    //For loop to iterate through all elements in the array
    for(i=0;i<size; i++){
    	//Checks each element to see if it is a non-zero number
        if(source[i]!=0){
        	//If so, the number will be placed in the val and pos array
            val[element]=source[i];
            pos[element]=i;
            element++;
        }
    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	//Initializing variables
    int i, j=0;
    //For loop that iterates through the vector source
    for(i=0;i<m;i++){
    	//Checks to see if the i is the same value as the position index
        if(i==pos[j]){
        	//if so, add value from vector source to main array
            source[i]=val[j];
            j++;
        }
        //If not, let the source enter a value of 0
        else source[i]=0;
    }
}

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	//Initializing variables
	int i, j, element=0, prev_small=-1, double_val;
	//For loop to iterate through pos1
	for(i=0;i<k1;i++){
		//sets any value that appears in pos1 and pos2 to 0
		double_val = 0;
		//For loop to iterate through pos2
		for(j=0;j<k2;j++){
			//Checks to see if 2 position values are equal for pos1 and pos2
		    if(pos1[i]==pos2[j]){
		    	//If so, the flag is triggered and sets double_val to 1
		        double_val = 1;
		        //Sets value of the position to prev_small so future iterations must be larger
		        prev_small = pos1[i];
		        //Checks to see if the sum of values is not equal to 0
		        if(val1[i]+val2[j]!=0){
		        	//Adds sum of values and position to pos3 and val3
		        	pos3[element]=pos1[i];
		            val3[element]=val1[i]+val2[j];
		            element++;
		        }
		        break;
		    }
		    //checks second case where pos2 values is smaller than pos1 value and larger than prev_small
	        if(pos2[j]<pos1[i]&&pos2[j]>prev_small){
	        	//Adds pos2 and val2 to pos3 and val3
	        	pos3[element]=pos2[j];
	        	val3[element]=val2[j];
	            prev_small=pos2[j];
	            element++;
	        }
		}
		//Checks to see if double_val == 0 to check pos1
	    if(double_val==0){
	    	//Adds pos1 and val1 to pos3 and val3
	    	pos3[element]=pos1[i];
	    	val3[element]=val1[i];
	    	prev_small=pos1[i];
	    	element++;
	    }
	    //Checks to see if there are any pos2 values larger than pos1
	    if(i==k1-1){
	    	//For loop to iterate through all pos2 values
	        for(j=0;j<k2;j++){
	        	//Checks the pos2 values that were too large to be checked previously to add to pos3 and val3
	            if(pos2[j]>prev_small){
	            	pos3[element]=pos2[j];
	                val3[element]=val2[j];
	                element++;
	                prev_small=pos2[j];
	            }
	        }
	    }
	}
}