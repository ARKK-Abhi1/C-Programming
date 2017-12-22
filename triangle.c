#include <stdio.h>
#include <math.h>
int main() {
	float a,b,c,area;
	printf("Enter the three sides : ");
	if(((a+b)>c)&&((b+c)>a)&&((c+a)>b)) {
		float s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("Area of the triangle is : %f",area);
	}
	else 
		printf("Triangle is not possible");
	    
}