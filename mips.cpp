#include "mips.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

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
    // vector<string>::iterator iter= tokenizedString.begin();
    // for( ; iter!=tokenizedString.end();iter++){
    //     if (*(iter) =="") tokenizedString.erase(iter);

    //     //iter--;
    // }
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

string replace(const string& s, const char& h = ',',const char& n = ' '){
	string answer = s;
    for (int i=0;i<s.length();i++){
		if (s[i]==h) answer[i] = n;
	}
	return answer;
}

string strip(const string &s){
    string str = s;
    if  (str.length() != 0){
        auto w = string(" ") ;
        auto n = string("\n") ;
        auto r = string("\t") ;
        auto t = string("\r") ;
        auto v = string(1 ,str.front()); 
        while((v == w) || (v==t) || (v==r) || (v==n)){
            str.erase(str.begin());
            v = string(1 ,str.front());
        }
        v = string(1 , str.back()); 
        while((v ==w) || (v==t) || (v==r) || (v==n)){
            str.erase(str.end() - 1 );
            v = string(1 , str.back());
        }
    }
    return str;
}
//--------------------One parameter instruction----------------------------
OneParameterInstruction::OneParameterInstruction(const string& s, Registers& r) :reg(r) {
    vector<string> words = tokenizer(s);
    operation = words[0];
    arg1 = words[1];
}

void OneParameterInstruction::execute(){
    if(operation == "mfhi"){
        reg[arg1] = reg["$hi"];
    }
    else if(operation == "mflo"){
        reg[arg1] = reg["$lo"];
    }
    else if(operation == "mthi"){
        reg["$hi"] = reg[arg1];
    }
    else if(operation == "mtlo"){
        reg["$lo"] = reg[arg1];
    }
}

//--------------------Two parameter instruction----------------------------
// std::string operation, reg1,reg2;
// Registers reg;
TwoParameterInstruction::TwoParameterInstruction(const string& s, Registers& r) :reg(r) {
    //cout<<"In 2"<<endl;
    vector<string> words = tokenizer(s);
    //cout<<"0 :"<<words[0] <<"\n1:"<<words[1]<<"\n2:"<<words[2]<<endl;
    operation = words[0];
    arg1 = words[1];
    arg2 = words[2];
}

void TwoParameterInstruction::execute(){
    //cout<<"executing 2"<<endl;
    if(operation == "li"){
        //cout<<"::li encountered::"<<endl;
        reg[arg1] = arg2;
    }
    else if (operation == "move"){
        reg[arg2] = reg[arg1];
    }
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
    if (reg["$v0"] == to_string(1) || reg["$v0"] == to_string(2) || reg["$v0"] == to_string(3 || reg["$v0"] == to_string(4) )  ){
        cout<<reg["$a0"];
    }
}

//----------------------Data instruction------------------------------
DataInstruction::DataInstruction(const std::string& line, Data&  data ) :d(data){

}

void DataInstruction::execute(){

}

//-------------------------------Registers-----------------------------------

Registers::Registers(){
	reg["$t0"] = to_string(0);
	reg["$t1"] = to_string(0);
	reg["$t2"] = to_string(0);
	reg["$t3"] = to_string(0);
	reg["$t4"] = to_string(0);
	reg["$t5"] = to_string(0);
	reg["$t6"] = to_string(0);
	reg["$t7"] = to_string(0);
	reg["$t8"] = to_string(0);
	reg["$t9"] = to_string(0);

	reg["$s0"] = to_string(0);
	reg["$s1"] = to_string(0);
	reg["$s2"] = to_string(0);
	reg["$s3"] = to_string(0);
	reg["$s4"] = to_string(0);
	reg["$s5"] = to_string(0);
	reg["$s6"] = to_string(0);
	reg["$s7"] = to_string(0);
    
    reg["$lo"] = to_string(0);
    reg["$hi"] = to_string(0);

    reg["$v0"] = to_string(0);
    reg["$a0"] = to_string(0);
    reg["$a1"] = to_string(0);

    reg["$zero"] = to_string(0);
}

string& Registers::operator[](const string& s){
	if (reg.find(s) != reg.end() )
		return reg[s];
	else
		cerr<<"Invalid register!";
}

ostream& operator<<(ostream& os,const Registers& r){
    os<<endl;
    os<<"+==========+=========+"<<endl;
    os<<"| Register |  Value  |"<<endl;
    os<<"+==========+=========+"<<endl;
    for (auto& [key,value] : r.reg){
        if (key == "$zero"){
            os<<"|  $zero   |   0     |"<<endl;
            continue;
        }
        os<<"|   "<<key<<"    |   "<<setw(3)<<left<<value<<"   |"<<endl;
    }
    os<<"+==========+=========+"<<endl;
    return os;
}

//---------------------------Data------------------------------------

ostream& operator<<(ostream& os,const Data& d){
    for(auto& [key,value] : d.data){
        os<<key<<" : "<<value<<endl;
    }
    return os;
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
        line = replace(strip(line));
        Instruction *inst = nullptr;
        //cout<<"WC of (" << line << ") is " << wc(line)<<endl;
        if(line==""){
            continue;
        }
        if (wc(line)==1){
            //cout<<"In wc 1"<<endl;
            //cout<<(line == "syscall") <<endl;
            if (line=="syscall"){
                //cout<<"in if"<<endl;
                if (reg["$v0"] == to_string(10)){
                    return;
                }
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
            else if (line=="main:"){
                textSegment = true;
                continue;
            }
        }
        if (textSegment){
            if (wc(replace(line))==2){
                //cout<<"One"<<endl;
                inst = new OneParameterInstruction(line,reg);
            }
            else if (wc(replace(line))==3){
                //cout<<"Two"<<endl;
                inst = new TwoParameterInstruction(line,reg);
            }
            else if (wc(replace(line))==4){
                //cout<<"Three"<<endl;
                inst = new ThreeParameterInstruction(line,reg);
            }
            else if (wc(line)!=1){
                cerr<<"Invalid instruction : "<<line<<endl;
                return;
            }
        }
        else{
            inst = new DataInstruction(line,d);
        }
        inst->execute();
        lineNumber++;
    }
}

void Interpreter::displayRegisters() const{
    cout << reg;
}
Interpreter::~Interpreter(){
    cout<<"Program execution completed!"<<endl;
}
/*
string Interpreter::getInstruction(int n){
    if (n<instruction.size())
        return instruction[n];
    return "";
}
*/

