
#include <iostream>
#include "scoped_refptr.h"
#include "ref_count.h"
#include "ref_counted_object.h"

using namespace std;
using namespace rtc;

class A : public RefCountInterface       /*需要继承自类RefCountInterface*/
{
public:
	A(int i)
		:data_(i)
	{
		cout << __FUNCTION__ << " : " << this << endl;
	}

	void display()
	{
		cout << "data = " << data_ << endl;
	}

	void set(int i)
	{
		data_ = i;
	}

	~A()
	{
		cout << __FUNCTION__ << endl;
	}

private:
	int data_;
};

void func(scoped_refptr<A> sp)
{
	sp->display();

	sp->set(200);
}

int main()
{
	/*只见new，不见delete。*/
	scoped_refptr<A> sp = new RefCountedObject<A>(100);

	/*获取托管对象的地址*/
	cout << "sp = " << sp.get() << endl;

	sp->display();

	func(sp);

	sp->display();

	return 0;
}
