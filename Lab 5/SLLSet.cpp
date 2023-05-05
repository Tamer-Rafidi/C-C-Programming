#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}

SLLSet::SLLSet(int sortedArray[], int arrSize) {
	//Initializing variables
	size = arrSize;
	head = NULL;
	int i;
	//For loop to create each node
	for (i=size-1; i>=0; i--) {
		//Initializing new node structure
		SLLNode* node = new SLLNode;
		//Assigning new value of node to its respective sortedArray
		node->value = sortedArray[i];
		//Setting the next node to the previous node
		node->next = head;
		//Adjusting head to the last node for next loop
		head = node;
	}
}

int SLLSet::getSize()
{
	
	return size;
}

SLLSet SLLSet::copy(){

	//Initializing variables
	SLLNode* temp = head;
	int arr[size];
	int i;
	//For loop to set values in arr
	for (i=0; i<size; i++) {
		arr[i] = temp->value;
		//Adjusting temp to point to next node
		temp = temp->next;
	}
	return *(new SLLSet(arr,size));
}

bool SLLSet::isIn(int v) {
	//Initializing variable
    SLLNode* temp = head;
    int i;
    //For loop to check if elements in SLLSet are equal to v
    for (i=0; i<size; i++) {
    	//Returns true if element in SLLSet is equal to v
    	if (temp->value == v) {
    		return true;
    	}
    	temp = temp->next;
    }
    //Else return false
	return false;
}

void SLLSet::add(int v) {
	//Initializing variable
	SLLNode* newNode = head;
	//Checks to see if v is already in SLLSet
	if(isIn(v)==false) {
		//if statement for when the set is already empty
    	if(newNode == NULL) {
    		//Initializing new node
    		SLLNode* temp1 = new SLLNode(v,NULL);
    		newNode = temp1;
    	}
    	//Else if statement for when value being added is at the beginning of the set
    	else if(newNode->value > v){
    	    SLLNode* temp2 = new SLLNode(v,newNode);
    	    head = temp2;
    	}
    	else {
    		//While loop to iterate through each node
    		while (newNode->next!=NULL) {
    			//Locating correct location for the value added
    			if (newNode->value < v && newNode->next->value > v) {
    				//Initializing a new node with the value
    				SLLNode* temp3 = new SLLNode(v,newNode->next);
    				//Pointing to next node
    				newNode->next = temp3;
    			}
    			//Else, if current value is not in the correct location, move to next location
    			else {
    				newNode = newNode->next;
    			}
    		}
    		//If statement for when the value being added is at the end of the set
    		if(newNode->value < v){
    			//Initializing a node v which points to NULL
    			SLLNode* temp4 = new SLLNode(v,NULL);
    			newNode->next = temp4;
    		}
    	}
    //If something is added, size is incremented
    size+=1;
	}
}

void SLLSet::remove(int v) {
	//If statement to check if v is already part of the set. Will be removed if true
	if(isIn(v) == true) {
		//Initializing new node
		SLLNode* temp = head;
		//Checks to see if v is equal to the value at the head. If so it is removed
		if (v == head->value) {
			head = head->next;
			//Size is decremented by 1
			size -= 1;
		}
		//While loop to adjust temp pointer for following node
		while (temp !=NULL && temp->next != NULL) {
			//Checks to see if correct node is found, then previous pointer is adjusted to point at the following node
			if ((temp->next)->value == v) {
				temp->next = (temp->next)->next;
				//Size is decremented
				size -= 1;
			}
			//Else, temp -> next is iterated to following node
			else {
				temp = temp->next;
			}
		}
	}
}

SLLSet SLLSet::setUnion(SLLSet s) {
	//Initializing the first node in setUnion
	SLLNode* nodeUnion = new SLLNode();
	//Initializing variables
	SLLSet* setUnion = new SLLSet();
	setUnion->head = nodeUnion;
	int size_count = 0;
	int i;
	//Initializing variables to track node address in three different sets
	SLLNode* unionSetAdd = setUnion->head;
	SLLNode* newSetAdd = s.head;
	SLLNode* oldSetAdd = head;
	//For loop to iterate n times
	for(i=0; i<size+s.getSize(); i++) {
		//All remaining values from the set are added if oldSetAdd is NULL
		if(oldSetAdd == NULL){
			//Checks to see if the new set has reached NULL
			if(newSetAdd != NULL){
				// Current unionSet value is set to the current newSet value
				unionSetAdd->value = newSetAdd->value;
				// Updates address
				newSetAdd = newSetAdd->next;
				// Updating the size_count for each new addition
				size_count += 1;
			}
		}
		//Else, the opposite case occurs if newSetAdd is NULL
		else if(newSetAdd == NULL){
			if(oldSetAdd != NULL){
				unionSetAdd->value = oldSetAdd->value;
				oldSetAdd = oldSetAdd->next;
				size_count += 1;
			}
		}
		//Makes sure the lower value is added to unionSet first
		else if(oldSetAdd->value < newSetAdd->value){
			unionSetAdd->value = oldSetAdd->value;
			// Next value is updated for check
			oldSetAdd = oldSetAdd->next;
			size_count += 1;
		}
		//Else if, the opposite case occurs to make sure the lower value is added to unionSet first
		else if(oldSetAdd->value > newSetAdd->value){
			unionSetAdd->value = newSetAdd->value;
			newSetAdd = newSetAdd->next;
			size_count += 1;
		}
		//Adding value when both oldSet values are equal
		else if(oldSetAdd->value == newSetAdd->value){
			//Updates unionSet with equal value
			unionSetAdd->value = oldSetAdd->value;
			//Both set locations are updated to avoid repeating values
			oldSetAdd = oldSetAdd->next;
			newSetAdd = newSetAdd->next;
			size_count += 1;
		}
		if(oldSetAdd == NULL && newSetAdd == NULL){
			break;
		}
		//Initializing a new node in unionSet for the following value
		SLLNode* nextUnionNode = new SLLNode();
		unionSetAdd->next = nextUnionNode;
		unionSetAdd = nextUnionNode;
	}
	//If statement for the case when there is no union between the sets
	if(size_count == 0){
		//Deleting the first created union node
		delete nodeUnion;
		//Set head to NULL
		setUnion->head = NULL;
		//Set unionSet size to 0
		setUnion->size = 0;
		return *setUnion;
	}
	//Set last node in unionSet to NULL
	unionSetAdd->next = NULL;
	//Update the size of unionSet
	setUnion->size = size_count;
	return *setUnion;
}

SLLSet SLLSet::intersection(SLLSet s) {
	//Initializing intersection set
	SLLSet* setInter = new SLLSet();
	//If current set is empty, an empty intersection set is returned.
	if (head == NULL) {
		return *setInter;
	}
	//If s set is empty, an empty intersection set will be returned
	if (s.head == NULL) {
		return *setInter;
	}
	//Initializing node and set it equal to head
	SLLNode* temp = head;
	//While loop to iterate through each node until NULL is reached
	while (temp!= NULL) {
		//If temp->value is not an element in s set, it will be removed
		if (s.isIn(temp->value) == false) {
			remove(temp->value);
		}
		//Updates the pointer for the following node of temp
		temp = temp->next;
	}
	//Intersection set is returned if the node points to NULL
	if (head == NULL) {
		return *setInter;
	}
	//Updates setInter using a copy of the edited version
	*setInter = copy();
	return *setInter;
}

SLLSet SLLSet::difference(SLLSet s) {
	//Initializing variable
	SLLSet *setDiff = new SLLSet();
	//setDiff is returned if head points to NULL
	if (head == NULL) {
		return *setDiff;
	}
	//setDiff is returned if head of the s set points to NULL
	if (s.head == NULL) {
		*setDiff = copy();
		return *setDiff;
	}
	//Initializing temp node and set equal to head
	SLLNode *temp = head;
	//While loop to iterate through each node
	while (temp != NULL) {
		//Removes value at any node if it is an element of set s
		if (s.isIn(temp->value) == true) {
			remove (temp->value);
		}
		//Pointer for the next node of temp is updated
		temp = temp->next;
	}
	//setDiff is returned if the given node points to NULL
	if (head == NULL) {
		return *setDiff;
	}
	//setDiff is updated using a copy of the edited version of the given set
	*setDiff = copy();
	 return *setDiff;
}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size) {
	//Initializing variable
	SLLSet* setUnion = new SLLSet();
	int i;
	//For loop to iterate through sArray
	for (i=0; i<size; i++) {
		//Updates setUnion to the union of all sets in the array
		*setUnion = (*setUnion).setUnion(sArray[i]);
	}
	return *setUnion;
}
string SLLSet::toString() {
	//Initializing variable
	SLLNode *temp = head;
	string output = "";
	int i;
	//For loop to iterate through each node
	for (i=0; i<size; i++) {
		//Converts element to string and is added to output
		output += to_string(temp->value);
		temp = temp->next;
		//Adding ", " between each element
		if (temp!=NULL) {
			output += ", ";
		}
	}
	return output;
}