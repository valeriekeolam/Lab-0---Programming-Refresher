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

        int i, n = 100;
        char buffer[n];
	FILE *fp;

	//If there are at least two arguments (command (1) and search term (2))
	if(argc >= 3){
		for(i = 3; i <= argc; i++){
                        FILE *fp = fopen(argv[i-1],"r");
                        if(fp == NULL){
                                puts("wgrep: file not found");
                                exit(1);
			} else {
				while (fgets(buffer, n, fp) != NULL) { //Get the first line from the file.
					if(strstr(buffer, argv[1]) != NULL) { //If the second term is found in buffer, print buffer.
						printf("%s", buffer);
					}
				}
			}
		}
		return 0;
	} else if (argc == 2) {
		while (1) {
			fgets(buffer, n, stdin);
			if(strstr(buffer, argv[1]) != NULL) {
				puts(buffer);
			}
		}
	} else if (argc == 1) {
		puts("wgrep: searchterm[file...]");
		exit(1);
	} else return 0;
}
