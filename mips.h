#pragma once
#include <string>
#include <vector>
#include <map>

class Registers{
	std::map<std::string, int> reg;
public:
	Registers();
	friend std::ostream& operator<<(std::ostream&,const Registers&);
	int operator[](const std::string&) const;
	void operator()(const std::string&,int);
};


class Interpreter{
	int lineNumber;
	std::vector<std::string> instruction;
	Registers reg;

public:
	std::string getInstruction(int);
	Interpreter() = delete;
	Interpreter(const std::string&) ;
	void executeInstructions();
	void displayRegisters();
};

class Instruction{
public:
	virtual void execute() = 0;
};

class OneParameterInstruction:public Instruction{
	std::string operation, reg1; // mflo $t0
	Registers reg;
public:
	OneParameterInstruction() = delete;
	OneParameterInstruction(const std::string&, Registers&); 
	void execute() override;
};

class TwoParameterInstruction:public Instruction{
	std::string operation, reg1,reg2;
	Registers reg;
public:
	TwoParameterInstruction() = delete;
	TwoParameterInstruction(const std::string&, Registers&);
	void execute() override;
};

class ThreeParameterInstruction:public Instruction{
	std::string operation, reg1,reg2,reg3; // add $t0,$t1,$t2
	Registers reg;
public:
	ThreeParameterInstruction() = delete;
	ThreeParameterInstruction(const std::string&,Registers&);
	void execute() override;
};

std::vector<std::string> tokenizer(const std::string&, const char&);

int wc(const std::string&);

