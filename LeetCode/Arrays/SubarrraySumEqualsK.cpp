//560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum
// equals to k.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_map<int,int> mymap;
        int currSUM=0;
        int count=0;
        int i=0;
        while(i<n){
            currSUM+=nums[i];
            
            if(currSUM==k){
                count++;
            }
            if(mymap.find(currSUM-k)!=mymap.end()){
                count+=mymap[currSUM-k];
            }
            mymap[currSUM]+=1;
            i++;
        }
        return count;
    }
};