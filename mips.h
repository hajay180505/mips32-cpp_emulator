class Registers{
	unordered_map<string, int> reg;
public:
	Registers();
	friend ostream& operator<<(ostream&,const Registers&);
	int operator[](const string&) const;
	void operator()(const string&,int);
};

class Interperter{
	int lineNumber;
	vector<String> instruction;
public:
	string getInstruction(int);
	Interpreter() = delete;
	Interpreter(const string&) ;
	void executeInstruction();
};

class Instruction{
public:
	virtual void execute(string&) = 0;
};

class OneParameterInstruction:public Instruction{
	string operation, reg
public:
	
};

class TwoParameterInstruction:public Instruction{

};

class ThreeParameterInstruction:public Instruction{

};
