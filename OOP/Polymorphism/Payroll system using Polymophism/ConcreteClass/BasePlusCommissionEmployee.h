#include "./CommissionEmployee.h"

#ifndef BASEPLUS_COMMISSION_EMPLOYEE
#define BASEPLUS_COMMISSION_EMPLOYEE 1

class BasePlusCommissionEmployee: public CommissionEmployee {
	public:
		BasePlusCommissionEmployee(const string &, const string &, const string &, 
						double = 0, double = 0, double = 0);
		virtual ~BasePlusCommissionEmployee(){};
		
		void setBaseSalary(double);
		double getBaseSalary() const;
		
		virtual double earnings() const override;
		virtual void print() const override;
		
	private:
		double baseSalary;
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, 
									const string &last, const string &ssn, 
									double sales, double rate, double salary)
	:CommissionEmployee(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary){
	if(salary >= 0)
		baseSalary = salary;
	else throw std::invalid_argument("Base Salary must be >= 0.0");
}

double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}


double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
	std::cout << "base-salaried ";
	CommissionEmployee::print();
	std::cout << "base salary: " << getBaseSalary() <<std::endl;
}

#endif



