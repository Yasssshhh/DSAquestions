#include<iostream>
using namespace std;

template<typename T,typename V>

class Pair{
T x;
V y;

public:
void setX(T x){
    this->x=x;
}

void setY(V y){
    this->y=y;
}

T getX(){
    return x;
}

V getY(){
    return y;
}

};

int main(){

Pair<int,double> p1;
p1.setX(12);
p1.setY(21.19);

cout<<p1.getX()<<" "<<p1.getY()<<endl;
}