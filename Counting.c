#include<stdio.h>
FILE *fp;
int main() {
	fp=fopen("TestFile.txt","r");
	int chars=0,tabs=0,spaces=0;
	if(fp==NULL){
		printf("File Cannot be opened");
		return 0;
	}
	char c;
	while((c=fgetc(fp))!=EOF) {
		if(c==9)
			tabs++;
		else if(c==32)
			spaces++;
		else if((c>=65&&c<90)||(c>=97&&c<=122))
			chars++;
	}
	printf("No. of Characters : %d\n",chars);
	printf("No. of Tabs       : %d\n",tabs);
	printf("No. of Spaces     : %d\n",spaces);
	fclose(fp);
}