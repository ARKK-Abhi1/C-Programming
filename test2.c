#include "stdio.h"
int x=20;
void fun();
main(){
	int x=10;
	printf("\n%d",x);
	fun();
	static int s;
	++s;
	printf("%d",s);
	if(s<=3)
	main();
	printf("%d",s);
	return 0;
}

void fun() {
	printf("\n%d",x);
}