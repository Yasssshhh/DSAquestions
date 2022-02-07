// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.


// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

class Solution {
public:
    
// j loop starts from 0 because, 0 can be used to form subsets too.
// Let us take an example to understand:
// arr : [0,0] target: 0 => (target+range)/2 = 0
// We can have 4 subsets here {0}(1st),{0}(2nd),{0,0},{}
// But if we start the jth loop from 1 instead of 0 we would just get 1 subset, ie, the empty subset {} (based on our initialization)
    
   int number_subsets(vector<int>& nums, int sum){
        int n = nums.size();
        int dp[n+1][sum+1];
        
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=sum; j++){  
                if(nums[i-1]<=j ) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else if(nums[i-1]>j) dp[i][j]  = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     
        int range = 0; 
        for(auto x : nums) range += x;
        target = abs(target);
        if(target>range or (target+range)%2 != 0) return 0;
        
        return number_subsets(nums,(target+range)/2);
        
    }
};