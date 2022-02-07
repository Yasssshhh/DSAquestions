// Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example 1:
// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11  

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	 
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	    bool t[n+1][sum+1];
	    for(int i=0;i<sum+1;i++)
	        t[0][i]=false;
	        for(int j=0;j<n+1;j++)
	            t[j][0]=true;
	            
	            for(int i=1;i<n+1;i++){
	                for(int j=1;j<sum+1;j++){
	                    if(arr[i-1]<=j){
	                        t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
	                    }else{
	                        t[i][j]=t[i-1][j];
	                    }
	                }
	            }
	            
	            int mn=INT_MAX;
	            for(int i=0;i<=sum/2;i++){
	                if(t[n][i]){
	                    mn=min(mn,sum-(2*i));
	                }
	            }
	            return mn;
	        }
};