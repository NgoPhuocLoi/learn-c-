#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void outputLine(int account,const string &name, double balance){
  cout << left;
  cout << setw(10) << account
      << setw(13) << name
      << setw(7) << balance << endl;
}

int main(){
  ifstream inClientFile("clients.txt", ios::in);
  int account;
  string name;
  double balance;

  if(!inClientFile){
    cerr << "File could not opened!";
    exit(EXIT_FAILURE);
  }

  cout << left<<setw(10) << "Account" << setw(13) << "Name" << "Balance" << endl;

  inClientFile.seekg(15);
  while(inClientFile >> account >> name >> balance){
    outputLine(account, name, balance);
    cout << "Location: " << inClientFile.tellg() << endl;
  }
}
