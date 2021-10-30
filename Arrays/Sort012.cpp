#include<iostream>
using namespace std;

//Approach 1.
void sort012(int arr[],int n){

int count0=0;
int count1=0;
int count2=0;

for(int i=0;i<n;i++){
if(arr[i]==0){
count0++;
}
else if(arr[i]==1){
count1++;
}
else{
count2++;
}
}

int k=0;
for(;k<count0;k++){
    arr[k]=0;
}
for(int j=0;j<count1;j++){
    arr[k]=1;
    k++;
}
for(;k<count2;k++){
    arr[k]=2;
}
}

int main()
{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;

	return 0;
}