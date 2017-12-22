#define SIZE 5
#include<stdio.h>
int queue[SIZE];
int front=0,rear=-1;

int isEmpty() {
	if(rear==-1)
		return 1;
	return 0;
}

int isFull() {
	if(rear==SIZE-1) 
		return 1;
	return 0;
}

void enqueue(int value) {
	if(isFull()) {
		printf("OverFlow\n");
		return;
	}
	rear++;
	queue[rear]=value;
}

int dequeue() {
	if(isEmpty()) {
		printf("UnderFlow\n");
		return -1;
	}
	int value=queue[front];
	front++;
	if(front>rear) { // reset the front and rear pointers
		front=0;
		rear=-1;
	}
	return value;
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
			/*case 3 : if((value=peek())!=-1)
						 printf("Element at the front : %d\n",value);
					 break;*/
			case 4 : break;
			default : printf("Invalid choice\n");
			          break;
		}
	}while(choice!=4);
}