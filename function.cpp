#include <iostream>
#include <functional>

using namespace std;

int sum (int x, int y){
    return x + y;
}

struct add_x {
    add_x(int val) : x(val) {}
    int operator() (int y) const {return x + y;}

private:
    int x;
};

int main() {


    add_x add42(42);
    int j = add42(34);
    int i = add42(2);

    cout << i << endl;
    cout << j << endl;

    function <int(int, int)> func;

    func = sum;

    cout << func(5,7) << endl;

    function <double(double,double)> sum3 = [](double A, double B) {return A+B;};
}


