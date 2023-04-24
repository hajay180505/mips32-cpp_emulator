#pragma once
#include <string>
#include <vector>
#include <map>

class Registers{
	std::map<std::string, std::string> reg;
public:
	Registers();
	friend std::ostream& operator<<(std::ostream&,const Registers&);
	std::string& operator[](const std::string&) ;
};

class Data{
	std::map<std::string, std::string> data;
public:
	friend std::ostream& operator<<(std::ostream&,const Data&);
	std::string& operator[](const std::string&) ;
	const std::string& operator()(const std::string&) const;
};

class Interpreter{
	int lineNumber;
	std::vector<std::string> instruction;
	Registers reg;
	Data d;
public:
	Interpreter() = delete;
	Interpreter(const std::string&) ;
	void executeInstructions();
	void displayRegisters() const;
	~Interpreter();
};

class Instruction{
public:
	virtual void execute() = 0;
};

class OneParameterInstruction:public Instruction{
	std::string operation, arg1; // mflo $t0
	Registers& reg;
public:
	OneParameterInstruction() = delete;
	OneParameterInstruction(const std::string&, Registers&); 
	void execute() override;
};

class TwoParameterInstruction:public Instruction{
	std::string operation, arg1,arg2;
	Registers& reg;
	Data &data;
public:
	TwoParameterInstruction() = delete;
	TwoParameterInstruction(const std::string&, Registers&,Data&);
	void execute() override;
};

class ThreeParameterInstruction:public Instruction{
	std::string operation, arg1,arg2,arg3; // add $t0,$t1,$t2
	Registers& reg;
public:
	ThreeParameterInstruction() = delete;
	ThreeParameterInstruction(const std::string&,Registers&);
	void execute() override;
};

class SyscallInstruction:public Instruction{
	Registers& reg;
public:
	SyscallInstruction() = delete;
	SyscallInstruction(Registers&);
	void execute() override;
};

class DataInstruction:public Instruction{
	Data& d;
	std::string instruction;
public:
	DataInstruction() = delete;
	DataInstruction(const std::string& , Data& );
	void execute() override;
};

std::vector<std::string> tokenizer(const std::string&, const char& );

int wc(const std::string&);

std::string removeComments(const std::string&);

std::string replace(const std::string& , const char& ,const char& );

std::string strip(const std::string &s);

