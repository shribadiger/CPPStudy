/*
  Program to count the number of charectors which making complete word
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getIndex(char input) {
   std::map<char,int> entry;
   entry.insert({'a',0});
   entry.insert({'b',1});
   entry.insert({'c',2});
   entry.insert({'d',3});
   entry.insert({'e',4});
   entry.insert({'f',5});
   entry.insert({'g',6});
   entry.insert({'h',7});
   entry.insert({'i',8});
   entry.insert({'j',9});
   entry.insert({'k',10});
   entry.insert({'l',11});
   entry.insert({'m',12});
   entry.insert({'n',13});
   entry.insert({'o',14});
   entry.insert({'p',15});
   entry.insert({'q',16});
   entry.insert({'r',17});
   entry.insert({'s',18});
   entry.insert({'t',19});
   entry.insert({'u',20});
   entry.insert({'v',21});
   entry.insert({'w',22});
   entry.insert({'x',23});
   entry.insert({'y',24});
   entry.insert({'z',25});
   
int countCharecter(vector<string>& words, string chars) {

  // this is real function to count the number of charecters in each word and if matches
  int charCounter[26];
  

} 
