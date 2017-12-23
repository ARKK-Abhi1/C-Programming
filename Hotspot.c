#define FILE_NAME "credentials.txt"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ssid[70],password[70];
/* This function will fetch credentials from the file */
int fetchCredentials() {
	FILE *fp=fopen(FILE_NAME,"r");
	if(fp==NULL) {
     	printf("Cannot find or open the credentials file\nConfiguring default settings...\n");
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
	printf("Enter the SSID : ");
	char id[70];
	fgets(id,70,stdin);
	if(strlen(id)>63) {
		printf("Too long ssid...\nMust be less than 63 characters long\n");
		while(fgetc(stdin)!='\n');// This line will flush the stdin 
		return 0;
	}
	if((toupper(id[0])<65)||(toupper(id[0])>90)) {
		printf("First character must be an alphabet...\n");
		return 0;
	}
	
	/* Asking the user to enter the password if the ssid is valid */
	printf("Enter the password : ");
	char passW[70];
	fgets(passW,70,stdin);
	while(fgetc(stdin)!='\n');
	if(strlen(passW)<8||strlen(passW)>63) {
		printf("The password should be between 8 and 63 characters long");
		return 0;
	}
	FILE *fp=fopen(FILE_NAME,"w");
	if(fp==NULL)
		return 0;
	
	fputs(id,fp);
	fputc('\n',fp);
	fputs(passW,fp);
	fclose(fp);
	return 1;
}


/* Function to start the Hotspot network */
int startHotspot() {
	if((system("netsh wlan start hostednetwork"))!=0)
		return 0;
	else {
		printf("\n--------------------------Current Settings-------------------------\n");
	    printf("SSID     : %s\n",ssid);
	    printf("PASSWORD : %s\n",password);
		return 1;
	}
}
int stopHotspot() {
	if(system("netsh wlan stop hostednetwork")==-1)
		return 0;
	return 1;
}
int setupHotspot() {
	char command[500];
	strcpy(command,"netsh wlan set hostednetwork mode=allow ssid=\"");
	strcat(command,ssid);
	strcat(command,"\" key=\"");
	strcat(command,password);
	strcat(command,"\"");
	return system(command);
}

int main() {
	int choice;
	system("cls");
	do {
		printf("\n---------------------------------------Chose an Option-----------------------------------\n");
		printf("1. Start Hotspot\n2. Stop Hotspot\n3. Restart Hotspot\n4. Change Credentials\n5. Exit\n\n");
		scanf("%d",&choice);
		getchar(); // clears the buffer
		int fetched,started;
		switch(choice) {
			case 1 : system("cls");
			         fetched=fetchCredentials();
			         setupHotspot();
					 started=startHotspot();
					 if(started) {
					     if(!fetched) {
						     printf("\nHotspot has been started with default settings\n");
					         printf("Please use the 'Change credentials option' to configure the hotspot\n");
					     }
			         }
				     break;
			case 2 : system("cls");
			         stopHotspot();
					 break;
			case 3 : system("cls");
			         stopHotspot();
			         startHotspot();
					 break;
			case 4 : system("cls");
			         if(changeCredentials()==0) 
				         printf("\nFailed to change credentials\n");
					 else {
						 fetchCredentials();
						 setupHotspot();
						 printf("\nCredentials changed Successfully\nRestart the Hotspot to apply changes\n");
					 }
					 break;
			case 5 : break;
			default : system("cls");
			          printf("\nINVALID CHOICE\n");
			          break;
		}
	}while(choice!=5);
}
