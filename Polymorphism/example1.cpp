#include "../Inheritance/CommissionEmployee/DerivedClass/BasePlusCommissionEmployee.h"

using namespace std;

int main(){
	CommissionEmployee e1("Jony", "Reip", "91000-123",20000, .08);;
	BasePlusCommissionEmployee e2("Loi", "Ngo", "12345-123",10000, .06, 3000);
	
	CommissionEmployee *cePtr = &e1;
	BasePlusCommissionEmployee *bcePtr = &e2;
	
	e1.print();
	cout << "\n\n";
	e2.print();
	
	cout << "\n\n";
	cePtr->print();
	cout << "\n\n";
	bcePtr->print();
	
	cePtr = &e2;
	cout << "\n\n";
	cePtr->setFirstName("ABC");
	e2.print();
}
