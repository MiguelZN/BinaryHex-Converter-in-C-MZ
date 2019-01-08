/*Miguel Zavala
10/11/18
LECTURE: CISC210-010
LAB: CISC210-021L
FILE: number.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "number.h"
#include <ctype.h>

/*int convertNum(int n,Numtype *ninfo);
  -takes in an integer(base10) and converts to both base 2 and base 16 and stores the infomation in a NumType structure; returns 0 if failed, anything else success*/
int convertNum(int num, NumType *numInfo){   
  /*Refreshes Arrays (clears the chars)*/
  refreshArray(numInfo->hex);
  refreshArray(numInfo->bin);
  if((num>=0)){
    char *retrievehex = convertBaseString(16,num);
    reverseString(retrievehex);
    int hex_length = findLength(retrievehex);
    for(int i=0;i<hex_length;i++){
      numInfo->hex[i] = retrievehex[i];
    }

    char *retrievebin = convertBaseString(2,num);
    reverseString(retrievebin);
    int bin_length = findLength(retrievebin);
    for(int i=0;i<bin_length;i++){
      numInfo->bin[i] = retrievebin[i];
    }
     printf("Base-10:%i\t\tHex:%s\t\tBinary:%s\n",num,numInfo->hex,numInfo->bin);

 }
  else{
    printf("Error-Could not convert\n");
    return 0;}
    

}


/*HELPER FUNCTIONS*/

/*int isNumber(char *string)
-iterates through the char string returns 0
if the the string contains letters, or a 1 if the 
string is a number*/

int isNumber(char *char_string){
  int length = findLength(char_string);
  for(int i=0;i<length;i++){
    if(!isdigit(char_string[i])){
      return 0;
    }
  }
  return 1;
}

/*int findlength(char *string){
-takes in a character pointer/array and iterates through it to count
the number of characters there are; returns an int*/

int findLength(char *char_string){
  int arr_size = 0;
  while(char_string[arr_size]!=NULL){
    /* printf("%c",char_string[arr_size]);*/
    arr_size++;
  }

  return arr_size;
}

/*char* convertBaseString(int b, int n)
-takes in two integers: a base, and a number and 
converts the number into the indicated base; returns a
char pointer of the array(allocated on the heap*/

char* convertBaseString(int base, int num){
  char *string_rep = malloc(sizeof(char)*MAX_STRING);
  
  /*TESTING*/
  /* printf("STARTOFCONVERTBASESTRING:   %s\n",string_rep);*/

  int running = 1;
  int current_pow = highest_NumPow(base,num,'p');  
  /*fills the string with 0s*/
  for(int i=0;i<current_pow;i++){
    string_rep[i] = '0';
  } 
  
  if(num==base){
    string_rep[1] = '1';
    running--;
    return string_rep;
  }
  else if(num==0){
    string_rep[0] = '0';
    running--;
    return string_rep;
  }
  while(running){
    int highest_pow = highest_NumPow(base,num,'p');
    int highest_num = highest_NumPow(base,num,'n');

    /*printf("HNUM:%i\nHPOW:%i\n,NUM:%i\n",highest_num,highest_pow,num);*/
    if((num<base)&&(current_pow==0)){
      if(num>=10){
	 char ascii_char = 55+num;
	 string_rep[0] = ascii_char;
      }
      else{
	string_rep[0] = num+'0';
      }
      return string_rep;
    }
    else if(current_pow>highest_pow){
      string_rep[current_pow] = '0';
      current_pow--;
    }
    else if(current_pow==highest_pow){
    int num_divisions = num/highest_num;
    num = num -(num_divisions*highest_num);
    
    if(num_divisions>=10){
      int difference = num_divisions-9;
      char ascii_char = 64+difference;
      string_rep[current_pow] = ascii_char;
    }
    else{
      string_rep[current_pow] = num_divisions+'0';
    }
    current_pow--;
    }
  }
}

/*void reverseString(char *string)
-takes in a char* pointer/array and reverses the elements
by Call-By-Pointer; returns nothing*/

void reverseString(char *char_string){
  int arr_size= findLength(char_string);
  int half_arrsize = arr_size/2;

  for(int i=0;i<half_arrsize;i++){
    char temp = char_string[arr_size-i-1];
    char_string[arr_size-i-1] = char_string[i];
    char_string[i] = temp;
  }
    return;
}

/*void refreshArray(char *string)
-takes in a char *pointer and iterates through
the array by finding its size with the findLength(char *string)
function and turns all elements into NULL leaving an empty char array/pointer;
returns nothing*/

void refreshArray(char *char_string){
  int arraylength = findLength(char_string);
  for(int i=0;i<arraylength;i++){
    char_string[i] = NULL;
  }
  return;
}


/*int highest_NumPow(int b, int number, char choice)
-takes in three arguments: a base, a number, and a char(either 'p'
or 'n') and finds the highest number/highest power of indicated
base that can "fit" into the number; returns the highest number(int)
or highest power(int)*/

int highest_NumPow(int base, int num, char choice){
  int highest_pow = 0;
  int highest_num = 1;

  while((highest_num*base)<=num){
    highest_num = highest_num*base;
    highest_pow++;
  }

  if(choice=='p'){
    /* printf("HighestPow:%i",highest_pow);*/
    return highest_pow;
  }
  else if (choice=='n'){
    /* printf("HighestNum:%i",highest_num);*/ 
    return highest_num;
  }
  else{
    /* printf("HighestPow:%i,HighestNum:%i",highest_pow,highest_num);*/
  return highest_num;
  }
}
