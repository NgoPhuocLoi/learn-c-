#include <iostream>
#include <stdexcept>
#include <string>

using std::string;

#ifndef PACKAGE
#define PACKAGE 1

struct PeopleInfo {
	string name;
	string address;
	string zipCode;
};

class Package {
	
	public:
		Package(const PeopleInfo &,const PeopleInfo &,
		 		double , double);
		virtual ~Package(){};
		
		string getSenderName() const;
		void setSenderName(const string &);
		string getSenderAddress() const;
		void setSenderAddress(const string &);
		string getSenderZipCode() const;
		void setSenderZipCode(const string &);
		void printSenderInfo() const;
		
		string getRecipientName() const;
		void setRecipientName(const string &);
		string getRecipientAddress() const;
		void setRecipientAddress(const string &);
		string getRecipientZipCode() const;
		void setRecipientZipCode(const string &);
		void printRecipientInfo() const;
		
		double getWeight() const;
		void setWeight(double);
		
		double getCostPerKg() const;
		void setCostPerKg(double);
		
		virtual double calculateCost() const;
		
	private:
		PeopleInfo sender;
		PeopleInfo recipient;
		double weight;
		double costPerKg;
};

//Definitions==========

//construtor
Package::Package(const PeopleInfo &s, const PeopleInfo &r,
				double w, double cost)
	:sender(s), recipient(r)
{
	setWeight(w);
	setCostPerKg(cost);
}

// sender infomations
string Package::getSenderName() const{
	return sender.name;
};
void Package::setSenderName(const string &name){
	sender.name = name;
};
string Package::getSenderAddress() const{
	return sender.address;
};
void Package::setSenderAddress(const string &address){
	sender.address = address;
};
string Package::getSenderZipCode() const{
	return sender.zipCode;
};
void Package::setSenderZipCode(const string &code){
	sender.zipCode = code;
};
void Package::printSenderInfo() const {
	std::cout << "===SENDER INFORMATIONS:\n"
			<< "Name: " << getSenderName()
			<<"\nAddress: " << getSenderAddress()
			<< "\nZip Code: " << getSenderZipCode() << std::endl;
}

//recipient informations
string Package::getRecipientName() const{
	return recipient.name;
};
void Package::setRecipientName(const string &name){
	recipient.name = name;
};
string Package::getRecipientAddress() const{
	return recipient.address;
};
void Package::setRecipientAddress(const string &address){
	recipient.address = address;
};
string Package::getRecipientZipCode() const{
	return recipient.zipCode;
};
void Package::setRecipientZipCode(const string &code){
	recipient.zipCode = code;
};
void Package::printRecipientInfo() const {
	std::cout << "===RECIPIENT INFORMATIONS:\n"
			<< "Name: " << getRecipientName()
			<<"\nAddress: " << getRecipientAddress()
			<< "\nZip Code: " << getRecipientZipCode() << std::endl;
}
// Package informations
double Package::getWeight() const{
	return weight;
};
void Package::setWeight(double w){
	if(w > 0 && w < 500)
		weight = w;
	else throw std::invalid_argument("Package's weight must be > 0kg and  < 500 kg");
};

double Package::getCostPerKg() const{
	return costPerKg;
};
void Package::setCostPerKg(double cost){
	if(cost > 0)
		costPerKg = cost;
	else throw std::invalid_argument("Cost must be > 0");
};
// Calculate function
double Package::calculateCost() const {
	return weight*costPerKg;
}

#endif
