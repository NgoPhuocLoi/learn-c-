#include "CreateAndDestroy.h"

using namespace std;

CreateAndDestroy first(1, "(global before main)");

void create(){
	cout << "\n===CREATE FUNCTION: EXECUTION BEGINS===" << endl;
	CreateAndDestroy fifth(5, "(local automatic in create)");
	static CreateAndDestroy sixth(6, "(local static in create)");
	CreateAndDestroy seventh(7, "(local automatic in create)");
	cout << "\n===CREATE FUNCTION: EXECUTION ENDS===" << endl;
}

int main(){
	cout << "\n===MAIN FUNCTION: EXECUTION BEGINS===" << endl;
	CreateAndDestroy second(2, "(local automatic in main)");
	static CreateAndDestroy third(3, "(local static in main)");
	create();
	
	CreateAndDestroy fourth(4, "(local automatic in main)");
	cout << "\n===MAIN FUNCTION: EXECUTION ENDS===" << endl;
//	cout << "Run";
}
