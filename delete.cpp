#include <iostream>
#include <string> 
#include <stdlib.h>
#include <conio.h>
using namespace std;
#define num 100
#define SurSize 20
#define ExSize 100
#define RecSize 100
struct SourceInfo
{
	string SName;
	int Date;
	double Value;
};
struct ExpenseInfo
{
	string EName;
	int Date[num];
	double Value[num];
};
struct RecurringInfo
{
	int Date[num];
	double Value[num];
};
//struct All
//{
//	SourceInfo SI[SurSize];
//	ExpenseInfo EI[ExSize];
//	RecurringInfo RI[ExSize];
//};
void MainMenu();
//[[noreturn]] void exit(int status);
void AddSource(SourceInfo SoIn[], int, int);
void AddExpense(ExpenseInfo ExIn[], int);
void AddRecurring(RecurringInfo RrIn[]);
//void ListRecurring();
//void ListSource();
void EditSource(SourceInfo Soln[], int);
void EditExpense(ExpenseInfo ExIn[], int);
void DeleteSource(SourceInfo SoIn[], int);
void DeleteExpens(ExpenseInfo ExIn[], int);

//void DisQuick();
//void DisDetalied();
void DateRange(int, int);

//All SuIn, ExIn, RcIn;


int main()
{

	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n\t     Welcome in our programe \" BUDGET TRACKER \" ;)... \n\n" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";

	MainMenu(); //choice's function

	char charcter;

	cout << "If you want to EXIT from our programe so press the leter \"e\"  :'(.... \n\n ";

	cin >> charcter;

	if (charcter == 'e' || charcter == 'E')
		return 0; //to exit from the program
				  //exit(0); //to exit from the programe

	system("pause");
	return 0;
} //end main

  //fuction that the user will choose from
void MainMenu() {



	SourceInfo SoIn[num];
	ExpenseInfo  ExIn[num];
	RecurringInfo RrIn[num];
	int NumSource = 0, SourcesEachTime;
	int NumExpense = 0, ExpenseEachTime;
	double UserSources = 0;
	double TotalExpenses = 0;
	double  TotalRecurring = 0;
	int DateNum;
	int counter = 0;

	while (true) {

		cout << "\n\t\t\t  HERE is our MAINMENU ;).. ";
		cout << "\n\t\t\t-----------------------------\n\n";
		int choice;  //the number of choice that the user will choose

		cout << "Please enter number _1_ to Add New Incomes :)...\n\n";

		cout << "Please enter number _2_ to Add New Expenss :)... \n\n";

		cout << "Please enter number _3_ to Add Recurring costs :)... \n\n";

		cout << "Please enter number _4_ to display The List of recurring costs :)... \n\n";

		cout << "Please enter number _5_ to display The List of incomes sources :)... \n\n";

		cout << "Please enter number _6_ to Edit any value :)... \n\n";

		cout << "Please enter number _7_ to Delete any value :)... \n\n";

		cout << "Please enter number _8_ to Show quick view on your current status :)... \n\n";

		cout << "Please enter number _9_ to Show the detailed status :)... \n\n";

		cout << "Please enter number _10_ to Enter specified date range to see the net flow of your money :)... \n\n";

		cout << endl;

		cout << "THE ANSWER IS : ";

		cin >> choice; //we forgot this so the user wasn't able to choose what he want

					   /*system("cls");*/
		switch (choice)
		{
		case 1:
			system("cls");

			cout << "PLease enter how many sources u want to add :  ";
			cin >> SourcesEachTime;
			NumSource += SourcesEachTime;
			AddSource(SoIn, NumSource, counter);
			counter += NumSource;
			break;
			//end case 1;

		case 2:
			system("cls");
			int NumExpense;

			cout << "Hello user :) How many expenses you want to add : ";
			cin >> NumExpense;


			AddExpense(ExIn, NumExpense);

			break;
			//end case 2;

		case 3:

			system("cls");

			AddRecurring(RrIn);

			break;
			//end case 3
		case 4:
			//ListRecurring();
		case 5:
			//ListSource();
		case 6:
			system("cls");

			int EditChoice;
			cout << "Hello User :) please selsect what do u want to edit :\n _1_Edit source \n_2_Edit expense \n _3_Edit recurring\n";

			cout << "THE ANSWER IS : ";
			cin >> EditChoice;

			switch (EditChoice)
			{
			case 1:
				EditSource(SoIn, NumSource);
				break;

			case 2:
				EditExpense(ExIn, NumExpense);
				break;

			case 3:
				break;
			}//end switch (editchoice)
			break;
			//end case 6;

		case 7:
			system("cls");
			int DeleteChoice;
			cout << "Hello User :).. Please choose the number U want to delete :(... \n _1_DELETE Source :(.. \n _2_DELETE Expense :(.. \n _3_DELETE Reccuiring :(..\n THE ANSWER IS :  ";
			cin >> DeleteChoice;

			switch (DeleteChoice) {
			case 1:
				DeleteSource(SoIn, NumSource);
				break;
				//end case 1

			case 2:

				break;
				//end case 2

			case 3:
				break;
				//end case 3
			}
			break;
			//end case 7
		case 8:
			//DisQuick();
		case 9:
			//DisDetalied();
		case 10:
			system("cls");

			int FirstDate, LastDate;

			cout << "Please enter a specific DATE RANGE :)... \n FROM :  ";

			cin >> FirstDate; //the  first day in the date range that will search from

			cout << "\n TO :  ";

			cin >> LastDate; //the  last day in the date range that will search to

			cout << endl;
			DateRange(FirstDate, LastDate);
			//end case 10;


			//default:
			//	cout << "\tUNDEFIND CHOICE :(.. \n\n";

			system("pause");
			system("cls");

		} //end switch (choice)

		string answer;

		cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "Please enter \"Yes\" if you want to back to the MainMenu :).. or \"No\" if you want to exit :(.. \n\n ";

		cout << "THE ANSWER IS : ";
		cin >> answer;//enter his choice ..
					  /*getline(cin, answer);*/
		cin.ignore();
		cout << endl;


		if (answer == "no" || answer == "No")
		{
			//clean screan at first then exit from the function
			system("cls");
			break; //to exit from this function
				   /*system("pause");*/
		}//endh if (answer)

		 /*answer == "yes" || answer == "Yes"*/

	} //end while(true)


} //end MAIMMENU

  // function to add sources of the user 
void AddSource(SourceInfo SoIn[], int NumSource, int counter) {

	double UserSources = 0;

	for (int i = counter; i < NumSource; i++) {

		cout << "Please enter source " << i + 1 << " name :  ";
		cin.ignore();
		getline(cin, SoIn[i].SName);

		cout << "Please enter source " << i + 1 << " date :  ";
		cin >> SoIn[i].Date;

		cout << "Please enter source " << i + 1 << " value :  ";
		cin >> SoIn[i].Value;

	}


	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "------------------------------------------------------------------------------------------------\n";

	cout << " Income Name\tIncome Date\tIncome Value\n";
	for (int i = 0; i < NumSource; i++) {
		UserSources += SoIn[i].Value;
		cout << SoIn[i].SName << "\t\t    " << SoIn[i].Date << "\t   " << SoIn[i].Value << "$\n";
	}
	cout << "ur total income is : " << UserSources;

	cout << "\n------------------------------------------------------------------------------------------------\n";

}
