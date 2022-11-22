/* C++ cod to simplify the path of file in Unix System*/

#include <iostream>
#include <stack>
using namespace std;

string simplifyPath(string path)
{
    stack<char> pathStack;
    // iterate all the chars of the path and add to stack based in the need
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/') // indicate the separation of the file names
            continue;
        string pathName;
        
    }
}

int main()
{
    string path = "//root//file1";
    cout << "\n Result: " << simplifyPath(path);
    return 0;
}