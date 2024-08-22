#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip.h"


void recuperation(char *ip, int *segment1, int *segment2, int *segment3, int *segment4)
{
    char *data = getenv("QUERY_STRING");
    if (data != NULL)
    {
        if (sscanf(data, "IP=%16s", ip) == 1)  
        {
            char *token = strtok(ip, ".");
            if (token != NULL) 
            {
                *segment1 = atoi(token);
            }

            token = strtok(NULL, ".");
            if (token != NULL)
            { 
                *segment2 = atoi(token);
                
            }

            token = strtok(NULL, ".");
            if (token != NULL)
            { 
                *segment3 = atoi(token);
               
            }

            token = strtok(NULL, ".");
            if (token != NULL)
            { 
            *segment4 = atoi(token);
            }
        }
        else
        {
            printf("<p>Error</p>\n");
        }
    }
    else
    {
        printf("<p>Error.</p>\n");
        exit(1);
    }
}

void open_save_file(FILE **file, char *ip)
{
    *file = fopen("ip.txt", "a");
    if (*file == NULL)
    {
        printf("Content-Type: text/html\n\n");
        printf("<HTML><HEAD><TITLE>ERROR</TITLE></HEAD><BODY><P>COULDN'T OPEN FILE</P></BODY></HTML>");
        exit(1); 
    }
}

void testing(char *ip, FILE *file, int segment1, int segment2, int segment3, int segment4)
{
    if (segment4 < 256)
    {
        if (segment1 < 128)
        {
            fprintf(file, "Your IP address %s is VALID\nIt is a class A IP\n", ip);
        }
        else if (segment1 < 192)
        {
            fprintf(file, "Your IP address %s is VALID\nIt is a class B IP\n", ip);
        }
        else if (segment1 < 224)
        {
            fprintf(file, "Your IP address %s is VALID\nIt is a class C IP\n", ip);
        }
        else if (segment1 < 240)
        {
            fprintf(file, "Your IP address %s is VALID\nIt is a class D IP\n", ip);
        }
        else if (segment1 < 256)
        {
            fprintf(file, "Your IP address %s is VALID\nIt is a class E IP\n", ip);
        }
    }
    else
    {
        fprintf(file, "Your IP address %s is an INVALID IP ADDRESS\n", ip);
    }
}