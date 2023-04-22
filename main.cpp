#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    // Interpreter i("nakku.txt");
    // i.executeInstruction();
    // i.displayRegisters();
    string s = "This string has five words";
    vector<string> tok = tokenizer(s,' ');
    cout<<"Words :"<<endl;
    for (auto& word : tok){
        cout<< word<<endl;
    }
    cout<<"WC = "<<wc(s)<<endl;
    
    }