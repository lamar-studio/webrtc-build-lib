
#include <iostream>
#include "scoped_refptr.h"
#include "ref_count.h"
#include "ref_counted_object.h"

using namespace std;
using namespace rtc;

class A : public RefCountInterface
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
	//new class,but no need del
	//RefCountedObject add the counter for A
	scoped_refptr<A> sp = new RefCountedObject<A>(100);

	//get class addr
	cout << "sp = " << sp.get() << endl;

	sp->display();

	func(sp);

	sp->display();

	return 0;
}
