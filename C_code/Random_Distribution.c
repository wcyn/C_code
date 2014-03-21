// Random_Distribution.c
/*
Program Specification: Genrates random numbers(seedling heights) between 3 and 5 and populates a two-dimentional array
                         of 100 by 100 and calculates:
                         i) The average height for each row
                        ii) The average heights for each column
                       iii) The total average
                        iv) The number of seedlings with height above average

  Special Features:      i)Use of two dimentional arrays.
                        ii)Use of a random generator
                       iii)Nested for loops
  Date Written:27th July, 2013
  Date Last Compiled: 4th August, 2013
*/

//include files needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//initializing global variables
int rsize = 100, csize = 100;

//function prototypes
int generateRandom(double maize[rsize][csize]);
double RowAvgHeight(double arr[rsize][csize]);
double ColAvgHeight(double arr[rsize][csize]);
int getSum(double arr[rsize][csize]);
int HeightAboveAvg(double arr[rsize][csize]);
double getTotalAvg(double arr[rsize][csize]);
double getStandardDev(double arr[rsize][csize]);

int main()//beginning of the main function
{
    //initializing the arrays and variables
    double array[rsize][csize];

    //calling the functions
    generateRandom(array);
    RowAvgHeight(array);
    ColAvgHeight(array);
    printf("\nThe sum of all the heights is %d\n",getSum(array));
    printf("The number of seedlings with height above average is %d\n",HeightAboveAvg(array));//outputs the number of values greater than 'wholeavg'
    printf("The total average of columns and rows is %lf\n",getTotalAvg(array)); //Prints out the total average of the array
    printf("The standard deviation of the array is %lf\n",getStandardDev(array));

    return 0;
}

//to find the average height of each row
double RowAvgHeight(double arr[rsize][csize])
{
    //declaring the variables
    int row, col,sum;
    double average;

    row = 0;//initializing row to '0'
    for(row = 0; row < rsize; row++)
    {
        sum = 0;//declaring variable 'sum'
        for(col = 0; col< csize; col++)
        {
            sum += arr[row][col];//add the value of 'array[row][col]' to the variable 'sum'
            average = (double)sum/rsize;//calculates the average height for each row

        }
        printf("The average height of row %d is %lf\n",(row+1),average );//prints the average for each row
        //row is added to '1' when printing since the array starts from zero.
    }
    //return row + 1;
    //return average;
}

//to find the average height of each column
double ColAvgHeight(double arr[rsize][csize])
{
    //declaring the variables
    int row, col, sum;
    double average;
    col = 0;
    for(col = 0; col < csize; col++)
    {
        sum = 0;
        for(row = 0; row < rsize; row++)
        {
            sum += arr[row][col];
            average = (double)sum/csize;
        }
        printf("The average height of column %d is %lf\n",(col+1),average);//prints the average of each column
        //column is added to '1' when printing since the array strats from zero.
    }
    //return (col + 1);
    //return average;
}

//to calculate the Sum of all the numbers
int getSum(double arr[rsize][csize])
{
    //daclaring the variables
    int row, col, sumbig;
    sumbig = 0;//initializing the variable
    for(row = 0; row < rsize; row++)
    {
        for(col = 0; col < csize; col++)
        {
            sumbig += arr[row][col];
        }
    }
    //printf("\nThe sum of all the heights is");//prints out the sum of all the numbers in the array
    return sumbig;
}

//to find the number of seedlings with height above average
int HeightAboveAvg(double arr[rsize][csize])
{
    //declaring the variables
    int count, row, col, sumbig;
    double wholeavg;

    sumbig = getSum(arr);

    wholeavg = (double)sumbig / (csize * rsize);//to calculate average of all the seedlings
    row = 0;
     for(row = 0; row < rsize; row++)//test conditions
    {
        for(col = 0; col < csize; col++)//test conditions
        {
            if(arr[row][col] > wholeavg)//test conditino for if statement
            count++; //adds one to the value of count if test condition is true
        }
    }
    //printf("Sumbig: %d\n" ,sumbig);
//    printf("The average height of all the seedlings is %lf\n",wholeavg);//prints the average height of all the seedlings
//    printf("The number of seedlings with height above average is %d\n",count);//outputs the number of values greater than 'wholeavg'
    return count;
}

//To find the total average of the whole array
//adds all the averages for each column and therefore rows.
double getTotalAvg(double arr[rsize][csize])
{
    //declaring the variables
    int row, col,sum;
    double totalAverage, rowAverage;

    row = 0;//initializing row to '0'
    for(row = 0; row < rsize; row++)
    {
        sum = 0;//declaring variable 'sum'
        for(col = 0; col< csize; col++)
        {
            sum += arr[row][col];//add the value of 'array[row][col]' to the variable 'sum'
            rowAverage = (double)sum/rsize;//calculates the average height for each row

        }
        totalAverage += rowAverage;
        //printf("The average height of row %d is %lf\n",(row+1),average );//prints the average for each row
        //row is added to '1' when printing since the array starts from zero.
    }
    return totalAverage;
}

//to find the standard deviation of the heights of the seedlings
double getStandardDev(double arr[rsize][csize])//user defined function
{
    //declaring variables
    int row, col;
    double squarediff, difference[rsize][csize];
    double wholeavg, variance, standard_dev,sum;

    wholeavg = (double)getSum(arr)/(rsize * csize);
    squarediff = 0;
    row = 0; col = 0;
    for(col = 0; col < csize; col++)
    {
        for(row = 0; row < rsize; row++)
        {
            difference[row][col] = arr[row][col] - wholeavg;
            //printf("%lf  ",difference[row][col]);//for debugging purposes
            squarediff += (difference[row][col] * difference[row][col]);//calculate the squares of the differences
            //sum += squarediff;//printf("Difference: %lf\n",difference[row][col]); //outputs differences witht the average
        }

    }

     variance = squarediff / (csize * rsize); //to calculate the variance of the array
     standard_dev = sqrt(variance);
     //printf("wholeavg: %lf",wholeavg);//for debugging purposes
     //printf("Squarediff: %lf\n",squarediff);//for debugging purposes
     printf("The variance of the array is %lf\n", variance);
     printf("standard_dev squared: %lf",(standard_dev * standard_dev));
     return standard_dev;

}

int generateRandom(double arr[rsize][csize])
{
    int row, col, random;
    srand(time(NULL));

    //populating the array with random numbers
    row = 0;
    for(row = 0; row < rsize; row++)//test conditions
    {   //Beginning of for loop

        for(col = 0; col < csize; col++)//test conditions
        {
          int random = 3 + (rand() % 3);//to get random numbers between 3 and 5.
          arr[row][col] = random;//assings the random numbers to every position of the array
          //printf("%d",random ); //For debigging purposes
        }

    }
    return random;
}

