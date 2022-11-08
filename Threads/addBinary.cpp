/* add binary numbes */
#include <iostream>
#include <string>
using namespace std;
char sum(char a, char b, char &carry)
{
    char res;
    if (carry == '1')
    {
        if (a == '1' && b == '1')
        {
            res = '1';
        }
        else if (a == '0' && b == '0')
        {
            res = '1';
            carry = '0';
        }
        else
        {
            res = '0';
        }
    }
    else
    {
        if (a == '1' && b == '1')
        {
            res = '0';
            carry = '1';
        }
        else if (a == '0' && b == '0')
        {
            res = '0';
            carry = '0';
        }
        else
        {
            res = '1';
        }
    }
}
string addBinary(string a, string b)
{
    int length_a = a.length();
    int length_b = b.length();
    char carry = '0';
    string result;
    int i;
    for (i = 0; i < length_a; i++)
    {
        if (i > length_b)
            break;
        result.push_back(sum(a[i], b[i], carry));
    }
    int j = i;
    // remaining numbers
    while (i < length_a)
    {
        result.push_back(sum(a[i], '0', carry));
        i++;
    }

    while (j < length_b)
    {
        result.push_back(sum('0', b[j], carry));
        j++;
    }
    string res;
    for (int i = result.length() - 1; i >= 0; i--)
    {
        res.push_back(result[i]);
    }
    return res;
}

int main()
{
    string s1 = "1010";
    string s2 = "1011";
    string result = "10101";
    cout << "\n Res:" << addBinary(s1, s2);
    if (result == addBinary(s1, s2))
    {
        cout << "\n Successful";
    }
    else
    {
        cout << "\n Failed";
    }
    return 0;
}