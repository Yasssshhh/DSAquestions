// Given two strings str1 and str2. The task is to remove or insert the minimum number of 
// characters from/in str1 so as to transform it into str2. 
//It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Example 1:

// Input: str1 = "heap", str2 = "pea"
// Output: 3

class Solution{
		
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
	 
	int minOperations(string str1, string str2) 
	{ 
	    int x=str1.size();
	    int y=str2.size();
	    
	    return x+y-2*LCS(str1,str2,x,y);
	} 
};