#include<iostream>
#include<climits>
using namespace std;

class stackusingarray{
int*data;
int nextIndex;
int capacity;

public:
stackusingarray(int totalsize){
    data=new int[totalsize];
    nextIndex=0;
    capacity=totalsize;
}

int size(){
    return nextIndex;
}

bool isEmpty(){
    return nextIndex==0;
}

void push(int element){
    if(nextIndex==capacity){
        cout<<"Stack Full"<<endl;
        return;
    }
    data[nextIndex]=element;
    nextIndex++;
}

int pop(){
    if(isEmpty()){
        cout<<"Stack Empty"<<endl;
        return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
}

int top(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    return data[nextIndex-1];
}
};


int main(){
    stackusingarray s(4);
    s.push(10);
    s.push(50);
    s.push(100);
    s.push(150);
    s.push(200);

cout<<s.top()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.size()<<endl;
cout<<s.isEmpty()<<endl;
}