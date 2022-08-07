#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "./ClientData.h"

using namespace std;

void outputLine(const ClientData &record){
  cout << left << setw(10) << record.getAccountNumber()
       << setw(16) << record.getLastName()
       << setw(11) << record.getFirstName()
       << setw(10) << right << record.getBalance() << endl;
}
int main(){
  ifstream inCredit("../Transaction-Processing Program/clients.dat", ios::in | ios::binary);
  ClientData client;

  if(!inCredit){
    cerr << "File could not opened!";
    exit(EXIT_FAILURE);
  }

  cout << left << setw(10) << "Account"
        << setw(16) << "Last name" << setw(11) << "First Name"
        << setw(10) << right << "Balance" << endl;

  inCredit.read(reinterpret_cast< char*>(&client), sizeof(ClientData));

  while(inCredit && !inCredit.eof()){
    if(client.getAccountNumber() > 0)
        outputLine(client);

    inCredit.read(reinterpret_cast< char*>(&client), sizeof(ClientData));
  }

}

