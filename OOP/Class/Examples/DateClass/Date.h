#include <iostream>
#include <stdexcept>

class Date {
	private:
		int day, month, year;
		bool isLeapYear(){
			return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
		}
		int countDayInMonth(int m){
			int dayInMonth;
			switch(m){
				case 4:
				case 6:
				case 9:
				case 11:
					dayInMonth = 30;
					break;
				case 2:
					dayInMonth = isLeapYear() ? 29 : 28;
					break;
				default:
					dayInMonth = 31;
			}
			return dayInMonth;
		}
	public:
		explicit Date(int d = 1, int m = 1, int y = 2000)
		{
			setYear(y);
			setMonth(m);
			setDay(d);
		}
		void setDay(int d){
			int dayInMonth = countDayInMonth(month);
			
			if(d > 0 && d <= dayInMonth){
				day = d;
			}else
				throw std::invalid_argument("Invalid day!");
			
		}
		void setMonth(int m){
			if(m > 0 && m <= 12){
				month = m;
			}else
				throw std::invalid_argument("Invalid month! (Month must be in range 1 to 12)");
		}
		void setYear(int y){
			if(y > 0){
				year = y;
			}else
				throw std::invalid_argument("Invalid year! (year must be geater than 0)");
		}
		int getDay() const {
			return day;
		}
		int getMonth() const {
			return month;
		}
		int getYear() const {
			return year;
		}
		
		void displayDate() const {
			std::cout << day << "/" 
					 << month << "/"
					 << year << std::endl;
		}
		
		void nextDay(){
			int dayInMonth = countDayInMonth(month);
			day++;
			if(day > dayInMonth){
				day = 1;
				month++;
			}
			if(month > 12){
				month = 1;
				year++;
			}
		}
};
