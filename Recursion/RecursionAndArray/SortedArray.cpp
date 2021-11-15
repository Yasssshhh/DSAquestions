#include<iostream>
using namespace std;

bool is_sorted(int*arr,int size){
    
    //Base Case.
    if(size==0 || size==1){
        return true;
    }

    //Small Calculation.
    if(arr[0]>arr[1]){
        return false;
    }

    //Recursive Call.
    bool isSmallerSorted=is_sorted(arr+1,size-1);
    return isSmallerSorted;
}

int main(){
    int n;
    cout<<"Enter Size Of Array:";
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    cout<<is_sorted(arr,n);   
}