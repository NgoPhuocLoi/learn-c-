#include "./Array.h"

using namespace std;

void testConstArr(const Array &z){
	cout << z[2] << endl;
}

int main(){
	Array a1(2);
	Array a2(3);
	Array a10 = {9,8,7,6};
	
	cout << "a1 size: " << a1.getSize() << endl;
	cout << a1;
	cout << "a2 size: " << a2.getSize() << endl;
	cout << a2;
	cout << "a10 size: " << a10.getSize() << endl;
	cout << a10;
	
	cin >> a1 >> a2;
	
	cout << a1 << a2;
	
	if(a1 != a2)
		cout << "a1 != a2 \n";
		
	Array a3(a1);
	cout << a3;
	
	a1 = a2;
	
	cout << a1 << a2;
	
	if(a1 == a2)
		cout << "a1 = a2\n";
		
	cout << "a1[2] = " << a1[2] << endl;
	
	a1[2] = 1000;
	cout << a1;
	
	const int a = a1[2];
	cout << a;
	
	try{
		a1[20] = 10;
	}catch(out_of_range &ex){
		
		cout << ex.what();
	}
	
	testConstArr(a1);
	
	cout << "\nRun";
}
