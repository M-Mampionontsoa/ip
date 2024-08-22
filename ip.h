#include <stdio.h>

void recuperation(char *ip, int *segment1, int *segment2, int *segment3, int *segment4);        //Récuperation de l'adresse ip de l'utilisateur

void open_save_file(FILE **file, char *ip);          //ouverture du fichier et  Enregistrement de l'adresse ip dans un fichier



void testing(char *ip, FILE *file, int segment1, int segment2, int segment3, int segment4);             //Test de validité de l'adresse ip