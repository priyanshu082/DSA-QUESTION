#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 2);
        std::cout << "Result: " << result << std::endl;
         
        result = divide(8, 0); // This will throw an exception
        std::cout << "Result: " << result << std::endl; // This won't be executed

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
