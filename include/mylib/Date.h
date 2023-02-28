#ifndef DATE_HPP
#define DATE_HPP
#include <iosfwd>
#include <string>
class Date
{
public:

	// Constructor By Parametres
	Date(int day, int month, int year);

	// Default Constructor
	Date();

	Date(int day, std::string monthStr, int year);

	// Get Day
	constexpr int GetDay() const;

	// Get Month
	constexpr int GetMonth() const;

	// Get Year
	constexpr int GetYear() const;

	// Set Day
	void SetDay(int days);

	// Set Month
	void SetMonth(int month);

	// Set Year
	void SetYear(int year);

	// Get Count of Days In Specific Month
	constexpr static int GetDaysInMonth(int index);

	// Overload Operator "<<"
	friend std::ostream& operator<< (std::ostream& out, const Date& Date);

	// Destructor
	~Date();

private:
	int days_;
	int month_;
	int year_;
	constexpr static int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};
#endif
