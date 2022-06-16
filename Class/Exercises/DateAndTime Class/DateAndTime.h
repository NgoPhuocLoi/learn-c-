#include "../../Examples/DateClass/Date.h"
#include "../../Examples/TimeClass/Time.h"

#ifndef DATE_AND_TIME
#define DATE_AND_TIME 1

class DateAndTime {
	public:
		DateAndTime(Date d, Time t)
			:date(d), time(t)
		{
		}
		void printUniversal() const {
			std::cout << std::setfill('0') << std::setw(2) << time.getHour() << ":"
				<< std::setw(2) << time.getMinute() << ":" 
				<< std::setw(2) << time.getSecond() << " ";
			date.displayDate();
		}
		void printStandard() const{
			std::cout <<((time.getHour() == 0 || time.getHour() == 12) ? 12 : time.getHour()%12) << ":" 
					<< std::setfill('0')<< std::setw(2) << time.getMinute() << ":"
					<< std::setw(2) << time.getSecond() 
					<< ((time.getHour() < 12) ? " AM" : " PM" ) << " ";
			date.displayDate();
		}
		
		void nextDay(){
			date.nextDay();
		}
		
		void tick(){
			if(time.getHour() == 23 && 
				time.getMinute() == 59 && 
				time.getSecond() == 59){
				date.nextDay();
			}
			time.tick();
			
		}

	private:
		Date date;
		Time time;
};

#endif


