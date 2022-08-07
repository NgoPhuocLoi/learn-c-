#include "Date.h"

using namespace std;

int main(){
	Date birthDay(25,11,2003);
	birthDay.displayDate();
	for(int i = 0; i < 60; i++){
		birthDay.nextDay();
		birthDay.displayDate();
	}

	birthDay.displayDate();
}
