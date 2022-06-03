#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(string s,string output){
    if(s.size()==0){
    cout<<output<<endl;
    return;
    }

    string op1=output;
    string op2=output;

    op1.push_back(s[0]);
    op2.push_back(toupper(s[0]));
    s.erase(s.begin()+0);

    solve(s,op1);
    solve(s,op2);

}

int main(){
    string s="ab";
    string output;
    solve(s,output);
    return 0;
}