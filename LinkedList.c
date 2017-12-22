#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct Node {
	int value;
	void *next;
} Node;
Node *start,*end;
int size;
int isEmpty() {
	if(start==NULL)
		return 1;
    return 0;
}
Node* addressAt(int index) {
	if(isEmpty())
		return NULL;
	static Node* temp;
	temp=start;
	for(int i=0;i<index;i++){
		if(temp==end) 
			break;
		temp=(Node*)(temp->next);
	}
	return temp;
}
int deleteAt(int index) {
	if(isEmpty())
		return 0;
	Node* tempAddr=addressAt(index-1);
	Node* deletionNode=(Node*)tempAddr->next;
	tempAddr->next=deletionNode->next;
	free(deletionNode);
	size--;
	return 1;
}

void insert(int value,int index) {
	Node *newNodeAddress=(Node*)malloc(sizeof(Node));
	if(isEmpty()) {
		start=newNodeAddress;
		start->value=value;
		end=newNodeAddress;
		size=1;
		return;
	}
	newNodeAddress->value=value;
	Node* tempAddr=addressAt(index-1);
	newNodeAddress->next=tempAddr->next;
	tempAddr->next=newNodeAddress;
	if(tempAddr==end)
		end=newNodeAddress;
	size++;
}


void printData() {
	Node* temp=start;
	printf("printing data\n");
	while(temp!=end) {
		printf("%d\n",temp->value);
		temp=(Node*)(temp->next);
	}
	printf("%d\n",end->value);
	printf("size : %d\n",size);
}
