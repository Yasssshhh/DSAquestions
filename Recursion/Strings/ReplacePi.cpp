#include<iostream>
#include<cstring>
using namespace std;

void replacePi(char input[]){
    if(strlen(input)<=1){
        return;
    }
    if(strlen(input)>=2 && input[0]=='p' && input[1]=='i'){
        int count=0,i=0;
        while(input[i]!='\0'){
            count++;
            i++;
        }
        for(int i=count+1;i>=2;i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';

        replacePi(input+4);
    }
    else{
        replacePi(input+1);
    }
}

int main(){
    char input[1000];
    cin.getline(input,1000);
    replacePi(input);
    cout<<input<<endl;
}