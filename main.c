#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512
void parseText(char html[],char tagType,int FoundAT,int strLen) {
    if (tagType == 'b') {
        printf("\n-----------\n");
        printf("|");
        for (int j=FoundAT+7; html[j] != '<' && j < strLen; j++) {
            printf("%c",html[j]);
        }
    
        printf("  |");
        printf("\n-----------\n"); 
    }
    else if (tagType == 'h') {
        for(int i=FoundAT+3; html[i]!= '<' && i < strLen; i++) {
            printf("%c",html[i]);
        }
    }
}   

void parse(char html[]) {
    int strLen = strlen(html);
    for(int i=0; i<2; i++) {
        if (html[i] == 'b') {
            parseText(html,'b',i,strLen);
        }
        else if (html[i] == 'h') {
            parseText(html, 'h',i,strLen);   
            printf("\n");
        }
        
       
    }
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    if(argc != 2) {
        printf("Please Provide a Html File Name \n");
        exit(-1);
    }
   FILE *fptr;
    char *html = (char*) malloc(MAX*sizeof(char)); 
    fptr = fopen(filename,"r"); 
    if(fptr == NULL) {
        printf("[ERROR] Could Not Open the File");
        exit(-1);
    }
    
    while((fgets(html, MAX, fptr)) != NULL) {

        parse(html);
    };
     
    fclose(fptr); 
    free(html);
    return 0;

};