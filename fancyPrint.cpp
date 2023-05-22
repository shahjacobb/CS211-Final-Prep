#include <iostream>
#include <string>

int main()
{

// Laying the intuition for printing the board, this is NOT the program.
    /*
    apparently the sum of i and j determines how to print the band
    if (i + j) % 2 == 0 (even) --> print black
    if (i + j) % 2 == 0 (odd) --> print white 

    remember also that black = char 219 / \xdb and that white = ' '

    more notes:
    remember the concept of a band? aka a strip across the board? so we'll use a loop variable k to represent the band, from 0 to 4. 
    so i represents the entire band, and k represents each line inside the band (5 lines)
    j represents all 7 columns
    but remember, since each column is up of 8 characters, we actually need another variable for the fourth column
    i -> k -> j -> l
    */

   int i, j;
   int k, l;

   for (i = 0; i < 7; i++)
   {
    // responsible for the strip of 5 rows
    for (k = 0; k < 5; k++)
    {
        // column
        for (j = 0; j < 8; j++)
        {
            // the dots inside the column, resets each time j increments to next column, is responsible for filling/printing
            for (l = 0; l < 7; l++)
            {
                if ((i + j) % 2 == 0) 
                {
                    std::cout << (char) 219;
                }

                else std::cout << " ";
            }
        }
        std::cout << "\n";
    }
   }

}