#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    Interpreter i("assembly.txt");
    i.executeInstructions();
    i.displayRegisters();
}