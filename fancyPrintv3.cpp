#include <iostream>
typedef char box[5][7];

int main()
{
    // 1. Create the board (an 8x8 array of type *box since they're all pointing to box)
    box* board[8][8];
    box bb, wb;

    // 2. Fill the white and block boxes
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            bb[i][j] = (char)219;
            wb[i][j] = ' ';
        }
    }

    // 3. Fill up the board (remember, i + j % 2 == 0 means it's black and if not, white)
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i+j) % 2 == 1)
            board[i][j] = &bb;
            else
            {
                board[i][j] = &wb;
            }
         }

         std::cout << *(board[1][2])[0][1] << "\n";
    }

    // remember that *board[i][j] will actually dereference whatever [i][j] is pointing to, actually printing the memory address of the wb or bb;
    // The problem is there's NO PRECISION HERE. cout << (*board[i][j]) will just print a referene to bb or wb, it WON'T PRINT OUT SHIT
    // You need to fix this by being sepcfic... remember k and l? Bingo! *(board[i][j])[k][l] will give you an EXACT box and WILL print something.
    // so to print out the board, you do this (reusing all the variables from before)

    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            for (int j = 0; j < 8; j++)
            {
                for (int l = 0; l < 7; l++)
                {
                    std::cout << (*board[i][j])[k][l];
                }
            }
        }

    }




}