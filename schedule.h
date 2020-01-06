#ifndef SCHEDULE_H

#define SCHEDULE_H
#define _XOPEN_SOURCE

#include <stdio.h>
#include  <map>
#include  <ucontext.h>
#include  "coroutine.h"
#include  "singleton.h"

/*
Э�̵�����ʵ��
*/

typedef std::map<int, Coroutine*> CrtMap;
class Schedule
{
	Schedule();
	virtual ~Schedule();

	// �û�Э����ں���
	static void coroutineEntry(void* crt);

	// ��Э�̼���Э�̳أ�������Э��
	void coroutineNew(Coroutine* crt);

	// �ָ��û�Э��
	void Resume(int id);

	// �ж�Э�̳����Ƿ���δ��ɵ�Э�̣�
	// �����Ѿ���ֹ��Э��ɾ��
	int HasCoroutine();

	// ͨ��Э��idɾ��Э��
	void Remove(int id);

	// ��ȡջ��
	char* GetStackBottom()
	{
		return stack + DEFAULT_STACK_SIZE;
	}

public:
	ucontext_t mainCtx;//���߳���������Ϣ
    char stack[DEFAULT_STACK_SIZE];  //Э�̶�ջ

private:
	CrtMap crtPool;

};


typedef Singleton<Schedule> SingleSchedule;



#endif
