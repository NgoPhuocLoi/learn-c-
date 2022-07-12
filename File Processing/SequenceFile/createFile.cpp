#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  ofstream outClientFile("clients.txt", ios::out);
  /* We can do that
   *    ofstream outClientFile;
   *    outClientFile.open("clients.txt", ios::out)
   * */

  if(!outClientFile){
    cerr << "File could not be opened!";
    exit(EXIT_FAILURE);
  }
  
  string name;
  int account;
  double balance;

  cout << "Enter the account, name and balance respectively.\n"
      << "Enter Ctrl + Z to end input\n?";

  while(cin >> account >> name >> balance){
    outClientFile << account << ' ' << name << ' ' << balance << endl;
    cout << '?';
  }
}
