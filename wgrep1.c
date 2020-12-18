/*
 * Programmer: Valerie Lam
 * Class: CIS 3207 - Section 001
 * Due Date: September 2nd, 2020
 * Assignment: Project 0 - Part B: wgrep.c
 * Description: Write a program to find a search term in a line, if found, print the entire line that contains the word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

        int n = 100;
        char buffer[n];
        char searchString[10];
	char *token;
	char holdSentence[n];

        if(argc == 1) return 0;
        else {
		strcpy(searchString, argv[1]);
//		printf("The searchString is %s\n", searchString);
        	FILE *fp = fopen(argv[2],"r");
                if(fp == NULL){
                        puts("wcat: file not found");
                        exit(0);
                } else {
			while (fgets(buffer, n, fp) != NULL){
				strcpy(holdSentence, buffer);
				token = strtok(buffer, " ");
				printf("The token is %s outside the loop\n", token);
				printf("The value of string compare between %s and search string is %d\n\n", token, strcmp(token, searchString));
				if(strcmp(token, searchString) == 0){
					puts(holdSentence);
				}


				do {
//					printf("The token is %s inside the loop\n", token);
//                                      printf("The value of string compare between %s and search string is %d\n", token, strcmp(token, searchString));
					if(strcmp(token, searchString) == 0)
                                                puts(holdSentence);

					token = strtok(NULL, " ");
					printf("The token is %s inside the loop\n", token);
                                      printf("The value of string compare between %s and search string is %d\n\n", token, strcmp(token, searchString));
				} while (token != NULL);
/*
				token = strtok(NULL, " ");
				if(strcmp(token, searchString) == 0)
                                                puts(holdSentence);
				while (token != NULL){
					printf("The token is %s\n", token);
					printf("The value of string compare between token and search string is %d\n", strcmp(token, searchString));
					if(strcmp(token, searchString) == 0)
                                		puts(holdSentence);
					token = strtok(NULL, " ");
				}
*/				printf("Exited inner loop.\n");
			}
			//Search the file for the word, if found, print the line that it's found on.
                }
        }
        return 0;
}
