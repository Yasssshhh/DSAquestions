// Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

// Example 1:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y 
// 0 1 2 3 4

// The longest subsequence is "xx". 
// It appears twice as explained below.

class Solution {
	public:
	
	int LCS(string X,string Y,int x,int y){
        int t[x+1][y+1];
        
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                t[i][j]=0;
                
                else if(X[i-1]==Y[j-1] && i!=j)
                t[i][j]=1+t[i-1][j-1];
                
                else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[x][y];
    }
		int LongestRepeatingSubsequence(string str){
		    return LCS(str,str,str.size(),str.size());
		}

};