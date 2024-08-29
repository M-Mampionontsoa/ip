#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000 

void recuperation(char *name,char *firstname,char *username,char *password)
{
    char *data = NULL;
    char *token = NULL;
    
    data = getenv("QUERY_STRING");  // Extraction des données via QUERY_STRING
    if (data != NULL) 
    {
        token = strtok(data, "=&");
        
        while (token != NULL) 
        {
            if (strcmp(token, "name")== 0) 
            {
                token = strtok(NULL, "=&");
                strcpy(name, token);
            } 
            else if (strcmp(token, "firstname") == 0) 
            {
                token = strtok(NULL, "=&");
                strcpy(firstname, token);
            } 
            else if (strcmp(token, "username") == 0) 
            {
                token = strtok(NULL, "=&");
                strcpy(username, token);
            }
            else if(strcmp(token, "password") == 0)
            {
                token=strtok(NULL,"=&");
                strcpy(password,token);
            }
            token = strtok(NULL, "=&");
        }
    } 
    else 
    {
        exit(1);
    }
   
}


void savedata(char *name,char *firstname,char *username,char *password)
{
   
    FILE *file = fopen("data.txt", "a");
    if (file == NULL) 
    {
        printf("Content-Type: text/html\n\n");
        printf("<html><body><p>CANNOT OPEN FILE</p></body></html>");
        exit(1);
    }
    fprintf(file, "%s %s %s %s\n", name, firstname, username,password);
    fclose(file);
}