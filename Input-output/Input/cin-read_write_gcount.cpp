#include <iostream>

using namespace std;

int main(){
  const int SIZE = 80;
  char buffer[80];

  cout << "Enter a sentence: \n";

  cin.read(buffer, 20);

  cout << "\ncin.gcount() is : " << cin.gcount();
  cout << "The sentence was: \n";
  cout.write(buffer, cin.gcount());
}
