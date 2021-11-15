#include <iostream>
using namespace std;

int sumOfDigits(int n) {
 
//Base Case.
if(n==0)
return 0; 

//Recursive Call.
int b=sumOfDigits(n/10);

//Small Calculation.
int a=n%10;
return a+b;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}