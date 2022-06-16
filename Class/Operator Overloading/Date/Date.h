#include <iostream>
#include <stdexcept>
#include <array>
#include <string>

#ifndef DATE
#define DATE 1

class Date {
	friend std::ostream & operator << (std::ostream &, Date &);
	public:
		Date(int d = 1, int m = 1, int y = 1900);
		void setDay(int, int, int );
		Date &operator++();
		Date operator++(int);
		Date &operator+=(unsigned int);
		static bool isLeapYear(int );
		bool endOfMonth(int) const;

	private:
		unsigned int day, month, year;
		static const std::array<unsigned int, 13> days;
		void helpIncrement();
};

//definitions

const std::array<unsigned int, 13> Date::days = { 0, 31, 28, 31, 30, 31, 
											30, 31, 31, 30, 31, 30, 31 };

Date::Date(int day, int month, int year){
	setDay(day, month, year); 
}	

void Date::setDay(int d, int m, int y){
	if(y >= 1900 && y <= 2100){
		year = y;
	}else
		throw std::invalid_argument("Invalid year!");
	
	if(m >= 1 && m <= 12)
		month = m;
	else
		throw std::invalid_argument("Invalid Month");
	
	if((month == 2 && Date::isLeapYear(year) && d >= 1 && d <= 29) || (d >= 1 && d <= days[month]))
		day = d;
	else
		throw std::invalid_argument("Invalid day!");
}

Date& Date::operator++(){
	helpIncrement();
	return *this;
}	

Date Date::operator++(int){
	Date temp = *this;
	helpIncrement();
	return temp;
}	

Date& Date::operator+=(unsigned int additionalDays){
	for(int i = 0; i < additionalDays; i++)
		helpIncrement();
	return *this;
}

bool Date::isLeapYear(int testYear){
	return (testYear % 400 == 0) || (testYear % 100 != 0 && testYear % 4 == 0);
}	

bool Date::endOfMonth(int testDay) const {
	if(month == 2 && isLeapYear(year))
		return testDay == 29;
	else
		return testDay == days[month];
}

void Date::helpIncrement(){
	if(!endOfMonth(day))
		day++;
	else{
		if(month < 12){
			month++;
			day = 1;
		}else{
			year++;
			month = day = 1;
		}
	}
}	

std::ostream& operator<< (std::ostream &output, Date &date){
	static std::string monthName[ 13 ] = { "", "January", "February",
 				"March", "April", "May", "June", "July", "August",
 				"September", "October", "November", "December" };
	
	output << date.day << " " << monthName[date.month] << " " << date.year;
	return output;
}						

#endif



