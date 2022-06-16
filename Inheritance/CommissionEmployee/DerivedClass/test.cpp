#include "./BasePlusCommissionEmployee.h"

using namespace std;

int main(){
	BasePlusCommissionEmployee e("Loi", "Ngo", "12345-123",10000, .06, 3000);
	e.print();
	cout << "Employee earns: " << e.earnings();
	e.setGrossSales(12000);
	e.setCommissionRate(.08);
	cout << "\nEmployee earns: " << e.earnings();
	cout << "\nRun";
}
