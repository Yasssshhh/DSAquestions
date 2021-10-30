//You have been given an integer array/list(ARR) of size N.
//It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
//Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

//Input:
// 1
// 6
// 5 6 1 2 3 4

//Output:2

#include<iostream>
using namespace std;

int checkArrayRotation(int *arr, int n)
{
    int index = 0;
    for(int i = 0; i < n-1; i++) {  
        if(arr[i+1] < arr[i]){
            index = i+1;
            break;
        }   
    }
    return index;
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

		cout << checkArrayRotation(input, size) << endl;
		delete[] input;
	
	return 0;
}