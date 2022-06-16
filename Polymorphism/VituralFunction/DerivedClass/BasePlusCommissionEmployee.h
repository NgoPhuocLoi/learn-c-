#include <iostream>
#include <stdexcept>
#include <string>
#include "../BaseClass/CommissionEmployee.h"

using std::string;

#ifndef BASEPLUS
#define BASEPLUS 1

class BasePlusCommissionEmployee : public CommissionEmployee {
	public:
		BasePlusCommissionEmployee(const string &first, const string &last,
								const string &ssn, double sales = 0, 
								double rate = 0, double salary = 0)
			: CommissionEmployee(first, last, ssn, sales, rate)
		{
			setBaseSalary(salary);
		}
		
		void setBaseSalary(double salary){
			if(salary > 0)
				baseSalary = salary;
			else throw std::invalid_argument("Base salary must be > 0");
		}
		
		double getBaseSalary() const {
			return baseSalary;
		}
		
		double earnings() const override {
			return getBaseSalary() + CommissionEmployee::earnings();
		}
		
		void print() const override {
				CommissionEmployee::print();
				std::cout << "Base salary: " << getBaseSalary() << std::endl;
		}

	private:
		double baseSalary;
};

#endif



