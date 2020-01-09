#include <stdio.h>
#include <memory>
#include "coroutine.h"
#include "schedule.h"
#include "singleton.h"

class Logic1 :public Coroutine
{
	void CoProcess()
	{
		puts("ctr1");
		Yield();
		puts("ctr2");
		Yield();
		puts("ctr3");
	}
};

class Logic2 :public Coroutine
{
	void CoProcess()
	{
		puts("ctr4");
		Yield();
		puts("ctr5");
		Yield();
		puts("ctr6");
	}
};

class Logic3 :public Coroutine
{
	void CoProcess()
	{
		puts("ctr7");
		Yield();
		puts("ctr8");
		Yield();
		puts("ctr9");
	}
};

int main(int argc,char * argv)
{
	std::shared_ptr<Coroutine> ctr1(new Logic1());
	std::shared_ptr<Coroutine> ctr2(new Logic2());
	std::shared_ptr<Coroutine> ctr3(new Logic3());

	ctr1->SetId(1);
	ctr2->SetId(2);
	ctr3->SetId(3);

	SingleSchedule::GetInst()->coroutineNew(ctr1.get());
	SingleSchedule::GetInst()->coroutineNew(ctr2.get());
	SingleSchedule::GetInst()->coroutineNew(ctr3.get());

	SingleSchedule::GetInst()->Resume(1);
	SingleSchedule::GetInst()->Resume(2);
	SingleSchedule::GetInst()->Resume(3);
	SingleSchedule::GetInst()->Resume(1);
	SingleSchedule::GetInst()->Resume(2);
	SingleSchedule::GetInst()->Resume(3);

	int count = SingleSchedule::GetInst()->HasCoroutine();
	printf("%d\n", count);

	return 0;
}