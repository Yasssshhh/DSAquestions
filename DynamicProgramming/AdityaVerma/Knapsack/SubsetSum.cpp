// Given an array of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum. 

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1 
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
       bool t[N+1][sum+1];
       for(int i=0;i<=N;i++)
       for(int j=0;j<=sum;j++)
       {
           if(i==0)t[i][j]= false;
           if(j==0)t[i][j]=true;
       }
       for(int i=1;i<=N;i++)
       for(int j=1;j<=sum;j++)
       {if(arr[i-1]<=j)
           t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
       else
           t[i][j]=t[i-1][j];
       }
       return t[N][sum];
    }
};