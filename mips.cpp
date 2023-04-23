#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

//--------------------One parameter instruction----------------------------
OneParameterInstruction::OneParameterInstruction(const string& s, Registers& r) :reg(r) {


}

void OneParameterInstruction::execute(){

}

//--------------------Two parameter instruction----------------------------
// std::string operation, reg1,reg2;
// Registers reg;
TwoParameterInstruction::TwoParameterInstruction(const string& s, Registers& r) :reg(r) {


}

void TwoParameterInstruction::execute(){

}

//--------------------Three parameter instruction----------------------------
ThreeParameterInstruction::ThreeParameterInstruction(const string& s, Registers& r) :reg(r) {


}

void ThreeParameterInstruction::execute(){

}

//--------------------Syscall instruction----------------------------
SyscallInstruction::SyscallInstruction(Registers& r) :reg(r){

}

void SyscallInstruction::execute(){

}

//----------------------Data instruction------------------------------
DataInstruction::DataInstruction(const std::string& line, Data&  data ) :d(data){

}

void DataInstruction::execute(){

}

//-------------------------------Registers-----------------------------------

Registers::Registers(){
	reg["$t0"] = 0;
	reg["$t1"] = 0;
	reg["$t2"] = 0;
	reg["$t3"] = 0;
	reg["$t4"] = 0;
	reg["$t5"] = 0;
	reg["$t6"] = 0;
	reg["$t7"] = 0;
	reg["$t8"] = 0;
	reg["$t9"] = 0;

	reg["$s0"] = 0;
	reg["$s1"] = 0;
	reg["$s2"] = 0;
	reg["$s3"] = 0;
	reg["$s4"] = 0;
	reg["$s5"] = 0;
	reg["$s6"] = 0;
	reg["$s7"] = 0;
    
    reg["$lo"] = 0;
    reg["$hi"] = 0;

    reg["$v0"] = 0;
    reg["$a0"] = 0;
    reg["$a1"] = 0;

    reg["$zero"] = 0;
}

int& Registers::operator[](const string& s){
	if (reg.find(s) != reg.end() )
		return reg[s];
	else
		cerr<<"Invalid register!";
}

ostream& operator<<(ostream& os,const Registers& r){
    os<<"+==========+=========+"<<endl;
    os<<"| Register |  Value  |"<<endl;
    os<<"+==========+=========+"<<endl;
    for (auto& [key,value] : r.reg){
        if (key == "$zero"){
            os<<"|  $zero   |    0    |"<<endl;
            continue;
        }
        os<<"|   "<<key<<"    |   "<<setw(3)<<left<<value<<"   |"<<endl;
    }
    os<<"+==========+=========+"<<endl;
    return os;
}

//---------------------------Data------------------------------------

ostream& operator<<(std::ostream&,const Data&){


}

string& Data::operator[](const string& key) {
        return data[key];
}

const string& Data::operator()(const std::string& s) const{
    return data.at(s);
}


//------------------------Interpreter--------------------------------
Interpreter::Interpreter(const std::string& filename) {
    ifstream ifs(filename);
    string line;
    while(getline(ifs,line)){
        instruction.push_back(removeComments(line));
    }
    lineNumber = 0;
    // for(auto& line: instruction){
    //     cout<<line<<endl;
    // }
}

void Interpreter::executeInstructions(){
    bool textSegment = false;
    for (auto& line: instruction){
        Instruction *inst = nullptr;
        if(line==""){
            continue;
        }
        if (wc(line)==1){
            if (line=="syscall"){
                inst = new SyscallInstruction(reg);
            }
            else if (line == ".data"){
                textSegment = false;
                continue;
            } 
            else if (line==".text"){
                textSegment = true;
                continue;
            }
        }
        if (textSegment){
            if (wc(replace(line))==2){
                inst = new OneParameterInstruction(line,reg);
            }
            else if (wc(replace(line))==3){
                inst = new TwoParameterInstruction(line,reg);
            }
            else if (wc(replace(line))==4){
                inst = new ThreeParameterInstruction(line,reg);
            }
            else{
                cerr<<"Invalid instruction : "<<line<<endl;
            }
        }
        else{
            inst = new DataInstruction(line,d);
        }
        inst->execute();
    }
}

void Interpreter::displayRegisters() const{
    cout << reg;
}

/*
string Interpreter::getInstruction(int n){
    if (n<instruction.size())
        return instruction[n];
    return "";
}
*/

//--------------------Non-member functions----------------------------
vector<string> tokenizer(const string& s, const char& c = ' '){
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
    return tokenizer(s).size();
}

string removeComments(const string& s){
    string answer = "";
    for(int i=0;i<s.length();i++){
        if (s[i]=='#')
            return answer;
        else
            answer+=s[i];
    }
    return answer;
}

string replace(string& s, const char& h = ',',const char& n = ' '){
	string answer = s;
    for (int i=0;i<s.length();i++){
		if (s[i]==h) answer[i] = n;
	}
	return answer;
}
