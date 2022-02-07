//Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
//Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:
// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
// sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10}


// Test case that won't work
// i/p:
// 9 1
// 0 0 0 0 0 0 0 0 1
// because normal problem doesn't deal with multiple zeros 

// so we need to keep a count of zeros and 
// add 2^count_of_zeros -1  
// becase with the zeros 2^count_of_zeros -1   extra combinations will be formed.
// here is the code


// To counter multiple zeroes, just change these 3 lines, easiest solution!!
// 1st calculate number of zeroes
// 2nd exclude calculation when arr[i-1]==0 
// 3rd multiply normal answer(without zeroes) with 2^zeroes.



class Solution{
public:
	int perfectSum(int arr[], int n, int sum)
	{
        long long dp[n+1][sum+1];
        long long mod=1e9+7;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            zero++;
        }
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        for(int i=1;i<=sum;i++)
        dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j && arr[i-1]!=0)
                {
                    dp[i][j]=((dp[i-1][j]%mod)+(dp[i-1][j-arr[i-1]]%mod))%mod;
                }
                else
                dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return pow(2,zero)*dp[n][sum]; 
	}
	  
}; 