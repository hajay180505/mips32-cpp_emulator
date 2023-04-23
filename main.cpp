#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    Interpreter i("nakku.txt");
    i.executeInstructions();
    i.displayRegisters();

    // string s = "    li $t0,4\n";
    // vector<string> tok = tokenizer(strip(s),' ');
    // for (auto& word : tok){
    //     cout<< "::"<<word<<"::"<<endl;
    // }
    // string s = "This string has five words";
    // vector<string> tok = tokenizer(s,' ');
    // cout<<"Words :"<<endl;
    // for (auto& word : tok){
    //     cout<< word<<endl;
    // }
    // cout<<"WC = "<<wc(s)<<endl;
    // cout<<"Registers :"<<endl;
    // Registers r;
    // cout<<r;
        // cout<<endl<<"Changes :"<<endl;
        // cout<<r<<endl;
}