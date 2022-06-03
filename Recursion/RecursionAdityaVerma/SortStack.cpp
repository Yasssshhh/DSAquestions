#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void pushing(stack<int>& s,int temp){
    if(s.size()==0|| s.top()<=temp){
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    pushing(s,temp);
    s.push(val);
    
}

void sortStack(stack<int>& s){
    if(s.size()<=1){
        return;
    }
    int temp=s.top();
    s.pop();
    sortStack(s);
    pushing(s,temp);
    
}


void SortedStack :: sort()
{
  sortStack(s);
}