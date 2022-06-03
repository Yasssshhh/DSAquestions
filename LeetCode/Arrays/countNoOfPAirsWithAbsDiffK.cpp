// Given an integer array nums and an integer k, 
// return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]-k]){
                count+=mp[nums[i]-k];
            }
        }
        return count;
    }
};