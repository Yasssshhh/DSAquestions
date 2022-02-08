//Given two strings X and Y of lengths m and n respectively, 
//find the length of the smallest string which has both, X and Y as its sub-sequences.

// Example 1

// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.

class Solution
{
    public:
    
    int LCS(string X,string Y,int x,int y){
        int t[x+1][y+1];
        
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                t[i][j]=0;
                
                else if(X[i-1]==Y[j-1])
                t[i][j]=1+t[i-1][j-1];
                
                else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[x][y];
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int ans=m+n-LCS(X,Y,m,n);
        return ans;
    }
};