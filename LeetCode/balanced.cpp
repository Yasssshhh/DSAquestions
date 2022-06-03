#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> answer;


void helper(int close,int open, string output){
    if(close==0 && open==0){
        answer.push_back(output);
        return;
    }

    if(open!=0){
        string op1=output;
        op1.push_back('(');
        helper(close,open-1,op1);
    }
    else if(close>open){
        string op2=output;
        op2.push_back(')');
        helper(close-1,open,op2);
    }
}

void generateParenthesis(int n){

int close=n;
int open=n;
string output="";
helper(close,open,output);

}


int main()
{
    cout<<"Enter Size:"<<endl;
    int n;
    cin>>n;
    generateParenthesis(n);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<< " ";
    }

}