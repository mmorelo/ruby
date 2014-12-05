#include <iostream>

class Base;
class ClassA;
class ClassB;
	
using namespace std;

class Visitor
{public:
	virtual void visit( Base * b) = 0;
};

class Base
{
public:
	virtual void accept(Visitor& v) = 0;
	virtual std::string name() = 0;
};


class DoFizz : public Visitor
{public:
	virtual void visit( Base * b)
	{
		(void)b;
		cout << "Fizz " << b->name( ) << endl;
	}
};

class DoBuzz: public Visitor
{public:
	virtual void visit(  Base * b) 
	{
		(void)b;
		cout << "Buzz " << b->name() << endl;
	}
};

class ClassA : public Base
{
	public:
	virtual void accept( Visitor& v)
	{  
		v.visit( this );	
	}

	virtual std::string name()
	{
		return "Class A";
	}
};

class ClassB : public Base
{
	public:
	virtual void accept( Visitor& v)
	{
			v.visit( this );
	}

	virtual std::string name()
	{
		return "Class B";
	}
};


int main()
{
	ClassA a;
	ClassB b;
	DoFizz f;
	DoBuzz buzz;

	a.accept( f );
	a.accept( buzz );

	b.accept( f );
	b.accept( buzz );

	return 0;
}






