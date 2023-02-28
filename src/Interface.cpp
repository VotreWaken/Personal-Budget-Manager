#include "Interface.h"
#include <iostream>
#include <string>
#include "Wallet.h"
#include "Card.h"
Interface::Interface()
{
	std::string BankValue;
	std::cout << "Welcome to Finance File System\n";
	std::cout << "Enter Your Bank Name: ";
	std::getline(std::cin, BankValue);
	int choice;
	std::cout << "\nDo you want a Credit or Debit card?\n";
	std::cout << "1. Credit Card\n2. Debit Card\n";
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << "Enter your credit limit: $";
		int limit;
		std::cin >> limit;
		Card* card = new CreditCard(BankValue, limit);
		cards.push_back(card);
	}
	else if (choice == 2)
	{
		Card* card = new DebitCard(BankValue, 0);
		cards.push_back(card);
	}
	else
	{
		std::cout << "Invalid choice.\n";
	}
}

void Interface::Start()
{
	while (1)
	{
		system("cls");
		int UserChoice;
		std::cout << "1. Write Spendings";
		std::cout << "\n2. Show All Cards";
		std::cout << "\n3. Week TOP - 3 Category Spendings";
		std::cout << "\n4. Month TOP - 3 Category Spendings";
		std::cout << "\n5. Week TOP - 3 Spendings";
		std::cout << "\n6. Month TOP - 3 Spendings";
		std::cout << "\n7. Day Spendings";
		std::cout << "\n8. Week Spendings";
		std::cout << "\n9. Month Spendings";
		std::cout << "\n10. Write To File";
		std::cout << "\n11. Read From File";
		std::cout << "\n12. Add Card To Wallet";
		std::cout << "\n13. Show Cards In Wallet\n";
		std::cin >> UserChoice;
		switch (UserChoice)
		{
		case 1:
		{
			std::cout << "Enter Index Card:\n";
			int value = 0;
			std::cin >> value;
			cards[value]->Input();
			system("pause");
			break;
		}
		case 2:
		{
			printAllCards();
			system("pause");
			break;
		}
		case 3:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			std::cout << "Enter Week: \n";
			int Week = 0;
			std::cin >> Week;
			cards[value]->searchByWeekCategory(Year, Month, Week);
			system("pause");
			break;
		}
		case 4:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			cards[value]->searchByMonthCategory(Year, Month);
			system("pause");
			break;
		}
		case 5:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			std::cout << "Enter Week: \n";
			int Week = 0;
			std::cin >> Week;
			cards[value]->searchByWeekTop(Year, Month, Week);
			system("pause");
			break;
		}
		case 6:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			cards[value]->searchByMonthTop(Year, Month);
			system("pause");
			break;
		}
		case 7:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			std::cout << "Enter Day: \n";
			int Day = 0;
			std::cin >> Day;
			cards[value]->searchByDay(Year, Month, Day);
			system("pause");
			break;
		}
		case 8:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			std::cout << "Enter Week: \n";
			int Week = 0;
			std::cin >> Week;
			cards[value]->searchByWeek(Year, Month, Week);
			system("pause");
			break;
		}
		case 9:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			std::cout << "Enter Month: \n";
			int Month = 0;
			std::cin >> Month;
			std::cout << "Enter Year: \n";
			int Year = 0;
			std::cin >> Year;
			cards[value]->searchByMonth(Year, Month);
			system("pause");
			break;
		}
		case 10:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			cards[value]->writeToFile();
			system("pause");
			break;
		}
		case 11:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			cards[value]->readFromFile();
			system("pause");
			break;
		}
		case 12:
		{
			std::cout << "Enter Index:\n";
			int value = 0;
			std::cin >> value;
			AddCardToWallet(value);
			system("pause");
			break;
		}
		case 13:
		{
			ShowCardInWallet();
			system("pause");
			break;
		}
		}
	}
}

void Interface::printAllCards()
{
	std::cout << "All Cards:\n";
	for (Card* card : cards)
	{
		card->Output();
	}
}

void Interface::AddCardToWallet(int cardIndex)
{

	if (cardIndex < 0 || cardIndex >= cards.size())
	{
		std::cout << "Invalid card index.\n";
	}
	else
	{
		Wallet::addCard(cards[cardIndex]);
	}

}

void Interface::ShowCardInWallet()
{
	Wallet::printCards();
}

Interface::~Interface()
{

}