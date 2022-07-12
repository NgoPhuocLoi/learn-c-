#include <string>

using std::string;

#ifndef CLIENT_DATA
#define CLIENT_DATA 1

class ClientData{
  public:
    ClientData(int = 0, const string & = "", const string & = "", double = 0);

    void setAccountNumber(int);
    int getAccountNumber() const;

    void setBalance(double);
    double getBalance() const;

    void setFirstName(const string &);
    string getFirstName() const;

    void setLastName(const string &);
    string getLastName() const;

    void setClientData()
  private:
    char firstName[10], lastName[15];
    int accountNumber;
    double balance;
};

// Definitions
ClientData::ClientData(int account, const string &first,
                      const string &last, double balanceValue)
  :accountNumber(account), balance(balanceValue)
{
  setFirstName(first);
  setLastName(last);
}

void ClientData::setAccountNumber(int accNum){
  accountNumber = accNum;
}
int ClientData::getAccountNumber() const {
  return accountNumber;
}

void ClientData::setBalance(double balanceValue){
  balance = balanceValue;
}
double ClientData::getBalance() const {
  return balance;
}

void ClientData::setFirstName(const string &first){
  int length = first.size();  
  length = (length < 10 ? length : 9);
  first.copy(firstName, length);
  firstName[length] = '\0';
}
string ClientData::getFirstName() const {
  return firstName;
}

void ClientData::setLastName(const string &last){
  int length = last.size();  
  length = (length < 15 ? length : 14);
  last.copy(lastName, length);
  lastName[length] = '\0';
}
string ClientData::getLastName() const {
  return lastName;
}
#endif
