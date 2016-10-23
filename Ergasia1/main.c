/* Prwth Ergasia leitourgika Xeimerino E3amhno 2016-2017 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main (void) 
{

	int error=0;
	int numcourses=0;
	float gpa=0.0;
	char *studid;
	char *lastname;
	char *firstname;
	char *deprt;
	char *postcode;
	char *order;
	char command[500];
	const char delim[2]=" ";
	char *token;
	int count=0;
	char *studida;
	char *studidb;
	int k;

	studid=malloc(15*sizeof(char));
	lastname=malloc(30*sizeof(char));
	firstname=malloc(30*sizeof(char));
	deprt=malloc(50*sizeof(char));
	postcode=malloc(6*sizeof(char));
	order=malloc(3*sizeof(char));
	studida=malloc(15*sizeof(char));
	studidb=malloc(15*sizeof(char));


	printf("Skip-List And Hash Table program started \n");

	while(error==0)
	{

		printf("Write a command: \n");

		fgets(command,sizeof(command),stdin);

		printf("The command given is: %s \n",command);

		token=strtok(command,delim);

		if(strcmp(token,"i")==0)
		{

			while (token != NULL )
			{

				if(count==1)
				{
					strcpy(studid,token);
					printf("studid %s \n",studid);
				}
				else if(count==2)
				{
					strcpy(lastname,token);
					printf("lastname %s \n",lastname);
				}
				else if(count==3)
				{
					strcpy(firstname,token);
				}
				else if(count==4)
				{
					gpa=atof(token);
					printf("gpa %.2f \n",gpa);
				}
				else if(count==5)
				{
					numcourses=atoi(token);
				}
				else if(count==6)
				{
					strcpy(deprt,token);
				}
				else if(count==7)
				{
					strcpy(postcode,token);
				}
				count++;
				token = strtok(NULL,delim);
			}
		}
		else if(strcmp(token,"q")==0)
		{
			while (token != NULL )
                        {
				
				if(count==1)
				{
                                	strcpy(studid,token);
                                	printf("studid %s \n",studid);
				}
				count++;
                                token = strtok(NULL,delim);

			}
		}
		else if(strcmp(token,"m")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(studid,token);
                                        printf("studid %s \n",studid);
                                }
				else if(count==2)
                                {
                                        gpa=atof(token);
                                        printf("gpa %.2f \n",gpa);
                                }
                                else if(count==3)
                                {
                                        numcourses=atoi(token);
                                }

                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"d")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(studid,token);
                                        printf("studid %s \n",studid);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"ra")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(studida,token);
                                        printf("studid %s \n",studida);
                                }
                                else if(count==2)
                                {
                                        strcpy(studidb,token);
                                        printf("studid b is %s \n",studidb);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"a")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(postcode,token);
                                        printf("studid %s \n",postcode);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"ta")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        k=atoi(token);
                                        printf("k %d \n",k);
                                }
				if(count==2)
				{
					strcpy(postcode,token);
					printf("postcode is %s \n",postcode);
				}
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"b")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        k=atoi(token);         
                                        printf("k %d \n",k);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"ct")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(postcode,token);
                                        printf("studid %s \n",postcode);
                                }
                                else if(count==2)
                                {
                                        strcpy(deprt,token);
                                        printf("studid b is %s \n",deprt);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"f")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        gpa=atof(token);
                                        printf("gpa is  %.2f \n",gpa);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
                }
		else if(strcmp(token,"p")==0)
                {
                        while (token != NULL )
                        {

                                if(count==1)
                                {
                                        strcpy(postcode,token);
                                        printf("postcode %s \n",postcode);
                                }
                                count++;
                                token = strtok(NULL,delim);

                        }
			error=1;
			printf("error is correct \n");
                }
		 else if(strcmp(token,"pe")==0)
                {
                         while (token != NULL ){token = strtok(NULL,delim);}
			printf("Function about the percentiles \n");

                }
                else if(strcmp(token,"e")==0)
                {
                        while (token!= NULL){  token=strtok(NULL,delim); }
			error=1; 
			printf("EXIT \n");
                }

	}

	printf("Skip-List And Hash Table program terminated \n");


	return 0; 
}
