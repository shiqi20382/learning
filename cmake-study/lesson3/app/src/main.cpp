#include <iostream>
#include <string>
#include "greeter.h" 

int  main(){
    const std::string message = makeGreeting("石器时代");
    std::cout << message;
    return 0;
}