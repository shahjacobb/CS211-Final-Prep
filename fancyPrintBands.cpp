#include <iostream>
#include <string>
int main()
{
    // string has a constructor (a, b) where the first argument is how many repetitions and the second is what to repeat. we can represent a char black block (char 219) using \xdb
    std::string a(8, '\xdb');
    std::string b(8, ' ');

    std::string line1 = a + b + a + b + a + b + a + b;
    std::string line2 = b + a + b + a + b + a + b + a;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <3; j++)
        {
            std::cout << line1 << "\n";
        }
        for (int j = 0; j < 3; j++)
        {
            std::cout << line2 << "\n";
        }
    }
}