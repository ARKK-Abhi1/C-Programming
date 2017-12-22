#include "LinkedList.h"
#include<stdio.h>
int top=-1;
int maxSize=10;
int push(int value) {
	if(top==maxSize-1)
		return -1;
	insertAt(value,top++);
	return value;
}
int pop() {
	if(isEmpty())
		return -1;
	int value=getValueAt(top);
	deleteAt(top);
	top--;
	return value;
}
int peek() {
	if(isEmpty())
		return -1;
	return getValueAt(top);
}

int main() {
	push(34);
	push(12);
	printData();
	printf("popped : %d\n",pop());
	printData();
	printf("popped : %d\n",pop());
	printData();
}