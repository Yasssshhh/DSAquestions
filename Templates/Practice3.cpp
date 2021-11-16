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

Pair<Pair<int ,int>,char> p2;
p2.setY('a');

Pair<int,int> p4;
p4.setX(15);
p4.setY(20);
p2.setX(p4);

cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;
}

