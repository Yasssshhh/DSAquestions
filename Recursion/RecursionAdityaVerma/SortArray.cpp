#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& vect,int temp){

    if(vect.size()==0 || vect[vect.size()-1]<=temp){
      vect.push_back(temp);
      return;
    }

    int val=vect[vect.size()-1];
    vect.pop_back();
    insert(vect,temp);
    vect.push_back(val);
    return;
}


void sort_array(vector<int>& vect){

    if(vect.size()<=1){
        return;
    }
    //we cannot put first element of array in temp ,because we are popping array from back.
    int temp=vect[vect.size()-1];
    vect.pop_back();
    sort_array(vect);
    insert(vect,temp);
}

int main(){
    
    
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(1);
    vect.push_back(10);
    vect.push_back(0);

    sort_array(vect);
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    return 0;

}