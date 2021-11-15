#include<iostream>
#include<cstring>
using namespace std;

bool helper(char input[],int start,int end){

//Base case.
if(end<start){
    return true;
}

//Small Calculation
if(input[start]!=input[end]){
    return false;
}

//Recursive Call.
bool ans =helper(input,start+1,end-1);
return ans;
}

bool checkPalindrome(char input[]){
    int start=0;
    int end =strlen(input)-1;
    return helper(input,start,end);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
