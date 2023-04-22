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
public:
	string getInstruction(int);
	Interpreter() = delete;
	Interpreter(const string&) ;
	void executeInstruction();
};

class Instruction{
public:
	virtual void execute() = 0;
};

class OneParameterInstruction:public Instruction{
	string operation, reg; // mflo $t0
public:
	OneParameterInstruction() = delete;
	OneParameterInstruction(const string&);
	void execute() override;
};

class TwoParameterInstruction:public Instruction{
	string operation, reg1,reg2;
public:
	TwoParameterInstruction() = delete;
	TwoParameterInstruction(const string&);
	void execute() override;
};

class ThreeParameterInstruction:public Instruction{
	string operation, reg1,reg2,reg3;
public:
	ThreeParameterInstruction() = delete;
	ThreeParameterInstruction(const string&);
	void execute() override;
};

vector<string> tokenizer(const string&, char);

int wc(const string&);
