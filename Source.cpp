/*
* CS-210 Project Two
* Airgead Banking Interest Calculator
* 
* William Peebles
* Assignment Due: February 6, 2022
*/

#include <vector>
#include "ConsoleColor.h"
#include "IOFunctions.h"
#include "CalcFunctions.h"
using namespace std;

// Simple welcome message
void welcomeMessage() {
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$ Welcome to the " << green << "Airgead Banking" << white << " Savings Simulator! $" << endl;
	cout << "$                                                   $" << endl;
	cout << "$                                                   $" << endl;
	cout << "$             Enter the values below                $" << endl;
	cout << "$             to see your money grow!               $" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl;
}

// Generates the report based on values from investmentCalculation function
void generateReport(int numYears, vector<vector<double>> monthsVec) {
	int currYear = 1;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Year              Final Balance            Earned Interest   " << endl;
	cout << "                                                              " << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = currYear; i <= numYears; i++) {
		double yearlyEarnedInterest = 0;
		int endMonth = (currYear * 12) - 1;

		cout << fixed << setprecision(2);
		cout << " " << currYear << "                      " << "$" << monthsVec[endMonth][4] << "                    ";


		for (int j = endMonth; j > (endMonth - 12); j--) {

			double f = monthsVec[j][3];
			yearlyEarnedInterest = yearlyEarnedInterest + f;
		}

		cout << "$" << yearlyEarnedInterest;
		cout << endl;

		currYear = currYear + 1;

	}
}

// "Crunches the numbers" based on paramaters that were specified from the user
void investmentCalculation(double firstDeposit, double monthlyDeposit, double interestRate, int numYears) {

	CalcFunctions calcFunctions;
	const int numMonths = calcFunctions.calcMonths(numYears);

	double earnedInterest;
	double openingAmount;
	double currTotal;
	double closingBalance;

	// Declare vector in vector for each monthly run
	vector<vector<double>> monthsVec;

	// Loop processes the accounts per month until it reaches the maximum number of months
	// specified by the user.
	int currMonth = 1;
	for (int i = currMonth; i <= numMonths; i++) {

		if (currMonth == 1)
		{
			openingAmount = firstDeposit;
			currTotal = calcFunctions.calcAccountSum(openingAmount, monthlyDeposit);
		}
		else {
			openingAmount = closingBalance;
			currTotal = calcFunctions.calcAccountSum(openingAmount, monthlyDeposit);
		}

		earnedInterest = calcFunctions.calcInterest(currTotal,interestRate);
		closingBalance = calcFunctions.calcAccountSum(currTotal, earnedInterest);
		//closingBalance = (currTotal + earnedInterest);

		vector<double> v1 = {openingAmount, monthlyDeposit, currTotal, earnedInterest, closingBalance};

		// Increase vector size based on number of months
		monthsVec.push_back(v1);

		// Increment current month
		currMonth = currMonth + 1;

		earnedInterest = 0;
		openingAmount = 0;
		currTotal = 0;
	}

	// Reset currMonth to 1
	currMonth = 1;

	/* FOR TROUBLESHOOTING PURPOSES!
	for (int i = currMonth; i <= (numMonths -1); i++) {

		cout << fixed << setprecision(2);
		cout << "Month: " << (currMonth + 1) << endl;
		cout << "Opening Amount: " << monthsVec[i][0] << endl;
		cout << "Monthly Deposit: " << monthsVec[i][1] << endl;
		cout << "Total (before interest): " << monthsVec[i][2] << endl;
		cout << "Earned Interest: " << monthsVec[i][3] << endl;
		// cout << "Earned interest" << calcFunctions.calcYearlyInterest(year[(i * 12)][2], inputOutput.getInterestRate())<< endl;
		cout << "Closing balance: " << monthsVec[i][4] << endl;
		cout << endl;


		currMonth = currMonth + 1;
	}
	*/

	// Generate report based on calculations above
	generateReport(numYears, monthsVec);

}


int main() {
	IOFunctions inputOutput;

	// Show welcome message and prompt for input
	welcomeMessage();
	inputOutput.inputVariables();
	
	// Collect variables from the prompt
	double monthlyDeposit = inputOutput.getMonthlyDeposit();
	const double firstDeposit = inputOutput.getFirstDeposit();
	const double interestRate = inputOutput.getInterestRate();
	const int numYears = inputOutput.getNumYears();
	
	// Generate first report with monthly deposits
	cout << "--------------------------------------------------------------" << green << endl;
	cout << "            Investment Report with Monthly Deposits           " << white << endl;
	investmentCalculation(firstDeposit, monthlyDeposit, interestRate, numYears);

	// Create distance between both reports, for neatness!
	cout << endl << endl << endl;

	// Generate second report without monthly deposits
	cout << "--------------------------------------------------------------" << green << endl;
	cout << "            Investment Report with NO Monthly Deposits           " << white << endl;
	inputOutput.clearMonthlyDeposits();
	monthlyDeposit = inputOutput.getMonthlyDeposit();
	investmentCalculation(firstDeposit, monthlyDeposit, interestRate, numYears);

	// Give option to run program again or quit
	char keyPress;
	cout << endl << "Press 'A' and ENTER to run the simulation again" << endl;
	cout << "Press 'Q' and ENTER to quit" << endl;
	cin >> keyPress;
	if (keyPress == 'A' || keyPress == 'a') {
		main();
	}
	else {
		return 0;
	}

	return 0;
}