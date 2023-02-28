#ifndef SPENDINGS_HPP
#define SPENDINGS_HPP
#include <iosfwd>
#include <string>
#include "Date.h"
#include "Time.h"
class Spendings
{
private:
	double amount_;
	Time curTime_;
	Date date_;
	std::string category_;
public:

	// Constructor by Parametres
	Spendings(std::string name, double amount, Time currentTime, Date date);

	Spendings(std::string name, double amount, Time currentTime);

	// Default Constructor
	Spendings();

	// Input All
	void Input();

	// Input Time 
	void InputTime();

	// Input Date
	void InputDate();

	// Input Category
	void InputCategory();

	// Input Amount
	void InputAmount();

	// Output
	void Output();

	// Get Amount
	double GetMoney() const;

	// Get Category
	std::string GetCategory() const;

	// Get Date
	const Date GetDate() const;

	// Get Time
	const Time GetTime() const;

	// Overload Operator "<<"
	friend std::ostream& operator<< (std::ostream& out, const Spendings& spend);

	// For Insert to Multiset
	bool operator<(const Spendings& rhs) const noexcept;

	// Destructor
	~Spendings();
private:

};
#endif