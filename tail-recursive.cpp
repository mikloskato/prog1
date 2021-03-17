#include <iostream>

using namespace std;

unsigned factorial_TR(int x, int y){
    if (x==0){
        return y;
    };

    return factorial_TR(x-1, y*x);
}

unsigned int factorial(int x){
    return factorial_TR(x,1);
}


int main() {
    
    cout << factorial(3) << endl;
    return 0;
}