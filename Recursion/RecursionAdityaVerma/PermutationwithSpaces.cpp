class Solution{
public:
    void solve(vector<string>&ans,string S,string op){
    if(S.size()==0)
   {
       ans.push_back(op);
       return;
   }
   string op1=op;
   string op2=op;
   op1.push_back(' ');
   op1.push_back(S[0]);
   op2.push_back(S[0]);
   S.erase(S.begin()+0);
   solve(ans,S,op1);
   solve(ans,S,op2);
   
}

    vector<string> permutation(string S){
        
     string op="";
     op.push_back(S[0]);
     S.erase(S.begin()+0);
     vector<string>ans;
     solve(ans,S,op);
     return ans;
    }
};
