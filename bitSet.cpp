/*
 Checking the bit set functionality 
*/
#include<iostream>
#include<bitset>
using namespace std;


int main()  {
    bitset<8> b1(1);
    bitset<8> b2(2);
    bitset<8> b3(3);
    bitset<8> b4(4);
    cout<<"\n Bits : "<< b1;
    cout<<"\n Bits : "<< b2;
    cout<<"\n Bits : "<< b3;
    cout<<"\n Bits : "<< b4;
    return 0;
}
