#define FILE_NAME "credentials.txt"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char ssid[50],password[50];
/* This function will fetch credentials from the file */
int fetchCredentials() {
	system("cls");
	FILE *fp=fopen(FILE_NAME,"r");
	if(fp==NULL) {
     	printf("Error in executing the program : cannot open the credentials file");
		strcpy(ssid,"windows hotspot");
		strcpy(password,"windowshs");
		return 0;
	}
	char c;
	int counter=0;
	/* This loop will fetch the ssid */
	while((c=fgetc(fp))!='\n') {
		ssid[counter]=c;
		counter++;
		if(counter>50)
			return 0;
	}
	ssid[counter]='\0';
	counter=0;
	/* This loop will fetch the password */
	while((c=getc(fp))!=EOF) {
		password[counter]=c;
		counter++;
		if(counter>50)
			return 0;
	}
	password[counter]='\0';
	fclose(fp);
	return 1;
}

/* This function will change the credentials for the Hotspot network */
int changeCredentials() {
	system("cls");
	FILE *fp=fopen(FILE_NAME,"w");
	if(fp==NULL)
		return -1;
	printf("Enter the SSID : ");
	char id[50];
	gets(id);
	printf("Enter the password : ");
	char passW[50];
	gets(passW);
	
	fputs(id,fp);
	fputc('\n',fp);
	fputs(passW,fp);
	fclose(fp);
}


/* Function to start the Hotspot network */
int startHotspot() {
	system("cls");
	return (system("netsh wlan start hostednetwork"));
}
int stopHotspot() {
	system("cls");
	return (system("netsh wlan stop hostednetwork"));
}
int setupHotspot() {
	system("cls");
	char command[500];
	strcpy(command,"netsh wlan set hostednetwork mode=allow ssid=\"");
	strcat(command,ssid);
	strcat(command,"\" key=\"");
	strcat(command,password);
	strcat(command,"\"");
	system(command);
}

int main() {
	int choice;
	do {
		printf("\nChose an Option\n");
		printf("1. Start Hotspot\n2. Stop Hotspot\n3. Restart Hotspot\n4. Change Credentials\n5. Exit\n\n");
		scanf("%d",&choice);
		getchar(); // clears the buffer
		int x;
		switch(choice) {
			case 1 : x=fetchCredentials();
			         setupHotspot();
					 startHotspot();
					 if(x==0)
						 printf("No credentials file found...\nStarting hotspot with default settings\nSSID : %s\nPassword : %s\n",ssid,password);
				     break;
			case 2 : stopHotspot();
					 break;
			case 3 : stopHotspot();
			         startHotspot();
					 break;
			case 4 : if(changeCredentials()==-1) 
				         printf("\nFailed to change credentials\n");
					 else
						 printf("\nCredentials changed Successfully\n");
					 break;
			case 5 : break;
			default : printf("\nINVALID CHOICE\n");
			          break;
		}
	}while(choice!=5);
}
