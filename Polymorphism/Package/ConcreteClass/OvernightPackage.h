#include "../AbstractClass/Package.h"

#ifndef OVERNIGHT_PACKAGE
#define OVERNIGHT_PACKAGE 1

class OvernightPackage: public Package{
	public:
		OvernightPackage(const PeopleInfo &,const PeopleInfo &,
		 		double , double, double);
		
		double getAdditionalFeePerKg() const;
		void setAdditionalFeePerKg(double);
		
		virtual double calculateCost() const override;
	private:
		double additionalFeePerKg;
};

//Definitions
OvernightPackage::OvernightPackage(const PeopleInfo &s, const PeopleInfo &r,
				double w, double cost, double fee)
	:Package(s, r, w, cost)
{
	setAdditionalFeePerKg(fee);
}

double OvernightPackage::getAdditionalFeePerKg() const {
	return additionalFeePerKg;
}
void OvernightPackage::setAdditionalFeePerKg(double fee){
	if(fee > 0)
		additionalFeePerKg = fee;
	else throw std::invalid_argument("Fee must be >0");
}

double OvernightPackage::calculateCost() const{
	return getWeight()*getAdditionalFeePerKg() + Package::calculateCost();
}
#endif
