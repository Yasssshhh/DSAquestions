#include<iostream>
using namespace std;

template<typename T>
class dynamicQueue{
T*data;
int nextindex;
int firstindex;
int size;
int capacity;

public:
dynamicQueue(){
    data=new int[5];
    nextindex=0;
    firstindex=-1;
    size=0;
    capacity=5;
}

int getsize(){
    return size;
}

bool isEmpty(){
    return size==0;
}

void enqueue(T element){
    if(size==capacity){
        T*newdata=new T[2*capacity];

        int j=0;
        for(int i=firstindex;i<capacity;i++){
            newdata[j]=data[i];
            j++;
        }
        for(int i=0;i<firstindex;i++){
            newdata[j]=data[i];
            j++;
        }
    delete[] data;
    data=newdata;
    firstindex=0;
    nextindex=capacity;
    capacity*=2;
    }
    data[nextindex]=element;
    nextindex=(nextindex+1)%capacity;
    if(firstindex==-1){
        firstindex=0;
    }
    size++;
}

T front(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return 0;
    }
    return data[firstindex];
}

T dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return 0;
    }

    T ans=data[firstindex];
    firstindex=(firstindex+1)%capacity;
    size--;
    
    if(size==0){
        firstindex=-1;
        nextindex=0;
    }
    return ans;
}
};


int main(){
    dynamicQueue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);


    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;

}