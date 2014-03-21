#include <stdio.h>
#include <stdlib.h>

int main()//declaring variables
{
    //declaring variables
    char c;
    char title[20], first[30], surname[30];

    printf("Enter your name including your title, eg. Mr, Mrs, Ms etc\n");
    printf("Begin with the title, your first name, and finally your surname\n");

    //accepts user input and assigns them to the three arrays
    scanf("%s%s%s",&title, &first, &surname);

    printf("Title: %s\nFirst Name:%s\nSurname:%s\n",title,first,surname);
    return 0;//indicates successful compilation
}
