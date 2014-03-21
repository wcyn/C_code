// Candidate_Registration.c
/*

Program Specification: This program takes candidates' ID numbers and country code as input and outputs a table bearing information on the candidate's Name, ID No., Country Code and Country.
  Special Features: Use of two dimentional arrays
  Date Written: 27th July, 2013
  Date Last Compiled: 29th July, 2013
*/
//include the file(s) needed
#include <stdio.h>//contains function prototypes for standard input and output library functions

//defining the structure
    typedef struct
    {
    int id;          //initializing variable
    char name[30];   //initializing array variable
    char code[6];    //initializing array variable
    char country[10];//intializing array variable
    }Candidates;//name of structure
int main()//beginning of the main function
{
   int num, i; //initializing variables

   printf("Enter the number of candidates to be entered\n");//user prompt
   scanf("%d",&num);//extracts value from keyboard input
   Candidates MyCandidates[num][5];//declaring instances of type 'Candidates'

i = 0;//declaring variable
for(i = 0; i < num; i++)//test conditions
{  //beginning of for loop
   printf("");
   gets(MyCandidates[i][0].name);

   printf("Enter the candidate's name\n");//user prompt
   gets(MyCandidates[i][0].name);//exctracts string from keyboard input

   printf("Enter the country code\nKenya - KE-1: Uganda - UG-2: Tanzania - TZ-3: Rwanda - RW-4: Burundi -  BR-5\n");//user prompt with instructions
   gets(MyCandidates[i][1].code);//exctracts string from keyboard input

   printf("Enter the Country\n");//user prompt
   scanf("%s",&MyCandidates[i][3].country);//exctracts string from keyboard input

   printf("Enter the ID number\n");//user prompt
   scanf("%d",&MyCandidates[i][2].id);//exctracts string from keyboard input
}


printf("Name\tCountry Code\tID number\tCountry\n");//prints the heading

i = 0;//initializing variables
for(i = 0; i < num; i++)//test conditions
{  //beginning of for loop

   printf("%s\t\t%s\t\t%d\t%s\n", MyCandidates[i][0].name,MyCandidates[i][1].code,MyCandidates[i][2].id,MyCandidates[i][3].country);
   //prints the Candidates' name(s), country code, Id and countries
}

	return 0;//tells the compiler that programm has run successfully

}

