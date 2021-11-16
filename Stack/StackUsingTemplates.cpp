#include<iostream>
#include<climits>
using namespace std;

template<typename T>
class stackusingarray{
T*data;
int nextIndex;
int Capacity;

public:
stackusingarray(){
data=new T[4];
nextIndex=0;
Capacity=4;
}

int size(){
    return nextIndex;
}

bool isEmpty(){
    return nextIndex==0;
}

void push(T element){
    if(nextIndex==Capacity){
        T*newData=new T[2*Capacity];  //new array with double Capacity.
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

T pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
}

T top(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    return data[nextIndex-1];
}
};


int main(){
    stackusingarray<int>S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    S.push(9);
    S.push(10);

cout<<S.top()<<endl; //10
cout<<S.pop()<<endl; //10
cout<<S.pop()<<endl; //9
cout<<S.top()<<endl; //8
cout<<S.size()<<endl;//8
cout<<S.pop()<<endl; //8
cout<<S.pop()<<endl; //7
cout<<S.pop()<<endl; //6
cout<<S.top()<<endl; //5 
cout<<S.size()<<endl;//5
cout<<S.isEmpty()<<endl;//0
}