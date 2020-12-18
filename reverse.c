/*
 * Programmer: Valerie Lam
 * Class: CIS 3207 - Section 001
 * Due Date: September 9th, 2020
 * Assignment: Project 0 - Part B: reverse.c
 * Description: Write a program to reverse the input of a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100

void flipWords(char *start, char *finish);

int main(int argc, char *argv[]){


        char *buffer;

	//If there are at least two arguments (command (1) and search term (2))
	if(argc == 3){
		if (strcmp(argv[1], argv[2]) == 0){
			puts("reverse: Input and output file must differ");
			exit(1);
		}
                FILE *fp = fopen(argv[1],"r");
		FILE *print = fopen(argv[2], "w");
                if(fp == NULL){
                        puts("reverse: file not found");
                        exit(1);
		} else {
			buffer = malloc(LENGTH);
			while (fgets(buffer, LENGTH, fp) != NULL) { //Get the first line from the file.
                        char *copy = buffer;
                        char *copyTwo = buffer;
                                while (*copy){
                                copy++;
                                        if (*copy == ' '){
                                                flipWords(copyTwo, copy - 1);
                                                copyTwo = copy + 1; //This allows the code to move onto the next word.
                                        }
                                        else if (*copy == '\n'){
                                                flipWords(copyTwo, copy - 1);
                                        }
                                }
                                flipWords(buffer, copy - 1);
                                fprintf(print, "%s", buffer);
                        }
		}
		fclose(fp);
		fclose(print);
		return 0;
	} else if (argc == 2) {
		FILE *fp = fopen(argv[1],"r");
                if(fp == NULL){
                        puts("reverse: file not found");
                        exit(1);
                } else {
			buffer = malloc(LENGTH);
                        while (fgets(buffer, LENGTH, fp) != NULL) { //Get the first line from the file.
			char *copy = buffer;
                	char *copyTwo = buffer;
	                	while (*copy){
        	                copy++;
                	        	if (*copy == ' '){
                        	        	flipWords(copyTwo, copy - 1);
                                		copyTwo = copy + 1; //This allows the code to move onto the next word.
                        		}
                        		else if (*copy == '\n'){
                                		flipWords(copyTwo, copy - 1);
                        		}
                		}
                		flipWords(buffer, copy - 1);
				printf("%s", buffer);
                	}
		}
		fclose(fp);
		return 0;
	} else if (argc == 1) {
		puts("Type your first sentence or ^C to quit.");
		char *input = malloc(LENGTH);
		fgets(input, LENGTH, stdin);
		char *copy = input;
               	char *copyTwo = input;
		while (*copy){
			copy++;
			if (*copy == ' '){
				flipWords(copyTwo, copy - 1);
				copyTwo = copy + 1; //This allows the code to move onto the next word.
			}
			else if (*copy == '\n'){
				flipWords(copyTwo, copy - 1);
			}
		}
		flipWords(input, copy - 1);
		printf("%s\n", input);
		return 0;
	}
	else return 0;
}

//What this function will do is get passed individual words, and will flip them.
//love would become evol
void flipWords(char *start, char *finish){
	char placeholder;
	while(start < finish){
		placeholder = *start;
		*start++ = *finish;
		*finish-- = placeholder;
	}
}
