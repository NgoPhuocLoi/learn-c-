#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;
vector<int> getExistAccount(ifstream &);
bool isIncludes(vector<int>, int);

int main(){
  ifstream inOldMasterFile("./Test Data/oldMaster.txt", ios::in);
  ifstream inTransFile("./Test Data/trans.txt", ios::in);
  ofstream outNewMasterFile("./Test Data/newMaster.txt", ios::out);

  int accountNumber, accountNum;
  string firstName, lastName;
  double balance, dollarAmount;
  bool isMatch = false;

  vector<int> existAccount;

  existAccount = getExistAccount(inOldMasterFile);

  inOldMasterFile >> accountNumber >> firstName >> lastName >> balance;

  while(!inOldMasterFile.eof()){
    cout << accountNumber << " " << firstName << lastName << " " << balance << endl;

    inTransFile >> accountNum >> dollarAmount;

    while(!inTransFile.eof()){
      if(accountNum == accountNumber){
        balance += dollarAmount;  
        isMatch = true;
      }
      inTransFile >> accountNum >> dollarAmount;
    }

    outNewMasterFile << accountNumber << " " << firstName << " "
                    << lastName <<" " << balance << endl;

    inTransFile.clear();
    inTransFile.seekg(0);

    inOldMasterFile >> accountNumber >> firstName >> lastName >> balance;
  }

  // check non-exist account 
  inTransFile.clear();
  inTransFile.seekg(0);

  inTransFile >> accountNum >> balance;
  while(!inTransFile.eof()){
    if(!isIncludes(existAccount, accountNum)){
      outNewMasterFile << "Unmatched transaction record for account number # " 
                      << accountNum << endl; 
    }
    inTransFile >> accountNum >> balance;

  }
  cout << "\nRun";
}

vector<int> getExistAccount(ifstream &inOldMasterFile){
  vector<int> existAccount;
  int accountNumber;
  string firstName, lastName;
  double balance;

  inOldMasterFile >> accountNumber >> firstName >> lastName >> balance;
  existAccount.push_back(accountNumber);

  while(!inOldMasterFile.eof()){
    inOldMasterFile >> accountNumber >> firstName >> lastName >> balance;
    existAccount.push_back(accountNumber);
  }

  inOldMasterFile.clear();
  inOldMasterFile.seekg(0);

  return existAccount;
}

bool isIncludes(vector<int> source, int key){
  for(int i = 0; i < source.size(); i++){
    if(key == source.at(i))
      return true;
  }
  return false;
}

