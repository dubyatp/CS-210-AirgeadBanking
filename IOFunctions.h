#ifndef PROJECT2_HEADERS_IOFUNCTIONS_H_
#define PROJECT2_HEADERS_IOFUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <vector>
#pragma once
class IOFunctions
{
public:
	void inputVariables();
	void setNextBalance(double);
	void clearMonthlyDeposits();

	double getCurrentBalance();
	double getMonthlyDeposit();
	double getInterestRate();
	double getFirstDeposit();
	int getNumYears();
private:
	double m_firstDeposit;
	double m_currentBalance;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYears;
};

#endif // PROJECT2_HEADERS_IOFUNCTIONS_H_