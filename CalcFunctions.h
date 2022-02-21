#ifndef PROJECT2_HEADERS_CALCFUNCTIONS_H_
#define PROJECT2_HEADERS_CALCFUNCTIONS_H_

#pragma once
class CalcFunctions
{
public:
	double calcInterest(double currTotal, double interestRate);
	double calcAccountSum(double currentBalance, double monthlyDeposit);
	int calcMonths(int numYears);
};

#endif PROJECT2_HEADERS_CALCFUNCTIONS_H_