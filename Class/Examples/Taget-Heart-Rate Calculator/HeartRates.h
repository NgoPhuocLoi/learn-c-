#include <iostream>
#include <string>
#include <ctime>
#include "../DateClass/Date.h"

int getCurrentYear(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return 1900 + ltm->tm_year;
}

class HeartRates {
	private:
		std::string name;
		Date birthday;
	public:
		explicit HeartRates(std::string n, Date date)
			: name(n), birthday(date)
		{
			
		}
		
		int getAge() const {
			return getCurrentYear() - birthday.getYear();
		}
		
		int getMaximumRate() const {
			return 220 - getAge();
		}
		
		float getTargetRate() const {
			return 0.75*getMaximumRate();
		}
		
		void checkInfo() const {
			std::cout << "Name: " << name << std::endl;
			std::cout << "Birthday: " ; birthday.displayDate();
			std::cout << "Age: " << getAge() << std::endl;
			std::cout << "Maximum heart rate: " << getMaximumRate() << std::endl;
			std::cout << "Target heart rate: " << getTargetRate() << std::endl;
		}
};
