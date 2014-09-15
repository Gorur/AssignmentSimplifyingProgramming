#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

#define MAX 100

int main(int argc, char **argv) {
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);
	int c;
	double share_value,share_Value;
	char *fvalue= NULL,*lvalue= NULL, lFlag=0, company_name[MAX],comp_name[MAX],update;
	FILE * fp,*filepointer;
	if (current_time == ((time_t)-1)) {
		(void) fprintf(stderr, "Failure to compute the current time.");
        	return EXIT_FAILURE;
    	}
	c_time_string = ctime(&current_time);
	if (c_time_string == NULL) {
        	(void) fprintf(stderr, "Failure to convert the current time.");
        	return EXIT_FAILURE;
    	}

	while((c=getopt(argc,argv,"l:f:")) !=-1) {
                switch(c) {
                        case 'f':fvalue=optarg;
                                 if(strcmp(fvalue,"share.csv") != 0) {
                                         printf("Can't open the required file\n");
                                         printf("The file to be opened was share.csv. TRY AGAIN!!!\n");
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
	/*(void) printf("Current time is %s", c_time_string);*/
	filepointer=fopen("log.txt","a+");
	fprintf(filepointer,"%s",c_time_string);
	fp=fopen("share.csv","r");
	while(!feof(fp)) {
		fscanf(fp,"%s",company_name);
printf("%s\n",company_name);
  		printf("Company name and share value's are: %s\n", company_name );
printf("Enter company name\n");
scanf("%s",comp_name);
printf("			%s\n",comp_name);
if(strcmp(company_name,comp_name)==0){
printf("%s\n",company_name);
}
else{
fseek(fp,0,SEEK_END);
fprintf(fp,"\n");
fprintf(fp,"%s",comp_name);
}
		/*if(strcmp(company_name,comp_name) == 0) {	 
  			printf("Company name and share value's are: %s\n", company_name );
			printf("Do you want to update the share value\n");
			scanf("%c",&update);
			printf("%c\n",update);
			if(update == 'y' || update == 'Y') {
				printf("Enter the share value\n");
				scanf("%lf",&share_Value);
			}
		}
		else {
			fseek(fp,0,SEEK_END);
			fprintf(fp,"\n");
			fprintf(fp,"%s",comp_name);
			fprintf(fp,",%lf",share_Value);
		}*/
	}
	fclose(fp);
	fclose(filepointer);
}
