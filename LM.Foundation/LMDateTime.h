#pragma once
#include "LMString.h"
#include <iostream>
namespace Foundation
{
	class DateTime;
	std::ostream& operator <<(std::ostream& os,const DateTime& datetime);
}
class Foundation::DateTime
{
public:
	friend std::ostream& Foundation::operator <<(std::ostream& os, const DateTime& datetime);
	DateTime(int year,int month,int day,int hour,int minute,int second);
public:
	const Foundation::String ToString();
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};
