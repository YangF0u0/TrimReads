/*zry_write_contents.h
Author: Ruoyin Zhou
Date:2022/5/17
Function:write differnt types of lines into a file
*/

#ifndef ZRY_WRITE_LINE_H_INCLUDED
#define ZRY_WRITE_LINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_line(char arr[],FILE *file);
void write_number(int arr[],int n,FILE *file);
void add_line(char arr[],FILE *file);
void write_length(int a,FILE *file);
#endif // ZRY_WRITE_LINE_H_INCLUDED
