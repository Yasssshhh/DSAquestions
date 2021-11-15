// Input 1 :0                     Output 1:1
// Input 2:000010204              Output 2:2

#include<iostream>
using namespace std;

int countZeroes(int n){
    
    //Base Case.
    if(n<9){
        if(n==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Small Calculation.
    int count=0;
    int last=n%10;
    
    if(last==0){
        count=1;
    }

    //Recursive Call
    int smallAns=countZeroes(n/10);

    return count+smallAns;
}


int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    cout<<countZeroes(n)<<endl;
}