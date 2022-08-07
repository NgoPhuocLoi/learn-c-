#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

enum RequestType {
  ZERO_BALANCE = 1,
  CREDIT_BALANCE,
  DEBIT_BALANCE,
  END
};
int getRequest();
bool shouldDisplay(int, double);
void outputLine(int, const string &, double);

int main(){
  ifstream inClientFile("../clients.txt");
  int account;
  string name;
  double balance;
  
  if(!inClientFile){
    cerr << "File cound not opened!";
    exit(EXIT_FAILURE);
  }

  int request = getRequest();

  while(request != END){
    switch(request){
      case ZERO_BALANCE :
        cout << "\n Accounts with zero balance: \n";
        break;
      case CREDIT_BALANCE :
        cout << "\n Accounts with credit balance: \n";
        break;
      case DEBIT_BALANCE :
        cout << "\n Accounts with debit balance: \n";
        break;
    }

    inClientFile >> account >> name >> balance;

    while(!inClientFile.eof()){
      if(shouldDisplay(request, balance))
        outputLine(account, name, balance);

      inClientFile >> account >> name >> balance;
    }
  
    inClientFile.clear(); //reset eof for the next input
    inClientFile.seekg(0);
    request = getRequest();
  }

  cout << "End of run" << endl;
}

int getRequest(){
  int request;

  cout << "\nEnter request: \n"
      <<"1. List accounts with zero balances\n"
      <<"2. List accounts with credit balances\n"
      <<"3. List accounts with debit balances\n"
      << "4. End of run";

  do{
    cout<< "\n?";
    cin >> request;
  }while(request < ZERO_BALANCE || request > END );

  return request;
}

bool shouldDisplay(int type, double balance){
  if(type == ZERO_BALANCE && balance == 0)
    return true;
  if(type == CREDIT_BALANCE && balance < 0)
    return true;
  if(type == DEBIT_BALANCE && balance > 0)
    return true;

  return false;
}

void outputLine(int account, const string &name, double balance){
  cout << left;
  cout << setw(10) << account
      << setw(13) << name
      << setw(7) << balance << endl;
}
