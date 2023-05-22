#include <iostream>
#include <cmath>
using namespace std;

bool okay(int q[], int c)
{
    static int a[8][5] = {
        {-1},
        {0, -1},
        {0, 1, -1},
        {0, 2, -1},
        {2, 3, -1},
        {1, 2, 3, 4, -1},
        {1, 2, 5, -1},
        {4, 5, 6, -1},
    };

    for (int i = 0; i < c; i++)
    { // Check if the number in position c has already been used
        if (q[i] == q[c])
            return false;
    }
    /*
   we're LOOPING THROUGH the neighbors of the adjacent neighbors in the matrix by looking up the neighbors in the matrix)
     let's break down q[h[c][i]: we ARE NOT accessing q[] like a 2D array. the expression inside q[] EVALUATES to a single number - the number at that square q[i]
     after looking up the value using h[c][i], it evaluates to q[i] then compares it against what q[c] is and sees if the magnitude is 1 or not
    */
    for (int i = 0; a[c][i] != -1; i++)
    { // Check if numbers are consecutive
        if (abs(q[c] - q[a[c][i]]) == 1)
            return false;
    }

    return true;
}

void print(int *q)
{
    static int sol = 1;
    cout << "Solution#:" << sol++ << endl;
    cout << " " << q[1] << q[4] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    cout << endl;
}

int main()
{
    int q[8];
    int c = 0;
    q[c] = 1; // Place number 1 at position 0
    while (c >= 0)
    {
        c++; // Move to the next position c
        if (c > 7)
        {
            print(q);
            c--;
        }
        else
            q[c] = -1;
        // Otherwise, move num to 0, which is one num smaller than 1
        while (c >= 0)
        {
            q[c]++;
            if (q[c] > 7)
                c--;
            else
            {
                if (okay(q, c))
                    break;
            }
            // Move to the next num
            // If no num can be placed at current position c
            // Backtrack to previous position
            // Else if number is ok break and go to next position c
        }
    }
}
