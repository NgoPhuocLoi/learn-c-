#include "./AbstractClass/Employee.h"
#include "./ConcreteClass/SalariedEmployee.h"
#include "./ConcreteClass/CommissionEmployee.h"
#include "./ConcreteClass/BasePlusCommissionEmployee.h"
#include <vector>

using namespace std;

int main(){
	SalariedEmployee a("Loi", "Ngo", "1234", 3000);
	CommissionEmployee b("john", "Erest", "1234", 3000, .6);
	BasePlusCommissionEmployee c("Loppy", "Fruster", "1234", 3000, .6, 10000);
	
	cout << "Employees processed individually using static binding:\n\n";
	a.print();
	cout << "Earned $" << a.earnings() << "\n\n";
	b.print();
	cout << "Earned $" << b.earnings() << "\n\n";
	c.print();
	cout << "Earned $" << c.earnings() << "\n\n";
	
	vector<Employee*> employees(3);
	employees[0] = &a;
	employees[1] = &b;
	employees[2] = &c;
	
	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	
	cout << "Virtual function calls made off base-class pointers:\n\n";
	for(const Employee *ePtr : employees){
		ePtr->print();
		cout << "\nearned $" << ePtr->earnings() << "\n\n";
	}
	
	cout << "Virtual function calls made off base-class references:\n\n";
	for(const Employee *ePtr : employees){
		(*ePtr).print();
		cout << "\nearned $" << (*ePtr).earnings() << "\n\n";
	}

	

}
