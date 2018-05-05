#include<iostream>
#include<istream>
#include<string>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
#include <limits>

#define num 50
#define SurSize 20
#define ExSize 100
#define RecSize 100

using namespace std;

struct SourceInfo
{
	string SName;
	int tybe;
	int month = NULL;
    int Date = NULL;
	double Value = NULL;
};
struct ExpenseInfo
{
	string EName;
	int Date = NULL;
	int month = NULL;
	double Value = NULL;
};
struct RecurringInfo
{
	string RName[num];
	int Date[num];
	double Value[num];
};
struct All
{
	SourceInfo SI;
	ExpenseInfo EI;
	RecurringInfo RI;
};
void MainMenu();
double AddSource(SourceInfo Soln[], int);
double AddExpense(ExpenseInfo ExIn[], int);
double AddRecurring(int&, int&, int&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&);
void ListRecurring(int&, int&, int&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&);
void ListSource(SourceInfo SoIn[], int);
void ListExpense(ExpenseInfo ExIn[], int);
void EditSource(SourceInfo Soln[], int);
void EditExpense(ExpenseInfo ExIn[], int);
void DeleteSource(SourceInfo SoIn[], int&);
void DeleteExpens(ExpenseInfo ExIn[], int&);

//void EditRec(int&, int&, int&, RecurringInfo&, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo&, RecurringInfo&);
double GenerateReport(SourceInfo Soln[], ExpenseInfo ExIn[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, int&, int&, int&, int&, int&, int&, int&, int&, double&);

void DisQuick(double, double, double);
void DisDetalied(SourceInfo SoIn[], ExpenseInfo ExIn[], int, double, double, double, int, int, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo);
void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo);
void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo);

int main()
{

	cout << "||-----------------------------------------------------------------------------------------------||\n";
	cout << "||-----------------------------------------------------------------------------------------------||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||\n";

	cout << "||\t\t\t\t \t\t\t\t \t\t\t\t ||\n||\t         Welcome in our programe \" BUDGET TRACKER \" ;)... \t\t\t\t ||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||" << endl;

	cout << "||-----------------------------------------------------------------------------------------------||\n";
	cout << "||-----------------------------------------------------------------------------------------------||\n";


	char charcter;

	cout << "\n\n\n  If you want to see our MAINMINUE soo press the leter \"M\" ;)...\n\n";

	cout << "  If you want to EXIT from our programe so press the leter \"E\"  :'(.... \n\n\t\t\t UR ANSWER IS :  ";

	cin >> charcter;

	if (charcter == 'm' || charcter == 'M') {
		system("cls");
		MainMenu(); //choice's function

	}

	else if (charcter == 'e' || charcter == 'E')
		return 0; //to exit from the program
				  //exit(0); //to exit from the programe

	system("pause");
	return 0;
} //end main

  //fuction that the user will choose from
void MainMenu()
{

	SourceInfo SoIn[num];
	ExpenseInfo  ExIn[num];
	RecurringInfo RrIn[num];
	int NumSource = 0, SourcesEachTime;
	int NumExpense = 0, ExpenseEachTime;
	double UserSources = 0;
	double TotalExpenses = 0;
	double TotalRecurring = 0;
	RecurringInfo Food = { 0 }, HomeRent = { 0 }, CarFuel = { 0 }, ElecBill = { 0 }, WaterBill = { 0 }, GasBill = { 0 }, Wi_Fi = { 0 }, MobileBill = { 0 }, Other = { 0 };
	int FoodCounter = 0, FuelCounter = 0, OtherCounter;


	//to read the saved data from a text file 
	ReadData(SoIn, ExIn, NumSource, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill);



	while (true) {
		int choice;  //the number of choice that the user will choose
		int EditChoice;
		std::cout << "Please enter number _1_ to Add New Incomes :)...\n\n";

		cout << "Please enter number _2_ to Add New (instantaneous) Expenses :)... \n\n";

		cout << "Please enter number _3_ to Add (Recurring) expenses :)... \n\n";

		cout << "Please enter number _4_ to display The List of recurring costs :)... \n\n";

		cout << "Please enter number _5_ to display The List of incomes sources :)... \n\n";

		cout << "Please enter number _6_ to Edit any value :)... \n\n";

		cout << "Please enter number _7_ to Delete any value :)... \n\n";

		cout << "Please enter number _8_ to Show quick view on your current status :)... \n\n";

		cout << "Please enter number _9_ to Show the detailed status :)... \n\n";

		cout << "Please enter number _10_ to generate a report :)... \n\n";

		cout << endl;
		cout << "YOUR ANS IS : ";

		cin >> choice;

		/*system("cls");*/
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Hello user :) how many source you want to add : ";
			cin >> SourcesEachTime;
			while (cin.fail())
			{
				system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hello user :) how many source you want to add : ";
				cin >> SourcesEachTime;

			}

			NumSource += SourcesEachTime;

			UserSources += AddSource(SoIn, NumSource);

			cout << "your total value of income during this month is : " << UserSources << endl;
			break;
		case 2:
			system("cls");


			cout << "hello user :) how many expenses you want to add : ";
			cin >> ExpenseEachTime;
			while (cin.fail())
			{
				system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hello user :) how many instantaneous expenses you want to add : ";
				cin >> ExpenseEachTime;

			}

			NumExpense += ExpenseEachTime;
			TotalExpenses += AddExpense(ExIn, NumExpense);

			break;
		case 3:
			system("cls");
			TotalRecurring += AddRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Other);
			break;
		case 4:
			ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Other);
			break;
		case 5:
			system("cls");
			ListSource(SoIn, NumSource);
			break;
		case 6:
			system("cls");
			{cout << "hello :) please selsect what do u want to edit :\n_1_Edit source\n_2_Edit expense\n_3_Edit recurring\n";
			cin >> EditChoice;
			switch (EditChoice)
			{
			case 1:
				system("cls");

				EditSource(SoIn, NumSource);
				break;

			case 2:
				system("cls");
				EditExpense(ExIn, NumExpense);
				break;
			case 3:
				system("cls");

				//EditRec(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Other);		
				break;
			}
			}
			break;
		case 7:
			system("cls");
			int DeleteChoice;
			cout << "Hello User :).. Please choose the number U want to delete :(... \n\n\t _1_DELETE Source :(.. \n\t _2_DELETE Expense :(.. \n\t _3_DELETE Reccuiring :(..\n\n\n\t\t THE ANSWER IS :  ";
			cin >> DeleteChoice;

			switch (DeleteChoice) {
			case 1:
				system("cls");

				DeleteSource(SoIn, NumSource);
				break;
			case 2:
				system("cls");

				DeleteExpens(ExIn, NumExpense);
				break;
			case 3:
				system("cls");

				break;
			}
			break;
		case 8:
			system("cls");

			DisQuick(UserSources, TotalExpenses, TotalRecurring);
			break;
		case 9:
			system("cls");

			DisDetalied(SoIn, ExIn, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill);
			break;
		case 10:
			system("cls");
			cout << "\n  THE generate reporte choice to enter a specifed date range as U want from start date to the end date U want ;).. \n\t !!! DURING the same Year \" It means from January to December \" ;)... \n\t AAND the programe will show what you got and paid during this interval :).. \n\t  AT the end it will print to U if you saving or in debt and how much is money ;)... \n   ";
			system("cls");


			int StartDay, StartMonth, EndDay, EndMonth;


			cout << " Please enter the START date \"DAY\" :  ";
			cin >> StartDay;
			while (!cin.eof())// while the end-of-file has not been reached
			{

				if (cin.fail()) {
					cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
					cout << " Please enter the START date \"DAY\" :  ";
					cin >> StartDay;

				}//end if (cin.fail())

			}//end while (!cin.eof())

			cout << "\n Please enter the START date \"MONTH\" :  ";
			cin >> StartMonth;
			while (!cin.eof())// while the end-of-file has not been reached
			{

				if (cin.fail()) {
					cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
					cout << "\n Please enter the START date \"MONTH\" :  ";
					cin >> StartMonth;

				}//end if (cin.fail())

			}//end while (!cin.eof())

			cout << "\n Please enter the END date \"DAY\" :  ";
			cin >> EndDay;
			while (!cin.eof())// while the end-of-file has not been reached
			{

				if (cin.fail()) {
					cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
					cout << "\n Please enter the END date \"DAY\" :  ";
					cin >> EndDay;

				}//end if (cin.fail())

			}//end while (!cin.eof())

			cout << "\n Please enter the END date \"MONTH\" :  ";
			cin >> EndMonth;


			while (!cin.eof())// while the end-of-file has not been reached
			{

				if (cin.fail()) {
					cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
					cout << "\n Please enter the END date \"MONTH\" :  ";
					cin >> EndMonth;

				}//end if (cin.fail())

			}//end while (!cin.eof())

			cout << endl << endl;

			double Current = 0;

			cout << "START = " << Current << endl << endl;

			GenerateReport(SoIn, ExIn, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, NumSource, NumExpense, FoodCounter, FuelCounter, StartDay, StartMonth, EndDay, EndMonth, Current);



			cout << "END = " << Current << endl << endl;

			
			cout << endl;
			break;
			//default:
			//cout << "\tUNDEFIND CHOICE :(.. \n\n";
			
			system("cls");

			system("pause");
		}




		string answer;

		cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "Please enter \"Yes\" if you want to back to the MainMenu :).. or \"No\" if you want to exit :(.. \n\n ";

		cin >> answer;//enter his choice ..

		cin.ignore();
		cout << endl;
		
		system("cls");

		if (answer == "no" || answer == "No")
		{
			//clean screen at first then exit from the function
			system("cls");
			break; //to exit from this function
				   /*system("pause");*/
		}

	}

	//saving everything in a file :) 
	InFile(SoIn, ExIn, NumSource, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill);

}
double AddSource(SourceInfo SoIn[], int NumSource)
{

	double UserSources = 0;
	int i = 0;

	while (i < NumSource)
	{//check foe an empty array to start filling the data in 
		if (SoIn[i].Value == NULL && SoIn[i].Date == NULL && SoIn[i].SName.size() == NULL && SoIn[i].month == NULL)
		{
			cout << endl;
			cout << "please enter source  " << i + 1 << "  name :: ";
			cin.ignore();

			getline(cin, SoIn[i].SName);

			cout << endl;

			cout << "please enter source  " << i + 1 << "  date :: ";
			cin >> SoIn[i].Date;
			cout << endl;

			cout << "please enter source  " << i + 1 << "  value :: ";
			cin >> SoIn[i].Value;
			cout << endl;

			cout << "please enter your income tybe ( _1_for instant /_2_for recurrent) :: ";
			cin >> SoIn[i].tybe;
			cout << endl;

			/*if (SoIn[i].tybe == 1)
			{
			cout << " since this income is instant :) So plz enter the month you have it in (ex: April= 4)  :: ";
			cin >> SoIn[i].month;
			}*/
			/*cout << "please enter your income tybe ( _1_for instant /_2_for recurrent) :: ";
			cin >> SoIn[i].tybe;
			cout << endl;*/
			while (true)
			{

				if (SoIn[i].tybe == 1)
				{
					cout << " since this income is instant :) So plz enter the month you have it in (ex: April= 4)  :: ";
					cin >> SoIn[i].month;
					break;
				}
				if (SoIn[i].tybe == 2)
					break;

				if (SoIn[i].tybe != 1 || SoIn[i].tybe != 2)
				{
					cout << "wrong choice !! \n";
					cout << "please renter your income tybe ( _1_for instant /_2_for recurrent) :: ";
					cin >> SoIn[i].tybe;
					cout << endl;
				}




			}


			cout << "----------------------------------------------------------\n";
			UserSources += SoIn[i].Value;


		}
		else
			i++;
	}


	return UserSources;
}

double AddExpense(ExpenseInfo ExIn[], int NumExpense)
{
	int DateNum[5];
	double TotalExpense = 0;
	int i = 0;
	while (i < NumExpense)
	{

		if (ExIn[i].Value == NULL && ExIn[i].Date == NULL && ExIn[i].EName.size() == NULL && ExIn[i].month == NULL)
		{
			cout << endl;
			cout << "enter expense  " << i + 1 << "  name : ";
			cin.ignore();
			getline(cin, ExIn[i].EName);
			cout << endl;

			cout << "enter expense  " << i + 1 << " date " << ":";
			cin >> ExIn[i].Date;
			cout << endl;
			cout << "enter expense " << i + 1 << "  month (ex: April= 4)  " << ":";
			cin >> ExIn[i].month;
			cout << endl;

			cout << "enter expense  " << i + 1 << "  value " << ":";
			cin >> ExIn[i].Value;
			cout << endl;

			TotalExpense += ExIn[i].Value;

		}

		else
			i++;

	}
	//print expenses
	cout << "#num\tname\tdate\tmonth\tvalue\t\n";

	for (int i = 0; i < NumExpense; i++)
	{


		cout << i + 1 << "\t" << ExIn[i].EName << "\t" << ExIn[i].Date << "\t" << ExIn[i].month << "\t" << ExIn[i].Value << "\t";

		cout << endl;
	}


	return TotalExpense;
}
//AddRecurring function
double AddRecurring(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo& Food, RecurringInfo& HomeRent, RecurringInfo & CarFuel, RecurringInfo& ElecBill, RecurringInfo & WaterBill, RecurringInfo &GasBill, RecurringInfo& Wi_Fi, RecurringInfo &MobileBill, RecurringInfo &Other)
{
	int n;
	string ans = "yes";

	string answer;
	double TotalFood = 0, TotalFuel = 0, TotalOther = 0, TotalRecurring = 0;

	while (true)
	{
		system("cls");

		cout << "_1_Food\n_2_Car Fuel\n_3_Electricity Bill\n_4_Water Bill\n_5_Gas Bill\n_6_Wi_Fi <3 \n_7_Mobile Bill\n_8_Home Rent \n_9_OTHERS....\n";
		cin >> n;
		switch (n)
		{
		case 1:
			do
			{
				cout << "<<< Food " << FoodCounter + 1 << ">>>> \n ";
				cout << "The Date" << FoodCounter + 1 << " : " << endl;
				cin >> Food.Date[FoodCounter];
				cout << "value" << FoodCounter + 1 << " : " << endl;
				cin >> Food.Value[FoodCounter];
				TotalFood += Food.Value[FoodCounter];
				cout << "Do you want to add more food costs ? \"yes\" OR \"no\" \n ";
				cin >> answer;
				FoodCounter++;
			} while (answer == "yes" || answer == "Yes");
			break;
		case 2:
			do
			{
				cout << "<<< Car Fuel " << FuelCounter + 1 << " >>>" << endl;
				cout << "The Date " << FuelCounter + 1 << " : " << endl;
				cin >> CarFuel.Date[FuelCounter];
				cout << "value " << FuelCounter + 1 << " : " << endl;
				cin >> CarFuel.Value[FuelCounter];
				TotalFuel += CarFuel.Value[FuelCounter];
				cout << "Do you want to add more Car Fuel costs ? \"yes\" OR \"no\" \n";
				cin >> answer;
				FuelCounter++;
			} while (answer == "yes" || answer == "Yes");
			break;
		case 3:
			cout << "<<< Electricity Bill >>>\n ";
			cout << "The Date : ";
			cin >> ElecBill.Date[0];
			cout << " value : ";
			cin >> ElecBill.Value[0];
			TotalRecurring += ElecBill.Value[0];
			break;
		case 4:
			cout << "<<< Water Bill >>> \n ";
			cout << "The Date : ";
			cin >> WaterBill.Date[0];
			cout << " value : ";
			cin >> WaterBill.Value[0];
			TotalRecurring += WaterBill.Value[0];
			break;
		case 5:
			cout << "<<< Gas Bill >>> \n ";
			cout << "The Date : ";
			cin >> GasBill.Date[0];
			cout << " value : ";
			cin >> GasBill.Value[0];
			TotalRecurring += GasBill.Date[0];
			break;
		case 6:
			cout << "<<< Wi_Fi Bill >>>\n  ";
			cout << "The Date : ";
			cin >> Wi_Fi.Date[0];
			cout << "value : ";
			cin >> Wi_Fi.Value[0];
			TotalRecurring += Wi_Fi.Value[0];
			break;
		case 7:
			cout << "<<< Mobile Phone Bill >>>\n ";
			cout << "The Date : ";
			cin >> MobileBill.Date[0];
			cout << "value : ";
			cin >> MobileBill.Value[0];
			TotalRecurring += MobileBill.Value[0];
			break;
		case 8:
			cout << "<<< Home Rent >>>\n  ";
			cout << "The Date: ";
			cin >> HomeRent.Date[0];
			cout << "value : ";
			cin >> HomeRent.Value[0];
			TotalRecurring += HomeRent.Value[0];
			break;
		case 9:
			cout << "<<<OTHERS>>>\n";
			do
			{
				cout << "<<_" << OtherCounter + 1 << "_>>\n ";
				cout << "Name : ";
				cin >> Other.RName[OtherCounter];
				cout << "Date : ";
				cin >> Other.Date[OtherCounter];
				cout << "Value : ";
				cin >> Other.Value[OtherCounter];
				TotalOther += Other.Value[OtherCounter];
				cout << "Do you want to add more Others costs ? \"yes\" OR \"no\" \n";
				cin >> answer;
				OtherCounter++;
			} while (answer == "yes" || answer == "Yes");
			break;
		}
		TotalRecurring += (TotalFood + TotalFuel + TotalOther);
		cout << endl << "-------------------------------------------------------------\n";
		cout << "Do you want to add more recurring data (yes/no)? ";
		cin >> ans;
		if (ans == "no")
			break;
	}
	return TotalRecurring;

}// End AddRecurring function

void EditSource(SourceInfo SoIn[], int NumSource)
{
	int i;
	string NewName;
	int NewMonth;
	int UserChoice, NewDate, ans;
	double NewVal;

	ListSource(SoIn, NumSource);
	cout << "plz choose number of source you want to edit in :: ";
	cout << "you choice is :: ";
	cin >> UserChoice;
	cout << "choose what do u want to edit in your selectd source \n_1_name\n_2_value\n_3_date\n_4_month(For your instant incomes only :)\n";
	cout << "your answer is :: ";
	cin >> ans;
	if (ans == 1)
	{
		cout << "please enter your New name :) : ";
		cin.ignore();
		getline(cin, NewName);
		SoIn[UserChoice - 1].SName = NewName;
		cout << "DONE :) " << endl;

	}
	if (ans == 2)
	{
		cout << "Enter your new value :: ";
		cin >> NewVal;
		SoIn[UserChoice - 1].Value = NewVal;
		cout << "DONE :) " << endl;

	}
	if (ans == 3)
	{
		cout << "Enter you new date :: ";
		cin >> NewDate;
		SoIn[UserChoice - 1].Date = NewDate;
		cout << "DONE :) " << endl;

	}
	if (ans == 4 && SoIn[UserChoice - 1].tybe == 1)
	{
		cout << "plz enter your new month ::";
		cin >> NewMonth;
		SoIn[UserChoice - 1].month = NewMonth;

		cout << "DONE :) " << endl;
	}

}//end edit of source

// //function to edit recurring expense of the user
//void EditRec(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo& Food, RecurringInfo& HomeRent, RecurringInfo& CarFuel, RecurringInfo& ElecBill, RecurringInfo& WaterBill, RecurringInfo& GasBill, RecurringInfo& Wi_Fi, RecurringInfo& MobileBill, RecurringInfo& Other)
//{
//
//	int userAns, NewVal, NewDate;
//	char ans;
//	do
//	{
//		ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Other);
//
//		cout << endl << "choose what do u want to edit in your Recurring List \n ";
//		cin >> userAns;
//		switch (userAns)
//		{
//		case 1://Food edit
//			int FoodNo, choice1;
//			cout << "Which food no. you want to edit ?!! ";
//			cin >> FoodNo;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
//			cin >> choice1;
//			if (choice1 == 1)
//			{
//				cout << "Enter your new value :: ";
//				cin >> NewVal;
//				Food.Value[FoodNo - 1] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice1 == 2)
//			{
//				cout << "Enter your new Date :: ";
//				cin >> NewDate;
//				Food.Date[FoodNo - 1] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 2://Car Fuel edit
//			int CarFuelNo, choice2;
//			cout << "Which car fuel no. you want to edit ?!! ";
//			cin >> CarFuelNo;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
//			cin >> choice2;
//			if (choice2 == 1)
//			{
//				cout << "Enter your new value :: ";
//				cin >> NewVal;
//				CarFuel.Value[CarFuelNo - 1] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice1 == 2)
//			{
//				cout << "Enter your new Date :: ";
//				cin >> NewDate;
//				CarFuel.Date[CarFuelNo - 1] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 3://Electric bill edit
//			int choice3;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n ";
//			cin >> choice3;
//			if (choice3 == 1)
//			{
//				cout << "<<< Electricity Bill (Value) >>>\n";
//				cout << "enter new value of your Electricity Bill :\n";
//				cin >> NewVal;
//				ElecBill.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice3 == 2)
//			{
//				cout << "<<< Electricity Bill (Date) >>>\n";
//				cout << "enter new date of your Electricity Bill : \n";
//				cin >> NewDate;
//				ElecBill.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 4://Home rent edit 
//			int choice4;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
//			cin >> choice4;
//			if (choice4 == 1)
//			{
//				cout << "<<< Home Rent (Value) >>>\n";
//				cout << "enter new value of your Home Rent : ";
//				cin >> NewVal;
//				HomeRent.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice4 == 2)
//			{
//				cout << "<<< Home Rent (Date) >>>\n";
//				cout << "enter new date of your Home Rent : ";
//				cin >> NewDate;
//				HomeRent.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 5://Water bill edit 
//			int choice5;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
//			cin >> choice5;
//			if (choice5 == 1)
//			{
//				cout << "<<< Water Bill (Value) >>>\n";
//				cout << "enter new value of your Water Bill \n:";
//				cin >> NewVal;
//				WaterBill.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice5 == 2)
//			{
//				cout << "<<<  Water Bill (Date) >>>\n";
//				cout << "enter new date of your Water Bill :\n";
//				cin >> NewDate;
//				WaterBill.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 6://Gas bill edit
//			int choice6;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
//			cin >> choice6;
//			if (choice6 == 1)
//			{
//				cout << "<<< Gas Bill (Value) >>>\n";
//				cout << "enter new value of your Gas Bill \n:";
//				cin >> NewVal;
//				GasBill.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice6 == 2)
//			{
//				cout << "<<<  Gas Bill (Date) >>>\n";
//				cout << "enter new date of your Gas Bill :\n";
//				cin >> NewDate;
//				GasBill.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//		case 7://Wi_Fi bill edit
//			int choice7;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
//			cin >> choice7;
//			if (choice7 == 1)
//			{
//				cout << "<<< Wi_Fi Bill (Value) >>>\n";
//				cout << "enter new value of your Wi_Fi Bill \n:";
//				cin >> NewVal;
//				Wi_Fi.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice7 == 2)
//			{
//				cout << "<<<  Wi_Fi Bill (Date) >>>\n";
//				cout << "enter new date of your Wi_Fi Bill :\n";
//				cin >> NewDate;
//				Wi_Fi.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 8://Mobile bill edit
//			int choice8;
//			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
//			cin >> choice8;
//			if (choice8 == 1)
//			{
//				cout << "<<< Mobile Bill (Value) >>>\n";
//				cout << "enter new value of your Mobile Bill \n:";
//				cin >> NewVal;
//				MobileBill.Value[0] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice8 == 2)
//			{
//				cout << "<<<  Mobile Bill (Date) >>>\n";
//				cout << "enter new date of your Mobile Bill :\n";
//				cin >> NewDate;
//				MobileBill.Date[0] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		case 9://other Rec. edit
//			int OtherNo, choice9;
//			string NewName;
//			cout << "Which  no. you want to edit ?!! ";
//			cin >> OtherNo;
//			cout << "You want to edit the Name OR Value OR Date ?!\n _1_Name \n _2_Value \n _3_Date \n ";
//			cin >> choice1;
//			if (choice9 == 1)
//			{
//				cout << "please enter your New name :) : ";
//				cin.ignore();
//				getline(cin, NewName);
//				Other.RName[OtherNo - 1] = NewName;
//				cout << "DONE :) " << endl;
//			}
//			if (choice9 == 2)
//			{
//				cout << "Enter your new Vale :: ";
//				cin >> NewVal;
//				Other.Value[OtherNo - 1] = NewVal;
//				cout << "Done :) " << endl;
//			}
//			if (choice9 == 3)
//			{
//				cout << "Enter your new Date :: ";
//				cin >> NewDate;
//				Other.Date[OtherNo - 1] = NewDate;
//				cout << "Done :) " << endl;
//			}
//			break;
//
//		}
//		cout << "Do you want to Edit more Recurring ? if yes press 'y' \n";
//		cin >> ans;
//	} while (ans == 'y' || ans == 'Y');
//
//
//}//end edit recurring


void ListRecurring(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo& Food, RecurringInfo& HomeRent, RecurringInfo& CarFuel, RecurringInfo& ElecBill, RecurringInfo& WaterBill, RecurringInfo& GasBill, RecurringInfo& Wi_Fi, RecurringInfo& MobileBill, RecurringInfo& Other)
{

	cout << "                         <<_1_ Food detailes >>           \n ";
	cout << "Food no.\tDate\tValue\n";
	for (int i = 0; i < FoodCounter; i++)
	{
		cout << "    " << i + 1 << "     \t" << Food.Date[i] << "     \t" << Food.Value[i] << endl << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                       <<_2_ Car Fuel detailes >>           \n ";
	cout << "car fuel no.\tDate\tValue\n";
	for (int i = 0; i < FuelCounter; i++)
	{
		cout << "     " << i + 1 << "     \t" << CarFuel.Date[i] << "    \t" << CarFuel.Value[i] << endl << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_3_ Electricity Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << ElecBill.Date[0] << "  \t\t" << ElecBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_4_ Home Rent Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << HomeRent.Date[0] << " \t \t" << HomeRent.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_5_ Water Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << WaterBill.Date[0] << "  \t\t" << WaterBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_6_ Gas Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << GasBill.Date[0] << "  \t\t" << GasBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_7_ Wi_Fi Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << Wi_Fi.Date[0] << "  \t\t" << Wi_Fi.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        <<_8_ Mobile Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << MobileBill.Date[0] << " \t \t" << MobileBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                         <<_9_ another detailes >>           \n ";
	cout << "Name\tDate\tValue\n";
	for (int i = 0; i < OtherCounter; i++)
	{
		cout << "_" << i + 1 << "_ " << Other.RName[i] << "     \t" << Other.Date[i] << "     \t" << Other.Value[i] << endl << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";


}// end list recurring

 //function to edit expense of the user
void EditExpense(ExpenseInfo ExIn[], int NumOfExp) {
	string Answer;
	cout << "Hello User :)...\n";
	while (true) {

		int i;
		string NewName;
		int NewMonth;
		int UserChoice, NewDate, ans;
		double NewVal;

		ListExpense(ExIn, NumOfExp);

		cout << "plz choose number of instantaneous expense you want to edit in :: \n";
		cout << "you choice is :: ";
		cin >> UserChoice;
		cout << "choose what do u want to edit in your selectd expense \n_1_name\n_2_value\n_3_date\n_4_month\n";
		cout << "your answer is :: ";
		cin >> ans;
		if (ans == 1)
		{
			cout << "please enter your New name :) : ";
			cin.ignore();
			getline(cin, NewName);
			ExIn[UserChoice - 1].EName = NewName;
			cout << "DONE :) " << endl;

		}
		if (ans == 2)
		{
			cout << "Enter your new value :: ";
			cin >> NewVal;
			ExIn[UserChoice - 1].Value = NewVal;
			cout << "DONE :) " << endl;

		}
		if (ans == 3)
		{
			cout << "Enter you new date :: ";
			cin >> NewDate;
			ExIn[UserChoice - 1].Date = NewDate;
			cout << "DONE :) " << endl;

		}
		if (ans == 4)
		{
			cout << "plz enter your new month ::";
			cin >> NewMonth;
			ExIn[UserChoice - 1].month = NewMonth;

			cout << "DONE :) " << endl;
		}

		cout << " DO U want to EDIT any expenses ??? :: ";
		cin.ignore();
		getline(cin, Answer);

		system("cls");

		if (Answer == "No" || Answer == "no")

			break;

		cout << "------------------------------------------------------------------------------------------------\n";


	}//end while

}//end of edit expense function

 //function to delete source
void DeleteSource(SourceInfo SoIn[], int& NumSource) {

	string Answer;


	while (true) {

		ListSource(SoIn, NumSource);//function that the user will choose from to delete

		cout << "\n\nPlease choose the number of the source U want to delete :(... : ";
		int ChoiceNum;
		cin >> ChoiceNum;

		while (cin.fail())
		{
				system("cls");
				cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
				cout << "\n\nPlease choose the number of the source U want to delete :(... ";
				cin >> ChoiceNum;

		}//end while (cin.fail())

		system("cls");

		bool IsDeleted = false;

		for (int i = 0; i < NumSource ; i++) {
			if (ChoiceNum == i) {//for Instant 
				for (int j = (i - 1); j < (NumSource - 1); j++) {
					SoIn[j].SName = SoIn[j + 1].SName;
					SoIn[j].Date = SoIn[j + 1].Date;
					SoIn[j].month = SoIn[j + 1].month;
					SoIn[j].Value = SoIn[j + 1].Value;
					SoIn[j].tybe = SoIn[j + 1].tybe;

				}//end for j

				IsDeleted = true;
				break;
			}//end if (ChoiceNum == i)

			else
				IsDeleted = false;
		
		}//end for i

		NumSource--;

		if (IsDeleted) {

			cout << "\n-------------------------------------------------------------------------------------------------\n";

			cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item :(...\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer


		}//end if (IsDeleted) 

		else
		{
			cout << "\n-------------------------------------------------------------------------------------------------\n";
			
			cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again ???..\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer

		}//end else

	}//end while

		system("cls");


	cout << "\n-------------------------------------------------------------------------------------------------\n";
	cout << "\n\t\tHere is UR source list :) :)...\n\n";

	ListSource(SoIn, NumSource);

	cout << endl << endl;

}//end delete source function


 //function to delete expenses
 void DeleteExpens(ExpenseInfo ExIn[], int & NumOfExp) {

	 string Answer;

	 while (true) {

		 ListExpense(ExIn, NumOfExp);//function that the user will choose from to delete

		 cout << "\n\nPlease choose the number of the instant expense U want to delete :(... : ";
		 int ChoiceNum;
		 cin >> ChoiceNum;

		 while (cin.fail())
		 {
			 system("cls");
			 cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
			 cout << "\n\nPlease choose the number of the instant expense U want to delete :(... : ";
			 cin >> ChoiceNum;

		 }//end while (cin.fail())

		 system("cls");

		 bool IsDeleted = false;

		 for (int i = 0; i < NumOfExp; i++) {
			 if (ChoiceNum == i) {//for Instant 
				 for (int j = (i - 1); j < (NumOfExp - 1); j++) {
					 ExIn[j].EName = ExIn[j + 1].EName;
					 ExIn[j].Date = ExIn[j + 1].Date;
					 ExIn[j].month = ExIn[j + 1].month;
					 ExIn[j].Value = ExIn[j + 1].Value;

				 }//end for j

				 IsDeleted = true;
				 break;
			 }//end if (i == choicenum)

			 else
				 IsDeleted = false;

		 }//end for i

		 NumOfExp--;

		 if (IsDeleted) {

			 cout << "\n-------------------------------------------------------------------------------------------------\n";

			 cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item :(...\n\n";

			 cin.ignore();

			 getline(cin, Answer);

			 if (Answer == "no" || Answer == "No") {
				 system("cls");
				 break;

			 }//end if answer


		 }//end if (IsDeleted) 

		 else
		 {
			 cout << "\n-------------------------------------------------------------------------------------------------\n";

			 cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again ???..\n\n";

			 cin.ignore();

			 getline(cin, Answer);

			 if (Answer == "no" || Answer == "No") {
				 system("cls");
				 break;

			 }//end if answer

		 }//end else

	 }//end while

	 system("cls");


	 cout << "\n-------------------------------------------------------------------------------------------------\n";
	 cout << "\n\t\tHere is UR instant expense list :) :)...\n\n";

	 ListExpense(ExIn, NumOfExp);

	 cout << endl << endl;

	
 }//end function of delete expense

  //date range function
 double GenerateReport(SourceInfo SoIn[], ExpenseInfo ExIn[], RecurringInfo& Food, RecurringInfo& HomeRent, RecurringInfo & CarFuel, RecurringInfo& ElecBill, RecurringInfo & WaterBill, RecurringInfo &GasBill, RecurringInfo& Wi_Fi, RecurringInfo &MobileBill, int& NumSource, int& NumExpense, int& FoodCounter, int& FuelCounter, int& StartDay, int& StartMonth, int& EndDay, int& EndMonth, double& Current)
 {
	 string TybeOfCosts;

	 while (true) {

		 for (int i = 0; i < NumSource; i++) {//search for sources

			 if (SoIn[i].tybe == 2) {//recurring source

				 if (SoIn[i].Date == StartDay && SoIn[i].month == StartMonth) {

					 Current += SoIn[i].Value;

					 cout << SoIn[i].Date << "/" << SoIn[i].month << "  ";
					 cout << "+" << SoIn[i].Value << " ";
					 cout << SoIn[i].SName << "  [Tybe = Recuirring]  [Current = " << Current << "]";
					 cout << endl;
				 }


			 }//end if (SoIn[i].tybe == 2)

			 if (SoIn[i].tybe == 1) {//instant source

				 if (SoIn[i].Date == StartDay) {

					 Current += SoIn[i].Value;

					 cout << SoIn[i].Date << "/" << StartMonth << "  ";
					 cout << "+" << SoIn[i].Value << " ";
					 cout << SoIn[i].SName << "  [Tybe = Instantinous]  [Current = " << Current << "]";
					 cout << endl;

				 }


			 }//end if (SoIn[i].tybe == 1)
		 }//end search for sources 

		 for (int i = 0; i < NumExpense; i++) {//search for expenses

			 if (ExIn[i].Date == StartDay && ExIn[i].month == StartMonth) {

				 Current -= ExIn[i].Value;

				 cout << ExIn[i].Date << "/" << ExIn[i].month << "  ";
				 cout << "-" << ExIn[i].Value << " ";
				 cout << ExIn[i].EName << "  [Tybe = Instantinous]  [Current = " << Current << "]";
				 cout << endl;
			 }

		 }//end search for expenses 

		  //switch case to search for months with 31 days and 30 days and 28 days
		 switch (StartMonth) {

		 case 1://January
		 case 3://March
		 case 5://May
		 case 7://July
		 case 8://Augest
		 case 10://October
		 case 12://December
			 if (StartDay == 31) {
				 StartDay = 1;
				 StartMonth++;
			 }

			 else
				 StartDay++;

			 break;
			 //end case 1,3,5,7,8,10,12

		 case 2://February
			 if (StartDay == 28) {
				 StartDay = 1;
				 StartMonth++;
			 }
			 else
				 StartDay++;
			 break;
			 //end case 2
		 case 4://April
		 case 6://June
		 case 9://September
		 case 11://November
			 if (StartDay == 30) {
				 StartDay = 1;
				 StartMonth++;
			 }

			 else
				 StartDay++;

			 break;
			 //end case 4,6,9,11
		 }//end switch

		  //if the date range the user entered has been reached soo display a Quik status
		 if (StartMonth == EndMonth && StartDay == EndDay) {

			 if (Current > 0)
				 cout << "Today Is Ur Day :)).. U R SAVIIING MONEY ;)....\n\n";
			 else if (Current < 0)
				 cout << "WATCH OUT :<.. U R In DEBTT :<... \n\n";
			 else
				 cout << "TOO Baaad :(.. U HAVE NO MORE MONEY :(...  \n\n";
			 cout << endl;

			 cout << "-----------------------------------------------------------------------------------------------\n";


			 break;
		 }

	 }//end while (true)


	 return Current;

 }//end date range function 


//to comput the total source, expense, reccuring from a specified date range
void DisQuick(double UserSources, double TotalExpenses, double TotalRecurring)
{

	double status = 0;
	status = UserSources - (TotalExpenses + TotalRecurring);
	cout << "your money left is : " << status << endl;
	if (status > 0)
		cout << "Horray :) you are saving money this month" << endl;
	else if (status < 0)
		cout << "OH NO :( you are depated " << endl;
	else
		cout << "you are not Saving any money " << endl;


}
void DisDetalied(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, RecurringInfo Food, RecurringInfo HomeRent, RecurringInfo CarFuel, RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill)
{
	int i = 0, j = 0, k = 0;
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "your income information :)......." << endl;
	cout << "------------------------------------------------------------------------------------------------\n";

	cout << "Name\tdate\tvalue\n";
	cout << "------------------------------------------------------------------------------------------------\n";

	while (SoIn[i].Value != NULL)

	{
		cout << SoIn[i].SName << "\t" << SoIn[i].Date << "\t" << SoIn[i].Value << endl;
		i++;

	}
	cout << "\n----------------------------------------------------------------------\n";
	cout << "\n----------------------------------------------------------------------\n";

	cout << "                     <<<your instant Expenses information >>>\n";

	for (int i = 0; i < NumExpense; i++)
	{
		cout << "<< Expense Name >> : " << endl;;
		cout << "#num\tdate\tvalue\t\n";
		/*for (int j = 0; j < ExIn[i].DateNum[i]; j++)
		{*/
		cout << i + 1 << "\t" << ExIn[i].EName << "\t" << ExIn[i].Date << "\t" << ExIn[i].month << "\t" << ExIn[i].Value << "  \t";

		cout << endl;

	}




	cout << "\n----------------------------------------------------------------------\n";
	cout << "\n----------------------------------------------------------------------\n";
	cout << "                    <<<Recurring information Details >>>\n";

	cout << "                       << Food detailes >>           \n ";
	cout << "Food no.\tDate\tValue\n";
	for (int i = 0; i < FoodCounter; i++)
	{
		cout << "    " << i + 1 << "     \t" << Food.Date[i] << "     \t" << Food.Value[i] << endl << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                       << Car Fuel detailes >>           \n ";
	cout << "car fuel no.\tDate\tValue\n";
	for (int i = 0; i < FuelCounter; i++)
	{
		cout << "     " << i + 1 << "     \t" << CarFuel.Date[i] << "    \t" << CarFuel.Value[i] << endl << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Electricity Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << ElecBill.Date[0] << "  \t\t" << ElecBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Home Rent Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << HomeRent.Date[0] << " \t \t" << HomeRent.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Water Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << WaterBill.Date[0] << "  \t\t" << WaterBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Gas Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << GasBill.Date[0] << "  \t\t" << GasBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Wi_Fi Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << Wi_Fi.Date[0] << "  \t\t" << Wi_Fi.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";
	cout << "                        << Mobile Bill >>>      \n ";
	cout << "The Date\tValue\n";
	cout << "   " << MobileBill.Date[0] << " \t \t" << MobileBill.Value[0] << endl;
	cout << endl << "------------------------------------------------------------------------------\n";

	cout << "\n----------------------------------------------------------------------\n";
	cout << "\n----------------------------------------------------------------------\n";

	cout << "                 <<<<your current status  >>>>";
	double status = 0;
	status = UserSources - (TotalExpenses + TotalRecurring);
	cout << "your money left is : " << status << endl << endl;

	cout << "\n----------------------------------------------------------------------\n";


	if (status > 0)
		cout << "Horray :) you are saving money this month" << endl;
	else if (status < 0)
		cout << "OH NO :( you are depated " << endl;
	else
		cout << "you are not Saving any money " << endl;




}// end detailed status

void ListSource(SourceInfo SoIn[], int NumSource)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\t\tYour recurrent Sources is :: \n";

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "#Num\t Name\t Day\t Value \n";
	cout << "------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < NumSource; i++)
	{
		if (SoIn[i].tybe == 2)
			cout << i + 1 << "\t " << SoIn[i].SName << "\t " << SoIn[i].Date << "\t " << SoIn[i].Value << "$" << endl;

	}

	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "\t\tAnd your instant incomes is :: \n";
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "#Num\t Name\t Day\t Month\t Value \n";
	cout << "-----------------------------------------------------------------------------" << endl;

	for (int i = 0; i < NumSource; i++)
	{
		if (SoIn[i].tybe == 1)
			cout << i + 1 << "\t " << SoIn[i].SName << "\t " << SoIn[i].Date << "\t " << SoIn[i].month << "\t " << SoIn[i].Value << "$" << endl;

	}

	cout << "-------------------------------------------------------------------------------" << endl;


}//end list Source

void ListExpense(ExpenseInfo ExIn[], int NumOfExp)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "------------------------------------------------------------------------------" << endl;

	cout << " #Num\t Name\t Day\t Month\t Value\n";
	
	cout << "------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < NumOfExp; i++)
	{
		cout << i + 1 << "\t " << ExIn[i].EName << "\t " << ExIn[i].Date << "\t " << ExIn[i].month << "\t "<< ExIn[i].Value << "$" << "\n";

	}
	cout << "------------------------------------------------------------------------------" << endl;

}

void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, RecurringInfo Food, RecurringInfo HomeRent, RecurringInfo CarFuel, RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill)
{
	ofstream infile;

	infile.setf(ios::fixed);
	infile.setf(ios::showpoint);
	infile.precision(2);


	infile.open("your budget info.txt");

	infile << "                           Your recurrent Sources is :: \n";
	infile << "--------------------------------------------------------------------------------------------------" << endl;
	infile << "#Num\t Name\t Day\t Value \n";
	infile << "--------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < NumSource; i++)
	{
		if (SoIn[i].tybe == 2)
			infile << i + 1 << "\t " << SoIn[i].SName << "\t " << SoIn[i].Date << "\t " << SoIn[i].Value << "$" << endl;

	}

	infile << "--------------------------------------------------------------------------------------------------" << endl;
	infile << "                         And your instant incomes is :: \n";
	infile << "--------------------------------------------------------------------------------------------------" << endl;
	infile << "#Num\t Name\t Day\t Month\t Value \n";
	infile << "--------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < NumSource; i++)
	{
		if (SoIn[i].tybe == 1)
			infile << i + 1 << "\t " << SoIn[i].SName << "\t " << SoIn[i].Date << "\t " << SoIn[i].Value << "$" << endl;

	}

	infile << "--------------------------------------------------------------------------------------------------" << endl;
	infile << "\t\t instant expenses informartion :: \n";
	cout << " #Num\t Name\t Day\t Month\t Value\n";

	for (int i = 0; i < NumExpense; i++)
	{
		cout << " Expense Name : " << endl;
		/*for (int j = 0; j < ExIn[i].DateNum[i]; j++)
		{*/
		infile << i + 1 << "\t" << ExIn[i].EName << "\t" << ExIn[i].Date << "\t" << ExIn[i].month << "\t" << ExIn[i].Value << "$" << "\t";

		infile << endl;
	}


	infile.close();
}

//function to read the saved data from the text file 
void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, RecurringInfo Food, RecurringInfo HomeRent, RecurringInfo CarFuel, RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill)
{
	ifstream InFile;

	string SavedData; // the data will save in

	
	InFile.open("your budget info.txt", ios::binary);

	if (InFile.is_open()) { //if the file is openend it return true else return false

		while (!InFile.eof()) {

			getline(InFile,SavedData);//get the data line by line saved in the string saved data
			cout << SavedData << endl;//to print the saved data line by line

		}
		InFile.close();
	}
	
	else {
	
		cout << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

		exit(1);//the program faild
	
	
	}
}//end read data function

