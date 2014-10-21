#include <iostream>

using namespace std;

//���з����ӿڳ���ӿ���
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

//Duck������ඨ��
class Duck{
public:
	Duck():m_fly(NULL){}

	//�趨Fly�ľ��巽��
	void setFly(Fly *pFly)
	{
		if (m_fly)
		{
			delete m_fly;//ɾ��ԭ����fly������ռ�ռ�
		}
		m_fly = pFly;
	}

	//����Fly����
	void performFly()
	{
		if (m_fly)
		{
			m_fly->fly();
		}
	}

	//��������
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

//Duck�Ӷ�����
class MallardDuck:public Duck{
public:
	MallardDuck()
	{
		cout << "I'm a Mallard duck" << endl;
		m_fly = new FlyWithWings();
	}
};

//Duck�Ӷ�����
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