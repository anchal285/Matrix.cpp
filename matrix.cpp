#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
int help(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
  {
      if(i<0 ||  i==grid.size() || j==grid[0].size()) return 0;
      
      if(dp[i][j]!=-1) return dp[i][j];

      int ans1=0; int ans2=0; int ans3=0;
      if(i+1<grid.size() && j+1<grid[0].size() && grid[i][j]<grid[i+1][j+1])
      ans1= max(ans1,1+help(i+1,j+1, grid, dp));
      if(i<grid.size() && j+1<grid[0].size() && grid[i][j]<grid[i][j+1])
      ans1= max(ans1,1+help(i,j+1, grid, dp));
      if(i-1>=0 && j+1<grid[0].size() && grid[i][j]<grid[i-1][j+1])
      ans1= max(ans1,1+help(i-1,j+1, grid, dp));

          return dp[i][j]  = ans1;

  }

    int maxMoves(vector<vector<int>>& grid) {
      int n = grid.size(); int m = grid[0].size();
      
      vector<vector<int>>dp(n,vector<int>(m,-1));
      int ans =0;
      for(int i=0;i<n;i++){
       ans = max(ans,help(i,0,grid,dp)); 
      }  
      return ans;
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    Solution solution ;
    
int result = solution.maxMoves(grid);
cout<<result;
return 0;
}