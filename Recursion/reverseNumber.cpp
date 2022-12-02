#include <iostream>
using namespace std;

static int sum = 0;

void reverse(int num)
{
   if (num == 0)
   {
      return;
   }

   int lastNumber = num % 10;
   sum = sum * 10 + lastNumber;
   reverse(num / 10);
}

int main()
{
   int number = 123456;
   reverse(number);
   cout << sum;
   return 0;
}