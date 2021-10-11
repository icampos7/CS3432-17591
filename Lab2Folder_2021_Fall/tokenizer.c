#include "tokenizer.h"
//#include "Lab1_checkDel.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LIMIT 50
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
     while(delim_character(*str))
     {
/*
	if(str[i] == '\t' || str[i] == ' ')
	{
	  i++;
	}//end if
	else
	    break;
	*/
	str++;
     }//end while
     return str;
}

/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str)
{
	//first keep track of the pointer to the str/meaning the previous value
	//char *prv = str;
	//int i  = strlen(str);
	while(non_delim_character(*str))
	{
	  /*
	  if(*str != '\0')
	  {
	    i--;
	  }*/
	   str++;
	}//end while
	return str;
}
 // counts the number of words or tokens
int count_tokens(char* str){
   int count = 0;
   int i = 0;
   char* s = word_start(str);
	/*
	while(str[i])
	{
	  if(str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
	  {
		count++;
	  }
	   i++;
	}*/

    while(*s != '\0')
    {
      if(non_delim_character(*s))
	{
	   count+= 1;
	}
	s = end_word(s);
	s = word_start(s);
   }
//return count++
    return count;

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
  // printf("Copy_str");
   int i = 0;
   //char* new_string = (char*) malloc((len+1) * sizeof(char));
   char* copy = malloc((len + 1) *sizeof(char));
   for(i = 0; i < len; i++)
   {
	copy[i] = inStr[i];
   }//end for
   copy[i] = '\0';
   return copy;
}
char* check_parenthesis(char* str, int len)
{
    int i = 0; 
    for(i = 0; i < len; i++)
    {
	if(str[i] == '(')
	{
	  str[i] = ' ';
	  break;
	}//end if
	
    }//end for
    return str;
}//end check
char** tokenize(char* str)
{
   // printf("tokenize method..");
    int mystrlen(char *);
    int len = mystrlen(str);
    char* rstr = check_parenthesis(*str,len);
    int i = 0;
    int total_count = count_tokens(rstr);
    char* s = rstr;
    char* e = rstr ;
    char** current_T  = malloc((total_count + 1)* sizeof(char*));
    //printf("inside the tokenize method\n");
    for(i = 0; i < total_count; i++)
    {
	//printf("inside the forloop\n");
	s = word_start(e);
	e = end_word(s);

	current_T[i] = copy_str(s,e-s);
    }
    s[i] = 0;
    return current_T;

}


void print_all_tokens(char** tokens){
// char* new_String = (char*)malloc(*sizeof(char))
//    printf("current print_all_tokens");
    for(int i = 0; tokens[i] != 0; i++)
    {
	printf("tokens[%d]",i);
	printf("%s\n", tokens[i]);

    }
    printf("\n");
}
/*
char* check_parenthesis(char* str, int len)
{
   int i = 0;
  // int len = strlen(*str);
   for(i = 0; i < len; i++)
   {
     if(str[i] == '(')
     {
	str[i] = ' ';
	break;
     }//end if
//	printf("--->%s",str);
   }//end forloop
    printf("--->%s", str);
   return str;
}*/
/*
int main()
{
	
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
	
//	char input[MAX_LIMIT];
//	printf("Please enter the input string:\n");
//	printf("$");
//	fgets(input,MAX_LIMIT,stdin);
//	int length = strlen(input);
//	check_parenthesis(input,length);
	//char** tokens = tokenize(input);
	//print_all_tokens(tokens);
//	scanf("%c", &input);
//	printf("$-->%c",input);
//	char** tokens = tokenize(input);
//	print_all_tokens(tokens);
	return 0;

 }*/

