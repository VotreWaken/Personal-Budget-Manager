#ifndef WALLET_HPP
#define WALLET_HPP
#include <vector>
class Card;
class Wallet
{
protected:
	// Wallet Fields
	std::vector<Card*> cards;
public:

	// Add Card To Wallet
	virtual void addCard(Card* card);

	// Print all Cards In Wallet
	virtual void printCards();
};
// Derived class for online wallets
class OnlineWallet : public Wallet
{
public:
	// Add Card To Wallet
	void addCard(Card* card);

	// Print all Cards In Wallet
	virtual void printCards();
};

// Derived class for physical wallets
class PhysicalWallet : public Wallet
{
public:
	// Add Card To Wallet
	void addCard(Card* card);

	// Print all Cards In Wallet
	virtual void printCards();
};
#endif
