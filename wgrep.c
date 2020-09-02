/*
 * Programmer: Valerie Lam
 * Class: CIS 3207 - Section 001
 * Due Date: September 2nd, 2020
 * Assignment: Project 0 - Part B: wgrep.c
 * Description: Write a program to find a search term in a line, if found, print the entire line that contains the word. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

        int i, n = 100;
        char buffer[n];
        char searchString[10];

        strcpy(searchString, argv[1]);
        //The second word is the search term, isolate it.

        if(argc == 1) return 0;
        else {
                        FILE *fp = fopen(argv[i-1],"r");
                        if(fp == NULL){
                                puts("wcat: file not found");
                                exit(0);
                        } else {
                                while(fgets(buffer, n, fp) != NULL)
                                        printf("%s", buffer);
                        }
        }
        return 0;
}

