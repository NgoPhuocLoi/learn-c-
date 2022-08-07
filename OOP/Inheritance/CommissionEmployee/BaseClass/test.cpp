#include "./CommissionEmployee.h"
#include <iomanip>
using namespace std;

int main(){
	CommissionEmployee e1("Loi", "Ngo", "123-45-6789", 10000, 0.06);
	
	cout << fixed << setprecision(2);
	
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << e1.getFirstName()
		<< "\nLast name is " <<  e1.getLastName()
		<< "\nSocial security number is " 
		<<	e1.getSocialSecurityNumber()
		<< "\nGross sales is " << e1.getGrossSales()
		<< "\nCommission rate is " << e1.getCommissionRate() << endl;

	e1.setGrossSales(12000);
	e1.setCommissionRate(.08);
	
	e1.print();
	
	cout << e1.earnings();

	cout << "Run";
}
