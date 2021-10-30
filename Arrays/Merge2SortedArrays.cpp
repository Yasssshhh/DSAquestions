#include<iostream>
using namespace std;

void merge(int*arr1,int m,int*arr2,int n,int*arr){
int i=0,j=0,k=0;

while(i < m && j<n){

if(arr1[i]<arr2[j]){
    arr[k]=arr1[i];
    k++;
    i++;
}

else{
arr[k]=arr2[j];
j++;
k++;
}

}
while(i < m){
    arr[k++]=arr1[i++];
}
while(j < n){
    arr[k++]=arr2[j++];
}
}


int main(){

int m;
cout<<"Enter size of 1st array:";
cin>>m;

int*arr1=new int[m];
for(int i=0;i<m;i++){
    cin>>arr1[i];
}

int n;
cout<<"Enter size of 2nd array:";
cin>>n;

int*arr2=new int[n];
for(int j=0;j<n;j++){
    cin>>arr2[j];
}

int*arr=new int[m+n];
merge(arr1,m,arr2,n,arr);

for(int k=0;k<m+n;k++){
cout<<arr[k]<<" ";
}
}