#include<stdio.h>
int main() {
	int a=10;
	float b=10.2;
	char c='d';
	double d=12.3d;
	
	int *p1=&a;
	float *p2=&b;
	char *p3=&c;
	double *p4=&d;
	
	printf("Address of : a %d",p1);
	printf("Address of : b %d",p2);
	printf("Address of : c %d",p3);
	printf("Address of : d %d",p4);
	
	printf("p1+1 : %d",p1+1);
	printf("p2+1 : %d",p2+1);
	printf("p3+1 : %d",p3+1);
	printf("p4+1 : %d",p4+1);
}