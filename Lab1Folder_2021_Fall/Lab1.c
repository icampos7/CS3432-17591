#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LIMIT 20
/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
//you can also do true or false;
bool delim_character(char c)
{
     if(c == '\t' || c == ' ')
     {
     	return 1;
     }
     return 0;
}
/*
   return true(non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c)
{
	//if(delim_character == \t

   if(!delim_character(c))
   {
	return 1;
   }
    return 0;
}

/* Returns a pointer to the first character of the next
   space-separated word*/
char *word_start(char* str)
{
    char hold;
    int i = 0;
 /*  while(*str == ' ' || *str == '\t')// this only checks for white space  to check '\0'
 {}*/
     while(*str == '\0')
     {
	if(str[i] == '\t' || str[i] == ' ')
	{
	  i++;
	}//end if
	else
	    break;
     }//en while
     return str;
}

/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str)
{
	//first keep track of the pointer to the str/meaning the previous value
	char *prv = str;
	int i  = strlen(str);
	while(*str)
	{
	  if(*str != '\0')
	  {
	    i--;
	  }
	}//end while
	return str;
}
 // counts the number of words or tokens
int count_tokens(char* str){
	int count = 0;
	int i = 0;
	while(str[i])
	{
	  if(str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
	  {
		count++;
	  }
	   i++;
	}
    return count++;

}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char *copy_str(char *inStr, short len){
   int i = 0;
   char* new_string = (char*) malloc((len+1) * sizeof(char));
   for(int i = 0; i < len; i++)
   {

	new_string[i] = inStr[i];
   }//end for
   return new_string;
}

char** tokenize(char* str)
{
    int i = 0;
    int  total_count = count_tokens(str);
    char* s = str;
    char* e = str;
    char** current_T  = malloc((total_count + 1)* sizeof(char*));
    for(i = 0; i < total_count; i++)
    {
	s = word_start(s);
	//current_T[i] = copy_str(s,e-s);
	e = end_word(e);
	current_T[i] = copy_str(s,e-s);
    }
    s[i] = 0;
    return current_T;

}


void print_all_tokens(char** tokens){
// char* new_String = (char*)malloc(*sizeof(char))
    for(int i = 0; tokens[i] != 0; i++)
    {
	printf("%sn", tokens[i]);

    }
    printf("\n");
}
int main()
{
	/*
	char test =  'a';
	char test2 = '\t';
	char test3 = ' ';
	char test4 = 'c';
	char test5[12] = "hello world";
	printf("test a -->%d\n",delim_character(test));
	printf("test2 t -->%d\n",delim_character(test2));
	printf("test3 whitespace -->%d\n",delim_character(test3));
	printf("test4 non_whitespace -->%d\n",non_delim_character(test4));
	char* test_P = word_start("Hello World ");
	*/
	char input[MAX_LIMIT];
	printf("Please enter the input string:\n");
	printf("$");
	fgets(input,MAX_LIMIT,stdin);
	char ** tokens = tokenize(input);
	print_all_tokens(tokens);
//	scanf("%c", &input);
//	printf("$-->%c",input);
//	char** tokens = tokenize(input);
//	print_all_tokens(tokens);
	return 0;

 }
