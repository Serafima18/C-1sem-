#include <iostream>
#include <functional>

class Fct {
public:
    using FunctionType = std::function<double(double)>;
    
    Fct(FunctionType func) : function(func) {}
    
    double evaluate(double x) {
        return function(x);
    }
    
private:
    FunctionType function;
};

int main() {
    Fct f([](double x) { return x * x; }); // пример с функцией x^2
    std::cout << "F(3) = " << f.evaluate(3) << std::endl;
    return 0;
}