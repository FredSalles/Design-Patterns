#include <iostream>
#include <vector>

using namespace std;

class subject;

//
// OBSERVER
//
class observer {
public:
	virtual void update(subject *) {};
};

//
// SUBJECT
//
class subject {
public:
	virtual void attach(observer *) = 0;
	virtual void notify() = 0;
	virtual void getName() = 0;
};

//
// CONCRETE
//
class a_subject : public subject {
private:
	string name;
	vector<observer*> v;
public:
	a_subject(string s) {
		name = s;
	}
	void attach(observer *s) {
		v.push_back(s);
	}
	void notify() {
		vector<observer*>::iterator i;
		for (i=v.begin(); i!=v.end(); i++) {
			(*i)->update(this);
		}
	}
	void getName() { 
		cout << name;
	}
	void change(string s) {
		name = s;
		notify();
	}
};

class an_observer : public observer {
private:
	string name;
public:
	an_observer(string s) {
		name = s;
	}
	void update(subject *sub) {
		cout << "Observer" << name << " subject: ";
		sub->getName();
		cout << endl;
	}
};



int main (int argc, char * const argv[]) {
	a_subject mySubject("subject_one");
	an_observer myObserverOne("observer_one");
	an_observer myObserverTwo("observer_two");
	mySubject.attach(&myObserverOne);
	mySubject.attach(&myObserverTwo);
	
	mySubject.notify();
	mySubject.change("new suject_one");
    return 0;
}
