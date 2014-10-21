//单例模式
#include <iostream>

using namespace std;

//经典单例模式实现
class Singleton{
private:
	static Singleton *uniqueInstance;//利用一个静态变量来记录Singleton的唯一实例
	Singleton(){};

	//删除Singleton实例的对象
	class DeleteSingleton{
	public:
		~DeleteSingleton(){
			if(Singleton::uniqueInstance)
				delete Singleton::uniqueInstance;
		}
	};
	static DeleteSingleton deleteSIngObj;//程序结束时，自动调用其析构函数

public:
	//实例化对象的方法
	static Singleton* getInstance()
	{
		if(NULL == uniqueInstance)
			uniqueInstance = new Singleton();
		return uniqueInstance;
	}
};

Singleton* Singleton::uniqueInstance = NULL;//静态成员变量初始化

int main()
{
	Singleton *singletonObj = Singleton::getInstance();

	delete singletonObj;

	return 0;
}