#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int intNumber = 2003;
  double doubleNumber = 1.98242;
  // original format
  cout << "The value of the flags variable is: " << cout.flags()
      << "\nPrint int and double in original format:  \n"
      << intNumber << '\t' << doubleNumber << endl << endl;
  
  // use cout flags to save the original format
  ios_base::fmtflags originalFormat = cout.flags();
  cout << hex << scientific << oct; //change format


  cout << "The value of the flags variable is: " << cout.flags()
      << "\nPrint int and double in new format:  \n"
      << intNumber << '\t' << doubleNumber << endl << endl;

  cout.flags(originalFormat); // restore format

  cout << "The restored value of the flags is : " << cout.flags() 
        << "\nPrint the original format again: \n"
      << intNumber << '\t' << doubleNumber << endl << endl;
}
