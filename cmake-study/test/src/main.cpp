#include "message.h"
#include <iostream>
#include <string>

int main(){
    std::string message = buildMessage("石器时代");
    std::cout << message  << std::endl;
    return 0;
}