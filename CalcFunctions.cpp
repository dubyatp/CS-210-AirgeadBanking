#include "CalcFunctions.h"

// Function calculates monthly interest based on the formula
// <total balance> * (<interest rate>/100) / 12
double CalcFunctions::calcInterest(double currTotal, double interestRate)
{
	return ((currTotal) * ((interestRate / 100) / 12));
}

// Calculates total number of months based on the years specified
int CalcFunctions::calcMonths(int numYears) {
	return (numYears * 12);
}

// Calculates account sum based on current balance plus the monthly deposit
// Also used to add interest to current balance
double CalcFunctions::calcAccountSum(double currentBalance, double monthlyDeposit)
{
	return currentBalance + monthlyDeposit;
}