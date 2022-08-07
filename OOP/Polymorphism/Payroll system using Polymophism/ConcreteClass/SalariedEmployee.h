#include "../AbstractClass/Employee.h"

#ifndef SALARIED_EMPLOYEE
#define SALARIED_EMPLOYEE 1

class SalariedEmployee: public Employee {
	public:
		SalariedEmployee(const string &, const string &, const string &, double = 0);
		virtual ~SalariedEmployee(){};
		
		void setWeeklySalary(double);
		double getWeeklySalary() const;
		
		virtual double earnings() const override;
		virtual void print() const override;
		
	private:
		double weeklySalary;
};

// Definitions

SalariedEmployee::SalariedEmployee(const string &first, const string &last, 
								const string &ssn, double salary)
	:Employee(first, last, ssn)
{
	setWeeklySalary(salary);
}

void SalariedEmployee::setWeeklySalary(double salary){
	if(salary > 0)
		weeklySalary = salary;
	else throw std::invalid_argument("Salary must be > 0");
}

double SalariedEmployee::getWeeklySalary() const {
	return weeklySalary;
}

double SalariedEmployee::earnings() const {
	return getWeeklySalary();
}

void SalariedEmployee::print() const {
	std::cout << "Salaried employee: ";
	Employee::print();
	std::cout << "\nweekly salary: " << getWeeklySalary() << std::endl;
}

#endif



