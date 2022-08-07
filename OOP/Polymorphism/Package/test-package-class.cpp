#include "./AbstractClass/Package.h"
#include "./ConcreteClass/TwoDayPackage.h"
#include "./ConcreteClass/OvernightPackage.h"
#include <vector>

using namespace std;

int main(){
	PeopleInfo sender;
	sender.name = "Loi";
	sender.address = "Can Tho";
	sender.zipCode = "1234";
	PeopleInfo recipient;
	recipient.name = "jonh";
	recipient.address = "Ha Noi";
	recipient.zipCode = "99911";
	
	//Base class (Package)
	Package a(sender, recipient, 20, 2);
	a.printRecipientInfo();
	a.printSenderInfo();
	cout << "Cost: " << a.calculateCost();
	
	// TwoDayPackage derived from Package
	TwoDayPackage b(sender, recipient, 30, 3, 40);
	cout << "\nTDP cost: " << b.calculateCost();
	
	//Overnight Package derived from Package
	OvernightPackage c(sender, recipient, 30, 3, 2);
	cout << "\nON cost: " << c.calculateCost();
	
	//Polymophism
	cout << "\n==================================\n";
	vector<Package*> packages(2);
	packages[0] = &b;
	packages[1] = &c;
	
	for(const Package* pkgPtr: packages){
		cout << "Cost: " << pkgPtr->calculateCost() << endl;
	}
	cout << "\nRun";
}
