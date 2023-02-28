#ifndef MONEYSTORAGE_HPP
#define MONEYSTORAGE_HPP
#include <set>
#include "Spendings.h"
class MoneyStorage
{
protected:
	int totalAmount_;
	bool creditLimit_;
	std::multiset<Spendings> spendings_;
public:

	// Constructor By Parametres
	MoneyStorage(int totalAmount, int LimitValue);

	// Initialize Spending
	void Input();

	// Display to Screen 
	void Output();

	// Search By Week By Category
	void searchByWeekCategory(int Year, int Month, int Week) const;

	void searchByMonthCategory(int Year, int Month) const;

	void searchByWeekTop(int Year, int Month, int Week) const;

	void searchByMonthTop(int Year, int Month) const;

	void searchByDay(int Year, int Month, int Day) const;

	void searchByWeek(int Year, int Month, int Week) const;

	void searchByMonth(int Year, int Month) const;

	void readFromFile();

	void writeToFile();

	// Default Constructor
	MoneyStorage();

	// Destrucotr
	~MoneyStorage();
};
#endif // !MoneyStorage