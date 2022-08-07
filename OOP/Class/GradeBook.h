#include <iostream>
#include <string>
#include <array>
class GradeBook {
	
	public:
		static const int students = 4;
		static const int tests = 3;
		
		GradeBook(std::string &name, 
					std::array<std::array<int, tests>, students> &a)
		: courseName(name), studentGrade(a)
		{
			
		}
	
		void setCourseName(std::string &name){
			if(name.length() <= 25)
				courseName = name;
			else{
				courseName = name.substr(0,25);
				std::cerr << "Name \"" << name << "\" exceeds the"
				" maximum length (25)" << std::endl;
			}
		}
		
		std::string getCourseName() const {
			return courseName;
		}
		
		void displayMessage() const {
			std::cout<<" WElcome to the Grade Book for " 
					 << getCourseName() << std::endl;
		}
		void displayGrade() const {
			std::cout << students << " Student's grade: \n";
			for(const auto &student: studentGrade){
				for(const int grade: student){
					std::cout << grade << " ";
				}
				std::cout << std::endl;
			}
		}
	private:
		std::string courseName;
		std::array<std::array<int, tests>, students> studentGrade;
		
};
