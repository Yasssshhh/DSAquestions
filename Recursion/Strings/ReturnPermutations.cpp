#include <string>
using namespace std;

int returnPermutations(string input, string output[]){

if(input.size()==0){
    output[0]=" ";   
    return 1;
}

    string smalloutput[1000];
    int smallsize=returnPermutations(input.substr(1),smalloutput);
    
    int k=0;
    for(int i=0;i<smallsize;i++){
        for(int j=0;j<smalloutput[i].length();j++){
            output[k++]=smalloutput[i].substr(0,j)+input[0]+smalloutput[i].substr(j);
        }
    }
    
    return k;
}