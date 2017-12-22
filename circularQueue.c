#define SIZE 5
#include<stdio.h>
int circularQ[SIZE];
int front=0,rear=-1;

int isEmpty() {
	if(rear==-1)
		return 1;
	return 0;
}

int isFull() {
	if(((rear==-1)?0:((rear+1)%SIZE==front))) // This condition is set so because on codition arises when
	    return 1;                        // rear=-1 and front =0 and incresing rear gives 0, which will show  the 
    return 0;							 // array to be full. However it is not the case
}

void enqueue(int value) {
	if(isFull()) {
		printf("Overflow\n");
		return;
	}
	rear=front+(rear+1)%SIZE;
	circularQ[rear]=value;
}

int dequeue() {
	if(isEmpty()) {
		printf("Underflow\n");
		return -1;
	}
	int value=circularQ[front];
	front=(front+1)%SIZE;
	if(front==(rear+1)%SIZE)
		rear=-1;
	return value;
}

int peek() {
	if(isEmpty()) {
		printf("No element in the queue\n");
		return -1;
	}
	return circularQ[front];
}

int main() {
	int choice,value;
	do {
		printf("\nSelect a choice : \n1 : enqueue\n2 : dequeue\n3 : Peek\n4 : Exit\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1 : printf("Enter a value : ");
				     scanf("%d",&value);
				     enqueue(value);
					 break;
		    case 2 : if((value=dequeue())!=-1)
				         printf("Dequeued value : %d\n",value);
					 break;
			case 3 : if((value=peek())!=-1)
						 printf("Element at the front : %d\n",value);
					 break;
			case 4 : break;
			default : printf("Invalid choice\n");
			          break;
		}
	}while(choice!=4);
}