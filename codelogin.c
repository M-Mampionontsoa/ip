#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "login.h"
#define MAX_LENGTH 1000

void extraction(char *username,char *password)
{
    char *data=NULL;
    char *token=NULL;

    data = getenv("QUERY_STRING");  // Extraction des données via QUERY_STRING
    if(data!=NULL)
    {
        token=strtok(data,"=&");
    

        while(token!=NULL)
        {
            if(strcmp(token,"username") == 0)
            {
                token=strtok(NULL,"=&");
                strcpy(username,token);
            }
            else if(strcmp(token,"username") == 0)
            {
                token=strtok(NULL,"=&");
                strcpy(password,token);
            }
            token=strtok(NULL,"=&");

        }
    }
    else
    {
        exit(1);
    }

}

void save(char *username,char *password)
{
    FILE *file=NULL;
    file=fopen("login.txt","a");
    if (file==NULL)
    {
        printf("Content-Type: text/html\n\n");
        printf("<html><body><p>CANNOT OPEN FILE</p></body></html>");
        exit(1);
    }
    fprintf(file,"%s %s\n",username,password);
    fclose(file);
    
}

void testlogin(char *username,char *password)
{
    char name[MAX_LENGTH];
    char firstname[MAX_LENGTH];
    char usernamebis[MAX_LENGTH];
    char passwordbis[MAX_LENGTH];
    char data[MAX_LENGTH];
    char *str=NULL;
    char *pass=NULL;
    FILE *file=NULL;

    file=fopen("data.txt","r");
    if(file==NULL)
    {
        printf("Content-Type: text/html\n\n");
        printf("<html><body><p>CANNOT OPEN FILE</p></body></html>");
        exit(1);
    }
    fgets(data,MAX_LENGTH,file);
    str=strstr(data,username);
    pass=strstr(data,password);
    if(str!=NULL && pass!=NULL)
    {
        printf("<Content-Type:text/html\n\n>");
        printf("<HTML><HEAD><meta charset=\"utf-8\"/><LINK REL=\"stylesheet\" HREF=\"login.css\"><TITLE>Login</TITLE></HEAD>");
        extraction(username,password);
        save(username,password);
        printf("<BODY><H1>GOOD MORNING AND ENJOY OUR PLATEFORM!!!</H1>");
        printf("<A HREF=\"test\">Start</A>");
        printf("</BODY></HTML>");
    }
    else
    {
        printf("<Content-Type:text/html\n\n>");
        printf("<html><body><p>username or password invalid</p></body></html>");

    }


}
