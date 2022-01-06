//238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> output;
        if(n==0){
            return output;
        }
        
        int product=1;
        for(int i=0;i<n;i++){
            product*=nums[i];
            output.push_back(product);
        }
        
        product=1;
        for(int i=n-1;i>0;i--){
            output[i]=output[i-1]*product;
            product*=nums[i];
        }
        output[0]=product;
        return output;
    }
};