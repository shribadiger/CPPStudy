/* code to check the memory related string checker function */
#include<iostream>
#include<string.h>
#include<string>
#include<string>
using namespace std;


void* memchr(const void* s, int c, size_t n) {
    const char* cs = (char*)s;
    const char* ce = cs+n;
    printf("\nCS : %s",cs);
    printf("\nCE : %s",ce);
    if(n==0) return 0; // not change is required
    for(;*cs!=(char)c;cs++) {
      printf("\nChar : %s",cs);
      if(cs==ce){ printf("\n Returning after specific char match"); return nullptr;}
    }
    printf("\n Returning - %s",cs);
    return (char*)cs;
}

int main() {
   char name1[]="shrikant";
   size_t n = sizeof(name1);
   void* res=memchr(name1,'\0',n);
   return 0;
}
