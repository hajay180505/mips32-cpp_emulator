class Registers{
	unordered_map<string, int> reg;
public:
	Registers();
	friend ostream& operator<<(ostream&,const Registers&);
	int operator[](const string&) const;
	void operator()(const string&,int);
};


class Interpreter{
	int lineNumber;
	vector<string> instruction;
	Registers reg;

public:
	string getInstruction(int);
	Interpreter() = delete;
	Interpreter(const string&) ;
	void executeInstruction();
	void displayRegisters();
};

class Instruction{
public:
	virtual void execute() = 0;
};

class OneParameterInstruction:public Instruction{
	string operation, reg; // mflo $t0
	Registers reg;
public:
	OneParameterInstruction() = delete;
	OneParameterInstruction(const string&, Registers&); 
	void execute() override;
};

class TwoParameterInstruction:public Instruction{
	string operation, reg1,reg2;
	Registers reg;
public:
	TwoParameterInstruction() = delete;
	TwoParameterInstruction(const string&, Registers&);
	void execute() override;
};

class ThreeParameterInstruction:public Instruction{
	string operation, reg1,reg2,reg3; // add $t0,$t1,$t2
	Registers reg;
public:
	ThreeParameterInstruction() = delete;
	ThreeParameterInstruction(const string&,Registers&);
	void execute() override;
};

vector<string> tokenizer(const string&, char);

int wc(const string&);

