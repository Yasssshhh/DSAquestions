//Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
//Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). 
//The idea here is to represent each array/list as an integer in itself of digits N and M.
//You need to find the sum of both the input arrays/list treating them as two integers and put the result in 
//another array/list i.e. output array/list will also contain only single digit at every index.

//The sizes N and M can be different. 
//Output array/list(of all 0s) has been provided as a function argument. 
//Its size will always be one more than the size of the bigger array/list.
//Place 0 at the 0th index if there is no carry. 

#include<iostream>
using namespace std;

void sumOfTwoArrays(int *arr1, int size1, int *arr2, int size2, int *output){
 
   int i=size1-1,j=size2-1;
   int carry=0;
   int k=0;
   
   if(size1 >size2){
       k=size1;
   }
    else{
       k=size2;
   }
    
   while(i>=0 && j>=0){
     
     int sum=arr1[i]+arr2[j]+carry;
     carry=sum/10;
     
     if(sum>9){
         output[k]=sum%10;
     }
      else{
          output[k]=sum;
      }
       i--;
       j--;
       k--;
     }
    while(i>=0){
        output[k]=arr1[i]+carry;
        i--;
        k--;
        carry=0;
     }
    while(j>=0){
        output[k]=arr2[j]+carry;
        j--;
        k--;
        carry=0;
    }
     output[0]=carry;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}