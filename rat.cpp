#include <iostream>
#include <vector>


class Rat{
    private:
    // numerator and denominator
    int n;
    int d;

    public:

    // default constructor
    Rat()
    {
        this->n = 0;
        this->d = 1;

    }

    // 2 arg constructor
    Rat(int n, int d)
    {
        this->n = n;
        this->d = d;
    }

    // getters
    int getN() const // using the const keyword just ensures we don't fuck with our object
    {
        return this->n;
    }

    int getD() const // again, using the const keyword ensures we don't fuck with our object. It's not completely necessary
    {
        return this->d;

    }

    Rat operator+(Rat other)
    {
        Rat temp;
        // cross multiply. The reason we use -> is when using the this keyword, we just fucking have to since apparently it's a pointer. But for another object, it's NOT a pointer, so we don't have to
        // worry about it.
        temp.n = this->n * other.d + this->d * other.n;
        // the denominator is just the product of the two denominators
        temp.d = this->d * other.d;
        return temp;

    }

    // overloading the << operator
    /*
    in c++, if you have private variables, other classes can't access them. however, if you use the friend keyword, you can define a function that does in fact utilize a class' member variables.
    in this case, using friend gives the ostream class access to our user defined class
    1) std::ostream is the return type of the function
    2) operator<< is the name of the function
    3) operator<< will take in two parameters, a const reference to the object, and a & reference to std::ostream
    4) you define the function outside the class
    */
   // This then lets us define a function that lets us have an ostream object on the left (cout) and an object on the right (Rat).
   friend std::ostream& operator<<(std::ostream &os, const Rat& rat);
};

std::ostream& operator<<(std::ostream &os, const Rat& rat)
{
    return os << rat.n << "/" << rat.d << "\n"; 
}

int main()
{
    Rat firstN(3,4);
    Rat secondN(10,15);
    Rat sum = firstN + secondN;
    std::cout << sum << "\n";


    std::cout << firstN;
}