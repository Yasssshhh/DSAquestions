  class Solution{
    public:
    void dfs(int x, int y, string current_path, vector<string> &ans, vector<vector<int>> m, int n){
         if(x < 0 || x == n || y < 0 || y == n || m[x][y] != 1){
            return;
        }
        
        if(x == n-1 && y == n-1){
                ans.push_back(current_path);
       
            return;
        }
         
        m[x][y] = -1;
        dfs(x-1,y,current_path + "U",ans,m,n);
        dfs(x,y-1,current_path + "L",ans,m,n);
        dfs(x+1,y,current_path + "D",ans,m,n);
        dfs(x,y+1,current_path + "R",ans,m,n);
        m[x][y] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
    
        dfs(0,0,"",ans,m,n);    
        return ans;
    }
};