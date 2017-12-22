#include<stdio.h>
void main(){
	int a;
	a=10;
	do
	while(a++<10);
	while(a++<=11);
	printf("%d",a);
	
	printf("\n%d%d",sizeof(10),sizeof(5,5));
}
