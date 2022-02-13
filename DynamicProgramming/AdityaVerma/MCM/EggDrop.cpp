// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.


// Example 1:

// Input: k = 1, n = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1. If it breaks, we know that f = 0.
// Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// If it does not break, then we know f = 2.
// Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

// RECURSION
class Solution {
public:
    
    int helper(int k,int n){
        if(n==0 || n==1) return n;
        if(k==1) return n;
        
        int mn=INT_MAX;
        for(int i=1;i<=n;i++){
            int temp=1 + max(helper(k-1,i-1),helper(k,n-i));
            mn=min(mn,temp);
        }
        return mn;
    }
    
    
    int superEggDrop(int k, int n) {
        return helper(k,n);
    }
};


// MEMOIZATION

class Solution {
public:
    int dp[101][10001];
  
   int solve(int eggs,int floors){
        if(floors==0 || floors==1) return floors;
    
        else if(eggs==1) return floors;
    
        else if(dp[eggs][floors]!=-1) return dp[eggs][floors];
   
        else{
  
        //Using Binary Search
          int l=1,h=floors;
          int mn=INT_MAX;
          while(l<=h) {
              int mid=l+(h-l)/2;
              int a=solve(eggs-1,mid-1);
              int b=solve(eggs,floors-mid);
              int x=max(a,b) + 1;
              mn=min(mn,x);
              if(a>b) h=mid-1;
              else l=mid+1;
          }
         dp[eggs][floors]=mn;   
        }  
        return dp[eggs][floors];
    } 
    int superEggDrop(int K, int N) {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL); 
       memset(dp,-1,sizeof(dp)); 

       return solve(K,N);
    }
};