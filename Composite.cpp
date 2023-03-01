#include <iostream>
#include <vector>

using namespace std;

class component {
public:
	virtual void print() {};
};

template <class T>
class element : public component {
private:
	T value;
public:
	element(T i) { 
	value = i; 
	};
	void print() {
		cout << "element_one: " << value << endl;
	}
};

template <class U>
class composite: public component {
private:
	U value;
	vector <component*> a;
public:
	composite (U v) {
		value = v;
	}
	void add(component *c) {
		a.push_back(c);
	}
	void print() {
		cout << "composite: " << value << endl;
		vector<component*>::iterator i;
		for(i=a.begin();i!=a.end();i++) {
			(*i)->print();
		}
	}
};

int main (int argc, char * const argv[]) {
	element<int> e1(1);
	element<string> e2("hi");
	element<int> e3(3);
	composite<int> c1(11);
	composite<string> c2("hello");
	c1.add(&e1);
	c1.add(&c2);
	c2.add(&e2);
	c2.add(&e3);
	c1.print();
    return 0;
}
