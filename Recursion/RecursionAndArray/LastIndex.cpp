#include<iostream>
using namespace std;

int lastIndex(int*arr,int size,int x){
    
    if(size==0){
        return -1;
    }
    
    int smallWork=lastIndex(arr+1,size-1,x);

    if(smallWork == -1){
        if(x==arr[0]){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return smallWork+1;
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

    cout<<lastIndex(arr,n,x)<<endl;
}