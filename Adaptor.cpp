#include <iostream>

// adapts one interface for a class into one that a client expects
using namespace std;

class server {
public:
	void doSomething() {
		cout << "Doing something!!" << endl;
	}
};

class adaptor {
private:
	server *_serv;
public:
	adaptor(server *s) {
		_serv = s;
	}
	void execute() {
		_serv->doSomething();
	}
};

class client {
private:
	adaptor *_adp;
public:
	 client(adaptor *a) {
		_adp=a;
	}
	void run() {
		_adp->execute();
	}
};

int main (int argc, char * const argv[]) {

	server s;
	adaptor a(&s);
	client c(&a);
	c.run();
    return 0;
}
