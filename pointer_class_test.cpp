#include <iostream>

using namespace std;

class A {
	int a;
public:
	A(int a);
	void print();
};

A::A(int a) {
	this->a = a;
}

void A::print() {
	cout << a << endl;
}

template<class T>
void runCFunc(T* t, void (T::*func)(void)) {
	(t->*func)();
}

void test() {
	A* a = new A(1);
	a->print();
	runCFunc(a, &A::print);
}

