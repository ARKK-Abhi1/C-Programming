#include<stdio.h>
FILE *fp;
int main() {
	fp=fopen("Consumer.class","r");
	char c;
	while((c=fgetc(fp))!=EOF) 
		printf("%c",c);
	fclose(fp);
}
