// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Example 1:
// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates 
// to true in 4 ways ((T|T)&(F^T)), 
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function 
// countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

class Solution{
public:
  int mod=1003;
  unordered_map<string,int> mp;
   int helper(string S,int i,int j,bool istrue){
       if(i>j) return 0;
       if(i==j){
           if(istrue==true)
           return S[i]=='T';
           
           else
           return S[i]=='F';
       }
       
       string temp=to_string(i)+" "+to_string(j)+" "+to_string(istrue);
       if(mp.find(temp)!=mp.end()){
           return mp[temp];
       }
       
       int ans=0;
       for(int k=i+1;k<=j-1;k=k+2){
           int lt=helper(S,i,k-1,true);
           int lf=helper(S,i,k-1,false);
           int rt=helper(S,k+1,j,true);
           int rf=helper(S,k+1,j,false);
           
           if(S[k]=='&'){
               if(istrue==true)
               ans=ans+lt*rt;
               else
                ans+=lf*rt+lf*rf+lt*rf;
           }
           else if(S[k]=='|'){
               if(istrue==true)
                   ans+=lt*rt+lt*rf+lf*rt;
               else
               ans+=lf*rf;
           }
           else if(S[k]=='^'){
               if(istrue==true)
                   ans+=lf*rt+lt*rf;
               else
               ans+=lt*rt+lf*rf;
           }
       }
       return mp[temp]=ans % mod;
   }

    int countWays(int N, string S){
        int i=0;
        bool istrue=true;
        
        return helper(S,i,N-1,istrue);
    }
};