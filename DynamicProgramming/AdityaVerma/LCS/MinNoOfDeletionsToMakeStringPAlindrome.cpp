// Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
// Note: The order of characters should be maintained.

// Example 1:

// Input: n = 7, str = "aebcbda"
// Output: 2
// Explanation: We'll remove 'e' and
// 'd' and the string become "abcba".


int minDeletions(string str, int n) {  
   string x = str;
   reverse(str.begin(),str.end());
   string y = str;
    
   int t[n+1][n+1];
   for(int i=0;i<n+1;i++)
       for(int j=0;j<n+1;j++){
           if(i == 0 || j == 0) t[i][j] = 0;
           else if(x[i-1] == y[j-1]) t[i][j] = 1 + t[i-1][j-1];
           else t[i][j] = max(t[i-1][j],t[i][j-1]);
       }
        
   return n-t[n][n];
}