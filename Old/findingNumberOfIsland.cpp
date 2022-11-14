/* code to find the number of islands in given input */

#include<iostream>
#include<vector>
#include<string>
#include <queue>
using namespace std;

int numOfIsland(vector<vector<char>>& grid) {
   // if the given grid is empty. then we need to return zero
   if(grid.empty() || grid[0].empty()) { return 0; }
   
   int answer=0;
 
   int height = grid.size();
   int width = grid[0].size(); 

   // initializing the visited array for checking each row and col
   vector<vector<bool>> visited(height, vector<bool>(width));

   // utility function to check the boundries are inside the given range
   // this the lamda function to check the  range of given input
   auto inside = [&](int row, int col)
   {
      return (0 <= row && row < height && 0 <= col && col < width);
   };

   // code to check the direction of the grid by moving th e index like 1,0,0,1,-1,0,0-1
   // all four direction checks
   vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

   for (int row = 0; row < height; row++)
   {
      for(int col=0; col<width; col++) {

         if (!visited[row][col] && grid[row][col] == '1')
         {
            answer++;
            // dfs();
            //  this complete code represents the BFS
            queue<pair<int, int>> q;
            q.push({row, col});
            while (!q.empty())
            {
               pair<int, int> p = q.front();
               q.pop();

               // below code needs to executed for all 4 points surrounding to that
               // hence adding the for loop for the each directions
               for (pair<int, int> dir : directions)
               {
                  int new_row = p.first + dir.first;
                  int new_col = p.second + dir.second;
                  if (inside(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '1')
                  {
                     q.push({new_row, new_col});
                     visited[new_row][new_col] = true;
                  }
               }
            }
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
