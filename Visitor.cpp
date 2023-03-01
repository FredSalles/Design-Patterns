#include <iostream>

// The purpose of the Visitor Pattern is to encapsulate an operation to be performed
// on the elements of a data structure. In this way, the operation being performed on 
// a structure can change without the need of changing the classes of the elements 
// that the operation operates on. 
// Visitor pattern decouples the classes for the data structure and the algorithms used upon them.

using namespace std;

class element_a;
class element_b;
class element_bundle;

class visitor;

class element {
public:
	virtual void accept (visitor &) = 0;
	virtual string name() = 0;
};

class visitor {
public:
	virtual void visit (element_a &) = 0;
	virtual void visit (element_b &) = 0;
	virtual void visit (element_bundle &) = 0;
};

class element_a : public element {
public:
	virtual void accept (visitor & v) {
		v.visit(*this);
	}
	virtual string name() {
		return "element_a";
	}
};

class element_b : public element {
public:
	virtual void accept (visitor & v) {
		v.visit(*this);
	}
	virtual string name() {
		return "element_b";
	}
};

class element_bundle : public element {
private:
	element_a _a;
	element_b _b;
public:
	virtual void accept (visitor & v) {
		v.visit(*this);
		//
		// DEFINES HOW ELEMENTS OF DATA STRUCTURE ARE VISITED
		//
		_a.accept(v);
		_b.accept(v);
	}
	virtual string name() {
		return "element_bundle";
	}
};

class visitor_one : public visitor {
public:
	//
	// DEFINES WHAT ALGORITHM TO APPLY TO EACH DATA STRUCTURE ELEMENT
	//
	virtual void visit (element_a &element) {
		cout << "One: Visiting " << element.name() << endl;
	}
	virtual void visit (element_b &element) {
		cout << "One: Visiting " << element.name() << endl; 
	}
	virtual void visit (element_bundle &element) {
		cout << "One: Visiting " << element.name() << endl; 
	}
};

class visitor_two : public visitor {
public:
	virtual void visit (element_a &element) {
		cout << "Two: Visiting " << element.name() << endl;
	}
	virtual void visit (element_b &element) {
		cout << "Two: Visiting " << element.name() << endl; 
	}
	virtual void visit (element_bundle &element) {
		cout << "Two: Visiting " << element.name() << endl; 
	}
};

int main (int argc, char * const argv[]) {

	element_bundle e;
	visitor_one	v1;
	visitor_two	v2;

	e.accept(v1);
	e.accept(v2);

    return 0;
}











