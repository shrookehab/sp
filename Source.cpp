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
void AddSource(SourceInfo Soln[], int);
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

			int NumSource;
			cout << "Hello user :) How many sources you want to add : ";

			cin >> NumSource;

			AddSource(SoIn, NumSource);
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
void AddSource(SourceInfo SoIn[], int NumSource)
{

	double UserSources = 0;


	for (int i = 0; i < NumSource; i++)
	{
		cout << "please enter source  " << i + 1 << "  name : ";
		cin.ignore();

		getline(cin, SoIn[i].SName);


		cout << "please enter source  " << i + 1 << "  date : ";
		cin >> SoIn[i].Date;

		cout << "please enter source  " << i + 1 << "  value : ";
		cin >> SoIn[i].Value;

		UserSources += SoIn[i].Value;
		cin.ignore();

	} //end for(numsource)

	cout << "your total value of income during this month is : " << UserSources << endl;
}//end addsource function

//function to add expense of the user 
void AddExpense(ExpenseInfo ExIn[], int NumExpense)
{

	for (int i = 0; i < NumExpense; i++)
	{
		
		cout << "enter expense  " << i + 1 << "  name : ";
		cin.ignore();

		getline(cin, ExIn[i].EName);

		int DateNum;
		cout << "how many dates for your expense : ";
		cin >> DateNum;


		for (int j = 0; j < DateNum; j++)
		{

			cout << "enter expense  " << i + 1 << " date " << j + 1 << ":";
			cin >> ExIn[i].Date[j];

			cout << "enter expense  " << i + 1 << "  value" << j + 1 << " :";
			cin >> ExIn[i].Value[j];

		}//end for(datenum)


	}//end for (numexpense)


}//end function of expense

 // function to AddRecurring of the user
void AddRecurring(RecurringInfo RrIn[])
{
	RecurringInfo Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill;
	int i = 0, n;
	char ans = 'y';

	string answer;
	//cout << "_1_Food\n_2_Car Fuel\n_3_Electricity Bill\n_4_Water Bill\n_5_Gas Bill\n_6_Wi_Fi <3 \n_7_Mobile Bill\n_8_Home Rent \n";
	//cin >> n;

	while (ans == 'y')
	{
		cout << "_1_Food\n_2_Car Fuel\n_3_Electricity Bill\n_4_Water Bill\n_5_Gas Bill\n_6_Wi_Fi <3 \n_7_Mobile Bill\n_8_Home Rent \n";
		cin >> n;
		switch (n)
		{
		case 1:
			do
			{
				cout << "<<< Food >>>> \n ";
				cout << "The Date: ";
				cin >> Food.Date[i];
				cout << "value : ";
				cin >> Food.Value[i];
				cout << "Do you want to add more food costs ? \"yes\" OR \"no\" \n ";
				cin >> answer;

			} while (answer == "yes" || answer == "Yes");
			break;
		case 2:
			do
			{
				cout << "<<< Car Fuel >>>  \n";
				cout << "The Date: ";
				cin >> CarFuel.Date[i];
				cout << "value : ";
				cin >> CarFuel.Value[i];
				cout << "Do you want to add more Car Fuel costs ? \"yes\" OR \"no\" \n";
				cin >> answer;

				i++;


			} while (answer == "yes" || answer == "Yes");
			break;
		case 3:
			cout << "<<< Electricity Bill >>> ";
			cout << "The Date: ";
			cin >> ElecBill.Date[0];
			cout << " value : ";
			cin >> ElecBill.Value[0];
			break;
		case 4:
			cout << "<<< Water Bill >>>  ";
			cout << "The Date: ";
			cin >> WaterBill.Date[0];
			cout << " value : ";
			cin >> WaterBill.Value[0];
			break;
		case 5:
			cout << "<<< Gas Bill >>>  ";
			cout << "The Date: ";
			cin >> GasBill.Date[0];
			cout << " value : ";
			cin >> GasBill.Value[0];
			break;
		case 6:
			cout << "<<< Wi_Fi Bill >>>  ";
			cout << "The Date: ";
			cin >> Wi_Fi.Date[0];
			cout << "value : ";
			cin >> Wi_Fi.Value[0];
			break;
		case 7:
			cout << "<<< Mobile Phone Bill >>>  ";
			cout << "The Date: ";
			cin >> MobileBill.Date[0];
			cout << "value : ";
			cin >> MobileBill.Value[0];
			break;
		case 8:
			cout << "<<< Home Rent >>>  ";
			cout << "The Date: ";
			cin >> HomeRent.Date[0];
			cout << "value : ";
			cin >> HomeRent.Value[0];
			break;
		}
		cout << "Do you want to add more recuerring ? ";
		cin >> ans;
	}
}// End AddRecurring function

//functiosn to edit name/date/value in the source of the user
void EditSource(SourceInfo Soln[], int NumSource)
{
	string Answer;
	cout << "Hello User :)...";
	while (true) {

		bool Correct = false;
		string Name, NewName;
		int UserAns, OldVal, NewVal;
		int OldDate, NewDate;
		cout << "Please choose what do u want to edit in your incomes \n _1_income name \n _2_income date \n _3_income value \n THE ANSWER IS :  ";
		cin >> UserAns;
		if (UserAns == 3)
		{
			system("cls");

			cout << "enter the income name :";
			cin.ignore();

			getline(cin, Name);
			cout << "enter old value of ur income :";
			cin >> OldVal;
			cout << "enter new value of ur income  :";
			cin >> NewVal;

			for (int i = 0; i <= NumSource; i++)
			{
				if (Soln[i].Value == OldVal && Soln[i].SName == Name)
				{
					Soln[i].Value = NewVal;
					Correct = true;

					cout << "  the new value is  :   " << Soln[i].Value;
					cout << "---------------------------------------------------------------------------------------------------" << endl;
				}//end if (oldval)

			}//end for(numsources)
			if (!Correct)
				cout << "the name of income doesnt match it's value !!!!!" << endl;

		}//end if (userans==3)

		if (UserAns == 1)
		{
			system("cls");

			cout << "enter the income old name :";
			cin.ignore();
			getline(cin, Name);


			for (int i = 0; i < NumSource; i++)
			{
				if (Soln[i].SName == Name)
				{

					cout << "enter income new name  :";
					Soln[i].SName.erase(0, Soln[i].SName.size());

					Soln[i].SName.insert(0, NewName);

					/*cin.ignore();
					getline(cin, Soln[i].SName);
					*/

					cout << "the new income name is : " << Soln[i].SName << endl;
				}//end if (Soln[i].SName == name)



			}//end for(numsource);

		}// end if (userans ==1)
		if (UserAns == 2)
		{
			system("cls");


			cout << "enter the income name :";
			cin.ignore();

			getline(cin, Name);

			cout << "enter the old date : ";
			cin >> OldDate;
			cout << "enter the new date : ";
			cin >> NewDate;

			for (int i = 0; i <= NumSource; i++)
			{
				if (Soln[i].Date == OldDate && Soln[i].SName == Name)
				{
					Soln[i].Date = NewDate;
					cout << " the new date is : " << Soln[i].Date << endl;
					Correct = true;
				}//end if (olddate)

			}//end for (numsource)

			if (!Correct)
				cout << "invalid date or date doesn't match the income name !!!!" << endl;


		}//end if (userAns == 2)

		cout << " DO U want to EDIT any incomes ??? :: ";
		cin.ignore();
		getline(cin, Answer);

		system("cls");

		if (Answer == "No" || Answer == "no")
			break;


	}//end while
	cout << "------------------------------------------------------------------------------------------------\n";
}//end function of edit source 

//function to edit expense of the user
void EditExpense(ExpenseInfo ExIn[], int NumOfExp) {
	string Answer;
	cout << "Hello User :)...";
	while (true) {

		bool Correct = false;
		string Name, NewName;
		int UserAns, OldVal, NewVal;
		int OldDate, NewDate;
		cout << "Please choose what do u want to edit in your expense \n _1_expense name \n _2_expense date \n _3_expense value \n THE ANSWER IS :  ";
		cin >> UserAns;
		switch (UserAns) {

		case 1:

			system("cls");

			cout << "enter the expense old name :";
			cin.ignore();
			getline(cin, Name);


			for (int i = 0; i < NumOfExp; i++)
			{
				if (ExIn[i].EName == Name)
				{

					cout << "enter expense new name  :";
					ExIn[i].EName.erase(0, ExIn[i].EName.size());

					ExIn[i].EName.insert(0, NewName);

					/*cin.ignore();
					getline(cin, Soln[i].SName);
					*/

					cout << "the new expense name is : " << ExIn[i].EName << endl;
				}//end if (Soln[i].SName == name)



			}//end for(numsource);
			
			break;
			//end case 1

		case 2:

			system("cls");

			cout << "enter the expense name :";
			cin.ignore();

			getline(cin, Name);

			for (int i = 0; i <= NumOfExp; i++)
			{
				int DateNum;
				cout << "how many dates for your expense : ";
				cin >> DateNum;

				for (int j = 0; j < DateNum; j++) {

					cout << "enter the old date of ur expense : ";
					cin >> OldDate;
					cout << "enter the new date of ur expense : ";
					cin >> NewDate;

					if (ExIn[i].Date[j] == OldDate && ExIn[i].EName == Name)
					{
						ExIn[i].Date[j] = NewDate;
						cout << " the new date is : " << ExIn[i].Date[j] << endl;
						Correct = true;
					}//end if (olddate)

				}//end for (datenum)
			}//end for (numsource)

			if (!Correct)
				cout << "invalid date or date doesn't match the expense name !!!!" << endl;
			
			break;
			//end case 2

		case 3:

			system("cls");

			cout << "enter the expense name :";
			cin.ignore();
			getline(cin, Name);
			
			
			for (int i = 0; i <= NumOfExp; i++)
			{
				int ValueNum;
				cout << "How many values for your expense : ";
				cin >> ValueNum;

				for (int j = 0; j < ValueNum; j++) {

					cout << "enter old value of ur expense :";
					cin >> OldVal;
					cout << "enter new value of ur expense  :";
					cin >> NewVal;

					if (ExIn[i].Value[j] == OldVal && ExIn[i].EName == Name)
					{
						ExIn[i].Value[j] = NewVal;
						Correct = true;

						cout << "  the new value is  :   " << ExIn[i].Value[j];
						cout << "---------------------------------------------------------------------------------------------------" << endl;
					}//end if (oldval)

				}//end for (valuenum)
			}//end for(numsources)
			if (!Correct)
				cout << "the name of expense doesnt match it's value !!!!!" << endl;


			break;
			//end case 3

		}//end switch (UserAns)
		
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
void DeleteSource(SourceInfo SoIn[], int NumOfSou) {

	string answer;

	while (true){

	bool Correct = false;
	int counter = 0;
	//cout << "\n How many INCOMES U want to delete :(... :  ";
	//cin >> Number;
	
	/*for (int i = 0; i < Number; i++) {
*/
		string SouName;

		cout << "Please enter the name of the income U want to DELETE :(.. \n";
		cin.ignore();
		getline(cin, SouName);

		for (int i = 0; i < NumOfSou; i++) {

			if (SouName == SoIn[i].SName) {
				counter = i;
				Correct = true;
			}

			else
				Correct = false;

		}//end for NumOfSou 1

		if (!Correct)
			cout << " INVALID NAME !!!!!!!\n";


		for (int i = counter; i < NumOfSou; i++) {
			SoIn[i].SName = SoIn[i + 1].SName;
			SoIn[i].Date = SoIn[i + 1].Date;
			SoIn[i].Value = SoIn[i + 1].Value;

		}//end for NumOfSou 2

		NumOfSou--;

		cout << "\n DO U want to delete another income :  ";
		getline(cin, answer);

		if (answer == "NO" || answer == "no")
			break;

		system("cls");

	}/*end while*/

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "------------------------------------------------------------------------------------------------\n";

	cout << " Income Name\tIncome Date\tIncome Value\n";
	for (int i = 0; i < NumOfSou; i++) {
		cout << SoIn[i].SName << "\t    " << SoIn[i].Date << "\t   " << SoIn[i].Value << "$\n";
	}

	cout << "------------------------------------------------------------------------------------------------\n";

}//end of delete source function

//function to delete expenses
void DeleteExpens(ExpenseInfo ExIn[], int NumOfExp) {

	string answer;
	int NumOfDates;

	while (true) {

		bool Correct = false;
		int counter = 0;

		int UserAnswer;
		cout << "HEllo user :).. PLease choose whate do U want to delete in UR EXPENSES \n _1_ALL information for one expense \n _2_Expense date and value \n\n   THE ANSWER IS :  ";
		cin >> UserAnswer;

		string ExpName;
		

		switch (UserAnswer) {

		case 1:
			system("cls");
	
			cout << "PLease enter the name of the expense U want to delete :  ";
			getline(cin, ExpName);
			
			for (int i = 0; i < NumOfExp; i++) {
				
				if (ExpName == ExIn[i].EName) {
					Correct = true;
					
					cout << "Please enter how many dates u have in that expense :  ";
					cin >> NumOfDates;

					for (int j = 0; j < NumOfDates; j++) {
						ExIn[i].Date[j] = ExIn[i].Date[j + 1];
						ExIn[i].Value[j] = ExIn[i].Value[j + 1];

					}//end for (numofdates)
			
					ExIn[i].EName = ExIn[i + 1].EName;
					NumOfExp--;
					NumOfDates = 0;
				}//end if (expname)

				else
					Correct = false;

			}//end for (numofexp)

			if (!Correct)
				cout << " INVALID NAME !!!!!!!\n";

			break;
			//end case 1
		
		case 2:

			int DateNum;
			cout << "Please enter the name u want to delete its date :  ";
			getline(cin, ExpName);
			cout << "Please enter the date u want to delete :  ";
			cin >> DateNum;

			for (int i = 0; i < NumOfExp; i++) {
				
				if (ExpName == ExIn[i].EName) {
					Correct = true;
					counter = i;

				}//end if

				else
					Correct = false;


			}//end for ( numofexp)

			cout << "Please enter how many dates u have in that expense :  ";
			cin >> NumOfDates;
			for (int i = counter; i < NumOfExp; i++) {

				for (int j = 0; j < NumOfDates; j++) {

					ExIn[i].Date[j] = ExIn[i].Date[j + 1];
					ExIn[i].Value[j] = ExIn[i].Value[j + 1];

				}//end for (numofdates) 2
				
				NumOfDates--;

			}//end for (numofexp) 2



			if (!Correct)
				cout << " INVALID NAME !!!!!!!\n";


			break;
			//end case 2

		}//end switch

		cout << "\n DO U want to delete another income :  ";
		getline(cin, answer);

		if (answer == "NO" || answer == "no")
			break;

		system("cls");

	}//end while

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "------------------------------------------------------------------------------------------------\n";

	cout << " Expense Name\tExpense Date\tExpense Value\n";
	for (int i = 0; i < NumOfExp; i++) {
		cout << ExIn[i].EName << "\n\t\t    ";
		for (int j = 0; j < NumOfDates; j++) {
			cout << ExIn[i].Date[j] << "\t   " << ExIn[i].Value[j] << "$\n";
		}
	}

	cout << "------------------------------------------------------------------------------------------------\n";


}//end function of delete expense



//to comput the total source, expense, reccuring from a specified date range
void DateRange(int FirstDate, int LastDate) {
	/*int FirstDate, LastDate;*/

	SourceInfo SoIn[num];
	ExpenseInfo  ExIn[num];
	RecurringInfo RrIn[num];

	double TotalValue = 0, TotalSource = 0, TotalExpense = 0, TotalRecurring = 0;

	int TotalDate = (31 - FirstDate) + LastDate;
	while (FirstDate != LastDate) // loop to search for date range
	{


		for (int i = 0; i < SurSize; i++) // searching for date in source
		{
			if (FirstDate == SoIn[i].Date) {

				TotalSource += SoIn[i].Value;
				cout << "The NAME of the source number " << i + 1 << " is : " << SoIn[i].SName;
				cout << "The DATE of the source number " << i + 1 << " is : " << SoIn[i].Date;
				cout << "The VALUE of the source number " << i + 1 << " is : " << SoIn[i].Value;

			}//end if 
		}//end for (source)
		for (int i = 0; i < ExSize; i++) {
			for (int j = 0; j < TotalDate; j++) {
				if (FirstDate == ExIn[i].Date[j]) {

					TotalExpense += ExIn[i].Value[j];
					cout << "The NAME of the expense number " << i + 1 << " is : " << ExIn[i].EName;
					cout << "The DATE of the expense number " << i + 1 << " is : " << ExIn[i].Date;
					cout << "The VALUE of the expense number " << i + 1 << " is : " << ExIn[i].Value;

				}//end if 1

				if (FirstDate == RrIn[i].Date[j]) {

					TotalRecurring += RrIn[i].Value[j];
					cout << "The DATE of the recurring number " << i + 1 << " is : " << RrIn[i].Date;
					cout << "The VALUE of the recurring number " << i + 1 << " is : " << RrIn[i].Value;

				}//end if 2
			}//end for (j)
		}//end for (i)

		FirstDate++;
		if (FirstDate == 31) {

			FirstDate -= 30;

		}//end if (dirstdate == 31)

	}//end while;
}//end function of daterange