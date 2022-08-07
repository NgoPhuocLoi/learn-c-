#include <iostream>
#include <stdexcept>
#include <string>

using std::string;

#ifndef EMPLOYEE
#define EMPLOYEE 1

class Employee {
	public:
		Employee(const string &first, const string &last, const string &ssn)
			:firstName(first), lastName(last), socialSecurityNumber(ssn){};			
		virtual ~Employee(){};
		
		void setFirstName(const string &);
		string getFirstName() const;
		
		void setLastName(const string &);
		string getLastName() const;
		
		void setSocialSecurityNumber(const string &);
		string getSocialSecurityNumber() const;
		
		virtual double earnings() const = 0;
		virtual void print() const;
	private:
		string firstName, lastName, socialSecurityNumber;
};

//Definitions

void Employee::setFirstName(const string &first){
	firstName = first;
}

string Employee::getFirstName() const {
	return firstName;
}

void Employee::setLastName(const string &last){
	lastName = last;
}

string Employee::getLastName() const {
	return lastName;
}

void Employee::setSocialSecurityNumber(const string &ssn){
	socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const {
	return socialSecurityNumber;
}

void Employee::print() const {
	std::cout << getFirstName() << ' ' << getLastName()
	<< "\nsocial security number: " << getSocialSecurityNumber();

}


#endif



