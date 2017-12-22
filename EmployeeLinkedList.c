#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	char *name;
	int age;
	int salary;
	struct Node *next;
} Node;
Node *head=NULL;
int isEmpty() {
	if(head==NULL)
		return 1;
	return 0;
}

void insert(Node *newNode) {
	if(isEmpty()) {
		head=newNode;
		head->next=NULL;
	}
	else {
		newNode->next=head->next;
		head=newNode;
	}
	printf("New Node inserted....\n");
}

void delete() {
	if(isEmpty()) 
		printf("Linked List Empty...\n");
	else {
		Node *temp=head;
		if(temp->next==NULL) {
			free(temp);
			head=NULL;
		}
		else {
			while(temp->next->next!=NULL) 
				temp=temp->next;
			free(temp->next);
			temp->next=NULL;
		}
	}
}
void traverse() {
	if(isEmpty())
		printf("Empty Linked List\n");
	else {
		Node *temp=head;
		printf("Name                    Age    Salary    \n");
		while(temp!=NULL) {
            printf("%-20s    %3d    %d",temp->name,temp->age,temp->salary);	
            temp=temp->next;
		}			
	}
}
int main(){
	Node newNode;
	newNode.name="Abhishek Bisht";
	newNode.age=18;
	newNode.salary=1000000;
	insert(&newNode);
	traverse();
}