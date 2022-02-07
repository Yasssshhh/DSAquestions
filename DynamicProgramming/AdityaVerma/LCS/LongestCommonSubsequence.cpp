// Given two sequences, find the length of longest subsequence present in both of them. 
// Example 1:

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH” of
// length 3.

//RECURSIVE CODE
class Solution {
public:
    
    int helper(string text1,string text2, int n,int m){
        if(n==0 ||m==0){
            return 0;
        }
        if(text1[n-1]==text2[m-1]){
            return 1+ helper(text1,text2,n-1,m-1);
        }
        else{
            return max(helper(text1,text2,n-1,m),helper(text1,text2,n,m-1));
        }
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        return helper(text1,text2,n,m);
    }
};

//MEMOIZATION

class Solution
{
    public:
     int t [1001][1001];
     
    //Function to find the length of longest common subsequence in two strings.
    int helper(string s1,string s2,int x,int y){
      
    if(x==0||y==0) 
    return 0;
    
    if(t[x][y]!=-1)
    return t[x][y];
    
    if(s1[x-1]==s2[y-1]){
        return t[x][y]=1+helper(s1,s2,x-1,y-1);
    }else{
        return t[x][y]=max(helper(s1,s2,x-1,y),helper(s1,s2,x,y-1));
    }
     
    }
    
    
    int lcs(int x, int y, string s1, string s2)
    {
       memset(t,-1,sizeof(t));
       return helper(s1,s2,x,y);
    }
};

//TABULATION

class Solution
{
    public:
    int t [1001][1001];
     
    int helper(string s1,string s2,int x,int y){
      
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            
            if(i==0){
            t[i][j]=0;
            }
            else if(j==0){
            t[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
            t[i][j]=1+t[i-1][j-1] ;  
            }
            else{
            t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
     return t[x][y];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
       return helper(s1,s2,x,y);
    }
};