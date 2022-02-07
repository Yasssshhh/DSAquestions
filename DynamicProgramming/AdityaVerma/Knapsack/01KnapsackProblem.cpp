//You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3

//MEMOIZATION

int dp[1001][1001];
int fun(int W, int wt[], int val[], int n)
{
   if(n==0 or W==0)
   return 0;
   if(dp[n][W]!=-1)
   return dp[n][W];
   if(wt[n-1]<=W)
   return dp[n][W]=max(val[n-1]+fun(W-wt[n-1],wt,val,n-1),fun(W,wt,val,n-1));
   if(wt[n-1]>W)
   return dp[n][W]=fun(W,wt,val,n-1);
}

class Solution
{
   public:

   int knapSack(int W, int wt[], int val[], int n) 
   { 
      memset(dp,-1,sizeof(dp));
      int profit=fun(W,wt,val,n);;
      return profit;
   }
};

//TABULATION
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
     int dp[n+1][W+1];        
      for(int i=0; i<n+1; i++){
          for(int j=0; j<W+1; j++)
          {
              if(i==0|| j==0) dp[i][j]=0;  
              
              else if(wt[i-1]<=j)
                   dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);          
              else
                  dp[i][j]=dp[i-1][j]; }}
      return dp[n][W];
    }
};