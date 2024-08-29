#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "login.h"
#include "codelogin.c"
#define MAX_LENGTH 1000 

int main(int argc,char *argv[])
{
    
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Content-Type:text/html\n\n");
    
    testlogin(username,password);
   

    return (0);
}