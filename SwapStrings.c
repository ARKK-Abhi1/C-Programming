#include<stdio.h>
char *p[]={"String1",
              "String2",
			  "String3",
			  "String4",
			  "String5",
			  "String6"};
int swap(int pos1,int pos2) {
	if(pos1>6||pos2>6)
		return 0;
	char *temp=p[pos1-1];
	p[pos1-1]=p[pos2-1];
	p[pos2-1]=temp;
	return 1;
}
void display(char **x,int size) {
	for(int i=0;i<size;i++) 
		printf("%s\n",*(x+i));
}
int main() {
	printf("Original Strings\n");
	display(p,6);
	printf("Swapping string 1 and 3....\n");
	swap(1,3);
	printf("After Swapping\n");
	display(p,6);
}