#include <iostream>
// i and j represent the end coordinate
int path(int i, int j)
{
    // 0 initializes whole board
    static int memo[5][5] {0};
    // base case (starting from bottom left to top right)
    if (i == 0 || j == 0)
    return 1;
    if (memo[i][j] != 0 )
    return memo[i][j];
    else
    {
        return memo[i][j] = path(i -1 , j) + path(i, j -1);
    }

}

int main()
{

    // making a 'shadow' 2d representation to print everything 

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << path(i, j) << " ";
        }
        std::cout << "\n";
    }
   

}