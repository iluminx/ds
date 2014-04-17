#include <iostream>
using namespace std;
template <typename T>
class autoptr{
	T* p;
public:
	autoptr (T* p):p(p){}
	~autoptr () {delete p;}
	autoptr(autoptr& a):p(0){operator=(a);}
	autoptr& operator=(autoptr& a){
		if(this == &a) return *this;
		if(p != NULL) delete p;
		p = a.p;
		a.p = NULL;
		return *this;
	}
	T& operator*()const{return *p;}
	T* operator->()const{return p;}

};
class A{
	int data;
public:
	A(int d):data(d){cout << this << "A(" << d << ")" << endl;}
	~A(){cout << this <<"~A()" << data << endl;}
	void show()const{cout << this << ":" << data << endl;}
};
int main()
{
	autoptr<A> p(new A(10));
	p->show();
	autoptr<A> q=p;
	q->show();
//	p->show();	
	autoptr<A> r(new A(20));
	(*r).show();
	r = q;

}


