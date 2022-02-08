// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some
//or no elements without changing the order of the remaining elements.

 
// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string w=s;
        reverse(s.begin(),s.end());
        int m=s.size();
        int dp[m+1][m+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
               if(s[i-1]==w[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[m][m];
    }
};