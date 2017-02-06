/*
 *     	 Project: Project 2
 *        Author: Gamage C.T.N. (E/13/107)
 * 	Created Date: April 24, 2015
 *          File: ArrayImpl.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "StackAndQueue.h"

#define NO_OF_ELEMENTS 1000000

typedef struct queue{
	int array[NO_OF_ELEMENTS];
	int start;
	int count;
	}queue;
	
typedef struct stack{
	int array[NO_OF_ELEMENTS];
	int top;
	}stack;
	
//-------------------- functions for Queue--------------------------------

//creating the queue
Queue* CreateQueue(){
	queue *Queue; //creating the queue variable
	Queue= (queue*)malloc(sizeof(queue)); // allocating memory
	
	if (Queue== NULL) {
		fprintf(stderr, "Not enough memory to create the queue\n"); //error message
		return(0); //error code
	}
	Queue->start=0;	//initializing the variables
	Queue->count=0;	
	return Queue;
}

//deleting the queue
int DeleteQueue(Queue* queue){
	free(queue);//freeing the allcated memory
	return 0;
	}

//adding entries for the queue
int QueueEnqueue(Queue* queue, int value){
	if((queue->count)>= (NO_OF_ELEMENTS)){	//check whether the maximum array elements have exceeded
		fprintf(stderr, "The Queue is full\n"); //error
		return(-1);  //error code
	}
	
	int newEntry = (queue->start + queue->count)% NO_OF_ELEMENTS; // calculating the index of the new entry	
	queue->array[newEntry] = value; // assigning the value to the array element
	queue->count++;
	
	return 0;
	}
	
//deleting elements in the queue
int QueueDequeue(Queue* queue, int* value){
	if (queue->count <= 0) {
		value=NULL;
		fprintf(stderr, "Queue is Empty\n");	//error message
		return(-1); //returnig the error code
	}
  
	*value = (queue->array[queue->start]); //assigning the address of the deleted element
	
	queue->start++;
	queue->start %= NO_OF_ELEMENTS;//this is to make the queue circular

	queue->count--;
	
	return 0;
	}

//peeking the queue
int QueuePeek(const Queue* queue, int* value){
	if (queue->count <= 0) {
		value=NULL;
		fprintf(stderr,"Queue is empty\n"); //checking whether the queue is empty
		return(-1);  
	}
	*value = (queue->array[queue->start]); //assigning the address of the element that is to be deleted
	return 0;
	}
/*
void print(Queue* queue){
	int i=queue->start;
	for(;i<(queue->count)+(queue->start);i++){
		printf("print %d ",queue->array[i]);
		}
	
	}*/
//-------------------- functions for Stack--------------------------------

//creating the stack
Stack* CreateStack(){
	stack *Stack; //creating the stack variable
	Stack= (stack*)malloc(sizeof(stack)); // allocating memory
	
	if (Stack== NULL) {
		fprintf(stderr, "Not enough memory to create the stack\n");
		return(0);
	}
	Stack->top=-1;	//initially the stack is empty
	
	return Stack;
}

//deleting the stack
int DeleteStack(Stack* stack){
	free(stack);//freeing the allcated memory
	return 0;
	}

//adding entries for the stack
int StackPush(Stack* stack, int value){
	if((stack->top)>= (NO_OF_ELEMENTS)){	//check whether the maximum array elements have exceeded
		fprintf(stderr, "The Stack is full\n"); //error
		return(-1);  //error code
	}
	stack->array[++stack->top] = value; // assigning the value to the array element
	return 0;
	}
	
//deleting elements in the stack
int StackPop(Stack* stack, int* value){
	if (stack->top < 0) {
		value=NULL;
		fprintf(stderr, "Empty Stack.\n");	//error message
		return(-1); //returnig the error code
	}
  
	*value = (stack->array[stack->top--]); //assigning the address of the deleted element
											// at the same time top is decremented by 1
	return 0;
	}


//peeking the stack
int StackPeek(const Stack* stack, int* value){
	if (stack->top <0) {
		value=NULL;
		fprintf(stderr, "Empty Stack\n"); //checking whether the stack is empty
		return(-1);  
	}
	*value = (stack->array[stack->top]); //assigning the address of the element that is to be deleted
	return 0;
	}
	/*
void printS(Stack* stack){
	int i;
	for(i=0;i<=(stack->top);i++){
		printf("print %d ",stack->array[i]);
		}
	
	}*/
	
