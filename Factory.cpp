#include <iostream>
#include <map>

using namespace std;

class element {
public:
	virtual element & construct() {return *(new element);};
	virtual string name() { return "unasigned";};
};

class element_a : public element {
public:
	virtual string name() {
		return "element_a";
	}
	virtual element & construct() {
		return *(new element_a);
	}
	void sayHi() { cout << "element_a Hi!" << endl;};
};

class element_b : public element {
public:
	virtual string name() {
		return "element_b";
	}
	virtual element & construct() {
		return *(new element_b);
	}
	void sayBye() { cout << "element_b Bye !" << endl;};
};

class factory {
private:
	map<string, element*> mapper;
public:
	factory() {
		mapper["element_a"] = new element_a;
		mapper["element_b"] = new element_b;
	}
	//
	// INSTANCIATES OBJECTS BASED TYPE
	//
	element& produceElement(string type) {
	//cout << "in mapper: "<< mapper.find(type)->second->name() << endl;
	return mapper.find(type)->second->construct();
	}
};

int main (int argc, char * const argv[]) {
	//
	// ADDING NEW TYPES/OBJECTS ONLY AFFECTS FACTORY
	//
	factory f;
	element &e1 = f.produceElement("element_a");
	element &e2 = f.produceElement("element_b");
	cout << "e1:" << e1.name() << endl; 
	cout << "e2:" << e2.name() << endl; 

	element * ee = &e1;
	element_a * ea = static_cast <element_a *> (ee);
	cout << "ee:" << ee->name() << endl; // call virtual implemented in child
	cout << "ea:" << ea->name() << endl; // call native
	ea->sayHi();						 // call native
	
	element_a &a = static_cast <element_a &> (f.produceElement("element_a"));
	element_b &b = static_cast <element_b &> (f.produceElement("element_b"));
	cout << "elements fetched from factory: " << endl;
	a.sayHi();
	b.sayBye();
    return 0;
}
