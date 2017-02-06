#include <stdio.h>
#include <stdlib.h>
#include "StackAndQueue.h"

int main()
{
	int i,r;
	printf("Testing Queue\n");
	Queue* queue = CreateQueue();
	Queue* queue2 = CreateQueue();
	
	printf("Inserting values for Q2\n");
	for(i = 100; i < 106; i++)
	{	
		printf("%d\n",i);
		int result = QueueEnqueue(queue2, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in enqueuing queue\n");
		}
	}
	printf("End bitch\n");
	print(queue2);
	printf("End bitch\n");

	printf("Inserting values\n");
	for(i = 6; i < 11 ; i++)
	{	
		printf("%d\n",i);
		int result = QueueEnqueue(queue, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in enqueuing queue\n");
		}
	}
	print( queue);
	int result2;
		QueuePeek(queue2,&result2);
		printf("\nresult2 %d\n",result2);
	
	printf("Removing values\n");
	for(i = 6; i < 8 ; i++)
	{
		int result =QueueDequeue(queue, &r);
		
		
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in dequeuing queue\n");
		}
	}
	//print( queue);
	QueuePeek(queue,&result2);
		printf("\nresult2 %d\n",result2);
	DeleteQueue(queue);
	//print( queue);
	printf("Inserting values for Q2\n");
	for(i = 150; i < 160; i++)
	{	
		printf("%d\n",i);
		int result = QueueEnqueue(queue2, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in enqueuing queue\n");
		}
		
	
	}
	//DeleteQueue(queue2);
	
print( queue2);
		printf("Removing values from 2\n");
	for(i = 6; i < 11 ; i++)
	{
		int result =QueueDequeue(queue2, &r);
		
		
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in dequeuing queue\n");
		}
	}
	print( queue2);
	//-------------------------------------------------------------------

	printf("\nTesting Stack\n");

	Stack* stack = CreateStack();
	Stack* stack2 = CreateStack();
	for(i = 0; i < 5 ; i++)
	{
		int result = StackPush(stack, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in pushing to stack");
		}
	}
	printS(stack);
	for(i = 50; i < 55 ; i++)
	{
		int result = StackPush(stack2, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in pushing to stack");
		}
	}
	printS(stack2);
	
	int s;
	StackPeek(stack2,&s);
		printf("\ns %d\n",s);
		
	printS(stack);
	for(i = 0; i < 6 ; i++)
	{
		int result = StackPop(stack, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	}
	//printS(stack);
	StackPeek(stack,&s);
		printf("\ns %d\n",s);
	for(i = 0; i < 2 ; i++)
	{
		int result = StackPop(stack2, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	}
	StackPeek(stack2,&s);
		printf("\ns2 %d\n",s);
		printS(stack2);
	DeleteStack(stack); 
	return 0;
}
