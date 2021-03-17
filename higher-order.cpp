#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    transform(v.begin(), v.end(), v.begin(),

        [](int n) {return n + (n * 2);}
    );

    for_each(v.begin(), v.end(),
        [](const int&x) {cout << x << endl;}

    );

    return 0;
}