//Given a value V and array coins[] of size M, the task is to make the change for V cents,
//given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins.
//Find the minimum number of coins to make the change. If not possible to make change then return -1.

// Example 1:

// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin
// and one 5 cent coin

class Solution{
//V is sum.
//j will traverse over sum.
	public:
	
	int helper(int coins[],int M,int V){
     
       int t[M+1][V+1];
       for(int i=0;i<=V;i++){
           t[0][i]=INT_MAX-1;
       }
       for(int i=0;i<=M;i++){
           t[i][0]=0;
       }
       for(int i=1,j=0;j<=V;j++){
           if(j%coins[0]==0){
               t[i][j]=j/coins[0];
           }
           else{
               t[i][j]=INT_MAX-1;
           }
       }
      for(int i=2;i<=M;i++){
          for(int j=1;j<=V;j++){
              if(coins[i-1]<=j){
                  t[i][j]=min(t[i-1][j],1+t[i][j-coins[i-1]]);
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
      if(t[M][V]==INT_MAX-1){
          return -1;
      }
       return t[M][V];
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
     int ans=helper(coins,M,V);
     return ans;
	} 
	  
};