//You have been given a random integer array/list(ARR) of size N. 
//You have been required to push all the zeros that are present in the array/list to the end of it. 
//Also, make sure to maintain the relative order of the non-zero elements.

//Input: 2 0 0 1 3 0 0
//Output:2 1 3 0 0 0 0

#include<iostream>
using namespace std;

//Approach 1
void pushZeroestoEnd(int *arr, int size)
{
int i=0;
int j=i+1;
    
while(j<size){
    if(arr[i]==0 &&  arr[j]==0){
        j++;
    }
    else if(arr[i]==0 && arr[j] !=0){
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        i++;
        j++;
    }
    else{
        i++;
        j++;
    }
}    
}

//Approach 2
// void pushZeroestoEnd(int *input, int size)
// {

// int nonZero = 0; 
// for (int i = 0; i < size; i++) { 
//     if (input[i] != 0) {
//         int tmp = input[i];
//         input[i] = input[nonZero];
//         input[nonZero] = tmp; 
//         nonZero++;
//     }
// }    
// } 
    
   


int main()
{
		int size;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroestoEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;

	return 0;
}