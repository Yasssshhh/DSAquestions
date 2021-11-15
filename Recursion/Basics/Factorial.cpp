#include<iostream>
using namespace std;

int factorial(int n){

// Base Case
if(n==0){
    return 1;
}

//Recursion
int smallOutput = factorial(n-1);

//Small Calculation
int output=n*smallOutput;
return output;
}


int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    cout<<factorial(n);
}