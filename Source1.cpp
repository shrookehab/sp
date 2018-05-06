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
	int month;
	int tybe;
	int Date = NULL;
	double Value = NULL;
};
struct ExpenseInfo
{
	string EName;
	int Date = NULL;
	double Value = NULL;
	int month;
};
struct RecurringInfo
{
	string RName;
	int Date = NULL;
	double Value = NULL;
};

void MainMenu();
double AddSource(SourceInfo Soln[], int);
double AddExpense(ExpenseInfo ExIn[], int);
double AddRecurring(int&, int&, int&, RecurringInfo food[], RecurringInfo&, RecurringInfo carfuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo others[]);

void ListRecurring(int&, int&, int&, RecurringInfo food[], RecurringInfo&, RecurringInfo carfuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo others[]);
void ListSource(SourceInfo SoIn[], int);
void ListExpense(ExpenseInfo ExIn[], int);

void EditSource(SourceInfo Soln[], int);
void EditExpense(ExpenseInfo ExIn[], int);
void EditRec(int&, int&, int&, RecurringInfo food[], RecurringInfo &, RecurringInfo carfuel[], RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo&, RecurringInfo othrs[]);

void DeleteSource(SourceInfo SoIn[], int&);
void DeleteExpens(ExpenseInfo ExIn[], int&);
void DeleteRec(int&, int&, int&, RecurringInfo food[], RecurringInfo &, RecurringInfo carfuel[], RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo&, RecurringInfo othrs[]);

void DisDetalied(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, int, RecurringInfo food[], RecurringInfo, RecurringInfo carfuel[], RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo others[]);

void DisQuick(double, double, double);
double GenerateReport(SourceInfo Soln[], ExpenseInfo ExIn[], RecurringInfo Food[], RecurringInfo&, RecurringInfo CarFuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo Others[], int&, int&, int&, int&, int&, int&, int&, int&, int&, double&);


void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, int, RecurringInfo food[], RecurringInfo, RecurringInfo carfuel[], RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo others[]);
//void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, RecurringInfo food[], RecurringInfo, RecurringInfo carfuel[], RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo);

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



	SourceInfo SoIn[num];
	ExpenseInfo  ExIn[num];
	//RecurringInfo RrIn[num];
	int NumSource = 0, SourcesEachTime;
	int NumExpense = 0, ExpenseEachTime;
	double UserSources = 0;
	double TotalExpenses = 0;
	double TotalRecurring = 0;
	RecurringInfo Food[num], HomeRent, CarFuel[num], ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others[num];
	int FoodCounter = 0, FuelCounter = 0, OtherCounter = 0;



	system("pause");
	return 0;




}


//function to save data in files
void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, int OtherCounter, RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill, RecurringInfo Others[])
{
	ofstream OutSource, OutExp, OutRecc;


	//saving the recurrent & instantinous sources in file
	OutSource.open("Source Info .txt");

	OutSource << "Sources\n";
	OutSource << '2' << "\n";

	for (int i = 0; i < NumSource; i++)
	{
		if (SoIn[i].tybe == 1)
			OutSource << i + 1 << "\n" << SoIn[i].tybe << "\n"<< SoIn[i].SName << "\n" << SoIn[i].Date << "\n" << SoIn[i].month << "\n" << SoIn[i].Value << endl;

		else if (SoIn[i].tybe == 2)
			OutSource << i + 1 << "\n" << SoIn[i].tybe << "\n" << SoIn[i].SName << "\n" << SoIn[i].Date << "\n" << SoIn[i].Value << endl;

	}

	OutSource.close();


	//saving the instantinous expense in another file
	OutExp.open("Instant Expense Info.txt");
	
	OutExp << "InstantExpenses\n";
	OutExp << '1' << "\n";

	for (int i = 0; i < NumExpense; i++)
	{

		OutExp << i + 1 << "\n" << ExIn[i].EName << "\n" << ExIn[i].Date << "\n" << ExIn[i].month << "\n" << ExIn[i].Value << "\n";


	}
	OutExp.close();




	//saving the recurring expenses in another file
	OutRecc.open("Reccurring Expenses Info.txt");
	
	OutRecc << "RecrringExpenses\n";
	OutRecc << '9' << "\n";
	
	for (int i = 0; i < FoodCounter; i++)
	{
		OutRecc << i + 1 << "\n" << Food[i].Date << "\n" << Food[i].Value << endl;
	}
	
	
	for (int i = 0; i < FuelCounter; i++)
	{
		OutRecc << i + 1 << "\n" << CarFuel[i].Date << "\n" << CarFuel[i].Value << endl;
	}

	OutRecc << ElecBill.Date << "\n" << ElecBill.Value << endl;


	OutRecc << HomeRent.Date << "\n" << HomeRent.Value << endl;


	OutRecc << WaterBill.Date << "\n" << WaterBill.Value << endl;

	OutRecc << GasBill.Date << "\n" << GasBill.Value << endl;

	OutRecc << Wi_Fi.Date << "\n"  << Wi_Fi.Value << endl;

	OutRecc << MobileBill.Date << "\n"  << MobileBill.Value << endl;

	for (int i = 0; i < OtherCounter; i++)
	{
		OutRecc <<  i + 1 << "\n" << Others[i].RName << "\n"  << Others[i].Date << "\n" << Others[i].Value << endl;
	}


	OutRecc.close();


}//end save data in files



void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter,int OtherCounter, RecurringInfo Others[], RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill)
{
	ifstream InSource, InExpense, InRecurring;

	string SourceData, ExpenseData, RecData; // the data will save in
	
											 
   //read the saved data of Recurring & instantinous sources from te saved file

	string Title_1;
	int count_1;


	InSource.open("Source Info .txt", ios::binary);

	InSource >> Title_1;
	InSource >> count_1;

	if (InSource.is_open()) { //if the file is openend it return true else return false

		while (!InSource.eof()) {

			getline(InSource, SourceData);//get the data line by line saved in the string saved data

			for (int i = 0; i < NumSource; i++)
			{
				if (SoIn[i].tybe == 1) {
					InSource >> i + 1;
					InSource >> SoIn[i].tybe;
					InSource >> SoIn[i].SName;
					InSource >> SoIn[i].Date;
					InSource >> SoIn[i].month;
					InSource >> SoIn[i].Value;
				} //end else if

				else if (SoIn[i].tybe == 2) {
					InSource >> i + 1;
					InSource >> SoIn[i].tybe;
					InSource >> SoIn[i].SName;
					InSource >> SoIn[i].Date;
					InSource >> SoIn[i].Value ;


				}//end else if

			}//end for

		}//end while

		InSource.close();
	}//end if file is opened

	else {

		cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

		exit(1);//the program faild


	}


	//read the saved data of instantinous expenses from te saved file

	string Title_2;
	int count_2;


	InExpense.open("Instant Expense Info .txt", ios::binary);

	InExpense >> Title_2;
	InExpense >> count_2;

	if (InExpense.is_open()) { //if the file is openend it return true else return false

		while (!InExpense.eof()) {

			getline(InExpense, ExpenseData);//get the data line by line saved in the string saved data

			for (int i = 0; i < NumExpense; i++)
			{

				InExpense >> i + 1;
				InExpense >> ExIn[i].EName;
				InExpense >> ExIn[i].Date;
				InExpense >> ExIn[i].month;
				InExpense >> ExIn[i].Value;


			}//end for

			}//end while
	
		InExpense.close();

		}//end if file is opened

	else {

		cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

		exit(1);//the program faild


	}


	//read the saved data of Recurring expenses from te saved file

	string Title_3;
	int count_3;


	InRecurring.open("Reccurring Expenses Info .txt", ios::binary);

	InRecurring >> Title_3;
	InRecurring >> count_3;

	if (InRecurring.is_open()) { //if the file is openend it return true else return false

		while (!InRecurring.eof()) {

			getline(InRecurring, RecData);//get the data line by line saved in the string saved data

			for (int i = 0; i < FoodCounter; i++)
			{
				InRecurring >> i + 1;
				InRecurring >> Food[i].Date;
				InRecurring >> Food[i].Value;
			}


			for (int i = 0; i < FuelCounter; i++)
			{
				InRecurring >> i + 1;
				InRecurring >> CarFuel[i].Date; 
				InRecurring >> CarFuel[i].Value;
			}

			InRecurring >> ElecBill.Date;
			InRecurring >> ElecBill.Value ;


			InRecurring >> HomeRent.Date;
			InRecurring >> HomeRent.Value;


			InRecurring >> WaterBill.Date;
			InRecurring >> WaterBill.Value;

			InRecurring >> GasBill.Date;
			InRecurring >> GasBill.Value ;

			InRecurring >> Wi_Fi.Date;
			InRecurring >> Wi_Fi.Value;

			InRecurring >> MobileBill.Date;
			InRecurring >> MobileBill.Value;

			for (int i = 0; i < OtherCounter; i++)
			{
				InRecurring >> i + 1;
				InRecurring >> Others[i].RName;
				InRecurring >> Others[i].Date;
				InRecurring >> Others[i].Value;
			}

		}//end while

		InRecurring.close();

	}//end if file is opened

	else {

		cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

		exit(1);//the program faild


	}






}//end read data function
