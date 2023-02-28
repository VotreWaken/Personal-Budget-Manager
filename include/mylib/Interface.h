#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include "Card.h"
#include "Wallet.h"
class Interface : public OnlineWallet, public PhysicalWallet
{
public:
	Interface();
	void Start();
	~Interface();
	void printAllCards();
	// Add Card To Wallet
	void AddCardToWallet(int cardIndex);
	void ShowCardInWallet();
private:
	std::vector<Card*> cards;
};
#endif