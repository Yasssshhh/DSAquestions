#include <iostream>
using namespace std;

//Approach 1
void sortZeroesAndOne(int*input, int size){

int count0=0,count1=0;
for(int i=0;i<size;i++){

if(input[i]==0){
count0++;
}
else{
count1++;    
}
}
    
for(int i=0;i<count0;i++){
        input[i]=0;
    }
for(int j=count0;j<size;j++){
        input[j]=1;
    }
}

//Approach 2
void sortZeroesAndOne(int *input, int size)
{
   int start = 0,end = size-1;
    while(start<end)
    {
        if(input[start]==0)
            start++;
        else if(input[end]==1)
            end--;
        else
        {
            swap(input[start],input[end]);
            start++;
            end--;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *input = new int[size];
    	for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);
    	for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}
	return 0;
}