#include "Date.h"

using namespace std;

int main(){
	Date d1(27, 12, 2010);
	Date d2;
	
	cout << "d1 is " << d1 << endl;	
	cout << "d1+=7 is " << (d1 += 7);
	cout << "\nRun";
	
	d2.setDay(28,2,2008);
	cout << "d2 is " << d2 << endl;
	cout << "++d2 is " << ++d2 << endl;
	
	Date d3(13, 7 ,2010);
	cout << "Testing prefix increment operator: \n";
	cout << "d3 is "<< d3 << endl;
	cout << "++d3 is " << ++d3 << endl;
	cout << "d3 is "<< d3 << endl;
	
	cout << "Testing postfix increment operator: \n";
	cout << "d3 is "<< d3 << endl;
	d3++;
	cout << "d3 is "<< d3 << endl;
}
