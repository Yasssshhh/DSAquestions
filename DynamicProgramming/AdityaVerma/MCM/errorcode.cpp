class Solution{
public:


bool isPalindrome(string s,int i,int j){
        if(i>=j) return true;
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
}

int static dp[2005][2005];
int helper(string &s, int i, int j)
   {
    
    if(i >= j)
    return 0;
       
    if(isPalindrome(s,i,j)){
            return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int minn=INT_MAX;     
    for(int k=i;k<j;k++){
            int tempans=helper(s,i,k)+helper(s,k+1,j)+1;
            
           minn=min(minn,tempans);
    }
   return dp[i][j]=minn;
}

    
    int palindromicPartition(string str)
    {
        int n=str.size();
        memset(dp,-1,sizeof(dp));
        return helper(str,0,n-1);
    }
}


//gfg.
/tmp/ccBGSVzY.o: In function `Solution::helper(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, int, int)':
35536012311206fdefafc572004230ff.cpp:(.text._ZN8Solution6helperERNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii[_ZN8Solution6helperERNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii]+0xa1): undefined reference to `Solution::dp'
35536012311206fdefafc572004230ff.cpp:(.text._ZN8Solution6helperERNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.................


//leetcode.
ld.lld: error: undefined symbol: Solution::dp
>>> referenced by prog_joined.cpp
>>>               /tmp/prog_joined-135473.o:(Solution::minCut(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >))
>>> referenced by prog_joined.cpp
>>>               /tmp/prog_joined-135473.o:(Solution::helper(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, int, int))
>>> referenced by prog_joined.cpp
>>>               /tmp/prog_joined-135473.o:(Solution::helper(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, int, int))
>>> referenced 1 more times
clang-11: error: linker command failed with exit code 1 (use -v to see invocation)