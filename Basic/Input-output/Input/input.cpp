#include <iostream>

using namespace std;

int main(){
  // cin.get()
  /*char character;
  cout << "before input, cin.eof() is: " << cin.eof() <<endl;
  cout << "Enter a sentence followed by the EOF"<<endl;

  while( (character = cin.get() ) != EOF){
    cout.put(character);
  }
  
  cout << "EOF in this system is " << character << endl;
  cout << "After input EOF, cin.eof() is " << cin.eof();*/

  // =========================================
  /* const int SIZE = 50;
  char buffer1[SIZE];
  char buffer2[SIZE];

  cout << "Enter a sentence: \n";
  cin >> buffer1;

  cout << "The string get with cin was: " << buffer1 << endl;

  cin.get(buffer2, SIZE, 'e');
  char c = cin.get();

  cout << "The string get with cin.get was: " << buffer2 << endl;
  cout << "The next character is: " << c ; */

  //=========================================
  char sentence[80];
  cin.getline(sentence, 80);
  cout << "The string get with cin.getline() was: \n" << sentence ;
}
