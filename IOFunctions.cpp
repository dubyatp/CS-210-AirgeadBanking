#include "IOFunctions.h"
using namespace std;

void IOFunctions::inputVariables() {
	// Initial Values
	m_firstDeposit = 0.0;
	m_monthlyDeposit = 0.0;
	m_interestRate = 0.0;
	m_numYears = 0;

	// Prompt user for first deposit, monthly deposit, interest rate, and number of years to calculate
	// Exceptions configued in case unacceptable answers are entered
	while (m_firstDeposit <= 0) {
		try {
			cout << "Enter opening amount: $";
			cin >> m_firstDeposit;
			cout << endl;

			// You cannot have a negative first deposit, nor a negative deposit of $0.
			// Exception is thrown if negative number OR 0 is entered
			if (m_firstDeposit <= 0.0) {
				throw m_firstDeposit;
			}
		}
		catch (double badDeposit) {
			cout << "Exception: Deposit cannot be less than $1" << endl;
		}
	}

	while (m_monthlyDeposit <= 0) {
		try {
			cout << "Enter monthly deposit: $";
			cin >> m_monthlyDeposit;
			cout << endl;

			// While the simulation does run a report without monthly deposits,
			// a monthly deposit amount is still required.
			// Exception is thrown if 0 or less
			if (m_monthlyDeposit <= 0) {
				throw m_monthlyDeposit;
			}
		}
		catch (double badDeposit) {
			cout << "Exception: Monthly deposit cannot be a 0 or a negative value" << endl;
			cout << "NOTE: The simulation will run a report with and without monthly deposits" << endl;
		}
	}
	while (m_interestRate <= 0) {
		try {
			cout << "Enter interest rate: %";
			cin >> m_interestRate;
			cout << endl;
			
			// Interest rate CAN be 0%, so we don't need to throw an exception as long as it doesn't become negative
			if (m_interestRate < 0) {
				throw m_interestRate;
			}
		}
		catch (double badIntRate) {
			cout << "Exception: Interest rate cannot be a negative value" << endl;
		}
	}

	while (m_numYears < 1) {
		try {
			cout << "Enter number of years: ";
			cin >> m_numYears;
			cout << endl;

			// You must calculate at least a year, so we need to throw an exception if anything less than 1 year is entered 
			if (m_numYears < 1) {
				throw m_numYears;
			}
		}
		catch (int badNumYears) {
			cout << "Exception: You must enter at least 1 year" << endl;
		}
	}
}

// Function clears the m_monthlyDeposit variable
void IOFunctions::clearMonthlyDeposits() {
	m_monthlyDeposit = 0;
}

// Function returns the m_firstDeposit variable
double IOFunctions::getFirstDeposit()
{
	return m_firstDeposit;
}

// Function returns the m_monthlyDeposit variable
double IOFunctions::getMonthlyDeposit() {
	
	return m_monthlyDeposit;
}

// Function returns the m_interestRate variable
double IOFunctions::getInterestRate() {
	
	return m_interestRate;
}

// Function returns the m_numYears variable
int IOFunctions::getNumYears() {

	return m_numYears;
}