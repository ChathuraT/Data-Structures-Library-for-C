/*
 *     	 Project: Project 2
 *        Author: Gamage C.T.N. (E/13/107)
 * 	Created Date: April 24, 2015
 *          File: LinkedListImpl.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "StackAndQueue.h"

typedef struct queue{
	int number;
	struct queue *next;
	struct queue *start;
	struct queue *end;
	}queue;
	
typedef struct stack{
	int number;
	struct stack *next;
	struct stack *top;

	}stack;
	
//-------------------- functions for Queue--------------------------------

//creating the queue
Queue* CreateQueue(){
	queue *Queue; //creating the queue variable
	Queue = (queue*)malloc(sizeof(queue)); // allocating memory

  if (Queue == NULL) {
    fprintf(stderr, "Not enough memory to create the queue\n"); //erroe message
    return(0); //error code
  }

  Queue->start= Queue->end = NULL; //pointing the pointers to null
  return Queue;
}

//deleting the queue
int DeleteQueue(Queue* queue){
	queue->start = queue->end = NULL; //setting pointers to null

	free(queue);//freeing the allcated memory
	return 0;
	}


//adding entries for the queue
int QueueEnqueue(Queue* queue, int value){
	Queue *newNode; //creating  a new node
	newNode = (Queue *)malloc(sizeof(Queue)); //allocating memory

	if(newNode== NULL){ //check whether the memory has allocated
		fprintf(stderr, "No enogh memeory\n"); //error
		return(-1);	//error code
	}
	
	newNode->number = value; //adding the new value
	newNode->next= NULL;
	
	if (queue->start == NULL) { //adding the first element
		queue->end = queue->start= newNode;
	  } else {
		queue->end->next = newNode; // holding the end of the stack
		queue->end = newNode;
	  }
	return 0;
	}
	
//deleting elements in the queue
int QueueDequeue(Queue* queue, int* value){
	
	if(queue->start==NULL){
		fprintf(stderr,"Queue is Empty\n"); //error message
		return(-1); //error code
		}
		
	Queue * tmp=queue->start; //holding the first element to free at the end
	*value=tmp->number; //holding the first element to return
	
	if(queue->start==queue->end){
		queue->start=queue->end=NULL; //the queue is now empty
		}
	else{
		queue->start=queue->start->next;
		}
	free(tmp);//freeing the initial first node
	return 0;
	}

//peeking the queue
int QueuePeek(const Queue* queue, int* value){
	
	if(queue->start==NULL){
		fprintf(stderr,"Queue is Empty\n"); //error message
		return(-1); //error code
		}
		
	*value=(queue->start->number); //holding the first element to return
	return 0;
	}
	/*
	void print(Queue* queue){
	
	printf("1 = %d\n", queue ->start->number);
	printf("2 = %d\n", queue ->start-> next -> number);
	printf("2 = %d\n", queue ->start-> next ->next -> number);
	printf("2 = %d\n", queue ->start-> next ->next ->next -> number);
	printf("3 = %d\n", queue -> end -> number);
	}*/
	

//-------------------- functions for Stack--------------------------------

Stack* CreateStack(){
	stack *Stack; //creating the stack variable
	Stack = (stack*)malloc(sizeof(stack)); // allocating memory

  if (Stack == NULL) {
    fprintf(stderr, "Not enough memory to create the queue\n"); //erroe message
    return(0); //error code
  }

  Stack->top= NULL; //pointing the pointers to null
  return Stack;
}

//deleting the stack
int DeleteStack(Stack* stack){
	stack->top= NULL; //setting pointers to null
	free(stack);//freeing the allcated memory
	return 0;
	}


//adding entries for the stack
int StackPush(Stack* stack, int value){
	Stack*newNode; //creating  a new node
	newNode = (Stack *)malloc(sizeof(Stack)); //allocating memory

	if(newNode== NULL){ //check whether the new node has been created
		fprintf(stderr, "No enogh memeory\n"); //error
		return(-1);	//error code
	}

	newNode->number=value; //storing the new value
	newNode->next = stack->top; // holding the end of the stack
	stack->top = newNode; //assigning the toop as the new node
	  
	return 0;
	}
	
//deleting elements in the stack
int StackPop(Stack* stack, int* value){
	
	if(stack->top==NULL){ //no elements have been added yet
		fprintf(stderr,"Stack is Empty\n"); //error message
		return(-1); //error code
		}
	
	Stack * temp=stack->top; //holding the first element to free
	*value=(temp->number); //holding the top element to return
	
	stack->top=stack->top->next;
	free(temp); //freeing the previous top
	return 0;
	}
	
//peeking the stack
int StackPeek(const Stack* stack, int* value){
	
	if(stack->top==NULL){
		fprintf(stderr,"Stack is Empty\n"); //error message
		return(-1); //error code
		}
	
	*value=(stack->top->number); //holding the top element to return
	
	return 0;
	}
	/*
void printS(Stack* stack){
	printf("1 = %d\n", stack ->top->number);
	printf("2 = %d\n", stack ->top-> next -> number);
	printf("3 = %d\n", stack ->top-> next ->next -> number);
	printf("4 = %d\n", stack ->top-> next ->next ->next -> number);
	printf("5 = %d\n", stack ->top-> next ->next ->next ->next -> number);
	
	}*/
