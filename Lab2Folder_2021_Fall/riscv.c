#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file
//#include "tokenizer.h"
//#include "Lab1_checkDel.h"
int32_t* reg; // Array of 32 32-bit registers

void init_regs();
bool interpret(char* instr);
void write_read_demo();

/**
 * Initialize register array for usage.
 * Malloc space for each 32-bit register then initializes each register to 0.
 * Do not alter this function!\\ */
void init_regs(){
	int reg_amount = 32;
	reg = malloc(reg_amount * sizeof(int32_t)); // 32 * 4 bytes
	for(int i = 0; i < 32; i++)
		reg[i] = i;
}
void Arithmatics(char* instr)
{
	int i = 0;
	int mystrlen(char *);
	int len = mystrlen(instr);
	char** tokens = tokenize(instr);
}
/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr)
{
	int i = 0;
	int mystrlen(char *);
	int len = mystrlen(instr);
	//int32_t address = null;
	//char* instruction = checkDel(*instr,len);
	char** tokens = tokenize(instr);
	for(i = 0; tokens[i] != 0; i++)
	{
	 //  int 
	   if(strcmp(*tokens[0], "LW"))
	   {

	      Add_Load(tokens[1],tokens[2],tokens[3]);
	      return 1;
	//int num = atoi(tokens[2]);
	     //int32_t infor = read_address(num + *tokens[3],"mem.txt");
		//	load_Info(infor);
		// printf("--->%s",tokenize[1]);
	   }//end if
	   else if(*tokens[0],"SW")
	  {
	 	Store_Instr(tokens[1],tokens[2],tokens[3]);
		return 1;
          }
	   else if(*tokens[0], "ADD")
	   {
		Add_Instr(tokens[1],tokens[2],tokens[3]);
		return 1;
	   }
	}//end forloop

	/*
	int i = 0;
	int len = strlen(instr);
	int32_t address = NULL;
	FILE *fp = fopen("mem.txt","r");
	if(instr == '\0')
	{
	   return false;
	}
	char* instrution = checkDel(instr,len);
	char** input_values = tokenizer(instruction);
	for(i = 0; input_values != '\0'; i++)
	{
	   if(input_value[i] == "LW");
	   {
	   	read_address(addresu, "mem.txt");

	  }//end if
	  else if(input_value[i] == "SW")
	  {
	  }//end else if 
	}*/
	return true;
}

/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
void write_read_demo(){
	int32_t data_to_write = 0xFFF; // equal to 4095
	int32_t address = 0x98; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}
void  load_register()
{

}
void Add_Load(char * totalSum, char* token_two,char * token_three)
{
	int32_t address, token_two_address, token_three_address;
	address = parse(totalSum);
	token_two_address =  parse(token_two);
	token_three_address = parse(token_three);
        int32_t data = reg[token_two_address] + token_three_address;
//	address = reg[tokenTwo] + tokenThree;
	reg[address] = read_address(address,"mem.txt");

}
void Add_Instr(char* totalSum, tokenOne,tokenTwo,tokenThree)
{
     int32_t address,tTwo,tThree;
     address = parse(totalSum);
     tTwo =  parse(tokenOne);
     tThree = parse(tokenThree);
     int32_t write_address = reg[tToken] + reg[tThree];
     reg[address] = write_address;
}
void Store_instr(char* tokenOne,char* tokenTwo,char* tokenThre)
{	//int32_t store,token 
	int32_t reg = parse(tokenOne);
	int32_t t1 = parse(tokenTwo);
	int32_t t2 = parse(tokenThre);
	int32_t address = reg[t2] + t1;
	int32_t data = reg[reg];
	write_address(data,address,"mem.txt");
}
int parse(char* tokens)
{
	
	int reg = atoi(tokens);
	return (int32_t)reg;
}
/**
 * Your code goes in the main
 *
 */
int main(){
	// Do not write any code between init_regs
	init_regs(); // DO NOT REMOVE THIS LINE
        //interpret();
	// Below is a sample program to a write-read. Overwrite this with your own code.
	//write_read_demo();
	//interpret();
	return 0;
}





































