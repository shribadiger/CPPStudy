#include <iostream>
#include <string>
using namespace std;

char getCharector(int number)
{
    switch (number)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    }
    return '0';
}

char getNumber(char number)
{
    switch (number)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
    return 0;
}

int genNumber(string s)
{
    int res = 0;
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res = (res * 10) + getNumber(s[i]);
    }
    return res;
}

void convert_to_string(int number, string &res)
{
    int digit = 0;
    if (number == 0)
    {
        res = "0";
    }
    while (number != 0)
    {
        int digit = number % 10;
        char charDigit = getCharector(digit);
        res.push_back(charDigit);
        number = number / 10;
    }
}
string multiply(string num1, string num2)
{
    int n1 = genNumber(num1);
    int n2 = genNumber(num2);
    int result = n1 * n2;
    cout << "\n Prod: " << result;
    string str;
    convert_to_string(result, str);
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string s1 = "0";
    string s2 = "0";
    string res = multiply(s1, s2);
    cout << "\n Result: " << res;
    return 0;
}