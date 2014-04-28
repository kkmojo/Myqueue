#include <stdio.h>
#include "queue.h"

int command_line();

int main(void)
{
   int command = command_line();
   TYPE val;
   TYPE result;
   Queue *queue = NULL;
   while(command != 6)
   {	
   		switch(command)
   		{
   			case 1:
   				queue = initQueue();
   				printf("Queue create successful!\n"); 
   				break;
   			case 2:
	   			printf("Please enter the value: ");
	   			scanf("%d", &val);
	   			enQueue(queue, val);
	   			printf("\nEnqueue successful!\n");
	   			break;
   			case 3:
	   			deQueue(queue);
	   			printf("\nDequeue successful!\n");
	   			break;
   			case 4:
		   		result = peek(queue);
		   		printf("%d\n", result); 
	   			break;
   			case 5:
	   			destroy(queue);
	   			printf("List delete successful!"); 
	   			break;
   			case 6:
   				break;
   			default:
   				printf("Wrong Comand! Enter Again!\n");
   		}

   		command = command_line();

   }

 return 0;
}


int command_line()
{
	int command;
	printf("1. Create queue\n2. Add\n3. Remove\n4. Get\n5. Delete\n6. Exit");
	scanf("%d", &command);
	return command;
}