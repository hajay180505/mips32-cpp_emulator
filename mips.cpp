#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

OneParameterInstruction::OneParameterInstruction(const string& s, Registers& r){


}
void OneParameterInstruction::execute(){

}

TwoParameterInstruction::TwoParameterInstruction(const string& s, Registers& r){


}
void TwoParameterInstruction::execute(){

}

ThreeParameterInstruction::ThreeParameterInstruction(const string& s, Registers& r){


}
void ThreeParameterInstruction::execute(){

}


Registers::Registers(){
	reg["t0"] = 0;
	reg["t1"] = 0;
	reg["t2"] = 0;
	reg["t3"] = 0;
	reg["t4"] = 0;
	reg["t5"] = 0;
	reg["t6"] = 0;
	reg["t7"] = 0;
	reg["t8"] = 0;
	reg["t9"] = 0;

	reg["s0"] = 0;
	reg["s1"] = 0;
	reg["s2"] = 0;
	reg["s3"] = 0;
	reg["s4"] = 0;
	reg["s5"] = 0;
	reg["s6"] = 0;
	reg["s7"] = 0;
    reg["lo"] = 0;
    reg["hi"] = 0;
}

int Registers::operator[](const string& s) const{
	return reg.at(s); // reg[s]
}

void Registers::operator()(const string& s,int i){
	if (reg.find(s) != reg.end() )
		reg[s] = i;
	else
		cerr<<"Invalid register!";
}

ostream& operator<<(ostream& os,const Registers& r){
    os<<"+==========+=========+"<<endl;
    os<<"| Register |  Value  |"<<endl;
    os<<"+==========+=========+"<<endl;
    for (auto& [key,value] : r.reg){
        os<<"|   $"<<key<<"    |   "<<setw(3)<<left<<value<<"   |"<<endl;
    }
    os<<"+==========+=========+"<<endl;
    return os;
}

string Interpreter::getInstruction(int n){

}

Interpreter::Interpreter(const std::string& filename) {
    ifstream ifs(filename);
    string line;
    while(getline(ifs,line)){
        instruction.push_back(line);
    }
    lineNumber = 0;
    for(auto& line: instruction){
        cout<<line<<endl;
    }
}

void Interpreter::executeInstructions(){

}

void Interpreter::displayRegisters(){

}

vector<string> tokenizer(const string& s, const char& c){
    vector<string> tokenizedString;
    string temp;
    for (int i=0;i<s.length();i++){
        if(s[i+1]=='\0'){
            if(s[i]==c)
                tokenizedString.push_back(temp);
            else
                tokenizedString.push_back(temp+s[i]);
        break;
        }
        if (s[i]==c){
  // cout<<s[i]<<"=="<<c<<endl;
  // cout<<temp<<endl;
            tokenizedString.push_back(temp);
            temp = "";
        }
        else{
            temp+=s[i];
        }
    }
    return tokenizedString;
}

int wc(const string& s){
    return tokenizer(s,' ').size();
}
