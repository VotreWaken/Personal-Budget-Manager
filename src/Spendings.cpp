#include "Spendings.h"
#include <iostream>
Spendings::Spendings(std::string name, double amount, Time currentTime, Date date) :
	category_(name), amount_(amount), curTime_(currentTime), date_(date)
{

}

Spendings::Spendings(std::string name, double amount, Time currentTime) :
	category_(name), amount_(amount), curTime_(currentTime)
{
}

Spendings::Spendings()
{
	amount_ = 0;
}

void Spendings::InputDate()
{
	Date temp;
	int Day;
	std::cout << "Enter Day: \n";
	std::cin >> Day;
	temp.SetDay(Day);
	std::cout << "Enter Month: \n";
	int Month;
	std::cin >> Month;
	temp.SetMonth(Month);
	std::cout << "Enter Year: \n";
	int Year;
	std::cin >> Year;
	temp.SetYear(Year);
	std::cin.ignore();
	date_ = temp;
}

void Spendings::Input()
{
	InputTime();
	InputDate();
	InputCategory();
	InputAmount();
}

void Spendings::InputTime()
{
	Time temp;
	int seconds;
	std::cout << "Enter Seconds: \n";
	std::cin >> seconds;
	temp.SetSeconds(seconds);
	std::cout << "Enter Minutes: \n";
	int minutes;
	std::cin >> minutes;
	temp.SetMinutes(minutes);
	std::cout << "Enter Hours: \n";
	int hours;
	std::cin >> hours;
	temp.SetHours(hours);
	curTime_ = temp;
}

void Spendings::InputCategory()
{
	std::cout << "Enter Category: \n";
	std::string category;
	std::cin >> category;
	category_ = category;
}

void Spendings::InputAmount()
{
	std::cout << "Enter Amount: \n";
	int amount;
	std::cin >> amount;
	amount_ = amount;
}

void Spendings::Output()
{
	std::cout << "Category: " << category_ << "\n";
	std::cout << "Amount: " << amount_ << "\n";
	std::cout << "Date: " << date_ << "\n";
	std::cout << "Time: " << curTime_ << "\n";
}

// Get Amount
double Spendings::GetMoney() const
{
	return amount_;
}

// Get Category
std::string Spendings::GetCategory() const
{
	return category_;
}

// Get Date
const Date Spendings::GetDate() const 
{
	return date_; 
}

// Get Time
const Time Spendings::GetTime() const
{
	return curTime_; 
}

// Overload Operator "<<"
std::ostream& operator<< (std::ostream& out, const Spendings& spend)
{
	out << "Category: " << spend.category_ << "\nAmount: " << spend.amount_ << "\n"
	<< "Time: " << spend.curTime_ << "\n" << spend.date_;
	return out;
}

// For Insert to Multiset
bool Spendings::operator<(const Spendings& rhs) const noexcept
{
	return this->amount_ < rhs.amount_;
}

// Destructor
Spendings::~Spendings()
{

}