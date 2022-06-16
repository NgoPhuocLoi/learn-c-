#include <iostream>

class Account {
	private:
		int balance;
	public:
		explicit Account(int accBalance)
			:balance(accBalance){
				if(accBalance < 0){
					balance = 0;
					std::cerr << "Invalid Balance!!";
				}
			}
		int getBalance() const {
			return balance;
		}
		void credit(int amount){
			balance += amount;
		}
		void debit(int amount){
			if(amount <= balance){
				balance -= amount;
			}else{
				std::cerr << "Debit amount exceeded account balance!\n";
			}
		}
		void checkBalance() const {
			std::cout << "Current balance: " << balance << std::endl;
		}
		
};
