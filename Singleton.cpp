#include <iostream>

using namespace std;

class singleton {
private:
	int value;
	singleton() { value = 0; cout << "Singleton constructor " << endl; };
protected:
	singleton(const singleton & s) {
		value = s.getValue();
		cout << "Singleton copy constructor "<< endl; 
	};
	singleton& operator= (const singleton & s) {
		value =s.getValue();
		cout << "Singleton assignment "<< endl;
		return (*this);
	};
public:
	static singleton & getReference() {
		//
		// A SINGLE OBJECT INSTANCE IS CREATED
		//
		static singleton _s;
		return _s;
	}
	void increase() { value++; };
	int getValue() const { return value; };
};

int main (int argc, char * const argv[]) {

	singleton &s1 = singleton::getReference();
	singleton &s2 = singleton::getReference();

	cout << " Singleton s1: " << s1.getValue() << ", s2: " << s2.getValue() << endl;
	s1.increase();
	cout << " Singleton s1: " << s1.getValue() << ", s2: " << s2.getValue() << endl;

    return 0;
}
