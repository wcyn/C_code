/***Consider a sequential file with the following fields for various types of nappier grass for Mr. Isanda's livestock  in his Tebuke farm:

Plant Name, Plant Id, Plant Type, Growth rate, Maximum Growth Period

Where,

Type A (Bana Clone): growth rate - 1 feet /month to a maximum of 5 feet
Type B (Pakistan Hybrid Clone): growth rate - 1 ft, 1mm / month to a maximum of 5ft, 2inches
Type C (Lucerne Clone): growth rate - 2 feet, 2cm / month to a maximum of 4 feet, 3inches

Assumptions:
- 1month =28 days
- All types will grow at half the rate during the first 1.5 months
- The growth rate is not affected by any other factor
- Plant Id values are A, B, C as given above
- Plant names are Bana, Pakistan Hybrid, Lucerne as given above.

The Program

a)Will Rank the Plant Types according to earliest time for harvest if all the three clones are planted at the same time.
The list will be as follows: Type, Maturity period (months), Maturity Period (days) in ascending order of maturity period. Ensure the list is left
 justified.

b) Will create a file, NappierAuto.dat, that will hold Height data at maturity for each of the 50 bushes of type A, 60 bushes of type B and 70 bushes of
type C as described above.

c) Will create a second file, NappierRandom.dat, that will hold the same numbers of bushes with each maximum growth for each bush following a random pattern
as follows: Type A - between 4 to 6 feet; Type B - between 5 feet and 5 feet, 5 inches; Type C - between 3 feet, 9 inches and 4 feet, 5 inches.

After running the program 5 times with different seeds each time and recording the results for each run, it is possible to see which model between the fixed growth rate in (b) and the
random pattern model in (c) yields a better harvest at the end of the maturity period.

To be adhered to:
-The conversion between inches, feet and millimeters should be well handled
-Convert the units to one type
-Use arrays to store data while under processing
***/

/*
  Program Specification: The whole Program Specification has been Commented above
                         In summarry, it helps determine whether growing nappier Grass
                         with fixed heights is better than growing them with random heights
  Special Features: use of functions: fopen(), fclose(), "w" as well as fprintf() and
                         fscanf().
  Date Written:21th August, 2013: Wednesday
  Date Last Compiled: 21th August, 2013: Wednesday
*/
//include the files needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define constants
#define CONVERSIONF 30.8 //1 ft == 30.8 cm
#define CONVERSIONM 0.1  //1 mm == 0.1 cm
#define CONVERSIONI 2.54 //1 Inch == 2.54cm
#define DAYS 28 //1 Month == 28 days

double generateRandom(double min, double max); //function prototype

int main()//main function
{
    //beginning of main function
    //inititalizing variables
    int x;
    char *plant_names[] = {"Bana Clone", "Pakistan Hybrid Clone",
                            "Lucerne Clone"};
    char plant_ID[2];
    char *plant_types [] = {"Type A", "Type B", "Type C"};
    //Growth rate in centimetres per month
    double mGrowth_rateA = 0, mGrowth_rateB = 0, mGrowth_rateC = 0;
    //maximum height in centimetres
    //One foot == 30.48 cm
    double max_heightA, max_heightB, max_heightC;
    double maturityMonthA, maturityMonthB, maturityMonthC;
    double maturityDayA, maturityDayB, maturityDayC;
    double height_halfRateA, height_halfRateB, height_halfRateC;
    double SumA, SumB, SumC, AvgSumA, AvgSumB, AvgSumC;

    //Arrays to hold data
    double maxHeightA[100], maxHeightB[100], maxHeightC[100];
    double maxRandA[100], maxRandB[100], maxRandC[100];
    double random;
    FILE *autoPtr;//pointer to NappierAuto.dat file
    FILE *randomPtr;//pointer to NappierRandom.dat file

    srand(time(NULL));//To generate random seed each time the program is run

/***Solutiion A***/

//To find Maturity Period in Months
//General Idea: Divide Maximum height by the Growth Rate
//First convert all length measurements to centimetres
//For Type A: 1 foot == 30.48 cm
mGrowth_rateA = 1 * CONVERSIONF;//growth rate of A in cm per month
max_heightA = 5 * CONVERSIONF;//max height of A in cm
height_halfRateA = (mGrowth_rateA/2) * 1.5; //the height of A grows during first 1.5 months
maturityMonthA = 1.5 + (max_heightA - height_halfRateA)/mGrowth_rateA;

//For tpye B: 1 mm == 1/10 cm
mGrowth_rateB = (1 * CONVERSIONF) + (1 * CONVERSIONM);//growth rate of B in cm per month
max_heightB = (5 * CONVERSIONF) + (2 * CONVERSIONI);//Max height of B in cm
height_halfRateB = (mGrowth_rateB/2) * 1.5; //the height of B grows during first 1.5 months
maturityMonthB = 1.5 + (max_heightB - height_halfRateB)/mGrowth_rateB;

//For type C:
mGrowth_rateC = (2 * CONVERSIONF) + 2;//Growth rate of C in cm per month
max_heightC = (4 * CONVERSIONF) + (3 * CONVERSIONI);//Max height of C in cm
height_halfRateC = (mGrowth_rateC/2) * 1.5; //the height of C grows during first 1.5 months
maturityMonthC = 1.5 + (max_heightC - height_halfRateC)/mGrowth_rateC;

//To find maturity period in Days
//General Idea. Simply convert the Maturity Period in Month into days
maturityDayA = maturityMonthA * DAYS;
maturityDayB = maturityMonthB * DAYS;
maturityDayC = maturityMonthC * DAYS;

//printf("rateA: %4.3lf\nrateB: %4.3lf\nrateC: %4.3lf\n",mGrowth_rateA,
//       mGrowth_rateB,mGrowth_rateC);//For Debugging Purposes
//printf("MatMonthA: %lf\nMatMonthB: %lf\nMatMonthC: %lf\n", maturityMonthA, maturityMonthB, maturityMonthC);//for debugging
//printf("MatDayA: %lf\nMatDayB: %lf\nMatDayC: %lf\n", maturityDayA, maturityDayB, maturityDayC);//for debugging

printf("%-10s%-28s%-26s\n","Type","Maturity Period(Months)","Maturity Period(Days)");//print the table heading


//To print out the Plants types and their maturity period in ascending order
if (maturityDayA < maturityDayB && maturityDayA < maturityDayC)
{
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[0],maturityMonthA,maturityDayA);
     if(maturityDayB < maturityDayC)
     {
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[1],maturityMonthB,maturityDayB);
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[2],maturityMonthC,maturityDayC);
     }
     else
     {
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[2],maturityMonthC,maturityDayC);
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[1],maturityMonthB,maturityDayB);
     }
    }

if (maturityDayB < maturityDayA && maturityDayB < maturityDayC)
    {
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[1],maturityMonthB,maturityDayB);
     if(maturityDayA < maturityDayC)
     {
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[0],maturityMonthA,maturityDayA);
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[2],maturityMonthC,maturityDayC);
     }
     else
     {
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[2],maturityMonthC,maturityDayC);
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[0],maturityMonthA,maturityDayA);
     }
    }

if (maturityDayC < maturityDayA && maturityDayC < maturityDayB)
    {
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[2],maturityMonthC,maturityDayC);
     if(maturityDayA < maturityDayB)
     {
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[0],maturityMonthA,maturityDayA);
        printf("%-10s%-28.3lf%-26.3lf\n",plant_types[1],maturityMonthB,maturityDayB);
     }
     else
     {
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[1],maturityMonthB,maturityDayB);
     printf("%-10s%-28.3lf%-26.3lf\n",plant_types[0],maturityMonthA,maturityDayA);
     }
    }

/***Solutiion B***/
//
//File to hold Height Data at Maturity for each of the Bushes
//Open file NappierAuto.dat for writing

    if ((autoPtr = fopen("NappierAuto.dat", "w")) == NULL)
        printf("File could not be opened\n");//error message
    else
    {
        //To print the heading
        fprintf(autoPtr,"%s\n", "FIXED MATURITY HEIGHTS IN CM");

        //to print 50 bushes of type A onto the file NappierAuto.dat
        fprintf(autoPtr,"\n%s\n","MATURITY HEIGHTS FOR TYPE A");
        fprintf(autoPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;
        for(x = 1; x <= 50; x++)//for loop to print 50 lines
        {
           fprintf(autoPtr, "%lf\t", max_heightA);
           if ((x % 10) == 0)
           fprintf(autoPtr,"%s","\n");
        }

        //To print 60 bushes of type B onto the file NappierAuto.dat
        fprintf(autoPtr,"\n%s\n","MATURITY HEIGHTS FOR TYPE B");
        fprintf(autoPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;
        for(x = 1; x <= 60; x++)//for loop to print 60 lines
        {
           fprintf(autoPtr, "%lf\t",max_heightB);
           if ((x % 10) == 0)
           fprintf(autoPtr,"%s","\n");

        }

        //To print 70 bushes of type C onto the file NappierAuto.dat
        fprintf(autoPtr,"\n%s\n","MATURITY HEIGHTS FOR TYPE C");
        fprintf(autoPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;
        for(x = 1; x <= 70; x++)//for loop to pritn 70 lines
        {
           fprintf(autoPtr, "%lf\t",max_heightC);
           if ((x % 10) == 0)
           fprintf(autoPtr,"%s","\n");

        }
    }

/*** Solution C ***/

//A second file, NappierRandom.dat that holds the same numbers of bushes
//with each maximum growth for each bush following a random pattern as
//follows: Type A - btwn 4 - 6 feet; Type B btwn 5ft and 5ft, 5 inches;
//Type C - between 3ft, 9 inches and 4ft, 5 inches.

//Open file NappierRandom.dat for writing
//defining new heights
//converting all the units to centimetres
double max_heightA2[2] = {(4 * CONVERSIONF),(6 * CONVERSIONF)};
double max_heightB2[2] = {(5 * CONVERSIONF),((5 * CONVERSIONF) + 5 * CONVERSIONI)};
double max_heightC2[2] = {((3 * CONVERSIONF) + 9 * CONVERSIONI),((4 * CONVERSIONF) + 5 * CONVERSIONI)};

/*For debugging purposes
        printf("%lf\n",max_heightA2[0]);
        printf("Conv: %lf\n",(4 * CONVERSIONF));
        printf("%lf\n",max_heightA2[1]);
        printf("Conv: %lf\n",(6 * CONVERSIONF));
        printf("%lf\n",max_heightB2[0]);
        printf("%lf\n",max_heightB2[1]);
        printf("%lf\n",max_heightC2[0]);
        printf("%lf\n",max_heightC2[1]);
//*/

    if ((randomPtr = fopen("NappierRandom.dat", "w")) == NULL)
        printf("File could not be opened\n");//error message
    else
    {
        //To print the heading
        fprintf(randomPtr,"%s\n", "RANDOM MATURITY HEIGHTS IN CM");
        //to print 50 bushes of type A onto the file NappierAuto.dat
        fprintf(randomPtr,"\n%s\n","RANDOM HEIGHTS FOR TYPE A");
        fprintf(randomPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;

        for(x = 1; x <= 50; x++)//for loop to print 50 lines
        {
           random = generateRandom(max_heightA2[0], max_heightA2[1]);
           fprintf(randomPtr, "%lf\t" ,random);
           if (x % 10 == 0)
           fprintf(randomPtr,"%s","\n");
           maxRandA[x - 1] =  random;
        }
        //To find the average sum of the random heights of A for comparison with fixed height of A
        for(x = 0;x<50; x++)
         {
             SumA += maxRandA[x];
         }
        AvgSumA = SumA/50;
        fprintf(randomPtr,"\n%-10s%lf\n","Average:", AvgSumA);
        fprintf(randomPtr,"%-10s%lf\n","Fixed  :", max_heightA);
        if(AvgSumA > max_heightA)
          fprintf(randomPtr,"%s\n", "RANDOM HEIGHTS YIELDS BETTER HARVEST THAN FIXED HEIGHT");
        else
          fprintf(randomPtr,"%s\n", "FIXED HEIGHT YIELDS BETTER HARVEST THAN RANDOM HEIGHTS");

        /*For debugging
        for(x = 0;x<50; x++)
        {
            printf("%lf \n",maxRandA[x]);
        }*/

        //To print 60 bushes of type B onto the file NappierAuto.dat
        fprintf(randomPtr,"\n%s\n","RANDOM HEIGHTS FOR TYPE B");
        fprintf(randomPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;
        for(x = 1; x <= 60; x++)//for loop to print 60 lines
        {
           random = generateRandom(max_heightB2[0], max_heightB2[1]);
           fprintf(randomPtr, "%lf\t" ,random);
           if (x % 10 == 0)
           fprintf(randomPtr,"%s","\n");
           maxRandB[x - 1] =  random;
        }
        //To find the average sum of the random heights of B for comparison with fixed height of B
        for(x = 0;x<60; x++)
         {
             SumB += maxRandB[x];
         }
        AvgSumB = SumB/60;
        fprintf(randomPtr,"\n%-10s%lf\n","Average:", AvgSumB);
        fprintf(randomPtr,"%-10s%lf\n","Fixed  :", max_heightB);
        if(AvgSumB > max_heightB)
          fprintf(randomPtr,"%s\n", "RANDOM HEIGHTS YIELDS BETTER HARVEST THAN FIXED HEIGHT");
        else
          fprintf(randomPtr,"%s\n", "FIXED HEIGHT YIELDS BETTER HARVEST THAN RANDOM HEIGHTS");
        /*for debugging
        for(x = 0;x<60; x++)
        {
            printf("%lf \n",maxRandB[x]);
        }*/
        //To print 70 bushes of type C onto the file NappierAuto.dat
        fprintf(randomPtr,"\n%s\n","RANDOM HEIGHTS FOR TYPE C");
        fprintf(randomPtr,"%s\n","-----------------------------------------------------------------------");
        x = 1;
        for(x = 1; x <= 70; x++)//for loop to pritn 70 lines
        {
           random = generateRandom(max_heightC2[0], max_heightC2[1]);
           fprintf(randomPtr, "%lf\t" ,random);
           if (x % 10 == 0)
           fprintf(randomPtr,"%s","\n");
           maxRandC[x - 1] =  random;
        }
        //To find the average sum of the random heights of C for comparison with fixed height of C
        for(x = 0;x<70; x++)
         {
             SumC += maxRandC[x];
         }
        AvgSumC = SumC/70;
        fprintf(randomPtr,"\n%-10s%lf\n","Average:", AvgSumC);
        fprintf(randomPtr,"%-10s%lf\n","Fixed  :", max_heightC);
        if(AvgSumC > max_heightC)
          fprintf(randomPtr,"%s\n", "RANDOM HEIGHTS YIELDS BETTER HARVEST THAN FIXED HEIGHT");
        else
          fprintf(randomPtr,"%s\n", "FIXED HEIGHT YIELDS BETTER HARVEST THAN RANDOM HEIGHTS");
    }

       fclose(randomPtr);//close the file NappierRandom.dat
       return 0;//informs the compiler of successful compilation
}
//generate a random floating point number from min to max
double generateRandom(double min, double max)//User defined function to genrate random numbers
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

