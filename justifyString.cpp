/* Program to justify the string of vectors in the given input */
#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int lineLength = 0;
    string lineString;
    int beginIndex = 0;
    for(int i=0; i<words.size(); i++) {
        if(lineLength+words[i].length()+1 <= maxWidth) {
            lineLength = lineLength + words[i].length() + 1;
            cout<<"\n Line Len = "<<lineLength;
            continue;
        } else {
            cout<<"\n Line: "<<lineLength;
            string spaces((maxWidth - lineLength),' ');
            lineString=lineString+words[beginIndex]+spaces;
            beginIndex++;
            while(beginIndex<i){
                lineString=lineString+' '+words[beginIndex];
                beginIndex++;
            }
        }
        //after preparing the string insert into result
        result.push_back(lineString);

        //resetting the counting variables
        lineString.clear();
        lineLength=0;
    }
    return result;
}

int main() {
    std::vector<string> input;
    input.push_back("shrikant");
    input.push_back("badiger");
    input.push_back("shruti");
    input.push_back("poddar");
    input.push_back("gauthami");
    input.push_back("shriyansh");

    std::vector<string> result = fullJustify(input,10);

    for(int i=0;i<result.size();i++)
        cout<<"\n"<<result[i];
    return 0;
}