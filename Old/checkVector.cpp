#include<iostream>
#include<vector> 
using namespace std;


int main() {
   int width=4;
   int height = 3;
    
   vector<vector<int>> visit(height, vector<int>(width,0));     

   for(int i=0; i< visit.size(); i++) {
       for(int j=0; j<visit[i].size(); j++) {
           cout<<"\t"<<visit[i][j];
       } 
       cout<<"\n";
   }
  return 0;
}
