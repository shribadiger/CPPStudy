/*
 Leet code program to identify minimum size of elements remove from the array
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSetSize(vector<int> &arr)
{
   std::vector<int> maxChecker;
   int counter = 1;
   std::sort(arr.begin(), arr.end());
   for (int i = 1; i < arr.size(); i++)
   {
      //cout<<"\n"<<arr[i]<<":"<<arr[i-1]<<endl;
      if (arr[i] == arr[i - 1])
      {
         counter++;
         continue;
      }
      maxChecker.push_back(counter);
      counter = 1;
   }
   maxChecker.push_back(counter);
   std::sort(maxChecker.begin(), maxChecker.end(), greater<int>());
   // printing the iterator and check the logic is working or not
   std::vector<int>::iterator itr = maxChecker.begin();
   cout << "\n Max Repeater List\n";
   int devider = 0;
   int excluder = 0;
   while (itr != maxChecker.end())
   {
      cout << "\t" << *itr;
      devider += *itr;
      if (arr.size() - devider <= arr.size() / 2)
      {
         excluder++;
         break;
      }
      itr++;
      excluder++;
   }

   return excluder;
}

int main()
{
   std::vector<int> input1 = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
   cout << "\n Result: " << minSetSize(input1);
   std::vector<int> input2 = {7, 7, 7, 7, 7, 7};
   cout << "\n Result: " << minSetSize(input2);
   std::vector<int> input3 = {9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19};
   cout << "\n Result: " << minSetSize(input3);
   // cout<<"\n Size of Input: "<<input.size();
   return 0;
}
