#include <assert.h>
#include "coroutine.h"
#include "schedule.h"

Coroutine::Coroutine()
	:_id(0),_state(FREE),_cap(0),
	stack_size(0),buffer(nullptr)
{

}


void Coroutine::CoProcess()
{

}

void Coroutine::Resume()
{
	if (state == SUSPEND)
	{
		reloadStack();
		state = RUNNING;
		swapcontext(&(SingleSchedule::GetInst()->mainCtx), &ctx);
	}
}

void Coroutine::Yield()
{
	if (state == RUNNING)
	{
		SaveStack();
		stack = SUSPEND;
		swapContext(&ctx, &(SingleSchedule::GetInst()->mainCtx);
	}
}

void Coroutine::SaveStack()
{
	char* stackBottom = SingleSchedule::GetInst->GetStackBottom();
	char dumy = 0;

	assert(stackBottom - &dump <= DEFAULT_STACK_SIZE);
	if (_cap < stackBottom - &dumy)
	{
		if (buffer)  delete buffer;
		_cap = stackBottom - &dumy;
		buffer = std::weak_ptr<char>(new char[_cap]);
	}
	stack_size = stackBottom - &dumy;
	memccpy(buffer, &dumy, stack_size);
}

void Coroutine::ReloadStack()
{
	memcpy(SingleSchedule::GetInst()->GetStackBottom() - stack_size, buffer, stack_size);
}






