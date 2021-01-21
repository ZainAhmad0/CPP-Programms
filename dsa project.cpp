#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void blockDisplay()
{
	cout << "Blocks Reserved for Electrical Department are : " << endl;
	cout << "1)XC-1\n2)XC-2\n3)XC-3\n4)XC-4\n" << endl;
	cout << "Blocks Reserved for Software Department are : " << endl;
	cout << "1)NC-1\n2)NC-2\n3)NC-3\n4)NC-4\n" << endl;
	cout << "Blocks Reserved for Computer Engineering Department are : " << endl;
	cout << "1)OC-1\n2)OC-2\n3)OC-3\n4)OC-4\n" << endl;
	cout << "Blocks Reserved for CS Department are : " << endl;
	cout << "1)HL-1\n2)HL-2\n3)HL-3\n4)HL-4\n" << endl;
}


void changeData(int x)
{
	if (x == 1)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		while (!(cin >> choice))
		{
			cout << "Only Numeric inputs allowed! Re-enter : ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			getline(read, line);
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt"); 
			ofstream fileout("proof.txt"); 
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 2; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}


	if (x == 2)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		while (!(cin >> choice))
		{
			cout << "Only Numeric inputs allowed! Re-enter : ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 3; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 4; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}


	if (x == 3)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		while (!(cin >> choice))
		{
			cout << "Only Numeric inputs allowed! Re-enter : ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 5; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 6; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}


	if (x == 4)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		while (!(cin >> choice))
		{
			cout << "Only Numeric inputs allowed! Re-enter : ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 7; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 8; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}


	if (x == 5)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		while (!(cin >> choice))
		{
			cout << "Only Numeric inputs allowed! Re-enter : ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 9; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <=10; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}

	if (x == 1)
	{
		int choice;
		cout << "Press 1 to change your user Name" << endl;
		cout << "Press 2 to change you password" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string line;
			ifstream read("data.txt");
			getline(read, line);
			read.close();
			string strNew;
			cout << "Please enter a new User Name" << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");

		}
		else if (choice == 2)
		{
			string line;
			ifstream read("data.txt");
			for (int i = 1; i <= 2; i++)
			{
				getline(read, line);
			}
			read.close();
			string strNew;
			cout << "Please enter a new Password " << endl;
			cin >> strNew;
			string strReplace = line;
			ifstream filein("data.txt");
			ofstream fileout("proof.txt");
			if (!filein || !fileout)
			{
				cout << "Error opening files!" << endl;
			}

			string strTemp;
			while (filein >> strTemp)
			{
				if (strTemp == strReplace)
				{
					strTemp = strNew;
				}
				strTemp += "\n";
				fileout << strTemp;

			}
			filein.close();
			fileout.close();
			remove("data.txt");
			rename("proof.txt", "data.txt");
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
}

bool loginVerified(string userName, string password, int check)
{
	if (check == 5)
	{
		string u, p;
		string line;
		ifstream read("data.txt");
		getline(read, line);
		u = line;
		getline(read, line);
		p = line;
		if (u==userName && p==password)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	else if (check == 1)
	{
		string u, p;
		string line;
		ifstream read("data.txt");
		for (int i = 1; i <= 2; i++)
		{
			getline(read, line);
			u = line;
			getline(read, line);
			p = line;
		}
		read.close();
		if (u == userName && p == password)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	else if (check == 2)
	{
		string u, p;
		string line;
		ifstream read("data.txt");
		for (int i = 1; i <= 3; i++)
		{
			getline(read, line);
			u = line;
			getline(read, line);
			p = line;
		}
		read.close();
		if (u == userName && p == password)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	else if (check == 3)
	{
		string u, p;
		string line;
		ifstream read("data.txt");
		for (int i = 1; i <= 4; i++)
		{
			getline(read, line);
			u = line;
			getline(read, line);
			p = line;
		}
		read.close();
		if (u == userName && p == password)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	else if (check == 4)
	{
		string u, p;
		string line;
		ifstream read("data.txt");
		for (int i = 1; i <= 5; i++)
		{
			getline(read, line);
			u = line;
			getline(read, line);
			p = line;
		}
		read.close();
		if (u == userName && p == password)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}


void main()
{

	int count = 0;
	string line;
	ifstream read("data.txt");
	getline(read, line);
	while (!read.eof())
	{
		getline(read, line);
		count++;
	}
	read.close();
	if (count == 0)
	{
		string u, p;
		int ch;
		ofstream obj;
		obj.open("data.txt");
		cout << "\nThere don't exsists any Admin or employees. Please hire them\n" << endl;
		cout << "\n\t\tHiring Admin\n" << endl;
		cout << "please provide username" << endl;
		cin >> u;
		cout << "Please provide password" << endl;
		cin >> p;
		obj << u << endl;
		obj << p << endl;
		cout << "\n\t\tHiring Electrical Department's faculty member\n" << endl;
		cout << "please provide username" << endl;
		cin >> u;
		cout << "Please provide password" << endl;
		cin >> p;
		obj << u << endl;
		obj << p << endl;
		cout << "\n\t\tHiring Software Department's faculty member\n" << endl;
		cout << "please provide username" << endl;
		cin >> u;
		cout << "Please provide password" << endl;
		cin >> p;
		obj << u << endl;
		obj << p << endl;
		cout << "\n\t\tHiring Computer Engineering Department's faculty member\n" << endl;
		cout << "please provide username" << endl;
		cin >> u;
		cout << "Please provide password" << endl;
		cin >> p;
		obj << u << endl;
		obj << p << endl;
		cout << "\n\t\tHiring CS Department's faculty member\n" << endl;
		cout << "please provide username" << endl;
		cin >> u;
		cout << "Please provide password" << endl;
		cin >> p;
		obj << u << endl;
		obj << p << endl;
		obj.close();

	}




	else
	{
		int choice = 0;
		cout << "\t\tWelcome to Orientation Session\n" << endl;
		while (choice != 3)
		{
			cout << "\nPress 1 for Admin sign up" << endl;
			cout << "Press 2 for faculty sign up" << endl;
			cout << "Press 3 to exit" << endl;
			while (!(cin >> choice))
			{
				cout << "Only Numeric inputs allowed! Re-enter : ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			if (choice == 1)
			{
				int x = 5;
				string userName, password;
				cout << "\n\t\tAdmin Login\n" << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Please provide your user name : ";
				cin >> userName;
				cout << "Please provide your user password : ";
				cin >> password;
				cout << "--------------------------------------------\n\n" << endl;
				if (loginVerified(userName, password, x) == 1)
				{
					int c = 0;
					cout << "\n\t\tWelcome to Admin Portal\n" << endl;
					while (c != 5)
					{
						cout << "\nPress 1 to change routes/distances between blocks" << endl;
						cout << "Press 2 to display all faculty's Information (Each Department)" << endl;
						cout << "Press 3 to view blocks reserved for each departement" << endl;
						cout << "Press 4 to change your personal data" << endl;
						cout << "Press 5 to sign out" << endl;
						while (!(cin >> c))
						{
							cout << "Only Numeric inputs allowed! Re-enter : ";
							cin.clear();
							cin.ignore(123, '\n');
						}
						if (c == 1)
						{
							cout << "." << endl;
						}
						else if (c == 2)
						{
							string line;
							ifstream read("data.txt");
						    int	counter = 0;
							while (!read.eof())
							{
								if (counter == 5)
								{
									break;
								}
								else
								{
									if (counter == 0)
									{
										cout << "\n\t\tAdmin's Data\n" << endl;
									}
									if (counter == 1)
									{
										cout << "\n\t\tElectrical Faculty's Data\n" << endl;
									}
									if (counter == 2)
									{
										cout << "\n\t\tSoftware Faculty's Data\n" << endl;
									}
									if (counter == 3)
									{
										cout << "\n\t\tComputer Engineering Faculty's Data\n" << endl;
									}
									if (counter == 4)
									{
										cout << "\n\t\tCS Faculty's Data\n" << endl;
									}
									getline(read, line);
									cout << "User Name : " << line << endl;
									getline(read, line);
									cout << "Password : " << line << endl;
									counter++;
								}
							}
							read.close();
						}
						else if (c == 3)
						{
							blockDisplay();
						}
						else if (c == 4)
						{
							int x = 1;
							changeData(x);
						}
						else if (c == 5)
						{
							break;
						}
						else
						{
							cout << "invalid input" << endl;
						}
					}
				}
				else
				{
					cout << "\nWrong credentials provided! Please check again" << endl;
				}
			}

			else if (choice == 2)
			{
				int ch;
				cout << "\nFor Which department you want to sign up" << endl;
				cout << "1) Electrical Engineering Department" << endl;
				cout << "2) Software Engineering Department" << endl;
				cout << "3) Computer Engineering Department" << endl;
				cout << "4) Computer Science" << endl;
				while (!(cin >> ch))
				{
					cout << "Only Numeric inputs allowed! Re-enter : ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				if (ch == 1)
				{
					int x = 1;
					string userName, password;
					cout << "\nPlease provide your user name : ";
					cin >> userName;
					cout << "Please provide your user password : ";
					cin >> password;
					if (loginVerified(userName, password, x))
					{
						int c = 0;
						cout << "\n\t\tWelcome to Faculy Portal\n" << endl;
						while (c != 4)
						{
							cout << "\nPress 1 to display the routes" << endl;
							cout << "Press 2 to view blocks reserved for each departement" << endl;
							cout << "Press 3 to change your personal data" << endl;
							cout << "Press 4 to sign out" << endl;
							while (!(cin >> c))
							{
								cout << "Only Numeric inputs allowed! Re-enter : ";
								cin.clear();
								cin.ignore(123, '\n');
							}
							if (c == 1)
							{
								cout << "." << endl;
							}

							else if (c == 2)
							{
								blockDisplay();
							}

							else if (c == 3)
							{
								int x = 2;
								changeData(x);
							}
							else if (c == 4)
							{
								cout << "." << endl;
							}
							else
							{
								cout << "Invalid Input" << endl;
							}
						}
					}
					else
					{
						cout << "Wrong credentials provided! Please check again" << endl;
					}
				}
				else if (ch == 2)
				{
					int x = 2;
					string userName, password;
					cout << "Please provide your user name : ";
					cin >> userName;
					cout << "Please provide your user password : ";
					cin >> password;
					if (loginVerified(userName, password, x))
					{
						int c = 0;
						cout << "\n\t\tWelcome to Faculy Portal\n" << endl;
						while (c != 4)
						{
							cout << "\nPress 1 to display the routes" << endl;
							cout << "Press 2 to view blocks reserved for each departement" << endl;
							cout << "Press 3 to change your personal data" << endl;
							cout << "Press 4 to sign out" << endl;
							while (!(cin >> c))
							{
								cout << "Only Numeric inputs allowed! Re-enter : ";
								cin.clear();
								cin.ignore(123, '\n');
							}
							if (c == 1)
							{
								cout << "." << endl;
							}

							else if (c == 2)
							{
								blockDisplay();
							}

							else if (c == 3)
							{
								int x = 3;
								changeData(x);
							}
							else if (c == 4)
							{
								cout << "." << endl;
							}
							else
							{
								cout << "Invalid Input" << endl;
							}
						}
					}
					else
					{
						cout <<"Wrong credentials provided! Please check again" << endl;
					}
				}
				else if (ch == 3)
				{
					int x = 3;
					string userName, password;
					cout << "Please provide your user name : ";
					cin >> userName;
					cout << "Please provide your user password : ";
					cin >> password;
					if (loginVerified(userName, password, x))
					{
						int c = 0;
						cout << "\n\t\tWelcome to Faculy Portal\n" << endl;
						while (c != 4)
						{
							cout << "\nPress 1 to display the routes" << endl;
							cout << "Press 2 to view blocks reserved for each departement" << endl;
							cout << "Press 3 to change your personal data" << endl;
							cout << "Press 4 to sign out" << endl;
							while (!(cin >> c))
							{
								cout << "Only Numeric inputs allowed! Re-enter : ";
								cin.clear();
								cin.ignore(123, '\n');
							}
							if (c == 1)
							{
								cout << "." << endl;
							}

							else if (c == 2)
							{
								blockDisplay();
							}

							else if (c == 3)
							{
								int x = 4;
								changeData(x);
							}
							else if (c == 4)
							{
								cout << "." << endl;
							}
							else
							{
								cout << "Invalid Input" << endl;
							}
						}
					}
					else
					{
						cout << "Wrong credentials provided! Please check again" << endl;
					}
				}
				else if (ch == 4)
				{
					int x = 4;
					string userName, password;
					cout << "Please provide your user name : ";
					cin >> userName;
					cout << "Please provide your user password : ";
					cin >> password;
					if (loginVerified(userName, password, x))
					{
						int c = 0;
						cout << "\n\t\tWelcome to Faculy Portal\n" << endl;
						while (c != 4)
						{
							cout << "\nPress 1 to display the routes" << endl;
							cout << "Press 2 to view blocks reserved for each departement" << endl;
							cout << "Press 3 to change your personal data" << endl;
							cout << "Press 4 to sign out" << endl;
							while (!(cin >> c))
							{
								cout << "Only Numeric inputs allowed! Re-enter : ";
								cin.clear();
								cin.ignore(123, '\n');
							}
							if (c == 1)
							{
								cout << "." << endl;
							}

							else if (c == 2)
							{
								blockDisplay();
							}

							else if (c == 3)
							{
								int x = 5;
								changeData(x);
							}
							else if (c == 4)
							{
								cout << "." << endl;
							}
							else
							{
								cout << "Invalid Input" << endl;
							}
						}
					}
					else
					{
						cout << "Wrong credentials provided! Please check again" << endl;
					}
				}
				else
				{
					cout << "Invalid option selected" << endl;
				}
			}


			else if (choice == 3)
			{
				break;
			}

			else
			{
				cout << "Invalid option selected" << endl;
			}
		}

	}


	system("pause");
}