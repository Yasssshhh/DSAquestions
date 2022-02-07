//Given two strings. The task is to find the length of the longest common substring.

// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.

class Solution{
    public:
 
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int t [n+1][m+1];
       
        for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            
            int mx=0;
            
            if(i==0){
            t[i][j]=0;
            }
            else if(j==0){
            t[i][j]=0;
            }
            else if(S1[i-1]==S2[j-1]){
            t[i][j]=1+t[i-1][j-1] ;
            }
            else{
            t[i][j]=0;
            }
        }
    }
        int ans=INT_MIN;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                ans=max(ans,t[i][j]);
            }
        }
        return ans;
    }
};