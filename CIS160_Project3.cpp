/*
	Name: Miguel Juarez
	Date: 11/01/2022
	Class: CIS 160 Fundamentals of Computer Science I
	Project Name: PCCC Catering & Convention Billing
	Description: Billing system for catering and convention services
*/

//Preprocessor directives needed for program
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//DESERT is cost of each desert, TAX is amount charged to total amount
//TIPS is amount charged to total amount, CHILD is 60% charged to the price of an adult's meal
const float DESERT = 4.50, TAX = 0.075, TIPS = 0.15, CHILD = 0.6;

//Function prototypes to take user input, perform calculations, and display output
void Input(string &, int &, int &, int &, float &, float &, float &);
void Process(int, int, int, float, float, float, float &, float &, float &, float &, float &, float &, float &, float &);
void Output(string, int, int, float, float, float, float, float, float, float, float, float, float, float);

//Used to print output out into a separate text file
ofstream fout("Output.txt");

int main()
{
	string name; //holds full name of the customer
	int numAdult; //number of adults
	int numChild; //number of children
	int numDesert; //number of deserts
	float adult; //price for an adult meal
	float fee; //room fee
	float deposit; //amount paid when reservation was made
	float costA; //total cost for all adults
	float costC; //total cost for all children
	float costD; //total cost for all deserts
	float food; //total cost of food oredered
	float tax; //taxed amount for total cost of food
	float tips; //tips added to the total amount of food ordered
	float bill; //total cost of food with tax and tips
	float balance; //total cost after reducing it with the deposit amount

	Input(name, numAdult, numChild, numDesert, adult, fee, deposit);
	Process(numAdult, numChild, numDesert, adult, fee, deposit, costA, costC, costD, food, tax, tips, bill, balance);
	Output(name, numAdult, numChild, adult, costA, costC, costD, food, tax, tips, fee, bill, deposit, balance);
}

//Prompts user to input customer information to be stored for calculations and output
//Parameters are defined variables that will be passed by reference to store user input
void Input(string &name, int &numAdult, int &numChild, int &numDesert, float &adult, float &fee, float &deposit)
{
	cout << "Customer Name: ";
	getline(cin, name);
	cout << "\nNumber of Adults: ";
	cin >> numAdult;
	cout << "\nNumber of Children: ";
	cin >> numChild;
	cout << "\nNumber of Deserts: ";
	cin >> numDesert;
	cout << "\nCost per Adult Meal: ";
	cin >> adult;
	cout << "\nRoom Fee: ";
	cin >> fee;
	cout << "\nDeposit Amount: ";
	cin >> deposit;
}

//Performs calculations to find the cost of all the food ordered, including tax, tips, fees, and reservation deposit
//Some parameters will be stored user input that will be passed by value
//Some parameters will be passed by reference to store calculations done and results to be used later
void Process(int numAdult, int numChild, int numDesert, float adult, float fee, float deposit, float &costA, float &costC, float &costD, float &food, float &tax, float &tips, float &bill, float &balance)
{
	costA = numAdult*adult;
	costC = numChild*(adult*CHILD);
	costD = numDesert*DESERT;
	food = costA+costC+costD;
	tax = food*TAX;
	tips = food*TIPS;
	bill = food+tax+tips+fee;
	balance = bill-deposit;
}

//Displays the output of the customer's information and bill in a separate text file
//Parameters are all user input and results from calculations that will be passed by value for displaying output
void Output(string name, int numAdult, int numChild, float adult, float costA, float costC, float costD, float food, float tax, float tips, float fee, float bill, float deposit, float balance)
{
	fout << "\n\n\tPassaic County Catering & Concention Services" << endl;
	fout << "\t\t\tFinal Bill" << endl;
	fout << "\nCustomer:\t\t\t\t" << name << endl;
	fout << "Number of Adults:\t\t\t" << numAdult << endl;
	fout << "Number of Children:\t\t\t" << numChild << endl;
	fout << fixed << showpoint << setprecision(2); //displays all prices with only 2 digits after the decimal
	fout << "\nCost of Meal Per Adult:\t\t\t$" << adult << endl;
	fout << "Cost of Child's Meal Per Child:\t\t$" << adult*CHILD << endl;
	fout << "Cost Per Desert:\t\t\t$" << DESERT << endl;
	fout << "\nTotal Cost for Adult Meals:\t\t$" << costA << endl;
	fout << "Total Cost for Chld Meals:\t\t$" << costC << endl;
	fout << "Total Cost for Desert:\t\t\t$" << costD << endl;
	fout << "Total Food Cost:\t\t\t$" << food << endl;
	fout << "\nPlus 7.5% Tax:\t\t\t\t$" << tax << endl;
	fout << "Plus 15% Tips:\t\t\t\t$" << tips << endl;
	fout << "Plus Room Fee:\t\t\t\t$" << fee << endl;
	fout << "\nTotal Bill:\t\t\t\t$" << bill << endl;
	fout << "Less Deposit:\t\t\t\t$" << deposit << endl;
	fout << "\nBalance Due:\t\t\t\t$" << balance << endl;
	fout << "\n\n\tThank You for Using Passaic  County Catering Services\n\n\n";
	fout.close();
}