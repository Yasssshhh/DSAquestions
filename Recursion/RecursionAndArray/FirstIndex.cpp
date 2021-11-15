#include<iostream>
using namespace std;

int firstIndex(int*arr,int n ,int x){
    
    //Base Case.
    if(n==0){
        return -1;
    }
    
    //Small Calculation.
    if(x==arr[0]){
        return 0;
    }

    //Recursive Call.
    int smallWork=firstIndex(arr+1,n-1,x);

    if(smallWork != -1){
        return smallWork+1;
    }
    else{
        return -1;
    }
}

int main(){
     int n;
    cout<<"Enter Size Of Array:";
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    int x;
    cin>>x;

    cout<<firstIndex(arr,n,x)<<endl;
}