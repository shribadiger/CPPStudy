/*
This code is to illustrate the friend functionality and there usefulness
*/
#include <iostream>
using namespace std;

class rational
{
public:
    rational() {}
    rational(long n) : num(n), den(1) {}
    rational(rational const &ro) = default;
    rational &operator=(rational const &ro) = default;

    rational &operator+=(rational const &ro)
    {
        this->num = this->num + ro.num;
        this->den = this->den + ro.num;
        return *this;
    }

    // having some more aithmetic opeations
    rational &operator+(rational const &ro)
    {
        this->num += ro.num;
        this->den += ro.den;
        return *this;
    }
    rational &operator-(rational const &ro)
    {
        this->num -= ro.num;
        this->den -= ro.den;
        return *this;
    }

    rational &operator*(rational const &ro)
    {
        this->num *= ro.num;
        this->den *= ro.den;
        return *this;
    }

    rational &operator/(rational const &ro)
    {
        this->num /= ro.num;
        this->den /= ro.den;
        return *this;
    }

    long get_number() { return this->num; }

    long get_denominator() { return this->den; }

    friend std::ostream &operator<<(std::ostream &os, const rational &obj)
    {
        os << obj.num << ":" << obj.den;
        return os;
    }

private:
    long den;
    long num;
};

int main()
{
    // testing  some functionality about the rational number
    rational obj1(10);
    rational obj2(5);

    rational obj3 = obj1 + obj2;
    rational obj4 = obj1 - obj2;
    cout << "\n obj3 number: " << obj3.get_number();
    cout << "\n obj3 denominator : " << obj3.get_denominator();
    cout << "\n obj4 number: " << obj4.get_number();
    cout << "\n obj4 denominator : " << obj4.get_denominator();

    cout << obj2;
    return 0;
}