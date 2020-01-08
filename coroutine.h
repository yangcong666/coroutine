#ifndef  COROUTINE_H

#define  COROUTINE_H
#define  DEFAULT_STACK_SIZE 1024*1024  //����ջ��С
#define  _XOPEN_SOURCE

#include  <stdio.h>
#include  <string.h>
#include  <ucontext.h>
#include  <memory>

// ״̬�� ���С����С���ͣ
enum Costate { FREE = 0, RUNNING = 1, SUSPEND = 2 };

// Э����
class Coroutine
{
public:
	Coroutine();
	virtual ~Coroutine() {
		delete buffer;
	};

	// �û�Э����ں���
	virtual void CoProcess();

	// �û�Э�ָ̻�����
	void Resume();

	// ��ȡЭ��ID
	int GetId() const {
		return _id;
	}

	// ����Э��Id
	void SetId(int id)
	{
		_id = id;
	}

	// ��ȡЭ��״̬
	int GetState() const
	{
		return _state;
	}

	// ����Э��״̬
	void SetState(Costate state)
	{
		_state = state;
	}

protected:

	// �û�Э�̹���
	void Yield();


	// ��ջ����
	void SaveStack();

	// ��ջ�ָ�
	void ReloadStack();

public:
	char * buffer;        // ����
	ucontext_t ctx;
private:
	int _stack_size;
	int _cap;
	int _id;
	Costate _state;
};



#endif


