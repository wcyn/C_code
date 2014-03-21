C_code
======

A collection of C language discoveries / innovations made during practice

<b>CandidateFiles</b>
 Program Specification: This program takes data containing County Candidate details
                         and writes them to an initial input file, after which the
                         data is sequencially sorted and written onto a different output file.<br><br>
  Special Features:<br>Use of functions: fopen(), fclose(), "r", "w", "a" as well as fprintf() and
                         fscanf().<br>
  Date Written:16th August, 2013: Friday<br>
  Date Last Compiled: 21th August, 2013: Wednesday
  
<b>Candidate_Registration</b>
Program Specification: This program takes candidates' ID numbers and country code as input and outputs a table bearing information on the candidate's Name, ID No., Country Code and Country.<br><br>
  Special Features: Use of two dimentional arrays<br>
  Date Written: 27th July, 2013<br>
  Date Last Compiled: 29th July, 2013
  
<b>NappierGrass(PROJECT)</b>
Consider a sequential file with the following fields for various types of nappier grass for Mr. Isanda's livestock  in his Tebuke farm:

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

a)Ranks the Plant Types according to earliest time for harvest if all the three clones are planted at the same time.
The list will be as follows: Type, Maturity period (months), Maturity Period (days) in ascending order of maturity period. Ensure the list is left
 justified.

b)Creates a file, NappierAuto.dat, that will hold Height data at maturity for each of the 50 bushes of type A, 60 bushes of type B and 70 bushes of
type C as described above.

c)Creates a second file, NappierRandom.dat, that will hold the same numbers of bushes with each maximum growth for each bush following a random pattern
as follows: Type A - between 4 to 6 feet; Type B - between 5 feet and 5 feet, 5 inches; Type C - between 3 feet, 9 inches and 4 feet, 5 inches.

After running the program 5 times with different seeds each time and recording the results for each run, it is possible to see which model between the fixed growth rate in (b) and the
random pattern model in (c) yields a better harvest at the end of the maturity period.

To be adhered to:
-The conversion between inches, feet and millimeters should be well handled
-Convert the units to one type
-Use arrays to store data while under processing

  Program Specification: The whole Program Specification has been Commented above
                         In summarry, it helps determine whether growing nappier Grass
                         with fixed heights is better than growing them with random heights
  Special Features: use of functions: fopen(), fclose(), "w" as well as fprintf() and
                         fscanf().
  Date Written:21th August, 2013: Wednesday
  Date Last Compiled: 21th August, 2013: Wednesday<br>

<b>Random Distribution</b>
Program Specification: Genrates random numbers(seedling heights) between 3 and 5 and populates a two-dimentional array
                         of 100 by 100 and calculates:<br>
                         i) The average height for each row<br>
                        ii) The average heights for each column<br>
                       iii) The total average<br>
                        iv) The number of seedlings with height above average<br><br>

  Special Features:      i)Use of two dimentional arrays.<br>
                        ii)Use of a random generator<br>
                       iii)Nested for loops<br>
  Date Written:27th July, 2013<br>
  Date Last Compiled: 4th August, 2013<br>
  
<b>shutcomp</b>
Program Specification: Shuts down the computer immediately without saving any files or sessions. Could be useful for preventing breech of security, or not :P . WARNING: Be careful with this code. Save all your work before running it.

<b>simpleHomemadeTokenizer</b>
Simple Homemade Tokenizer instead of using the strtok() function in C

