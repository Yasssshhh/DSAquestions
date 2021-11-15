//Fib(n)=Fib(n-1)+Fib(n-2);
//0 1 1 2 3 5 8 13 21

#include<iostream>
using namespace std;

int fib(int n){

    //Base Case.
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    //Recursive Call.
    int smallOutput1=fib(n-1);
    int smallOutput2=fib(n-2);

    return smallOutput1 + smallOutput2;
}

int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    cout<<fib(n)<<endl;
}