#ifndef CARD_HPP
#define CARD_HPP
#include "MoneyStorage.h"
class Card : public MoneyStorage
{
	std::string bankName_;
public:

	Card();
	Card(int num, std::string name, float credit = 0);
	virtual void Output();
	void Input();
	~Card();
};

// Derived class for debit cards
class DebitCard : public Card
{
protected:

public:

	// Constructor
	DebitCard(std::string& Name, int LimitValue);
	// Display Card To Screen
	virtual void print();
};

// Derived class for credit cards
class CreditCard : public Card
{
protected:
	float credit_limit;

public:
	// Constructor
	CreditCard(std::string& Name, int LimitValue, float credit_limit = 0);

	// Display Card To Screen
	virtual void print();
};
#endif