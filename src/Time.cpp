#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iomanip>
Time::Time()
{
	time_t Times;
	time(&Times);
	struct tm* timeinfo;
	timeinfo = localtime(&Times);

	minutes_ = timeinfo->tm_min;
	hours_ = timeinfo->tm_hour;
	seconds_ = timeinfo->tm_sec;
}
Time::Time(int hour, int min, int sec) : seconds_(sec), minutes_(min), hours_(hour)
{
	if (hour > 24 || min > 59 || sec > 59)
	{
		throw(std::domain_error("Time value out of range"));
	}
}
void Time::SetSeconds(int Seconds)
{
	seconds_ = Seconds;
}
void Time::SetMinutes(int Minutes)
{
	minutes_ = Minutes;
}
void Time::SetHours(int Hours)
{
	hours_ = Hours;
}
// Overload Operator << 
std::ostream& operator<<(std::ostream& out, const Time& t)
{
	auto oldfill = out.fill('0');
	return out << t.hours_
		<< ':' << std::setw(2) << t.minutes_
		<< ':' << std::setw(2) << t.seconds_ << std::setfill(oldfill);
}
Time::~Time()
{

}