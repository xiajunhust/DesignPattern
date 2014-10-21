//��������ģʽ���ʵ��
#include <iostream>
#include <string>

using namespace std;

//������Pizza
class Pizza{
public:
	Pizza(){}
	virtual void prepare(){};//׼��pizza
	virtual void bake(){};//�濾pizza
	virtual void cut(){};//��Ƭ
	virtual void box(){}; //װ��
};

//�����pizza��
//ŦԼ��ζ�ĸ��ֿ�ζPizza
class NYStyleCheesePizza:public Pizza{
public:
	NYStyleCheesePizza(){
		cout << "NYStyleCheesePizza is created!" << endl;
	}

	void prepare(){
		cout << "NYStyleCheesePizza is prepared!" << endl;
	};

	void bake(){
		cout << "NYStyleCheesePizza is baked!" << endl;
	}

	void cut(){
		cout << "NYStyleCheesePizza is cut!" << endl;
	}

	void box(){
		cout << "NYStyleCheesePizza is boxed!" << endl;
	}
};

class NYStylePepperoniPizza:public Pizza{
public:
	NYStylePepperoniPizza(){
		cout << "NYStylePepperoniPizza is created!" << endl;
	}

	void prepare(){
		cout << "NYStylePepperoniPizza is prepared!" << endl;
	};

	void bake(){
		cout << "NYStylePepperoniPizza is baked!" << endl;
	}

	void cut(){
		cout << "NYStylePepperoniPizza is cut!" << endl;
	}

	void box(){
		cout << "NYStylePepperoniPizza is boxed!" << endl;
	}
};

//֥�Ӹ��ζ�ĸ��ֿ�ζPizza
class ChicagoStyleCheesePizza:public Pizza{
public:
	ChicagoStyleCheesePizza(){
		cout << "ChicagoStyleCheesePizza is created!" << endl;
	}

	void prepare(){
		cout << "ChicagoStyleCheesePizza is prepared!" << endl;
	};

	void bake(){
		cout << "ChicagoStyleCheesePizza is baked!" << endl;
	}

	void cut(){
		cout << "ChicagoStyleCheesePizza is cut!" << endl;
	}

	void box(){
		cout << "ChicagoStyleCheesePizza is boxed!" << endl;
	}
};

class ChicagoPepperoniPizza:public Pizza{
public:
	ChicagoPepperoniPizza(){
		cout << "ChicagoPepperoniPizza is created!" << endl;
	}

	void prepare(){
		cout << "ChicagoPepperoniPizza is prepared!" << endl;
	};

	void bake(){
		cout << "ChicagoPepperoniPizza is baked!" << endl;
	}

	void cut(){
		cout << "ChicagoPepperoniPizza is cut!" << endl;
	}

	void box(){
		cout << "ChicagoPepperoniPizza is boxed!" << endl;
	}
};

//������PizzaStore
class PizzaStore{
public:
	PizzaStore()
	{
		pizza = NULL;
	}
	~PizzaStore()
	{
		delete pizza;
	}
	Pizza* orderPizza(string PizzaType)
	{
		pizza = createPizza(PizzaType);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

	virtual Pizza* createPizza(string PizzaType) = 0;

private:
	Pizza *pizza;
};

//ŦԼ��ζPizzaStore��
class NYStylePizzaStore:public PizzaStore{
public:
	Pizza* createPizza(string PizzaType){
		Pizza *pizza;
		if ("cheese" == PizzaType)	{
			pizza = new NYStyleCheesePizza();
		}
		else if ("pepperoni" == PizzaType)
		{
			pizza = new NYStylePepperoniPizza();
		}

		return pizza;
	}
};

//֥�Ӹ��ζPizzaStore��
class ChicagoStylePizzaStore:public PizzaStore{
public:
	Pizza* createPizza(string PizzaType){
		Pizza *pizza;
		if ("cheese" == PizzaType)	{
			pizza = new ChicagoStyleCheesePizza();
		}
		else if ("pepperoni" == PizzaType)
		{
			pizza = new ChicagoPepperoniPizza();
		}
		return pizza;
	}
};

int main()
{
	PizzaStore *nyPizzaStore = new NYStylePizzaStore();
	nyPizzaStore->orderPizza("cheese");

	PizzaStore *chiPizzaStore = new ChicagoStylePizzaStore();
	chiPizzaStore->orderPizza("pepperoni");

	delete nyPizzaStore;
	delete chiPizzaStore;
}