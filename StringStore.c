#include<stdio.h>
#include<string.h>
FILE *ft;
char buffer[100];
int main() {
	ft=fopen("TestFile2.txt","w");
	if(ft==NULL) {
		printf("The file could not be creater\n");
		return 0;
	}
	printf("Enter some text\n");
	while(strlen(gets(buffer))>0) {
		fputs(buffer,ft);
		fputc('\n',ft);
	}
	fclose(ft);
	return 0;
}