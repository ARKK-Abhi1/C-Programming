#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct Node {
	int value;
	void *next;
} Node;
Node *start,*end;
int size;
//-------------------------
int getSize() {
	return size;
}
//-------------------------------
//-------------------------------
int isEmpty() {
	if(start==NULL)
		return 1;
    return 0;
}
//------------------------------------------------
//------------------------------------------------
Node* addressAt(int index) {
	if(isEmpty()||(index>=size)||(index<0))
		return NULL;
	
	static Node* temp;
	temp=start;
	for(int i=0;i<index;i++)
		temp=(Node*)(temp->next);
	return temp;
}
//-----------------------------------------------------------
//-------------------------------------------------------------
int deleteAt(int index) {
	printf("deleting\n");
	if(isEmpty())
		return 0;
	Node* deletionNode=NULL;
	if(index==0) {
		deletionNode=start;
		start=(Node*)deletionNode->next;
		end=NULL;
	}
	else {
		Node* prevAddr=addressAt(index-1);
		if(prevAddr==NULL||prevAddr->next==NULL) // check if a node exists on the 
			return 0;                            // specified position
		deletionNode=(Node*)prevAddr->next;
		prevAddr->next=deletionNode->next;
		if(index==size-1) //if the deleted node is the last node 
			end=prevAddr; // then change the value of end
	}
    free(deletionNode);
	size--;
	return 1;
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------
/* This function will insert a node at the specified index.
    If the index is invalid then the node is inserted at the end
	of the linked list
*/
int insertAt(int value,int index) {
	Node *newNodeAddress=(Node*)malloc(sizeof(Node));
	if(isEmpty()) {
		start=newNodeAddress;
		start->value=value;
		end=newNodeAddress;
		size=1;
		return value;
	}
	newNodeAddress->value=value;
	Node* prevAddr=addressAt(index-1);
	if(prevAddr==NULL)
		prevAddr=end;
	newNodeAddress->next=prevAddr->next;
	prevAddr->next=newNodeAddress;
	if(prevAddr==end) {
		end=newNodeAddress;
		end->next=NULL;
	}
	size++;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
int getValueAt(int index) {
    if(!isEmpty()) {
	    Node* prevAddr=addressAt(index);
		if(prevAddr!=NULL)
		    return prevAddr->value;
	}
	return -1;
}
void printData() {
	Node* temp=start;
	printf("printing data\n");
	for(int i=0;i<getSize();i++){
		printf("%d\n",temp->value);
		temp=(Node*)(temp->next);
	}
	/*while(temp!=end) {
		printf("%d\n",temp->value);
		temp=(Node*)(temp->next);
	}
	printf("%d\n",end->value);*/
	printf("size : %d\n",getSize());
}


