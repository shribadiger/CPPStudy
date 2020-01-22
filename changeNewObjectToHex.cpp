/*
 * Program to change the newObjectId from xml file to desired hex value
 */
#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

template< typename T >
std::string int_to_hex( T i )
{
  std::stringstream stream;
  stream << "0x" 
         << std::setfill ('0') << std::setw(sizeof(T)*2) 
         << std::hex << i;
  return stream.str();
}

int ReplaceStringInFile( std::string file1,
                          std::string file2) {
    ifstream in(file1);
    ofstream out(file2);
    string wordToReplace="$$NewObjectID$$";
    int number =50 ;

    if (!in)
    {
        cerr << "Could not open " << file1<< "\n";
        return 1;
    }

    if (!out)
    {
        cerr << "Could not open " <<file2<< "\n";
        return 1;
    }

    string line;
    size_t len = wordToReplace.length();
    while (getline(in, line))
    {
        std::string wordToReplaceWith = int_to_hex(number);
        while (true)
        {
            size_t pos = line.find(wordToReplace);
            if (pos != string::npos) {
                line.replace(pos, len, wordToReplaceWith);
                number++;
	    }
            else 
                break;
        }

        out << line << '\n';
    }
}

int main() {
	std::string file1 = "PredefinedResources.xml";
	std::string file2 = "newFile.xml";
        ReplaceStringInFile(file1,file2);
        return 0;
}



