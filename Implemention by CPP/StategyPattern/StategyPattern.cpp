#include <iostream>

using namespace std;

//飞行方法接口抽象接口类
class Fly{
public:
	virtual void fly() = 0;
};

class FlyWithWings:public Fly
{
public:
	void fly()
	{
		cout << "I'm flying" << endl;
	}
};

class FlyNoWay:public Fly
{
public:
	void fly()
	{
		cout << "I can't fly" << endl;
	}
};

class FlyRocketPowered:public Fly
{
public:
	void fly()
	{
		cout << "I'm flying with a rocket" << endl;
	}
};

//Duck抽象基类定义
class Duck{
public:
	Duck():m_fly(NULL){}

	//设定Fly的具体方法
	void setFly(Fly *pFly)
	{
		if (m_fly)
		{
			delete m_fly;//删除原来的fly方法所占空间
		}
		m_fly = pFly;
	}

	//运行Fly方法
	void performFly()
	{
		if (m_fly)
		{
			m_fly->fly();
		}
	}

	//析构函数
	~Duck()
	{
		if (m_fly)
		{
			delete m_fly;
			m_fly = NULL;
		}
	}

protected:
	Fly *m_fly;
};

//Duck子对象定义
class MallardDuck:public Duck{
public:
	MallardDuck()
	{
		cout << "I'm a Mallard duck" << endl;
		m_fly = new FlyWithWings();
	}
};

//Duck子对象定义
class ModelDuck:public Duck{
public:
	ModelDuck()
	{
		cout << "I'm a Model duck" << endl;
		m_fly = new FlyNoWay();
	}
};

int main()
{
	MallardDuck myDuck1;
	myDuck1.performFly();

	myDuck1.setFly(new FlyRocketPowered());
	myDuck1.performFly();

	ModelDuck myDuck2;
	myDuck2.performFly();
}