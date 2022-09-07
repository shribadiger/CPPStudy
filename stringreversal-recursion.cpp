#include <iostream>
using namespace std;

string string_reversal(std::string input)
{
    // case 1: Base condition to break the reversal function
    // 1: empty string reversion is empty string
    if (input == "")
        return "";

    // case 2: smallest amount of the work that can be constructed
    // calling the same function + input->beginchar();
    return ((string_reversal(input.substr(1)) + input[0]));
}

int main()
{
    cout << string_reversal("shrikant badiger going to USA");
    return 0;
}