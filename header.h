
/*
In this header file all 
the predefined header files
are called as well as some common 
function are defined
*/

#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stddef.h>
#include<stdbool.h>
#include<stdlib.h>


#define SCREEN_SIZE_X 1500  //Size of window
#define SCREEN_SIZE_Y 800  //Size of window
#define M_PI 3.142

//This function is used to count digits in a integer
int count_digit(int n)
{
    return (n == 0) ? 0 : floor(log10(n) + 1);
}



void delay()//This function is for creating delay for animation
{
    for(int i = 0; i < 5000; i++)
    {
        for(int j = 0; j < 5000; j++);
    }
}


void to_string(char *s, int num)//This function is used to convert integer to string
{
    int r, d;
    d = count_digit(abs(num));
    if (num == 0)
    {
        s[0] = '0';
        d++;
    }

    if (num < 0)
    {
        s[0] = '-';
        d++;
    }
    s[d] = '\0';
    num = abs(num);
    while (num != 0)
    {
        r = num % 10;
        s[--d] = r + '0';
        num /= 10;
    }
} 
