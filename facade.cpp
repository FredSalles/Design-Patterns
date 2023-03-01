#include <iostream>

using namespace std;

template <class T> 
class foo {
private:
	T value;
public:
	foo(T t) {
		value = t;
	}
	void run() {
		cout << "Component: " << value << endl;
	}
};

class facade {
public:
	void doSomething() {
		foo<int> one(5);
		foo<string> two("five");
		one.run();
		two.run();
	}
};

int main (int argc, char * const argv[]) {

	facade f;
	f.doSomething();
	
    return 0;
}
