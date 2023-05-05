#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
	//	Initializing variables
	colsNum = col;
	rowsNum = row;
	int j;
	int i;
	//	Setting columns and rows to 3 if values is less than 0
	if (col<=0){
			colsNum=3;
		}
	if (row<=0){
		rowsNum=3;
	}
	//	Allocate memory for matrixData
	matrixData=NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	//	Allocating memory for each row
	for (i = 0; i < rowsNum; i++){
	       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}
	//	For loop to construct a matrix of 0s
	for(i = 0; i < rowsNum; i++){
	    for(j = 0; j < colsNum; j++){
	    	matrixData[i][j]=0;
	    }
	}
}


Matrix::Matrix(int row, int col, int** table){
	//Initializing variables
	rowsNum = row;
	colsNum = col;
	matrixData=NULL;
	int i;
	int j;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	//For loop to set each element of matrixData to table
	for (i = 0; i < rowsNum; i++){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
		for (j = 0; j < colsNum; j++){
			matrixData[i][j]=table[i][j];
		}
	}
}

int Matrix::getElement(int i, int j){
	//Checks to see if row and column are valid indices, exception is thrown if they are not
	int element;
	if (i<0 || i>rowsNum || j<0 || j>colsNum){
		throw std::out_of_range("Invalid indexes.");
	}
	//Else, element is set to the value at i and j of matrixData
	else {
		element = matrixData[i][j];
	}
	return element;
}

bool Matrix::setElement(int x, int i, int j){
	//	Checks to see if i and j are valid indices
	if(i<=rowsNum || j<=colsNum){
		matrixData[i][j] = x;
		return true;
	}
    return false;
}

Matrix Matrix::copy(){
	//	Creates a copy using the matrix constructor
	Matrix copy = Matrix(rowsNum,colsNum,matrixData);
    return  copy;
}

void Matrix::addTo( Matrix m ){
	//Initializing variables
	int i;
	int j;
	//Checks to see if number or rows and columns are equal, an exception is thrown if they are not
	if (m.getsizeofrows() != rowsNum || m.getsizeofcols() != colsNum){
		throw std::invalid_argument( "Invalid operation" );
	}
	//Else, for loop is used to add the matrices
	else {
		for (i = 0; i < rowsNum; i++){
			for (j = 0; j < colsNum; j++){
				setElement(m.getElement(i,j) + matrixData[i][j],i,j);
			}
		}
	}
}

Matrix Matrix::subMatrix(int i, int j){
	//Initializing submatrix
	Matrix subM = Matrix(i,j);
	//Checks to see if i and j are valid indices, throws exception if they are not
	if (i<0 || i>rowsNum || j<0 || j>colsNum){
		throw std::out_of_range("Submatrix not defined");
	}
	//Else, a submatrix of size i and j is created
	else {
		Matrix subM(i+1,j+1,matrixData);
		return  subM;
	}
    return  subM;
}

int Matrix::getsizeofrows(){
	return rowsNum;
}

int Matrix::getsizeofcols(){
    return colsNum;
}

bool Matrix::isUpperTr(){
	//Initializing variables
	int i;
	int j;
	//	Creates a for loop to iterate through matrixData
	for (i = 0; i < rowsNum; i++){
		for (j = i+1; j < rowsNum; j++){
			//Checks to see if non-zero values are below the diagonal, returns false if they are
			if (matrixData[j][i]!=0){
				return false;
			}
		}
	}
	return true;
}

string Matrix::toString(){
	//	Initializing variables
	string output="";
	int i;
	int j;
	//Created for loop to iterate through matrix and add each row to output as a string
	for (i = 0; i < rowsNum; i++){
		for (j = 0 ;j < colsNum ; j++){
			output += to_string(getElement(i,j)) + " ";
		}
		//Adding a new line for each new row
		output += "\n";
	}
	 return output;
}