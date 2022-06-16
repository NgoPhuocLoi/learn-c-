#include "iostream"
#include <string>

class Employee {
	private:
		std::string firstName, lastName;
		int monthlySalary;
	public:
		explicit Employee(std::string fName, std::string lName, int salary)
			: firstName(fName), lastName(lName), monthlySalary(salary)
		{
			if(salary < 0){
				monthlySalary = 0;
				std::cerr << "Invalid salary!!\n";
			}
		}
		
		void checkInfo() const {
			std::cout << "First name: " << firstName << std::endl;
			std::cout << "Last name: " << lastName << std::endl;
			std::cout << "Monthly salary: " << monthlySalary << std::endl;
		}
};
