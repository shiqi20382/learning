#include <iostream>     
#include "greeter.h" 

int main(){
    std::string message = makeGreeting("石器时代");

    std::cout << message << std::endl;

    return 0;
}