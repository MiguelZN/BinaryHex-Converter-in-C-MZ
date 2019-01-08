/*Miguel Zavala
10/11/18
LECTURE: CISC210-010
LAB: CISC210-021L
FILE: main.c
*/


#include <stdlib.h>
#include <stdio.h>
#include "number.h"
#include "number.c"
#include <ctype.h>


int main(int argc, char *argv[]){
  /*char *argv[] are a list of string command-arguments*/
  /*argv[1] is the first argument, argv[0] is the program's name*/
 
  /*Creates a NumType for each argv[i] argument and prints
    its base-10, hex, and binary values then frees the 
    NumType memory location at the end of each iteration*/

  for(int i=1;i<argc;i++){
    int current_arg = atoi(argv[i]);
    if(isNumber(argv[i])==0){
    current_arg = -1;}
    int hexstringlength=0;
    int binstringlength=0;
     NumType *numtype1 = malloc(sizeof(NumType)*1);
     convertNum(current_arg,numtype1);
     free(numtype1);
  }return 0;
}
