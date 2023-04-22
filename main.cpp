#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    Interpreter i("nakku.txt");
    // i.executeInstruction();
    // i.displayRegisters();
    string s = "This string has five words";
    vector<string> tok = tokenizer(s,' ');
    cout<<"Words :"<<endl;
    for (auto& word : tok){
        cout<< word<<endl;
    }
    cout<<"WC = "<<wc(s)<<endl;
    cout<<"Registers :"<<endl;
    Registers r;
    cout<<r;
    cout<<endl<<"Changes :"<<endl;
    r("t0",100);
    r("t1",r["t0"]);
    r("s7",99);
    cout<<r<<endl;
}