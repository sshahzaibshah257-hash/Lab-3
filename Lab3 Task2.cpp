#include<iostream>
using namespace std;
class Employee {
protected:
	virtual void calculateSalary() = 0;
};
class FullTimeEmployee :public Employee {
	int salary = 60000;
	string name;
	int id;
public:
	FullTimeEmployee(string n, int id) {
		name = n;
		this->id = id;

		}
	void calculateSalary() override {
		cout << name << "'s salary is " << salary << endl;
	}
};
class Parttimeemploye :public Employee {
	int salary;
	string name;
	int hourlyrate;
	int hours;
public:
	Parttimeemploye(string name, int hourlyrate, int hours) {
		this->hourlyrate = hourlyrate;
		this->hours = hours;
		this->name = name;

	}
	void calculateSalary() override {
		salary = hourlyrate * hours;
		cout << name << "'s salary is " << salary << endl;

	}
};
int main() {
	FullTimeEmployee o1("Shahzaib", 24);
	o1.calculateSalary();
	Parttimeemploye o2("Saim", 100, 13);
	o2.calculateSalary();
	return 0;
}
