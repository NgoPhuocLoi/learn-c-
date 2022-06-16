
#include "GradeBook.h"
using namespace std;



int main(){
	string name = "hello";
	array<array<int, GradeBook::tests>, GradeBook::students> grades = {1,2,3
				,4,5,6,
				7,8,9,
				10,11,12};
	GradeBook a(name, grades);

	a.displayMessage();
	a.displayGrade();
	cout << "\n\n===Run successfully!!===";
}

