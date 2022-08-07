#include "./AbstractClass/Employee.h"
#include "./ConcreteClass/SalariedEmployee.h"
#include "./ConcreteClass/CommissionEmployee.h"
#include "./ConcreteClass/BasePlusCommissionEmployee.h"
#include <vector>
#include <typeinfo>

using namespace std;

int main(){
	vector <Employee*> employees(3);
	employees[0] = new SalariedEmployee("Loi", "Ngo", "1234", 3000);
	employees[1] = new CommissionEmployee("john", "Erest", "1234", 3000, .6);
	employees[2] = new BasePlusCommissionEmployee("Loppy", "Fruster", "1234",
													 3000, .6, 10000);
													 
	for(Employee* ePtr: employees){
		ePtr->print();
		cout << endl;
		// atempt to downcase pointer
		BasePlusCommissionEmployee *derivedPtr = 
			dynamic_cast<BasePlusCommissionEmployee*>(ePtr);
		// determine whether element points to a BasePlusCommissionEmployee
		if(derivedPtr != nullptr){
			double oldSalary = derivedPtr->getBaseSalary();
			cout << "Old salary: " << oldSalary << endl;
			derivedPtr->setBaseSalary(1.1*oldSalary);
			cout << "New salary: " << derivedPtr->getBaseSalary() << endl;
		}
		
		cout << "Earnings : " << ePtr->earnings() << endl;
	}
	
	// deallocate 
	for(const Employee *ePtr: employees){
		cout << "Deleting object of " << typeid(*ePtr).name() << endl;
		delete ePtr;
	}
	
	cout << "\nRun";
}
