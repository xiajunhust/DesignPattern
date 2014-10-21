//简单工厂模式编程实现
#include <iostream>
#include <string>

using namespace std;

//比萨抽象类
class Pizza{
public:
	Pizza(){}
	virtual void prepare(){};//准备pizza
	virtual void bake(){};//烘烤pizza
	virtual void cut(){};//切片
	virtual void box(){}; //装盒
};

//具体的pizza类
class CheesePizza:public Pizza{
public:
	CheesePizza(){
		cout << "CheesePizza is created!" << endl;
	}

	void prepare(){
		cout << "CheesePizza is prepared!" << endl;
	};

	void bake(){
		cout << "CheesePizza is baked!" << endl;
	}

	void cut(){
		cout << "CheesePizza is cut!" << endl;
	}

	void box(){
		cout << "CheesePizza is boxed!" << endl;
	}
};

class VeggiePizza:public Pizza{
public:
	VeggiePizza(){
		cout << "VeggiePizza is created!" << endl;
	}

	void prepare(){
		cout << "VeggiePizza is prepared!" << endl;
	};

	void bake(){
		cout << "VeggiePizza is baked!" << endl;
	}

	void cut(){
		cout << "VeggiePizza is cut!" << endl;
	}

	void box(){
		cout << "VeggiePizza is boxed!" << endl;
	}
};

class ClamPizza:public Pizza{
public:
	ClamPizza(){
		cout << "ClamPizza is created!" << endl;
	}

	void prepare(){
		cout << "ClamPizza is prepared!" << endl;
	};

	void bake(){
		cout << "ClamPizza is baked!" << endl;
	}

	void cut(){
		cout << "ClamPizza is cut!" << endl;
	}

	void box(){
		cout << "ClamPizza is boxed!" << endl;
	}
};

class PepperoniPizza:public Pizza{
public:
	PepperoniPizza(){
		cout << "PepperoniPizza is created!" << endl;
	}

	void prepare(){
		cout << "PepperoniPizza is prepared!" << endl;
	};

	void bake(){
		cout << "PepperoniPizza is baked!" << endl;
	}

	void cut(){
		cout << "PepperoniPizza is cut!" << endl;
	}

	void box(){
		cout << "PepperoniPizza is boxed!" << endl;
	}
};

//简单工厂：负责创建pizza
class SimplePizzaFactory{
public:
	//创建pizza对象
	Pizza* createPizza(string PizzaType){
		Pizza *pizza = NULL;
		if("cheese" == PizzaType)
			pizza = new CheesePizza();
		else if("pepperoni" == PizzaType)
			pizza = new PepperoniPizza();
		else if("clam" == PizzaType)
			pizza = new ClamPizza();
		else if("veggie" == PizzaType)
			pizza = new VeggiePizza();

		return pizza;
	}
};

//pizza store类
class PizzaStore{
private:
	SimplePizzaFactory factory;//简单工厂对象

	Pizza *pizza;

public:
	PizzaStore(SimplePizzaFactory factory){
		this->factory = factory;
		pizza = NULL;
	}

	~PizzaStore(){
		if(NULL != pizza)
			delete pizza;
	}

	Pizza* orderPizza(string PizzaType)
	{
		pizza = factory.createPizza(PizzaType);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}
};

int main()
{
	SimplePizzaFactory factory;
	PizzaStore *store = new PizzaStore(factory);
	store->orderPizza("cheese");
	store->orderPizza("clam");

	return 0;
}