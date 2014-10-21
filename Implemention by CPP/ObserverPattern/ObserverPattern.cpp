//�۲���ģʽC++���ʵ��
//author����������
//E-Mail��xiajunhust@gmail.com
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int setConditionTimes = 0;//��¼���õ��ܴ���

//�۲��ߣ�����壩����ӿ�
class Observer{
public:
	virtual void update(float temp,float humidity,float pressure) = 0;
};

//�������ӿ�
class Subject{
public:
	virtual void registerObserver(Observer *o) = 0;//ע��۲���
	virtual void removeObserver(Observer *o) = 0;//ɾ���۲���
	virtual void notifyObserver() = 0;//������״̬�ı�ʱ��֪ͨ���й۲���
};

//�������ʾ
class DisplayElement{
public: 
	virtual void display()= 0;
};

//WeatherData�����࣬�̳������������
class WeatherData:public Subject{
private:
	vector<Observer *> observers;
	float temperature;
	float humility;
	float pressure;

public:
	WeatherData(){}

	~WeatherData(){
		vector<Observer*>::iterator pos = observers.begin();
		for (;pos != observers.end();++pos)
		{
			delete (*pos);
		}
	}

	void registerObserver(Observer *o){
		observers.push_back(o);
	}

	void removeObserver(Observer *o){
		vector<Observer*>::iterator pos = find(observers.begin(),
			observers.end(),o);
		if (pos != observers.end())
		{
			observers.erase(pos);
		}
	}

	void notifyObserver()
	{
		vector<Observer*>::iterator pos = observers.begin();
		for (;pos != observers.end();++pos)
		{
			(*pos)->update(temperature,humility,pressure);
		}
	}

	//��������վ�õ����¹۲�ֵʱ��֪ͨ�۲���
	void messurementsChanged(){
		notifyObserver();
	}

	//��������վ�۲�ֵ
	void setMessurements(float temperature,float humility,float pressure){
		++setConditionTimes;
		this->temperature = temperature;
		this->humility = humility;
		this->pressure = pressure;
		messurementsChanged();
	}
};

//���������ࣺĿǰ״��
class CurrentConditionDisplay:public Observer,public DisplayElement{
private:
	float temperature;
	float humility;
	
	Subject *weatherData;

public: 
	CurrentConditionDisplay(Subject *weatherData){
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	~CurrentConditionDisplay(){}

	void update(float temp,float humi,float pressure){
		this->temperature = temp;
		this->humility = humi;

		display();
	}

	void display(){
		cout << "Current conditions: " << temperature << "F degrees and " <<
			humility << "% humility" << endl;
	}
};

//���������ࣺ����ͳ����
class WeatherStatisticsDisplay:public Observer,public DisplayElement{
private:
	float avgTemperatuere,maxTemperature,minTemperature;
	Subject *weatherData;

public: 
	WeatherStatisticsDisplay(Subject *weatherData){
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	~WeatherStatisticsDisplay(){}

	void update(float temp,float humi,float pressure){
		if (1 == setConditionTimes)
		{
			this->avgTemperatuere = temp;
			this->maxTemperature = temp;
			this->minTemperature = temp;
		}
		else{
			this->avgTemperatuere = (this->avgTemperatuere * (setConditionTimes - 1) + temp) / setConditionTimes;
			this->maxTemperature = this->maxTemperature > temp ? this->maxTemperature : temp;
			this->minTemperature = this->minTemperature < temp ? this->minTemperature : temp;
		}

		display();
	}

	void display(){
		cout << "Avg/Max/Min: temperature  " << avgTemperatuere << "/" << 
			maxTemperature << "/" <<minTemperature << endl;
	}
};

int main()
{
	WeatherData *weatherData = new WeatherData();

	CurrentConditionDisplay *currentConditionDisplay = new CurrentConditionDisplay(weatherData);
	WeatherStatisticsDisplay *weatherStatisticsDisplay = new WeatherStatisticsDisplay(weatherData);
	
	weatherData->setMessurements(80,65,30.4f);
	weatherData->setMessurements(82,70,29.2f);
	weatherData->setMessurements(78,90,29.2f);

	weatherData->removeObserver(weatherStatisticsDisplay);

	cout << "after remove observer WeatherStatisticsDisplay:" << endl;
	weatherData->setMessurements(80,65,30.4f);
	weatherData->setMessurements(82,70,29.2f);
	weatherData->setMessurements(78,90,29.2f);

	return 0;
}