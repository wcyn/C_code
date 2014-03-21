// CandidateFiles.c : Defines the entry point for the console application.
/*

  Program Specification: This program takes data containing County Candidate details
                         and writes them to an initial input file, after which the
                         data is sequencially sorted and written onto a different output file.
  Special Features: use of functions: fopen(), fclose(), "r", "w", "a" as well as fprintf() and
                         fscanf().
  Date Written:16th August, 2013: Friday
  Date Last Compiled: 21th August, 2013: Wednesday
*/
//include the files needed
#include <stdio.h>
#include <stdlib.h>

int main()//main function
{
    //beginning of main function
    //inititalizing variables
    int position_code;
    char candidate_ID[10];
    char county_name[15];
    char county_code [10];
    char candidate_name1 [15];
    char candidate_name2 [15];
    char position[10];
    FILE *inputPtr;//pointer to the input file
    FILE *outputPtr;//pointer to the output file

//Open file candidates.dat for writing
    if ((inputPtr = fopen("candidates.dat", "w")) == NULL)
        printf("File could not be opened\n");//error message
    else
    {
        printf("Enter the Candidates Details:\n");//User Prompt
        printf("Enter CTRL + Z to end input\n");//User Instructions

        //To print the heading; acts as a guideline to the user
        printf("%-10s%-10s%-11s%-11s%-8s%-8s\n","Position","Position",
               "Candidate", "Candidate", "County", "County");
        printf("%-10s%-10s%-11s%-11s%-8s%-8s\n","","Code", "Name(Two)","ID","Name","Code");
        printf("?\n");//to indicate that a new entry is ready to be accepted
        scanf("%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);//stores user input into the specified variables

        while(!feof(stdin))//while the user does not press CTRL + Z
        {
            //To print the heading; acts as a guideline to the user
            printf("%-10s%-10s%-11s%-11s%-8s%-8s\n","Position","Position",
               "Candidate", "Candidate", "County", "County");
            printf("%-10s%-10s%-11s%-11s%-8s%-8s\n","","Code", "Name(Two)","ID","Name","Code");

            //writes user input onto the input file
            fprintf(inputPtr," %-10s %-10d %-10s%-10s %-11s %-11s %-8s \n",position,position_code,candidate_name1,
                    candidate_name2,candidate_ID,county_name, county_code);
            printf("?\n");//to indicate that a new entry is ready to be accepted
            scanf("%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);//stores user input into the specified variables

        }
     fclose( inputPtr);//closes the input file

    }


//Opening input file for reading
//opening files to cater for the first scenario, where position_code == 1
    if ((inputPtr = fopen("candidates.dat", "r")) == NULL)//opening input file
        printf("File could not be opened\n");//error message
    else
    {
    if ((outputPtr = fopen("candidates2.dat", "w")) == NULL)//open output file
        printf("Target file could not be opened\n");//error message
    else
    {
        //Prints out the Table heading for the file, for easier referencing
        fprintf(outputPtr,"|%-10s|%-10s|%-20s|%-11s|%-11s|%-8s|\n","Position","Position",
               "Candidate's Name", "Candidate", "County", "County");
        fprintf(outputPtr,"|%-10s|%-10s|%-20s|%-11s|%-11s|%-8s|\n","","Code", "","ID","Name","Code");
        fprintf(outputPtr,"%s","------------------------------------------------------------------------------\n" );

        //scans data from the input file ready to print it to the output file
        fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);

        while(!feof(inputPtr))//while the pointer does not point to the EOF...
        {
            if(position_code == 1)//if condition
            {
            //prints data onto the file if if condition is met
            fprintf(outputPtr," %-10s %-10d %-10s%-10s %-11s %-11s %-8s \n",position,position_code,candidate_name1,
                    candidate_name2,candidate_ID,county_name, county_code);
            }
            //scans data from the input file ready to print it to the output file
            fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);

            }
        }
    }
    fclose( inputPtr);//close input file
    fclose( outputPtr);//close the output file

//opening files to cater for the second scenario, where position_code == 2
    if ((inputPtr = fopen("candidates.dat", "r")) == NULL)
        printf("File could not be opened\n");
    else
    {
    if ((outputPtr = fopen("candidates2.dat", "a")) == NULL)//Opens output file to and appends the scanned data to the already existing one
        printf("Target file could not be opened\n");
    else
    {   //scans data from the input file ready to append it to the output file
        fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);
        while(!feof(inputPtr))//while the input file pointer does not point to the EOF...
        {
            if(position_code == 2)
            {
            //prints data onto the file if if condition is met
            fprintf(outputPtr," %-10s %-10d %-10s%-10s %-11s %-11s %-8s \n",position,position_code,candidate_name1,
                    candidate_name2,candidate_ID,county_name, county_code);

            }
            //scan the data from the input file in order to append it to the output file
            fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);
        }
    }
    }
    fclose( inputPtr);//close input file
    fclose( outputPtr);//close output file

//opening files to cater for the third scenario, where position_code == 3
    if ((inputPtr = fopen("candidates.dat", "r")) == NULL)
        printf("File could not be opened\n");
    else
    {
    if ((outputPtr = fopen("candidates2.dat", "a")) == NULL)//Opens output file to and appends the scanned data to the already existing one
        printf("Target file could not be opened\n");
    else
    {
        //scans data from the input file ready to append it to the output file
        fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);
        while(!feof(inputPtr))//while the input file pointer does not point to the EOF...
        {
            if(position_code == 3)
            {
            //prints data onto the file if if condition is met
            fprintf(outputPtr," %-10s %-10d %-10s%-10s %-11s %-11s %-8s \n",position,position_code,candidate_name1,
                    candidate_name2,candidate_ID,county_name, county_code);

            }
            //scans the data from the input file in order to append it to the output file
            fscanf(inputPtr,"%s%d%s%s%s%s%s",position,&position_code,candidate_name1
               ,candidate_name2,candidate_ID,county_name, county_code);
        }
    }
    }
    fclose( inputPtr);//close input file
    fclose( outputPtr);//close output file

    return 0;//informs the compiler of successful compilation
}
