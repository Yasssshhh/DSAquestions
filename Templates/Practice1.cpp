#include<iostream>
using namespace std;


//Without Templates
// class Pair{
//     int x;
//     int y;

//     public:
//     void setX(int x){
//         this->x=x;
//     }

//     void setY(int y){
//         this->y=y;
//     }

//     int getX(){
//         return x;
//     }
//     int getY(){
//         return y;
//     }
// };

// int main(){
// Pair P1;
// P1.setX(100);
// P1.setY(200);

// cout<<P1.getX()<<endl;
// cout<<P1.getY()<<endl;
// }


//With Templates
template<typename T>

class Pair{
T x;
T y;

public:
void setX(T x){
    this->x=x;
}

void setY(T y){
    this->y=y;
}

T getX(){
    return x;
}

T getY(){
    return y;
}

};

int main(){

Pair<int> p1;
p1.setX(12);
p1.setY(21);

cout<<p1.getX()<<" "<<p1.getY()<<endl;
}