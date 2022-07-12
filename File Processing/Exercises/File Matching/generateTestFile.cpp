#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int getChoice();
void createMasterFile();
void createTransactionFile();

int main(){
  createTransactionFile();
}

int getChoice(){
  int choice;
  cout << "\nEnter your choice:\n"
      << "1. Create master file\n"
      << "2. Create transaction file\n"
      << "3. Exit\n? ";

  cin >> choice;
  return choice;
}

void createMasterFile(){
  int accountNumber, recordNumber;
  char name[30];
  double balance;
  ofstream outMasterFile("./Test Data/oldMaster.txt", ios::out);

  if(!outMasterFile){
    cerr << "File could not be created!";
    exit(EXIT_FAILURE);
  }

  cout << "Enter the number of record to create: ";
  cin >> recordNumber;
  vector<int> existAccount;

  for(int i = 0; i < recordNumber; i++){
    bool isExist = false;

    cout << "\nEnter the information of record " << i+1 << " :\n";
    cout << "Account Number: ";
    cin >> accountNumber ;

    // check exist account
    for(int j = 0; j < existAccount.size(); j++){
      if(existAccount.at(j) == accountNumber){
        isExist = true;
        break;
      }
    }

    if(!isExist){
      existAccount.push_back(accountNumber);
      cin.ignore();
      cout << "Name: ";
      cin.getline(name, 30);
      cout << "Balance: ";
      cin >> balance;

      outMasterFile << accountNumber << " " << name << " " << balance << endl;
    }else{
      cout << "The account has already taken!. Try again\n";
      i--;
    }
  }
}

void createTransactionFile(){
	int accountNumber;
	double dollarAmount;
	ofstream outTransFile("./Test Data/trans.txt", ios::out);
	
	cout << "Enter the accountNumber (-1 to end):\n? ";
	cin >> accountNumber;
	while(accountNumber > 0){
		cout << "Enter the amount: \n? ";
		cin >> dollarAmount;
		
		outTransFile << accountNumber << " " << dollarAmount << endl;
		
		cout << "Enter the accountNumber (-1 to end):\n? ";
		cin >> accountNumber;
	}
}

