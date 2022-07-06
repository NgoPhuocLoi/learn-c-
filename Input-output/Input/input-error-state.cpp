#include <iostream>

using namespace std;

int main(){
  int number;
  cout << "Before bad input operation: "
      << "\n cin.rdstate(): " << cin.rdstate()
      << "\n cin.eof(): " << cin.eof()
      << "\n cin.fail(): " << cin.fail()
      << "\n cin.bad(): " << cin.bad()
      << "\n cin.good(): " << cin.good()
      << "\n\n Expects an integer but enter a character: ";

  cin >> number;
  cout << endl;

  cout << "After bad input operation: "
      << "\n cin.rdstate(): " << cin.rdstate()
      << "\n cin.eof(): " << cin.eof()
      << "\n cin.fail(): " << cin.fail()
      << "\n cin.bad(): " << cin.bad()
      << "\n cin.good(): " << cin.good()
      << "\n\n Expects an integer but enter a character: ";

  cin.clear();

  cout << "After clear: \n" << "cin.fail() is : " << cin.fail()
        << "\n cin.good() is : " << cin.good() << endl;
}
