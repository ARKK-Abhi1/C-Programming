#include<stdio.h>
int sum(int a,int b) {
	return (a+b);
}
int main() {
	printf("Enter two values\n");
	int a,b;
	scanf("%d%d",&a,&b);
	int sum_=sum(a,b);
	printf("Sum is : %d",sum_);
}