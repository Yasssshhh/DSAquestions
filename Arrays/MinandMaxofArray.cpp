#include <iostream>
#include<climits>
using namespace std;

int main() {
int n;
cout<<"Enter number of elements:"<<endl;
cin>>n;

int*arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int min=INT_MAX;
int max=INT_MIN;

for(int i=0;i<n;i++){
    if(arr[i]<min){
        min =arr[i];
    }
}

for(int i=0;i<n;i++){
    if(arr[i]>max){
        max =arr[i];
    }
}


cout<<min<<endl;
cout<<max<<endl;

return 0;
}