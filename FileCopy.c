#include<stdio.h>
FILE *fp1,*fp2;
int main() {
	fp1=fopen("TestFile.txt","r");
	fp2=fopen("TestFile(copy).txt","w");
	if(fp1==NULL) {
		printf("Cannot open source file\n");
		return 0;
	}
	char c;
	while((c=fgetc(fp1))!=EOF) {
		fputc(c,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}