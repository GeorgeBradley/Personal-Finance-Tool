// Personal Finance Tool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Utils.h"
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
	std::vector<Bill>objBillsToPay;
public:
	User(std::string sName, double dMonthlyWage)
	:m_sName(sName), m_dMonthlyWage(dMonthlyWage) {}
	
	void AddBill(std::string sBillName, double dMonthlyBill) 
	{
		objBillsToPay.push_back({ sBillName, dMonthlyBill });
	}

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

/*void CreateUser(std::vector<User>&objUsers) 
{
	std::string sName = "";
	unsigned char ucOption = 0;
	double dMonthlySalary = 0;
	std::string sLine = "";
	Message_And_Input("Enter your name: ", &sName);
	do 
	{
		Message_And_Input("Enter your monthly salary: ", &sLine);
	} 
	while (Is_Input_A_Number(sLine, &dMonthlySalary) == false);
	objUsers.push_back({ sName, dMonthlySalary });

	Message_And_Input("Do you have monthly bills to pay? (Y / N): ", &ucOption);
	
	if (ucOption == 'Y') 
	{
		int iAmountOfBills = 0;
		do 
		{
			sLine = "";
			Message_And_Input("How many  bills do you have to pay?: ", &sLine);
		} 
		while (Is_Input_A_Number(sLine, &iAmountOfBills) == false);
		for (std::size_t st = 0; st < iAmountOfBills;st++) 
		{
			std::string sBillName = "";
			double dMonthlyBill = 0;
			Message_And_Input("Enter bill name", &sBillName);
			do 
			{
				Message_And_Input("Enter monthly bill amount: ", &dMonthlyBill);
			} 
			while (Is_Input_A_Number(sLine, &dMonthlyBill) == false);
			objUsers.at(objUsers.size() - 1).AddBill(sBillName, dMonthlyBill);
		}
	}
}*/
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

void TestData(std::vector<User>& objUsers)
{
	objUsers.push_back({ "Jack Kimmins", 764});
	objUsers.at(0).AddBill("Water Bill", 65);
	objUsers.push_back({ "George Bradley", 332});
	objUsers.push_back({ "Jason Hill", 343 });
	objUsers.push_back({ "Sean Shearing", 374 });
}

int main()
{
	std::vector<User>objUsers;
	TestData(objUsers);
	//CreateUser(objUsers); Will need to be wrapped in a while loop if uncommented
	DisplayResults(objUsers);
	system("pause"); //Ignore this, I know using system isn't good, just to stop it
}