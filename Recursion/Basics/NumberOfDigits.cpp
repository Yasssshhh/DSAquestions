#include<iostream>
using namespace std;

int count(int n){
    // Base Case
    if(n==0){
        return 0;
    }
    
    //Recursive Call
    int smallAns=count(n/10);

    //Small Calculation
    return smallAns+1;
}


int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    count(n);
}