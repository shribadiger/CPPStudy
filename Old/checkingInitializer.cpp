/* String class implemetation */
#include <iostream>
using namespace std;

class String
{
public:
    String() : _str(nullptr), _length(0) {}
    // paramterized constructor
    String(const char *input)
    {
        cout << "\n Assignment of char array";
        // passing the const char reference
        try
        {
            int len = strlen(input);
            cout << "\n Length: " << len;
            _str = new char[len + 1];
            // copying the string input
            for (int i = 0; i < len; i++)
            {
                _str[i] = input[i];
            }
            _str[len] = '\0'; // null terminated
            _length = len;
        }
        catch (...)
        {
            perror("Failed to allocate memory to String object");
        }
    }
    // copy constructor
    String(const String &refObj) : _str(refObj._str), _length(refObj._length) {}

    // copyn assignment operator
    const String &operator=(const String &refObj)
    {
        char *temp = this->_str;
        try
        {
            delete[] this->_str;
            this->_str = new char[strlen(refObj._str) + 1];
            int len = sizeof(refObj._str);
            for (int i = 0; i < len; i++)
            {
                _str[i] = refObj._str[i];
            }
            _str[len] = '\0'; // null terminated
            _length = len;
        }
        catch (...)
        {
            perror("Failed to allocated memory to String Object");
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, String &str)
    {
        out << str._str;
        return out;
    }

private:
    char *_str;
    int _length;
};

int main()
{
    String s1("shrikant");
    String s2 = "Badigershrikant";
    cout << s1 << endl;
    cout << s2 << endl;
    s2 = "shriyanshbadiger";
    cout << s2 << endl;

    return 0;
}