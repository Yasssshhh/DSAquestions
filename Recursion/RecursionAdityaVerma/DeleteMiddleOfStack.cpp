#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

stack<int> solve(stack<int> &s,int k){
       if(k==1){
           s.pop();
           return s;
       }
       int temp=s.top();
       s.pop();
       solve(s,k-1);
       s.push(temp);
       return s;
   }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
          int mid;
       if(sizeOfStack%2==0){
           mid=ceil(sizeOfStack/2.0)+1;
       }
       else{
           mid=ceil(sizeOfStack/2.0);
       }
       solve(s,mid);
        // code here.. 
    }
};