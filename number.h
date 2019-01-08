/*Miguel Zavala
10/11/18
LECTURE: CISC210-010
LAB: CISC210-021L
FILE: number.h
*/


#ifndef __NUMBER__
#define __NUMBER__

#define MAX_STRING 100
typedef struct tagNumType{
  char hex[MAX_STRING];
  char bin[MAX_STRING];
} NumType;

/*-----------
**Name: convertNum
*Description: converts an integer in base 10 and stores the information
in a NumType structure
**Parameters:
** num: the decimal value to be converted
** numInfo: a pointer to a NumType struct to receive the conversion
Returns: 0 on failure, non-zero on success
**Side Effects: Overwrites the two strings inside the NumType structure
*************
int convertNum(int num, NumType* numInfo);





/*HELPER FUNCTIONS-Miguel*/
char* convertBaseString(int base, int num);
int highest_NumPow(int base, int num, char choice);
void reverseString(char* char_string);
int findLength(char* char_string);
void refreshArray(char* char_string);
int isNumber(char *char_string);
#endif
