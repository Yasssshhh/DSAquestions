//You have been given a random integer array/list(ARR) of size N.
// Write a function that rotates the given array/list by D elements(towards the left).

// Input:
// 7
// 1 2 3 4 5 6 7
// 2
//Output:
//3 4 5 6 7 1 2

#include<iostream>
using namespace std;
//Approach 1
int reverse(int*input,int i,int j){
    
    while(i<=j){
        int temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void rotate(int *input, int d, int n)
{
    reverse(input,0,n-1);
    reverse(input,0,n-d-1);
    reverse(input,n-d,n-1);
}
  

int main()
{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;

	return 0;
}