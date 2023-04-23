#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Registers{
	unordered_map<string , int> reg;
	public :
		Registers();
		int& operator[](const string&) ;
		//void operator()(const string&, int);
};
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
}

int& Registers::operator[](const string& s) {
	if (reg.find(s) != reg.end() )
		return reg[s];
	else
		cerr<<"Invalid register!";
}

// void Registers::operator()(const string& s,int i){
// 	if (reg.find(s) != reg.end() )
// 		reg[s] = i;
// 	else
// 		cerr<<"Invalid register!";
// }


int main(){
	Registers r;
	cout<<r["t0"]<<endl;
	r["t0"] = 10;
	r["t1"] = 11;

	cout<<r["t0"];
}
