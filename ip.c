#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip.h"

int main(int argc, char *argv[])
{
    printf("Content-Type: text/html\n\n"); 
    FILE *file = NULL;
    char ip[17];
    int segment1 = 0, segment2 = 0, segment3 = 0, segment4 = 0;
     printf("<html><head><title>IP</title></head><body>");
    printf("<h1>TESTING FINISHED:</h1>");
    recuperation(ip, &segment1, &segment2, &segment3, &segment4);
    open_save_file(&file, ip);
    testing(ip, file, segment1, segment2, segment3, segment4);

    fclose(file); 
    
     printf("</body></html>");
    return (0);
}