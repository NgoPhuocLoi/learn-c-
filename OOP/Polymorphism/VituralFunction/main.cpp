#include "./DerivedClass/BasePlusCommissionEmployee.h"

using namespace std;

int main(){
	CommissionEmployee e1("Jony", "Reip", "91000-123",20000, .08);;
	BasePlusCommissionEmployee e2("Loi", "Ngo", "12345-123",10000, .06, 3000);
	
	CommissionEmployee *cePtr = &e1;
	e1.print();
	cout << "\n\n";
	e2.print();
	cout << "\n\n";
	cePtr->print();
	cout << "\n\n";
	
	cePtr = &e2;
	cePtr->print();
	cout << "\nRun";
}
