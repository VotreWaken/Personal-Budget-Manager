#ifndef TIME_HPP
#define TIME_HPP
#include <iosfwd>
class Time
{
public:
	// Default Constructor
	Time();

	// Int Constructor
	Time(int hour, int min, int sec);

	// Set Second
	void SetSeconds(int Seconds);

	// Set Minutes
	void SetMinutes(int Minutes);

	// Set Hours
	void SetHours(int Hours);

	// Destructor
	~Time();

	// Overload Operator << 
	friend std::ostream& operator<<(std::ostream& out, const Time& t);

private:
	int seconds_;
	int minutes_;
	int hours_;
};
#endif // !TIME_HPP

