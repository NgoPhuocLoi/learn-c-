#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <ctime>

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

class Time{
	public:
		 Time(int h = 0, int m = 0, int s = 0)
		{
			if(h || m || s)
				setTime(h,m,s);
			else
				setTime(getCurrentHour(),getCurrentMinute(),getCurrentSecond());
		}
		void setTime(int h, int m, int s){
			setHour(h);
			setMinute(m);
			setSecond(s);
		}	
		void setHour(int h){
			if(h >= 0 && h < 24){
				hour = h;
			}else{
				throw std::invalid_argument("Hour must be 0-23");
			}
		}
		void setMinute(int m){
			if(m >= 0 && m < 60){
				minute = m;
			}else{
				throw std::invalid_argument("Minute must be 0-59");
			}
		}
		void setSecond(int s){
			if(s >= 0 && s < 60){
				second = s;
			}else{
				throw std::invalid_argument("Second must be 0-59");
			}
		}
		unsigned int getHour() const {
			return hour;
		}
		unsigned int getMinute() const {
			return minute;
		}
		unsigned int getSecond() const {
			return second;
		}
		void printUniversal() const {
			std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
				<< std::setw(2) << getMinute() << ":" 
				<< std::setw(2) << getSecond() << std::endl;
		}
		void printStandard() const{
			std::cout <<((getHour() == 0 || getHour() == 12) ? 12 : getHour()%12) << ":" 
					<< std::setfill('0')<< std::setw(2) << getMinute() << ":"
					<< std::setw(2) << getSecond() 
					<< ((getHour() < 12) ? " AM" : " PM" )<< std::endl;
		}
		void tick(){
			second++;
			if(second == 60){
				second = 0;
				minute++;
			}
			if(minute == 60){
				minute = 0;
				hour++;	
			}
			if(hour == 24)
				hour = 0;
		}
		
		unsigned int getCurrentHour() const {
			return ltm->tm_hour;
		}
		unsigned int getCurrentMinute() const {
			return ltm->tm_min;
		}
		unsigned int getCurrentSecond() const {
			return ltm->tm_sec;
		}
		
	private:
		unsigned int hour;
		unsigned int minute;
		unsigned int second;
		time_t now = time(0);
		tm *ltm = localtime(&now);		
};

#endif
