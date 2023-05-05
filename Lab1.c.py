#include "Questions.h"

int Q1_for(){
	//Initialize variables
	int sum=0;
	int i;
	//Creating a for loop from 30 to 1000
	for(i=30; i<=1000; i++){
		//Checks to see if the number is a multiple of 4 and adds it to sum if it is
		if (i%4==0){
			sum = sum +i;
		}
	}
	return sum;
}
int Q1_while(){
	//Initialize variables
	int sum=0;
	int i=30;
	//While loop that iterates from 30 to 1000
	while (i<=1000){
		//Checks to see if the number is a multiple of 4 and adds it to sum if it is
		if (i%4==0){
			sum = sum +i;
			i += 1;
		}
		//iterates to next number if it isn't a multiple of 4
		else {
			i += 1;
			continue;
		}
	}
	return sum;
}


int Q1_do(){
	//Initializes variables
	int sum=0;
	int i=30;
	//Performs this code if the while loop is true
	do {
		//Checks if the number is a multiple of 4 and adds it to sum
	    if (i%4==0){
			sum = sum +i;
			i += 1;
		}
	    //Iterates to the next value if it is not a multiple of 4
		else {
			i += 1;
			continue;
		}
	}
	//Creating the while loop condition that will cause i to go from 30 to 1000
	while (i<=1000);
	return sum;
}


//===============================================================================================
int Q2(int Q2_input){
	//Initializing variables including flag variable
	int IsFiveDigit=0;
	int digits = 0;
	//While loop that will end when the first digit of the input is a 0
	while (Q2_input!=0){
		//Divides input by 10 if the first digit is not a zero and increases digit counter by 1
	    Q2_input/= 10;
	    digits += 1;
	}
	//Initializes flag to 1 if the input had 5 digits
	if (digits==5){
	    IsFiveDigit = 1;
	}
	//Initializes flag to 0 if the input had any other number of digits
	else{
	    IsFiveDigit = 0;
	}
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	//Initializes variables
	float GPA;
	// Series of if and else if statements to determine what GPA the student has
    if (Q3_input >= 90 && Q3_input<= 100){
        GPA = 4;
    }
    else if (Q3_input >= 80 && Q3_input<= 89){
        GPA = 3;
    }
    else if (Q3_input >= 70 && Q3_input<= 79){
        GPA = 2;
    }
    else if (Q3_input >= 60 && Q3_input<= 69){
        GPA = 1;
    }
    else if (Q3_input >= 0 && Q3_input<= 59){
        GPA = 0;
    }
    // Returns -1 if student doesn't provide a grade within the proper range
    else {
        GPA = -1;
    }
    //return the GPA
    return GPA;
}
	

//===============================================================================================
double Q4(int Q4_input){
	
	// Initializing Variables
	double pi=0;
	int term = 0;
	
	// For loop that runs Q4_input times
	for (term=0; term<Q4_input; term++){
		// Mathematical equation to add the next term in the infinite series following the pattern
	    pi += (4.0/(2*term+1))*(-1+2*((term+1)%2));
	}
	// Return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	//Initializing variables
	int totNumTribles=0;
	int side1; int side2; int hyp;
	// For loop that ends once hypotenuse is greater than 400
	for(hyp=1; hyp<= 400; hyp++){
		//Nested for loop that makes sure side2 wouldn't be greater than the hypotenuse
	    for(side2=1; side2<=hyp; side2++){
	    	//Another nested for loop to meet the condition that side1 will be smaller than side2
	        for(side1=1; side1<=side2; side1++){
	        	//Checks pythagorean thereom for every possible combination within these conditions
	            if(hyp*hyp==side2*side2+side1*side1){
	            	//If condition is met, add 1 to the total counter
	                totNumTribles += 1;
	            }
	        }
	    }
	}
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
		// Initializing variables
	    int counts=0;
	    int x; int y; int sum;
	    //Initializing a for loop to iterate through every number from 1 to input
	    for(x=1; x<=Q6_input; x++){
	    	//Make sum=0 after the number gets checked to be a perfect number
	        sum = 0;
	        // Creating a for loop that checks every number lower than the number being checked
	        for(y=1; y<x; y++){
	        	//Checks to see if the number is a divisor
	            if(x%y==0){
	            	//Adds to sum
	                sum += y;
	            }
	        }
	        //Checks to see if the sum of divisors is equal to original number
	        if (sum==x){
	        	//If so, it will be appended to the array as a perfect number
	            perfect[counts]=x;
	            counts++;
	        }
	    }
	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input){
	//Initializing variables
	int reversedInt=0;
	int digits = 0;
	//If statement to check if input given is a 7 digit integer
	if((Q7_input/1000000<10 &&Q7_input/1000000>=1)||(Q7_input/1000000<=-1 && Q7_input/1000000>-10)){
		digits = 7;
	}
	//If statement that only allows 7 digit inputs to pass
	if(digits==7){
		//While loop to iterate until all digits have been accessed. Will return the backwards integer
		while(Q7_input!=0){
			//reversedInt is multiplied by 10 every iteration before the formula
			reversedInt = reversedInt*10;
			//Formula that isolates digits from the back to the front
			reversedInt = reversedInt+ Q7_input%10;
			//Dividing output by 10 allows the final digit to shift every iteration
			Q7_input = Q7_input/10;
		 }
	}
    return reversedInt;
}

int Q7b(int Q7b_input){
	//Initializing variables
	int reversedInt=0;
	//While loop to iterate until all digits have been accessed. Will return the backwards integer
	while(Q7b_input!=0){
		//reversedInt is multiplied by 10 every iteration before the formula
		reversedInt = reversedInt*10;
		//Formula that isolates digits from the back to the front
		reversedInt = reversedInt+ Q7b_input%10;
		//Dividing output by 10 allows the final digit to shift every iteration
		Q7b_input = Q7b_input/10;
	}
	return reversedInt;
}