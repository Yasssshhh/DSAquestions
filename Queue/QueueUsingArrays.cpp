#include<iostream>
using namespace std;

template<typename T>
class QueueUsingArray{

T*data;
int nextindex;  //to keep track where we will fill the data.
int firstindex; // index of front element.
// initially it will be -1 , but when we will insert 1 element,it will become zero,and after that it will be updated only on dequeue operation. 
int capacity;
int size;

public:
QueueUsingArray(int s){
    data=new T[s];
    nextindex=0;
    firstindex=-1;
    size=0;
    capacity=s;
}

int getsize(){
    return size;
}

bool isEmpty(){
    return size==0;
}

void enqueue(T element){
    if(size==capacity){
        cout<<"Queue is Full"<<endl;
        return;
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
    
    //Resetting orignal parameters if queue becomes empty.(not necessary)
    if(size==0){
        firstindex=-1;
        nextindex=0;
    }
    return ans;
}
};

int main(){
    QueueUsingArray<int> q(5);

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