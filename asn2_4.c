#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<time.h>

#include<unistd.h>



#define MAX 30


int main(int argc, char ** argv) {

	int c,i,val_i,j,k=0;

	char str[MAX], *x[MAX];

	char *fvalue=NULL, *lvalue=NULL,lFlag=0,ch;

	char lines[MAX][BUFSIZ];

	FILE *fp;

	while((c=getopt(argc,argv,"l:f:")) != -1) {

		switch(c) {
 
			case 'f':fvalue=optarg;

				if(strcmp(fvalue,"share.csv") !=0) {

					printf("Can't open file\nThe file was share.csv.TRY AGAIN!!!\n");

					exit(EXIT_FAILURE);

				}

				break;


			case 'l':lFlag=1;

				lvalue=optarg;

				if(strcmp(lvalue,"log.txt") != 0) {

					printf("Can't open the required file\n");

					printf("The file to be opened was log.txt. TRY AGAIN!!!\n");
    
					exit(EXIT_FAILURE);

				}

				break;

			default:

				printf("Invaild input \n");

				exit(EXIT_FAILURE);

			}

	}

	fp=fopen("share.csv","r");

	if( fp == NULL ) {

		perror("Error while opening the file.\n");

     		exit(EXIT_FAILURE);

   	}
	
printf("Successfully file opened\n");

	printf("The contents of file are\n");


        while((ch=fgetc(fp)) != EOF) {

		printf("%c",ch);

	}

	fclose(fp);

	printf("File closed\n");

}
