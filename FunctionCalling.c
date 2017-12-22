#include<stdio.h>
void callByVal(int x,int y) {
	x=0;
	y=0;
}

void callByRef(int *p1,int *p2) {
	*p1=0;
	*p2=0;
}

int main() {
	int x=10,y=20;
	printf("Original values\nx : %d\ny : %d\n",x,y);
	callByVal(x,y);
	printf("Values after call by value\nx : %d\ny : %d\n",x,y);
	callByRef(&x,&y);
	printf("Values after call by Reference\nx : %d\ny : %d\n",x,y);
}