#include <iostream>
using namespace std;

string howAreYou()
{
    return "How Are you all?";
}
string
friends()
{
    return "friends, " + howAreYou();
}
string Hello()
{
    return "Hello " + friends();
}

int main()
{
    cout << Hello();
    return 0;
}