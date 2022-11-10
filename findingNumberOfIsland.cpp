/* code to find the number of islands in given input */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int numOfIsland(vector<vector<char>>& grid) {
   // if the given grid is empty. then we need to return zero
   if(grid.empty() || grid[0].empty()) { return 0; }
   
   int answer=0;
 
   int height = grid.size();
   int width = grid[0].size(); 

   // initializing the visited array for checking each row and col
   vector<vector<int>> visited(height,vector<int>(width,0));

   for(int row=0; row<height; row++) {
      for(int col=0; col<width; col++) {
        cout<<"\t"<<grid[row][col];
        if(visited[row][col] && grid[row][col]=='1') {
             answer++;
             //dfs();
        }
      }
      cout<<"\n";
   }
   return answer;
}

int main() {
   vector<vector<char>> input={{'1','1','0','0','0'},
                        {'1','1','0','0','0'},
                        {'0','0','1','0','0'},
                        {'0','0','0','1','1'}};
  cout<<"\n Result: "<<numOfIsland(input);

  return 0;
}
