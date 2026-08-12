#include "message.h"
#include<string>

std::string buildMessage(const std::string& name){
    return "欢迎学习 CMake," + name +"!";
}