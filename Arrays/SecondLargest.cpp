//You have been given a random integer array/list(ARR) of size N. 
//You are required to find and return the second largest element present in the array/list.
//If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31.

//Input:
// 7
// 2 13 4 1 3 6 28

//Output: 13

#include<iostream>
#include<climits>

using namespace std;

//First Approach
int secondLargest(int*input,int size){
int max=INT_MIN;
for(int i=0;i<size;i++){
if(input[i]>max){
    max=input[i];
}
}
int secondmax=INT_MIN;
for(int j=0;j<size;j++){
    if(input[j]>secondmax && input[j] <max){
        secondmax=input[j];
    }
}
return secondmax;
}


// Second Approach
int secondLargest(int*arr,int size){
    
int max=INT_MIN;
int secondmax=INT_MIN;
 
for(int i=0;i<size;i++){

    if(arr[i]>max){
        secondmax=max;
        max=arr[i];
    }
    else if(arr[i]>secondmax && arr[i] !=max){
        secondmax=arr[i];
    }
    
}
return secondmax;
}

int main()
{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << secondLargest(input, size) << endl;

		delete[] input;

	return 0;
}