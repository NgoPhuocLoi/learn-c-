#include <iostream>
#include <stdexcept>
#include <string>

using std::string;

#ifndef COMMISSION
#define COMMISSION 1

class CommissionEmployee  {
	public:
		CommissionEmployee(const string &, const string &, 
					const string &, double = 0, double = 0);
		
		void setFirstName(const string &);
		string getFirstName() const;
		
		void setLastName(const string &);
		string getLastName() const;
		
		void setSocialSecurityNumber(const string &);
		string getSocialSecurityNumber() const;
		
		void setGrossSales(double);
		double getGrossSales() const;
		
		void setCommissionRate(double);
		double getCommissionRate() const;
		
		virtual double earnings() const;
		virtual void print() const;
	protected:
		string firstName, lastName, socialSecurityNumber;
		double grossSales, commissionRate;
};

// definitions

CommissionEmployee::CommissionEmployee(const string &first, const string &last, 
									const string &ssn, double sales, double rate)
	:firstName(first), lastName(last), socialSecurityNumber(ssn)
{
	setGrossSales(sales);
	setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const string &first){
	firstName = first;
}

string CommissionEmployee::getFirstName() const {
	return firstName;
}

void CommissionEmployee::setLastName(const string &last){
	lastName = last;
}

string CommissionEmployee::getLastName() const {
	return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn){
	socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const {
	return socialSecurityNumber;
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
	std::cout << "commission employee: " << getFirstName() << ' ' << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber()
		<< "\ngross sales: " << getGrossSales()
		<< "\ncommission rate: " << getCommissionRate() << std::endl;
}

#endif



