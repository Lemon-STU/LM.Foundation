#pragma once
#include "LMString.h"
#include <iostream>
namespace Foundation
{
	class DateTime;
}
class Foundation::DateTime
{
public:
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
