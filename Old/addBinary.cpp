/* adding the bianry string */
#include<iostream>
#include<vector>
using namespace std;

string addBinary(string a, string b)
{
    int len1 = a.length();
    int len2 = b.length();
    int itr = len1-1;
    int carry =0;
    string result;
    string finalResult;
    for(int i=len2-1;i>=0;i--) {
        if(a[itr]=='1' && b[i]     inu1`     == '1') {
            carry=1;
            result.push_back('0');
            itr++;                                                                                                       nm 
            continue;
        }
        else if (a[itr] =='1' && b[i] == '0'){
            if(carry){
                result.push_back('0');
                itr++;
                continue;
            }
            result.push_back('1');
            carry=0;
        }
        else if(a[itr] =='0' && b[i] =='0') {
            if(carry){
                result.push_back('0');
                itr++;
                continue;
            }
            result.push_back('1');
            carry=0;
        }
        else if(a[itr]=='0' && b[i]=='1'){
            if(carry) {
                result.push_back('0');
                itr++;
                continue;
            }
            result.push_back('1');
            carry=0;
        }
    }
    if(carry)
        result.push_back('1');
    for(int i=result.length()-1;i>=0;i--) {
        finalResult.push_back(result[i]);
    }
    return finalResult;
}

int main() {
    string a ="11";
    string b = "1";
    cout<<addBinary(a,b);
    return 0;
}