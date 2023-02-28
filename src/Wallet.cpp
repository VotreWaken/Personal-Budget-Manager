#include "Wallet.h"
#include "Card.h"
#include <iostream>
// Add Card To Wallet
void Wallet::addCard(Card* card)
{
	cards.push_back(card);
}

// Print all Cards In Wallet
void Wallet::printCards()
{
	for (Card* card : cards)
	{
		card->Output();
		std::cout << "\n";
	}
}

void OnlineWallet::addCard(Card* card)
{
	if (dynamic_cast<DebitCard*>(card))
	{
		cards.push_back(card);
	}
	else {
		std::cout << "Only debit cards can be added to an online wallet.\n";
	}
}

// Print all Cards In Wallet
void OnlineWallet::printCards()
{
	std::cout << "Online Wallet Cards\n";
	Wallet::printCards();
}

void PhysicalWallet::addCard(Card* card)
{
	if (dynamic_cast<CreditCard*>(card))
	{
		cards.push_back(card);
	}
	else
	{
		std::cout << "Only credit cards can be added to a physical wallet.\n";
	}
}

// Print all Cards In Wallet
void PhysicalWallet::printCards()
{
	std::cout << "Physical Wallet Cards\n";
	Wallet::printCards();
}