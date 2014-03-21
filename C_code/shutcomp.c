/*

Program Specification: Shuts down the computer immediately without saving any files or sessions. Could be useful for preventing breech of security, ot not :P

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number;
    printf("Enter num");
    scanf("%d",&number);
    if (number!=100)
    {

    system("Shutdown -r -f -t 00");

    }
    return 0;
}
