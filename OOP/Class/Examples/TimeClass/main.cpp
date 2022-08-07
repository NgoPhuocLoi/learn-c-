#include "Time.h"

using namespace std;

int main(){
	Time a(23,59,30);
	a.printStandard();
	for(int i = 0; i < 60; i++){
		a.tick();
		a.printStandard();
	}
//	time(a);
}
