#include <iostream>

int main(){

    [](){
        std::cout << "Hello C++ lambda" << std::endl;
    }
    ();

    auto sum = [](double A, double B) {return A+B;};

    auto sum2 = [](double A, double B) -> double {return A+B;};

    std::cout << sum(3.25 + 5.44) << std::endl;
    std::cout << sum2(3.25 + 5.44) << std::endl; 

    double pi = 3.1416;

    auto func = [](double pi){
        std::cout << "The value of pi is: " << pi << std::endl;
    };
    func(pi);

    auto func2 = [pi](){
        std::cout << "The value of pi is: " << pi << std::endl;
    };
    func2();

    auto gene_lambda = [](auto arg) {return arg + arg;};

    std::cout << gene_lambda(5) << std::endl;
    std::cout << gene_lambda(3.1416) << std::endl;

    return 0;
}