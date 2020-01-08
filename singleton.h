#ifndef SINGLETON_H
#define SINGLETON_H

template<class T>
class Singleton
{
public:

	// ������ȡ
	static T* GetInst()
	{
		if (!flag_instance)
		{
			flag_instance = new Singleton();
		}
		return &(flag_instance->_instance);
	}

protected:

	// ��������
	Singleton() {};

private:

	// ����ʵ��
	T _instance;

	// ����ģ��ʵ��
	static Singleton<T>* flag_instance;


};

template<class T>
Singleton<T>* Singleton<T>::flag_instance = NULL;



#endif
