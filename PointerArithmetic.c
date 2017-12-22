#include<stdio.h>
int main() {
	int a=10;
	float b=10.2;
	char c='d';
	double d=12.3d;
	
	int *p1;
	printf("value of p1 %p\n",p1);
	p1=&a;
	float *p2=&b;
	char *p3=&c;
	double *p4=&d;
	
	printf("Address of : a %d\n",p1);
	printf("Address of : b %d\n",p2);
	printf("Address of : c %d\n",p3);
	printf("Address of : d %d\n",p4);
	
	printf("p1+1 : %d\n",p1+1);
	printf("p2+1 : %d\n",p2+1);
	printf("p3+1 : %d\n",p3+1);
	printf("p4+1 : %d\n",p4+1);
	
	printf("value of a = %d\n",a);
	printf("value of a = %d",*p1);
}