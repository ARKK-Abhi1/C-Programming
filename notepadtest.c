#define FILE_NAME "credentials.txt"
#include<stdlib.h>
#include<stdio.h>
char *ssid,*password;
int fetchCredentials() {
	FILE fp=fopen(FILE_NAME,"r");
	char c;
	char id[50];
	char passW[50];
	int counter=0;
	while((c=fgetc(fp))!='\n') {
		id[counter]=c;
		counter++;
	}
	id[counter]='\0';
	counter=0;
	
	while((c=getc(fp))!=EOF) {
		passW[counter]=c;
		counter++;
	}
	password[counter]='\0';
	ssid=id;
	password=passW;
}

int main() {
	/*do {
		FILE fp;*/
		/* Reading the credentials from the file */
		/*fp=fopen("credentials.txt",fp);
		if(fp==NULL) {
			printf("Error in executing the program : cannot open the credentials file");
			return 0;
		}
		int choice;
		printf("1. Start Hotspot\n2. Stop Hotspot\n3. Restart Hotspot\n4. Change credentials\n5. Exit);
		scanf("%d",&choice);
		switch(choice) {
			case 1 : 
		}*/
		
		fetchCredentials();
		printf("%s\n%s",ssid,password);
	}
}
