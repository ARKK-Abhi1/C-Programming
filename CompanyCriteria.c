#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int id;
	int marks;
	struct Node *next;
} Node;
Node *head=NULL;
int count=0;

int isEmpty() {
	if(head==NULL)
		return 1;
	return 0;
}

void insert(int id,int marks) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->id=id;
	newNode->marks=marks;
	newNode->next=NULL;
	
	if(head==NULL) {
		head=newNode;
	}
	else if(marks<=head->marks) {
		newNode->next=head;
		head=newNode;
	}
	else {
		Node *temp=head;
		while(temp!=NULL) {
			if(temp->next==NULL) {
				temp->next=newNode;
				break;
			}
			else if(marks<=temp->next->marks) {
				newNode->next=temp->next;
				temp->next=newNode;
				break;
			}
			temp=temp->next;
		}
	}
}
void display(int criteria) {
	Node *temp=head;
	printf("ID          Marks\n");
	while(temp!=NULL) {
		if(temp->marks>criteria) {
			printf("%-8d    %d\n",temp->id,temp->marks);
		}
		temp=temp->next;
	}
}

void display_() {
	Node *temp=head;
	while(temp!=NULL) {
		printf("%d ",temp->marks);
		temp=temp->next;
	}
}
int main() {
	insert(1,90);
	insert(2,98);
	insert(3,70);
	insert(4,87);
	display_();
	display(85);
}