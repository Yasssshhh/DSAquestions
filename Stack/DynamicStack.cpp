#include<iostream>
#include<climits>
using namespace std;

class stackusingarray{
int*data;
int nextIndex;
int Capacity;

public:
stackusingarray(){
data=new int[4];
nextIndex=0;
Capacity=4;
}

int size(){
    return nextIndex;
}

bool isEmpty(){
    return nextIndex==0;
}

void push(int element){
    if(nextIndex==Capacity){
        int *newData=new int[2*Capacity];  //new array with double Capacity.
        for(int i=0;i<Capacity;i++){
            newData[i]=data[i];   //Copying previous elements in new array.
        }
        Capacity=2*Capacity;  //Capacity doubled.
        delete[] data;
        data=newData;  //data will point to new data.
    }
    data[nextIndex]=element;
    nextIndex++;
}

int pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
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
    stackusingarray S;
    S.push(10);
    S.push(50);
    S.push(100);
    S.push(150);
    S.push(200);

cout<<S.top()<<endl;
cout<<S.pop()<<endl;
cout<<S.pop()<<endl;
cout<<S.pop()<<endl;
cout<<S.size()<<endl;
cout<<S.isEmpty()<<endl;
}