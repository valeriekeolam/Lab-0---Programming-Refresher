#include <stdlib.h>
#include <stdio.h>

void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin;
	printf("temp: %c", temp);
        *begin++ = *end; 
	printf("\nbegin: %s\n", begin);
        *end-- = temp;
	printf("end: %s\n", end);
    } 
	puts("");
} 
  
// Function to reverse words*/ 
void reverseWords(char* s) 
{ 
    char* word_begin = s; 
  
    // Word boundary 
    char* temp = s; 
  
    // Reversing individual words as 
    // explained in the first step 
    while (*temp) { 
        temp++; 
        if (*temp == '\0') { 
            reverse(word_begin, temp - 1); 
	    printf("word_begin: %s\n", word_begin);
	    printf("temp1: %s\n", temp);
        } 
        else if (*temp == ' ') { 
            reverse(word_begin, temp - 1); 
            word_begin = temp + 1;
	    printf("word_begin: %s\n", word_begin);
		printf("temp1: %s\n", temp);
        } 
    } 
  
    // Reverse the entire string 
    reverse(s, temp - 1); 
} 
  
// Driver Code 
int main() 
{ 
    char s[] = "i like this program very much"; 
    char* temp = s; 
    reverseWords(s); 
    printf("%s", s); 
    return 0; 
} 
