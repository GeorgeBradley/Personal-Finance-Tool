// Personal Finance Tool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

//THANKS JACK FOR YOUR FANTASTIC IDEA!!!!!!!!!!!!
class Bill 
{
private:
	std::string m_sBillName;
	double m_dMonthlyBill;
public:
	Bill(std::string sBillName, double dMonthlyBill)
	:m_sBillName(sBillName),m_dMonthlyBill(dMonthlyBill) {}

	double GetMonthlyBill() {
		return m_dMonthlyBill;
	}
};

class User 
{
private:
	std::string m_sName;
	double m_dMonthlyWage;
public:
	User(std::string sName, double dMonthlyWage)
	:m_sName(sName), m_dMonthlyWage(dMonthlyWage) {}
	std::vector<Bill>objBillsToPay;

	double WeeklyWage() {
		return m_dMonthlyWage / 4;
	}
	double YearlyWage() {
		return m_dMonthlyWage * 12;
	}
	double TotalSpentOnBills()
	{
		double dTotal = 0;
		for (Bill &objBill : objBillsToPay) 
		{
			dTotal += objBill.GetMonthlyBill();
		}
		return dTotal;
	}

	double LeftToSaveMonthly()
	{
		return (YearlyWage() / 12) - (TotalSpentOnBills() / 12);
	}

	double TotalLeftToSaveYearly() 
	{
		return YearlyWage() - TotalSpentOnBills();
	}

	double OverSaved() 
	{
		return TotalLeftToSaveYearly() * 0.10;
	}

	double UnderSaved() {
		return TotalLeftToSaveYearly() - (TotalLeftToSaveYearly() * 0.10);
	}
};

void CreateUser(std::vector<User>&objUsers) 
{
	std::string sName = "";
	unsigned char ucOption = 0;
	double dMonthlySalary = 0;
	std::cout << "Enter your name: ";
	std::cin >> sName;
	std::cout << "Enter your monthly salary: ";
	std::cin >> dMonthlySalary;
	objUsers.push_back({ sName, dMonthlySalary });
	std::cout << "Do you have monthly bills to pay? (Y / N): ";
	std::cin >> ucOption;
	if (ucOption == 'Y') 
	{
		int iAmountOfBills = 0;
		
		std::cout << "How many bills do you have to pay?: ";
		std::cin >> iAmountOfBills;
		for (std::size_t st = 0; st < iAmountOfBills;st++) 
		{
			std::string sBillName = "";
			double dMonthlyBill = 0;
			std::cout << "Enter bill name" << st + 1 << ": ";
			std::cin >> sBillName;
			std::cout << "Enter monthly bill amount: ";
			std::cin >> dMonthlyBill;
			objUsers.at(objUsers.size() - 1).objBillsToPay.push_back({ sBillName, dMonthlyBill });
		}
	}
}

void DisplayResults(std::vector<User>& objUsers) {

	for (User& objUser : objUsers) {
		std::cout << "***" << std::endl;
		std::cout << "Weekly wage: " << objUser.WeeklyWage() << std::endl;
		std::cout << "Yearly wage: " << objUser.YearlyWage() << std::endl;
		std::cout << "10% over total that can be saved: " << objUser.OverSaved() << std::endl;
		std::cout << "10% under total that can be saved: " << objUser.UnderSaved() << std::endl;
		std::cout << "Total left to save yearly: " << objUser.TotalLeftToSaveYearly() << std::endl;
		std::cout << "Total spent on bills: " << objUser.TotalSpentOnBills() << std::endl;
		
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<User>objUsers;
	while (true) 
	{
		CreateUser(objUsers);
		DisplayResults(objUsers);
	}
}

