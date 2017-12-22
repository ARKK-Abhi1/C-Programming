#include<stdio.h>
int stack[15];
int top=-1;
const int size=15;

int isEmpty() {
	if(top==-1)
		return 1;
	return 0;
}

int isFull() {
	if(top==size-1)
		return 1;
	return 0;
}
int push(int value) {
	if(isFull()) {
		return -1;
	}
	top++;
	stack[top]=value;
	return value;
}
int pop() {
	if(isEmpty()) {
		return -1;
	}
	int value=stack[top];
	top--;
	return value;
}
int peek() {
	if(isEmpty())
		return -1;
	return stack[top];
}
void display(int array[]) {
	int i=0;
	for(i=size-1;i>=0;i--)
		printf("%d\n",array[i]);
	printf("\ntop : %d\n",top);
	printf("\n\n");
}

int main() {
	display(stack);
	int counter=1;
	/*while(push(counter)!=-1) {
		display(stack);
		counter++;
	}*/
	push(1);
	//printf("popped : %d\n",pop());
	/*printf("popped : %d\n",pop());
	printf("popped : %d\n",pop());
	printf("popped : %d\n",pop());*/
	display(stack);
	push(24);
	display(stack);
	push(25);
	display(stack);
	pop();
	display(stack);
	printf("peek : %d",peek());
}