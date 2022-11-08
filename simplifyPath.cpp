/* This is program to simplyfy the path in UNIX*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

string simplifyPath(string path)
{
    string result;
    queue<string> dataStack;
    // iterating the string
    string dir = "";
    // checking the root path
    if (path[0] == '/')
    {
        // root path inserting to stack
        dataStack.push("/");
    }
    int len = path.length();
    if (path[len - 1] == '/')
    {
        // trailing with slash
        len = len - 1;
    }
    for (int i = 1; i < len; i++)
    {

        if (path[i] == '/')
        {
            if (path[i - 1] == '/')
                continue;
            if (dir != "")
            {
                dataStack.push(dir);
            }
            dataStack.push("/");
            dir = "";
        }
        else
        {
            dir = dir + (path[i]);
        }
    }
    while (!dataStack.empty())
    {
        result = result + dataStack.front();
        dataStack.pop();
    }
    return result;
}

int main()
{
    string path = "/home//sbadiger/";
    string res = simplifyPath(path);
    // assert(res == "/home/sbadiger");
    cout << "\n Result: " << res;
    return 0;
}