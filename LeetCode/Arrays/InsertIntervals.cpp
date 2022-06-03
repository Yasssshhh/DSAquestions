Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]

//Solution 01
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        temp=intervals[0];
        
        for(auto it:intervals){
            if(temp[1]>=it[0]){
                temp[1]=max(temp[1],it[1]);
            }else{
                ans.push_back(temp);
                temp=it;
            }
        }
         ans.push_back(temp);
        return ans;
    }
};

//Solution 02
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        for(int i = 0; i <= intervals.size(); i++){
            if(i ==intervals.size()){
                intervals.push_back(newInterval);
            }
            if(intervals[i][0] >= newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        
        vector<vector<int>> ans;
        vector<int> temp;
        temp=intervals[0];
        
        for(auto it:intervals){
            if(temp[1]>=it[0]){
                temp[1]=max(temp[1],it[1]);
            }else{
                ans.push_back(temp);
                temp=it;
            }
        }
         ans.push_back(temp);
        return ans;
    }
};