#include "MoneyStorage.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
MoneyStorage::MoneyStorage(int totalAmount, int LimitValue)
{
	totalAmount_ = totalAmount;
	creditLimit_ = LimitValue;
}
void MoneyStorage::Input()
{
	Spendings temp;
	temp.Input();
	spendings_.insert(temp);
}

// Display to Screen 
void MoneyStorage::Output()
{
	for (auto it = spendings_.begin(); it != spendings_.end(); it++)
	{
		std::cout << *it << " ";
	}
}

// Search Top 3 By Week By Category
void MoneyStorage::searchByWeekCategory(int Year, int Month, int Week) const
{
	// map to store total spendings for each category in the week
	std::unordered_map<std::string, double> weekSpendings;

	// recursive function to traverse the tree and calculate total spendings for each category in the week
	std::function<void(int, int, int)> traverse = [&](int year, int month, int week)
	{
		for (const auto& res : spendings_)
		{
			int nodeYear = res.GetDate().GetYear();
			int nodeMonth = res.GetDate().GetMonth();
			int nodeWeek = (res.GetDate().GetDay() - 1) / 7 + 1;

			if (nodeYear == year && nodeMonth == month && nodeWeek == week)
			{
				std::string category = res.GetCategory();
				double cost = res.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};

	traverse(Year, Month, Week);


	// create a vector of pairs with category name and total spending
	std::vector<std::pair<std::string, double>> weekSpendingsVec;
	for (const auto& item : weekSpendings)
	{
		weekSpendingsVec.emplace_back(item);
	}

	// sort categories by total spendings in descending order
	std::sort(weekSpendingsVec.begin(), weekSpendingsVec.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	// print top 3 categories
	std::cout << "Top 3 categories of spending in week " << Week << " of month " << Month << " in year " << Year << ":\n";
	for (int i = 0; i < std::min(3, static_cast<int>(weekSpendingsVec.size())); i++)
	{
		auto& categorySpending = weekSpendingsVec[i];
		std::cout << categorySpending.first << ": " << categorySpending.second << std::endl;

		// check if there are other categories with the same total spending
		double currentSpending = categorySpending.second;
		int j = i + 1;
		while (j < weekSpendingsVec.size() && weekSpendingsVec[j].second == currentSpending) {
			std::cout << "  " << weekSpendingsVec[j].first << std::endl;
			categorySpending.second += weekSpendingsVec[j].second;
			j++;
		}
		i = j - 1;
	}
}

// Search Top 3 By Month By Category
void MoneyStorage::searchByMonthCategory(int Year, int Month) const
{
	std::unordered_map<std::string, double> weekSpendings; // map to store total spendings for each category in the week

	// recursive function to traverse the tree and calculate total spendings for each category in the week
	std::function<void(int, int)> traverse = [&](int year, int month)
	{
		for (const auto& res : spendings_)
		{
			int nodeYear = res.GetDate().GetYear();
			int nodeMonth = res.GetDate().GetMonth();


			if (nodeYear == year && nodeMonth == month)
			{
				std::string category = res.GetCategory();
				double cost = res.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};

	traverse(Year, Month);


	// create a vector of pairs with category name and total spending
	std::vector<std::pair<std::string, double>> weekSpendingsVec;
	for (const auto& item : weekSpendings)
	{
		weekSpendingsVec.emplace_back(item);
	}

	// sort categories by total spendings in descending order
	std::sort(weekSpendingsVec.begin(), weekSpendingsVec.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	// print top 3 categories
	std::cout << "Top 3 categories of spending in month " << Month << " and year " << Year << ":\n";
	for (int i = 0; i < std::min(3, static_cast<int>(weekSpendingsVec.size())); i++)
	{
		auto& categorySpending = weekSpendingsVec[i];
		std::cout << categorySpending.first << ": " << categorySpending.second << std::endl;

		// check if there are other categories with the same total spending
		double currentSpending = categorySpending.second;
		int j = i + 1;
		while (j < weekSpendingsVec.size() && weekSpendingsVec[j].second == currentSpending) {
			std::cout << "  " << weekSpendingsVec[j].first << std::endl;
			categorySpending.second += weekSpendingsVec[j].second;
			j++;
		}
		i = j - 1;
	}
}

// Search By Week Top 3
void MoneyStorage::searchByWeekTop(int Year, int Month, int Week) const
{
	std::unordered_map<std::string, double> weekSpendings;

	std::function<void(int, int, int)> traverse = [&](int year, int month, int week)
	{
		for (const auto& spending : spendings_)
		{
			int nodeYear = spending.GetDate().GetYear();
			int nodeMonth = spending.GetDate().GetMonth();
			int nodeWeek = (spending.GetDate().GetDay() - 1) / 7 + 1;

			if (nodeYear == year && nodeMonth == month && nodeWeek == week) 
			{
				std::string category = spending.GetCategory();
				double cost = spending.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};


	traverse(Year, Month, Week);

	// sort categories by total spendings in descending order
	std::vector<std::pair<std::string, double>> sortedSpendings(weekSpendings.begin(), weekSpendings.end());
	std::sort(sortedSpendings.begin(), sortedSpendings.end(), [](const auto& a, const auto& b)
	{
		return a.second > b.second;
	});

	// print week spendings
	std::cout << "Week " << Week << " of month " << Month << " in " << Year << ":\n";
	for (int i = 0; i < std::min(3, static_cast<int>(sortedSpendings.size())); i++) 
	{
		auto& categorySpendings = sortedSpendings[i];
		std::cout << categorySpendings.first << ": " << categorySpendings.second << std::endl;
	}
}

// Search By Month Top 3
void MoneyStorage::searchByMonthTop(int Year, int Month) const
{
	std::unordered_map<std::string, double> weekSpendings;

	std::function<void(int, int)> traverse = [&](int year, int month)
	{
		for (const auto& spending : spendings_)
		{
			int nodeYear = spending.GetDate().GetYear();
			int nodeMonth = spending.GetDate().GetMonth();
			int nodeWeek = (spending.GetDate().GetDay() - 1) / 7 + 1;

			if (nodeYear == year && nodeMonth == month)
			{
				std::string category = spending.GetCategory();
				double cost = spending.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};


	traverse(Year, Month);

	// sort categories by total spendings in descending order
	std::vector<std::pair<std::string, double>> sortedSpendings(weekSpendings.begin(), weekSpendings.end());
	std::sort(sortedSpendings.begin(), sortedSpendings.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	// print week spendings
	std::cout << "Month " << Month << " in " << Year << ":\n";
	for (int i = 0; i < std::min(3, static_cast<int>(sortedSpendings.size())); i++)
	{
		auto& categorySpendings = sortedSpendings[i];
		std::cout << categorySpendings.first << ": " << categorySpendings.second << std::endl;
	}
}

// Search By Day
void MoneyStorage::searchByDay(int Year, int Month, int Day) const
{
	std::unordered_map<std::string, double> weekSpendings; // map to store total spendings for each category in the week

	// recursive function to traverse the tree and calculate total spendings for each category in the week
	std::function<void(int, int, int)> traverse = [&](int year, int month, int day)
	{
		for (const auto& res : spendings_)
		{
			int nodeYear = res.GetDate().GetYear();
			int nodeMonth = res.GetDate().GetMonth();
			int nodeDay = res.GetDate().GetDay();
			if (nodeYear == year && nodeMonth == month && nodeDay == day)
			{
				std::string category = res.GetCategory();
				double cost = res.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};

	traverse(Year, Month, Day);


	// create a vector of pairs with category name and total spending
	std::vector<std::pair<std::string, double>> weekSpendingsVec;
	for (const auto& item : weekSpendings)
	{
		weekSpendingsVec.emplace_back(item);
	}

	// sort categories by total spendings in descending order
	std::sort(weekSpendingsVec.begin(), weekSpendingsVec.end(), [](const auto& a, const auto& b)
	{
		return a.second > b.second;
	});

	// print top 3 categories
	std::cout <<  "Spending in Day " << Day << " in month " << Month << " and year " << Year << ":\n";
	for (int i = 0; i < weekSpendingsVec.size(); i++)
	{
		auto& categorySpending = weekSpendingsVec[i];
		std::cout << categorySpending.first << ": " << categorySpending.second << std::endl;

		// check if there are other categories with the same total spending
		double currentSpending = categorySpending.second;
		int j = i + 1;
		while (j < weekSpendingsVec.size() && weekSpendingsVec[j].second == currentSpending) {
			std::cout << "  " << weekSpendingsVec[j].first << std::endl;
			categorySpending.second += weekSpendingsVec[j].second;
			j++;
		}
		i = j - 1;
	}
}

// Search By Week
void MoneyStorage::searchByWeek(int Year, int Month, int Week) const
{
	std::unordered_map<std::string, double> weekSpendings; // map to store total spendings for each category in the week

	// recursive function to traverse the tree and calculate total spendings for each category in the week
	std::function<void(int, int, int)> traverse = [&](int year, int month, int week)
	{
		for (const auto& res : spendings_)
		{
			int nodeYear = res.GetDate().GetYear();
			int nodeMonth = res.GetDate().GetMonth();
			int nodeWeek = (res.GetDate().GetDay() - 1) / 7 + 1;
			if (nodeYear == year && nodeMonth == month && nodeWeek == week)
			{
				std::string category = res.GetCategory();
				double cost = res.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};

	traverse(Year, Month, Week);


	// create a vector of pairs with category name and total spending
	std::vector<std::pair<std::string, double>> weekSpendingsVec;
	for (const auto& item : weekSpendings)
	{
		weekSpendingsVec.emplace_back(item);
	}

	// sort categories by total spendings in descending order
	std::sort(weekSpendingsVec.begin(), weekSpendingsVec.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	// print top 3 categories
	std::cout << "Spending in Week " << Week << " in month " << Month << " and year " << Year << ":\n";
	for (int i = 0; i < weekSpendingsVec.size(); i++)
	{
		auto& categorySpending = weekSpendingsVec[i];
		std::cout << categorySpending.first << ": " << categorySpending.second << std::endl;

		// check if there are other categories with the same total spending
		double currentSpending = categorySpending.second;
		int j = i + 1;
		while (j < weekSpendingsVec.size() && weekSpendingsVec[j].second == currentSpending) {
			std::cout << "  " << weekSpendingsVec[j].first << std::endl;
			categorySpending.second += weekSpendingsVec[j].second;
			j++;
		}
		i = j - 1;
	}
}

// Search By Month
void MoneyStorage::searchByMonth(int Year, int Month) const
{
	std::unordered_map<std::string, double> weekSpendings; // map to store total spendings for each category in the week

	// recursive function to traverse the tree and calculate total spendings for each category in the week
	std::function<void(int, int)> traverse = [&](int year, int month)
	{
		for (const auto& res : spendings_)
		{
			int nodeYear = res.GetDate().GetYear();
			int nodeMonth = res.GetDate().GetMonth();
			int nodeDay = res.GetDate().GetDay();
			if (nodeYear == year && nodeMonth == month)
			{
				std::string category = res.GetCategory();
				double cost = res.GetMoney();
				weekSpendings[category] += cost;
			}
		}
	};

	traverse(Year, Month);


	// create a vector of pairs with category name and total spending
	std::vector<std::pair<std::string, double>> weekSpendingsVec;
	for (const auto& item : weekSpendings)
	{
		weekSpendingsVec.emplace_back(item);
	}

	// sort categories by total spendings in descending order
	std::sort(weekSpendingsVec.begin(), weekSpendingsVec.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	// print top 3 categories
	std::cout << "Spending in Month " << Month << " and year " << Year << ":\n";
	for (int i = 0; i < weekSpendingsVec.size(); i++)
	{
		auto& categorySpending = weekSpendingsVec[i];
		std::cout << categorySpending.first << ": " << categorySpending.second << std::endl;

		// check if there are other categories with the same total spending
		double currentSpending = categorySpending.second;
		int j = i + 1;
		while (j < weekSpendingsVec.size() && weekSpendingsVec[j].second == currentSpending) {
			std::cout << "  " << weekSpendingsVec[j].first << std::endl;
			categorySpending.second += weekSpendingsVec[j].second;
			j++;
		}
		i = j - 1;
	}
}

// Read From File

void MoneyStorage::readFromFile()
{
	std::string filename = "Tree.txt";
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file " << filename << '\n';
		return;
	}

	std::string line;
	std::multiset<Spendings> spendings;
	Date date(0, "", 0); // default date
	int total = 0;
	while (std::getline(file, line))
	{
		if (line.empty()) continue; // skip empty lines
		if (line.find("Date: ") == 0)
		{
			// Store previous node, if any
			if (!spendings.empty())
			{
				spendings_.insert(spendings.begin(), spendings.end());
				spendings.clear();
			}

			// Read date
			std::istringstream iss(line);
			std::string dateStr, monthStr;
			int day, year;
			char point;
			iss >> dateStr >> day >> point >> year >> monthStr;
			if (dateStr != "Date:" || iss.fail())
			{
				std::cerr << "Error: could not read date from line: " << line << '\n';
				continue;
			}
			date = Date(day, monthStr, year);

			// Read total
			std::getline(file, line);
			std::istringstream totals(line);
			std::string totalStr;
			totals >> totalStr >> total;
			if (totalStr != "Total:" || totals.fail())
			{
				std::cerr << "Error: could not read total from line: " << line << '\n';
				continue;
			}
		}
		else
		{
			// Read spending
			std::istringstream spendIss(line);
			std::string name;
			int cost;
			char point1, point2;
			int hour, minute, second;
			spendIss >> name >> cost >> hour >> point1 >> minute >> point2 >> second;
			name.pop_back();
			if (spendIss.fail())
			{
				std::cerr << "Error: could not read spending from line: " << line << '\n';
				continue;
			}
			Time time(hour, minute, second);
			spendings.insert(Spendings(name, cost, time));
		}
	}

	// Store last node, if any
	if (!spendings.empty())
	{
		spendings_.insert(spendings.begin(), spendings.end());
		spendings.clear();
	}

	totalAmount_ = total;
}

// Write to File
void MoneyStorage::writeToFile()
{
	std::string filename("Tree.txt");
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file " << filename << std::endl;
		return;
	}

	// Traverse the tree and write each node's information to the file
	if (spendings_.size() == 0)
	{
		std::cerr << "Failed to write your Spendings empty " << filename << std::endl;
		return;
	}

	for (const auto& res : spendings_)
	{
		file << res.GetDate() << "Total: " << res.GetMoney() << "\n";
		file << res.GetCategory() << ": " << res.GetMoney() << " " << res.GetTime() << "\n";
	}
}

// Default Constructor
MoneyStorage::MoneyStorage()
{
	totalAmount_ = 0;
	creditLimit_ = 0;
}

// Destructor
MoneyStorage::~MoneyStorage()
{

}