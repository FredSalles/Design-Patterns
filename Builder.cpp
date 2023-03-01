#include <iostream>
#include <vector>
#include <list>

using namespace std;

class component {
public:
	virtual void print() = 0;
};

template <class T>
class element: public component {
private:
	T value;
public:
	element (T t) {
		value = t;
	}
	virtual void print() {
		cout << "element: " << value << endl;
	}
};

//
// STRUCTURE
//
class structure {
private:
	vector <component*> v;
public:
	void add_element(component *e) {
				v.push_back(e);
	}
	void print() {
		vector<component*>::iterator i;
		for(i=v.begin();i!=v.end();i++) {
			(*i)->print();
		}
	}
};

//
// BUILDER
//
class builder {
protected:
	structure s;
public:
	virtual void add_element(component *) = 0 ;
	virtual structure& getStructure() = 0; 
};

class builder_one : public builder {
private:
public:
	virtual void add_element(component *e) {
		//
		// This builder adds elements twice 
		//
		s.add_element(e);
		s.add_element(e);
	}
	virtual structure& getStructure() {
		return s;
	}
	
};

//
// DIRECTOR
// 
class director {
private: 
	builder* bld;
public:
	director (builder *b) {
		bld = b;
	}
	void direct () {
		element<int> e1(1);
		element<string> e2("hi");
		bld->add_element(&e1);
		bld->add_element(&e2);
		structure &s = bld->getStructure();
		s.print();
	}
};

int main (int argc, char * const argv[]) {
	
	builder_one b;	
	director d(&b);
	d.direct();
    return 0;
}
