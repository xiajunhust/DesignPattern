//抽象工厂模式编程实现
//Author：江南烟雨
//E-Mail：xiajunhust@gmail.com
#include <iostream>
#include <string>

using namespace std;

//原料抽象类
class Dough{

};

class Sauce{

};

//原料具体类
class ThinCrustDough:public Dough{
public:
	ThinCrustDough(){
		cout << "ThinCrustDough is created" << endl;
	}
};

class MarinaraSauce:public Sauce{
public:
	MarinaraSauce(){
		cout << "MarinaraSauce is created" << endl;
	}
};

class ThickCrustDough:public Dough{
public:
	ThickCrustDough(){
		cout << "ThickCrustDough is created" << endl;
	}
};

class PlumTomatoSauce:public Sauce{
public:
	PlumTomatoSauce(){
		cout << "PlumTomatoSauce is created" << endl;
	}
};

//抽象工厂为产品家族提供接口
//原料工厂-抽象类
class PizzaIngredientFactory{
public:
	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
};

//原料工厂-纽约工厂具体类
class NYPizzaIngredientFactory:public PizzaIngredientFactory{
public:
	Dough* createDough(){
		return (new ThinCrustDough());
	}

	Sauce* createSauce(){
		return (new MarinaraSauce());
	}
};

//原料工厂-芝加哥工厂具体类
class ChicagoPizzaIngredientFactory:public PizzaIngredientFactory{
public:
	Dough* createDough(){
		return (new ThickCrustDough());
	}

	Sauce* createSauce(){
		return (new PlumTomatoSauce());
	}
};

//Pizza抽象类
class Pizza{
public:
	virtual void prepare() = 0;//负责搜集原料

	void bake(){
		cout << "baking" << endl;
	}

	void cut(){
		cout << "cutting" << endl;
	}

	void box(){
		cout << "boxing" << endl;
	}

	void setName(string name){
		this->name = name;
	}

	string getName(){
		return name;
	}

	~Pizza(){
		delete sauce;
		delete dough;
	}

	Sauce *sauce;
	Dough *dough;

private:
	string name;
};

//Pizza具体类-CheesePizza
class CheesePizza:public Pizza{
private:
	PizzaIngredientFactory *ingredientFactory;
	
public:
	~CheesePizza(){
		delete ingredientFactory;
	}

	CheesePizza(PizzaIngredientFactory *ingredientFactory){
		this->ingredientFactory = ingredientFactory;
	}

	void prepare(){
		cout << "Preparing " << getName() << endl;
		dough = ingredientFactory->createDough();
		sauce = ingredientFactory->createSauce();
	}
};

//Pizza具体类-ClamPizza
class ClamPizza:public Pizza{
private:
	PizzaIngredientFactory *ingredientFactory;

public:
	~ClamPizza(){
		delete ingredientFactory;
	}

	ClamPizza(PizzaIngredientFactory *ingredientFactory){
		this->ingredientFactory = ingredientFactory;
	}

	void prepare(){
		cout << "Preparing " << getName() << endl;
		dough = ingredientFactory->createDough();
		sauce = ingredientFactory->createSauce();
	}
};

//PizzaStore抽象类
class PizzaStore{
private: 
	Pizza *pizza;

public:
	PizzaStore(){
		pizza = NULL;
	}
	~PizzaStore(){
		delete pizza;
	}

	virtual Pizza* createPizza(string PizzaType) = 0;

	void orderPizza(string PizzaType){
		pizza = createPizza(PizzaType);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
	}
};

//PizzaStore具体类
class NYPizzaStore:public PizzaStore{
public:
	Pizza* createPizza(string PizzaType){
		//使用对应的原料工厂
		PizzaIngredientFactory *ingredientFactory = new NYPizzaIngredientFactory();
		Pizza *pizza;

		if ("cheese" == PizzaType)
		{
			pizza = new CheesePizza(ingredientFactory);
			pizza->setName("New York Style Cheese Pizza");
		}
		else if ("clam" == PizzaType)
		{
			pizza = new ClamPizza(ingredientFactory);
			pizza->setName("New York Style Clam Pizza");			
		}

		return pizza;
	}
};

//PizzaStore具体类
class ChicagoPizzaStore:public PizzaStore{
public:
	Pizza* createPizza(string PizzaType){
		//使用对应的原料工厂
		PizzaIngredientFactory *ingredientFactory = new ChicagoPizzaIngredientFactory();
		Pizza *pizza;

		if ("cheese" == PizzaType)
		{
			pizza = new CheesePizza(ingredientFactory);
			pizza->setName("Chicago Cheese Pizza");
		}
		else if ("clam" == PizzaType)
		{
			pizza = new ClamPizza(ingredientFactory);
			pizza->setName("Chicago Clam Pizza");			
		}

		return pizza;
	}
};

int main()
{
	PizzaStore *pizzaStore = new NYPizzaStore();
	pizzaStore->orderPizza("cheese");

	PizzaStore *pizzaStore2 = new  ChicagoPizzaStore();
	pizzaStore2->orderPizza("clam");

	delete pizzaStore;
	delete pizzaStore2;

	return 0;
}