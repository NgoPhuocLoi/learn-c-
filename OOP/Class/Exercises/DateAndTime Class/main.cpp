#include "./DateAndTime.h"
using namespace std;
int main(){
	Date d(25,11,2003);
	Time t(23,59,30);
	DateAndTime test(d,t);
	for(int i = 0; i < 60; i++){
		test.tick();
		test.printStandard();
	}
}
