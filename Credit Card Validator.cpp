#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;
void CreditCard(const string& ccNumber);
bool CheckccNumber(const string& ccNumber);
int Sum(string ccNumber);
string gnAmericanExpress(string NewccNumbers[]);
string gnVisa(string NewccNumbers[]);
string gnMastercard(string NewccNumbers[]);
string gnDiscover(string NewccNumbers[]);
string gnUnionPay(string NewccNumbers[]);
string changetostring(int gncc[]);
string generator(int size, int fnum, int vu, string NewccNumbers[]);

int main ()
{
	int crr[20], j = 0;
	string NewccNumber[100], ccNumber, ccname[5] = {"American Express Card","Visa Card","Master Card","Disacover Card","Union Pay Card"};
	char ans;
	srand( time(NULL) );
	while (true)
	{
		cout << "\t\t\t~ Credit Card <Generator / Validator> ~\n" << endl << endl;
		cout << " Select the options from below:" << endl;
		if(j>0)
		{
			cout << "\t 1. Validate a Credit Card.\n\t 2. Generate a Credit Card. \n\t 3. View Previously Generated Credit Card(s)." <<endl;
		}
		else
		{
			cout << "\t 1. Validate a Credit Card.\n\t 2. Generate a Credit Card." <<endl;
		}
		int opt;
		cout << " Enter your option : ";
		cin >> opt;
		if (opt == 1)
		{
			cout << "\n Please enter a Credit Card Number: ";
			cin >> ccNumber;
			if (!CheckccNumber(ccNumber))
			{
				cout << "\n The input value is not correct!" << endl;
				cout << "\n <Press any key>";
				getch();
				system("CLS");
				continue;
			}
			int s;
			s = Sum(ccNumber);
			if (s % 10 == 0)
			{
				cout << "\n Your Credit Card number is Valid!" << endl;
				CreditCard(ccNumber);
			}
			else
			{
				cout << "\n Your Credit Card number is not Valid!" << endl;
			}
			char ans;
			cout << "\n Do you want to continue? (Y / N) ";
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
			{
				system("CLS");
				continue;
			}
			else
			{
				cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
				break;
			}
		}
		else if (opt == 2)
		{
			cout << " Select a Cedit Card company:" << endl;
			cout << "\t 1. American Express.\n\t 2. Visa.\n\t 3. Mastercard.\n\t 4. Discover.\n\t 5. UnionPay." << endl;
			int ccopt;
			cout << " Enter your option (1-5): ";
			cin >> ccopt;
			if (ccopt == 1)
			{
				crr[j] = 0;
				NewccNumber[j] = gnAmericanExpress(NewccNumber);
				j++;
				cout << "\n Do you want to continue? (Y / N) ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					system("CLS");
					continue;
				}
				else
				{
					cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
					break;
				}
			}
			else if (ccopt == 2)
			{
				crr[j] = 1;
				NewccNumber[j] = gnVisa(NewccNumber);
				j++;
				cout << "\n Do you want to continue? (Y / N) ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					system("CLS");
					continue;
				}
				else
				{
					cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
					break;
				}
			}
			else if (ccopt == 3)
			{
				crr[j] = 2;
				NewccNumber[j] = gnMastercard(NewccNumber);
				j++;
				cout << "\n Do you want to continue? (Y / N) ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					system("CLS");
					continue;
				}
				else
				{
					cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
					break;
				}
			}
			else if (ccopt == 4)
			{
				crr[j] = 3;
				NewccNumber[j] = gnDiscover(NewccNumber);
				j++;
				cout << "\n Do you want to continue? (Y / N) ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					system("CLS");
					continue;
				}
				else
				{
					cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
					break;
				}
			}
			else if (ccopt == 5)
			{
				crr[j] = 4;
				NewccNumber[j] = gnUnionPay(NewccNumber);
				j++;
				cout << "\n Do you want to continue? (Y / N) ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					system("CLS");
					continue;
				}
				else
				{
					cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
					break;
				}
			}
		}
		else if( opt == 3)
		{
			int f = 1;
			cout<<"\n Previously Generated Credit Cards: ";
			for(int z=0 ; z<j ; z++)
			{
				cout << "\n " << f << ". " << ccname[crr[z]] << "     " << NewccNumber[z];
				f++;
			}
			cout << "\n\n Do you want to continue? (Y / N) ";
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
			{
				system("CLS");
				continue;
			}
			else
			{
				cout << "\n Thank you for using our Program! Have a nice Day!" << endl;
				break;
			}
		}
		else
		{
			cout << "\n Your option is invalid!";
			return 0;
		}
	}
	return 0;
}
bool CheckccNumber(const string& ccNumber)
{
	int len, i;
	len = ccNumber.length();
	if ((len < 13) || (len > 19))
	{
		return false;
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			if (ccNumber[i] < '0' || ccNumber[i] > '9')
			{
				return false;
			}
		}
		return true;
	}
}
int Sum(string ccNumber)
{
	int len;
	len = ccNumber.length();
	int i, dbl, s = 0;
	for ( i = len - 2; i >= 0; i = i - 2)
	{
		dbl = ((ccNumber[i] - 48) * 2);
		if (dbl > 9)
		{
			dbl = (dbl / 10) + (dbl % 10);
		}
		s += dbl;
	}
	for (int i = len - 1; i >= 0; i = i - 2)
	{
		s += (ccNumber[i] - 48);
	}
	return s;
}
void CreditCard(const string& ccNumber)
{
	int len = ccNumber.length();
	if(ccNumber[0] == '3')
	{
		if (ccNumber[1] == '4' || ccNumber[1] == '7')
		{
			cout<<" Your Credit Card is of American Express" << endl;
		}
	}
	else if(ccNumber[0] == '4')
	{
		cout<<" Your Credit Card is of Visa" << endl;
	}
	else if(ccNumber[0] == '5')
	{
		cout<<" Your Credit Card is of Mastercard" << endl;
	}
	else if(ccNumber[0] == '6')
	{
		if(ccNumber[1] == '2')
		{
			cout<<" Your Credit Card is of UnionPay" << endl;
		}
		else
		{
			cout<<" Your Credit Card is of Discover" << endl;
		}
	}
}
string gnAmericanExpress(string NewccNumbers[])
{
	int S = 15, fccn = 3, vu = 1;
	string newcc;
	newcc = generator(S, fccn, vu, NewccNumbers);
	cout << " Your new Credit Card number is " << newcc << endl;
	return newcc;

}
string gnVisa(string NewccNumbers[])
{
	int S = 15, fccn = 4, vu = 0;
	string newcc;
	newcc = generator(S, fccn, vu, NewccNumbers);
	cout << " Your new Credit Card number is " << newcc << endl;
	return newcc;
}
string gnMastercard(string NewccNumbers[])
{
	int S = 16, fccn = 5, vu = 0;
	string newcc;
	newcc = generator(S , fccn , vu, NewccNumbers);
	cout << " Your new Credit Card number is " << newcc << endl;
	return newcc;
}
string gnDiscover(string NewccNumbers[])
{
	int S = 16, fccn = 6, vu = 0;
	string newcc;
	newcc = generator(S, fccn, vu, NewccNumbers);
	cout << " Your new Credit Card number is " << newcc << endl;
	return newcc;
}
string gnUnionPay(string NewccNumbers[])
{
	int S = 16, fccn = 6, vu = 2;
	string newcc;
	newcc = generator(S, fccn, vu, NewccNumbers);
	cout << " Your new Credit Card number is " << newcc << endl;
	return newcc;
}
string changetostring(int gncc[])
{
	int i;
	ostringstream os;
	for (i = 0; i < 15; i++)
	{
		os << gncc[i];
	}
	return os.str();
}
string generator(int size, int fnum, int vu, string NewccNumbers[])
{
	int gncc[size];
	int i = 1;
	gncc[0] = fnum;
	if (vu == 1)
	{
		int a, b;
		a = rand() % 7;
		if (a <= 4)
		{
			b = 4 - a;
			gncc[1] = a + b;
		}
		else
		{
			b = 7 - a;
			gncc[1] = a + b;
		}
	}
	if (vu == 2)
	{
		gncc[1] = 2;
	}
	while (true)
	{
		for (i = 2; i < size; i++)
		{
			gncc[i] = rand() % 10;
		}
		string newcc;
		newcc = changetostring(gncc);
		int n, j = 0;
		n = Sum(newcc);
		if (n % 10 == 0)
		{
			while (i = 0)
			{
				if (NewccNumbers[i] == newcc)
				{
					j++;
					break;
				}
			}
			if (j == 1)
			{
				continue;
			}
			else
			{
				return newcc;
			}
		}
		else
		{
			continue;
		}
		i++;
	}
}