#include <iostream>
#include <cstdlib>
#include <fstream>
#include "./ClientData.h"

using namespace std;

int main(){
  int account;
  string firstName, lastName;
  double balance;
  ClientData client;
  fstream outCredit("clients.dat", ios::out | ios::binary);

  cout << "Enter the account number (1- 100), 0 to end input: \n?";
  cin >> account;

  while(account > 0 && account <= 100){
    cout << "Enter last name, first name, balance respectively:\n?";
    cin >> lastName >> firstName >> balance;

    client.setFirstName(firstName);
    client.setLastName(lastName);
    client.setBalance(balance);
    client.setAccountNumber(account);

    // seek position in file to write
    outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

    outCredit.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

    cout << "Enter the account number (1- 100), 0 to end input: \n?";
    cin >> account;
  }
  
}
