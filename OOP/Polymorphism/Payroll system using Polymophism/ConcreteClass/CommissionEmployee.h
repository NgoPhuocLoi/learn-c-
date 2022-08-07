#include "../AbstractClass/Employee.h"

#ifndef COMMISSION_EMPLOYEE
#define COMMISSION_EMPLOYEE 1

class CommissionEmployee: public Employee {
	public:
		CommissionEmployee(const string &, const string &, const string &, 
						double = 0, double = 0);
		virtual ~CommissionEmployee(){};
		
		void setGrossSales(double);
		double getGrossSales() const;
		
		void setCommissionRate(double);
		double getCommissionRate() const;
		
		virtual double earnings() const override;
		virtual void print() const override;
		
	private:
		double grossSales;
		double commissionRate;
};

CommissionEmployee::CommissionEmployee(const string &first, const string &last, 
									const string &ssn, double sales, double rate)
	:Employee(first, last, ssn)
{
	setGrossSales(sales);
	setCommissionRate(rate);
}

void CommissionEmployee::setGrossSales(double sales){
	if(sales >= 0)
		grossSales = sales;
	else throw std::invalid_argument("Gross sales must be >= 0.0");
}

double CommissionEmployee::getGrossSales() const {
	return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate){
	if(rate > 0 && rate < 1)
		commissionRate = rate;
	else throw std::invalid_argument("Commission rate must be > 0 and < 1");
}

double CommissionEmployee::getCommissionRate() const {
	return commissionRate;
}

double CommissionEmployee::earnings() const {
	return getGrossSales()*getCommissionRate();
}

void CommissionEmployee::print() const {
	std::cout << "commission employee: ";
	Employee::print();
	std::cout << "\ngross sales: " << getGrossSales()
	<< "; commission rate: " << getCommissionRate() <<std::endl;
}

#endif



