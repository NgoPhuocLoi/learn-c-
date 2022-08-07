#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "./ClientData.h"

using namespace std;

enum Choices {PRINT = 1, UPDATE, NEW, DELETE, END};

int enterChoice();
void createTextFile(fstream &);
void newRecord(fstream &);
void updateRecord(fstream &);
void deleteRecord(fstream &);
void outputLine(ostream &, const ClientData &);
int getAccount(const char* const);

int main(){
  fstream inOutCredit("clients.dat", ios::in | ios::out | ios::binary);
  int choice;

  if(!inOutCredit){
    cerr << "File could not opened!";
    exit(EXIT_FAILURE);
  }

  while((choice = enterChoice()) != END){
    switch(choice){
      case PRINT:
        createTextFile(inOutCredit);
        break;
      case NEW:
        newRecord(inOutCredit);
        break;
      case UPDATE:
        updateRecord(inOutCredit);
        break;
      case DELETE:
        deleteRecord(inOutCredit);
        break;
      default:
        cerr << "Incorrect choice!\n";
        break;
    }
    inOutCredit.clear(); // reset end-of-file indicator
  }
}


int enterChoice(){
  int choice;
  cout << "\nEnter your choice:\n"
      << "1. Store a formatted text file of accounts for printing\n"
      << "2. Update an account\n"
      << "3. Add new account\n"
      << "4. Delete an account\n"
      << "5. End program\n? ";
  cin >> choice;
  return choice;
}
void createTextFile(fstream &readFromFile){
  ofstream outPrintFile("print.txt", ios::out);
  ClientData client;

  if(!outPrintFile){
    cerr << "File could not be created!";
    exit(EXIT_FAILURE);
  }

  outPrintFile << left << setw(10) << "Account"
              << setw(16) << "Last Name"
              << setw(11) << "First Name" 
              << right << setw(10) << "Balance\n";

  readFromFile.seekg(0);
  readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

  while(!readFromFile.eof()){
    if(client.getAccountNumber() != 0)
      outputLine(outPrintFile, client);

    readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
  }
}
void updateRecord(fstream &updateFile){
  int accNum = getAccount("Enter the account to update");
  ClientData client;
  double transaction;

  updateFile.seekg((accNum - 1)*sizeof(ClientData));
  updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

  if(client.getAccountNumber() != 0){
    outputLine(cout, client);

    cout << "Enter charge (+) or payment (-): ";
    cin >> transaction;

    client.setBalance(client.getBalance() + transaction);
    outputLine(cout, client);

    updateFile.seekp((accNum -1)*sizeof(ClientData));
    updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
  }else{
    cerr << "Account #" << accNum << " has no information\n";
  }
}
void newRecord(fstream &insertInFile){
  int accNum = getAccount("Enter new account number");
  ClientData client;

  insertInFile.seekg((accNum - 1)*sizeof(ClientData));
  insertInFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

  if(client.getAccountNumber() == 0){
    string firstName, lastName;
    double balance;

    cout << "Enter lastname, firstname, balance\n? ";
    cin >> setw(15) >> lastName 
        >> setw(10) >>firstName >> balance;
    
    client.setAccountNumber(accNum);
    client.setFirstName(firstName);
    client.setLastName(lastName);
    client.setBalance(balance);

    insertInFile.seekp((accNum - 1)*sizeof(ClientData));
    insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

  }else{
    cerr << "Account #" << accNum << " already contains information\n";
  }
}
void deleteRecord(fstream &deleteFromFile){
  int accNum = getAccount("Enter account to delete");
  ClientData client;

  deleteFromFile.seekg((accNum - 1)*sizeof(ClientData));
  deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

  if(client.getAccountNumber() != 0){
    ClientData blankClient;

    deleteFromFile.seekp((accNum - 1)*sizeof(ClientData));
    deleteFromFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

    cout << "Account #" << accNum << " deleted!\n";
  }else{
    cerr << "Account #" << accNum << " is empty\n";
  }
}
void outputLine(ostream &output, const ClientData &record){
  output << left << setw(10) << record.getAccountNumber()
        << setw(16) << record.getLastName()
        << setw(11) << record.getFirstName()
        << setw(10) << right << fixed << setprecision(2) << record.getBalance() << endl;
}
int getAccount(const char* const prompt){
  int accNum;

  do{
    cout << prompt << " (1 - 100): ";
    cin >> accNum;
  }while(accNum < 1 || accNum > 100);

  return accNum;
}
