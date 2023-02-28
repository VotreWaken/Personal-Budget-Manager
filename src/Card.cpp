#include "Card.h"
#include <iostream>
Card::Card() : MoneyStorage()
{

}
Card::Card(int num, std::string name, float credit)
{
	bankName_ = name;
	totalAmount_ = num;
	creditLimit_ = credit;
}
void Card::Output()
{
	std::cout << bankName_ << "\n";
	std::cout << totalAmount_ << "\n";
	std::cout << creditLimit_ << "\n";
	MoneyStorage::Output();
}
void Card::Input()
{
	MoneyStorage::Input();
}
Card::~Card()
{

}

DebitCard::DebitCard(std::string& Name, int LimitValue) : Card(LimitValue, Name)
{

}
// Display Card To Screen
void DebitCard::print()
{
	std::cout << "Debit Card Details\n";
	Card::Output();
}

CreditCard::CreditCard(std::string& Name, int LimitValue, float credit_limit) : Card(LimitValue, Name, credit_limit)
{

}

// Display Card To Screen
void CreditCard::print()
{
	std::cout << "Credit Card Details\n";
	Card::Output();
	std::cout << "Credit Limit: $" << credit_limit << "\n";
}