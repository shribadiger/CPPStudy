#include <iostream>
using namespace std;

std::string decimal_to_bonary(int decimal, std::string result)
{
    if (decimal == 0)
        return result; // base condition
    // computation of the result
    result = to_string(decimal % 2) + result;
    return decimal_to_bonary(decimal / 2, result);
}

int main()
{
    cout << "\n Decimal: 20 - Binary : " << decimal_to_bonary(20, "");
    cout << "\n Decimal: 456 - Binary : " << decimal_to_bonary(456, "");
}