#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
#include "codesignin.c"
#define MAX_LENGTH 1000

int main(int argc,char *argv[])
{
    char name[MAX_LENGTH];
    char firstname[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Content-Type:text/html\n\n");
    printf("<HTML><HEAD><meta charset=\"utf-8\"/><LINK REL=\"stylesheet\" HREF=\"login.css\"><TITLE>Login</TITLE></HEAD>");
    recuperation(name,firstname,username,password);
    savedata(name,firstname,username,password);
    printf("<BODY><H1> WELCOME %s </H1>",username);
    printf("<A HREF=\"login.html\">Login</A>");
    printf("</BODY></HTML>");
    return (0);
}