#include<iostream>
using namespace std;

//Approach 1
int findDuplicate(int*arr,int n){
    int i=0;    
    while(i<n-1){
        int j=i+1;
        while(j<n){
            if(arr[i]==arr[j])
                return arr[i];
            j++;
        }
        i++;
    }
    return -1;
}
//Approach 2

int main(){
    int n;
    cin>>n;
    int*arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>n;
    }
    cout<<findDuplicate(arr,n);
}