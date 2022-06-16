#include "Account.h"
using namespace std;
int main(){
	Account acc1(1000);
	acc1.checkBalance();
	acc1.debit(200);
	acc1.checkBalance();
	acc1.credit(900);
	acc1.checkBalance();
}
