#include "CalculatorImp.h"

void CalculatorImp::initialize()
{}

void CalculatorImp::destroy()
{}

tars::Int32 CalculatorImp::add(
    tars::Int32 left,
    tars::Int32 right,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    return left + right;
}