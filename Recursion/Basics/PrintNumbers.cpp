#include<iostream>
using namespace std;

void print(int n){
    
    // Base Case
    if(n==0){
        return;
    }

    //Recursive Call
    print(n-1);

    //Small Calculation
    cout<<n<<" "<<endl;
}

int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    print(n);
}