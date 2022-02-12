// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
// Determine the fewest cuts needed for palindrome partitioning of given string.


// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".

//GFG
// Constraints:
// 1 ≤ length of str ≤ 500

class Solution{
public:

bool isPalindrome(string s, int i, int j){
       
       while(i<j){
           if(s[i]!=s[j]){
               return false;
           }
           i++;
           j--;
       }
       return true;
   }
   
   int helper(string s,int i, int j,int **dp){
       
       if(i>=j){
           return 0;
       }
       if(isPalindrome(s,i,j)==true){
           return 0;
       }
       
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       
       int ans=INT_MAX,left,right;
       for(int k=i;k<=j-1;k++){
           
           //checking for left sub-problem
           if(dp[i][k]!=-1){
               left=dp[i][k];
           }
           else{
               left=helper(s,i,k,dp);
               dp[i][k]=left;
           }
           
           //checking for right sub-problem
           if(dp[k+1][j]!=-1){
               right=dp[k+1][j];
           }
           else{
               right=helper(s,k+1,j,dp);
               dp[k+1][j]=right;
           }
           
           //now maintaining tempAns
           int t=1+left+right;
           ans=min(ans,t);
       }
       dp[i][j]=ans;
       return ans;
   }
   
   int palindromicPartition(string str)
   {
       // code here
       int n=str.length();
       int i=0,j=str.length()-1;
       
       int **dp=new int*[n+1];
       for(int i=0;i<=n;i++){
           dp[i]=new int[n+1];
           for(int j=0;j<=n;j++){
               dp[i][j]=-1;
           }
       }
       
       return helper(str,i,j,dp);
   }
};

//LEETCODE
// 1 <= s.length <= 2000

class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] !=a s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    
    int solve(string &s, int start, int end,vector<vector<int>> &dp) {
        
        if(dp[start][end] != -1) return dp[start][end];
        
        if(start >= end) return dp[start][end] = 0 ;
        
        if(isPalindrome(s,start,end) == true)
            return dp[start][end] = 0;
        
        int ans = INT_MAX;
        
        for(int ctr = start ; ctr < end ; ctr ++ ) {
            
            if(isPalindrome(s,start,ctr)==false)
                continue;
            
            int tempAns = solve(s,start,ctr,dp) + solve(s,ctr+1,end,dp) + 1;
            
            if(tempAns < ans) ans = tempAns;
        }
        
        return dp[start][end] = ans;
        
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
        return solve(s,0,s.length()-1,dp);
    }
};