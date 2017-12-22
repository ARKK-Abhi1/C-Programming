#include "stdio.h"
main()
{
    int i;
	static int a=0;
    for(i=0;i<5;i++) {
		static int a=0;
		a=0;
	    a++;
	    printf("%d",a);
    }
	printf("%d",a);
	printf("\n%d %d %d",50,34);
}
