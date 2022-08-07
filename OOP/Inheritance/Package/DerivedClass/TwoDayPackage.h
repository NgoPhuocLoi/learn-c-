#include "../BaseClass/Package.h"

#ifndef TWO_DAY_PACKAGE
#define TWO_DAY_PACKAGE 1

class TwoDayPackage: public Package{
	public:
		TwoDayPackage(const PeopleInfo &,const PeopleInfo &,
		 		double , double, double);
		
		double getFlatFee() const;
		void setFlatFee(double);
		
		double calculateCost() const;
	private:
		double flatFee;
};

//Definitions
TwoDayPackage::TwoDayPackage(const PeopleInfo &s, const PeopleInfo &r,
				double w, double cost, double fee)
	:Package(s, r, w, cost)
{
	setFlatFee(fee);
}

double TwoDayPackage::getFlatFee() const {
	return flatFee;
}
void TwoDayPackage::setFlatFee(double fee){
	if(fee > 0)
		flatFee = fee;
	else throw std::invalid_argument("Fee must be >0");
}

double TwoDayPackage::calculateCost() const{
	return getFlatFee() + Package::calculateCost();
}
#endif
