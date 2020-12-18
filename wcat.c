/*
 * Programmer: Valerie Lam
 * Class: CIS 3207 - Section 001
 * Due Date: September 2nd, 2020
 * Assignment: Project 0 - Part A: wcat.c
 * Description: Write code for a file that takes in (a/an) input file(s) from the command and prints the output.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

        int i, n = 100;
        char buffer[n];

        if(argc >= 2){
                for(i = 2; i <= argc; i++){
                        FILE *fp = fopen(argv[i-1],"r");
                        if(fp == NULL){
                                puts("wcat: cannot open file");
                                exit(0);
                        } else {
                                while(fgets(buffer, n, fp) != NULL)
                                        printf("%s", buffer);
                        }
                }
        } else if (argc == 1) return 0;
        return 0;
}
