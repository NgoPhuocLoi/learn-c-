#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  // dec, oct, hex and setbase ============================
 /* int number;
  cout << "Enter a decimal number: ";
  cin >> number;

  cout << "in hexadecimal is: " << hex << number << endl;
  cout << "in octal is: " << oct << number << endl;

  cout << setbase(10) << "in decimal is: " << number; */

  // floating-point precision================================
  /*double root2 = sqrt(2);
  int places;

  cout << "Square root of 2 with precisions 0-9: \n";

  cout << fixed;

  for(places = 0; places < 10; places++){
    cout.precision(places);
    cout << root2 << endl;
  }

  cout << "set with setprecision: \n";
  
  for(places = 0; places < 10; places++){
    cout << setprecision(places) << root2 << endl;
  } */

  // width, setw =========================================
  int widthValue = 4;
  char sentence[10];
  cout << "Enter a sentence: \n";
  cin.width(5);

  while(cin >> sentence){
    cout.width(widthValue++);
    cout << sentence <<endl;
    cin.width(5);
  }
}
