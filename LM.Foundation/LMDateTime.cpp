#include "pch.h"
#include "LMDateTime.h"
#include "LMString.h"
#include <cstring>
#include <iostream>
Foundation::DateTime::DateTime(int year, int month, int day, int hour, int minute, int second):
	_year(year),_month(month),_day(day),_hour(hour),_minute(minute),_second(second)
{

}

const Foundation::String Foundation::DateTime::ToString()
{
	char buffer[100]{ 0 };
	sprintf_s(buffer, "%d-%d-%d %d:%d:%d", _year, _month, _day, _hour, _minute, _second);
	return Foundation::String(buffer);
}

std::ostream& Foundation::operator<<(std::ostream& os, const DateTime& datetime)
{
	char buffer[100]{ 0 };
	sprintf_s(buffer, "%d-%d-%d %d:%d:%d", datetime._year, datetime._month, datetime._day, 
		datetime._hour, datetime._minute, datetime._second);
	os <<"DateTime:" << buffer;
	return os;
}
