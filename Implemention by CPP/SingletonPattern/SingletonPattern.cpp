//����ģʽ
#include <iostream>

using namespace std;

//���䵥��ģʽʵ��
class Singleton{
private:
	static Singleton *uniqueInstance;//����һ����̬��������¼Singleton��Ψһʵ��
	Singleton(){};

	//ɾ��Singletonʵ���Ķ���
	class DeleteSingleton{
	public:
		~DeleteSingleton(){
			if(Singleton::uniqueInstance)
				delete Singleton::uniqueInstance;
		}
	};
	static DeleteSingleton deleteSIngObj;//�������ʱ���Զ���������������

public:
	//ʵ��������ķ���
	static Singleton* getInstance()
	{
		if(NULL == uniqueInstance)
			uniqueInstance = new Singleton();
		return uniqueInstance;
	}
};

Singleton* Singleton::uniqueInstance = NULL;//��̬��Ա������ʼ��

int main()
{
	Singleton *singletonObj = Singleton::getInstance();

	delete singletonObj;

	return 0;
}