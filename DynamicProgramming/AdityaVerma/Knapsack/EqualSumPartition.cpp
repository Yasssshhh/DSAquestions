// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that the sum of elements
// in both subsets is equal.

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

class Solution {
public:
    
    bool subsetSum(vector<int>& nums,int n,int sum){

        vector<vector<bool>> t(n+1,vector<bool> (sum+1));
        
        for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
                
               if(j==0)
               t[i][j]=true;
               else if(i==0)
               t[i][j]=false;
               else if(nums[i-1]<=j)
               {
                   t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
               }
               else
               t[i][j]=t[i-1][j];
        
      }
    }
        return t[n][sum];
}

    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
       
        return subsetSum(nums,n,sum/2);
    }
};