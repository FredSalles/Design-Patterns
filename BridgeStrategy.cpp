#include <iostream>

// decouple an abstraction from its implementation 
// so that the two can vary independently

using namespace std;

class implementation {
public:
	virtual void doIt() {};
};

class abstraction {
protected:
	implementation* _impl;
public:
	virtual void doSomething() {
		_impl->doIt();
	}
};

class client : public abstraction {
public:
	client(implementation *impl) {
		_impl = impl;
	}
	void doSomething() {
		cout << "About to do something" << endl;
		abstraction::doSomething();
	}
};
	//
	// DIFFERENT IMPLEMENTATIONS FOR SAME ABSTRACTION
	// 
class server: public implementation {
public:
	void doIt() {
		cout << "Doing it !" << endl;
	}
};
class server_two: public implementation {
public:
	void doIt() {
		cout << "Doing it too!" << endl;
	}
};

//
// OTHER STYLE - AN OBJECT STRATEGY RECEIVE AND OBJECT AND A FUNCTION AND DECIDES HOW TO 
// IMPLEMENT FUNCTION BASED ON OBJECT TYPE 
//
int main (int argc, char * const argv[]) {
	server s;
	server_two s2;
	client c(&s), d(&s2);
	c.doSomething();
	d.doSomething();
    return 0;
}
