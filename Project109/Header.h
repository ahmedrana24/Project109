#pragma once
#include"Account.h" 
#include"Repositry.h" 
#include"Commit.h" 
#include"Social.h" 
using namespace std;
Repositry_Account_Tree rp;
int frok = 0;
class Account
{
public:
	bool visibility;
	int account_status;
	string username, password, userdata;
	account_linklist accounts;
	Account()
	{
		username = " ";
		password = " ";
		visibility = false;
	}
	void creataccount(account_node*& root)
	{
		cout << "\n\nName : ";
		getline(cin, username);
		cout << "Password : ";
		getline(cin, password);
		system("cls");

		cout << "Congratulations!!" << endl;
		cout << "\t Your repositry has been created \n";
		cout << "\nPress 1 to keep Private";
		cout << "\nPress 2 to keep Public";
		cout << "\nPress : "; 
		cin >> account_status;
		if (account_status == 1)
		{
			visibility = false;
		}
		else if (account_status == 2)
		{
			visibility = true;
		}
		else
		{
			cout << "\tSorry! Inavlid choice>>\n";
		}
		accounts.account_detail_insertion(username, password, visibility, root); 
		ofstream repositry;
		repositry.open(username + "repositry.txt");
		repositry << username << endl;
		rp.insertion(username, rp.root);
		accounts.displayList(root);
	}
};
void check_login_information(account_node*& account)
{
	string loginame, name, password, commit, repositrydata;
	char check;
	bool loggedIn = false;
	account_node* current = account;
	account_linklist b;
	do {
		cout << "\nName: ";
		getline(cin, loginame);
		cout << "Password: ";
		getline(cin, password);
		current = account;
		while (current != nullptr)
		{
			if (current->name == loginame && current->password == password) {
				cout << "\nLogged in\n";
				loggedIn = true;
				Sleep(2000);
				break;
			}
			current = current->next;
		}
		if (!loggedIn)
		{
			cout << "\nIncorrect username or password\n";
		}
	} while (!loggedIn);
	Graph gp;
	gp.addEdge(loginame);
	do {
		system("cls");
		cout << "\nFollow/UnFollow Freinds?\n"; cout << "\nY Yes";
		cout << "\nN No\n";
		cout << "Enter ( Y or N ) : "; cin >> check;
		system("cls");
		if (check == 'Y' || check == 'y')
		{
			cin.ignore();
			cout << "\nSearch name : "; getline(cin, name); current = account;
			while (current != nullptr)
			{
				if (current->name == name)
				{
					cout << "\n" << current->name << endl;
					cout << "\nFollow/UnFollow\n";
					cout << "\nEnter ( F or U ) : "; cin >> check;
					if (check == 'F' || check == 'f')
					{
						gp.addEdge(name);
					}
					else if (check == 'U' || check == 'u')
					{
						gp.deletevectex(name);
					}
					break;
				}
				current = current->next;
			}
		}
	} while (!(check == 'N' || check == 'n'));
	commit_linkist c;
	do {
		system("cls");
		cout << "\nCheck can be know?\n"; cout << "\nP Profile View";
		cout << "\nV View Stats";
		cout << "\nL Logout\n";
		cout << "\nselsect ( P or V ) : "; cin >> check;
		if (check == 'P' || check == 'p')
		{
			system("cls");
			cin.ignore();
			cout << "\nEnter name : "; getline(cin, name); current = account;
			while (current != nullptr)
			{
				if (current->name == name && current->visibl)
				{
					ifstream repositry;
					repositry.open(name + "repositry.txt");
					while (!(repositry.eof()))
					{
						getline(repositry, repositrydata);
						cout << repositrydata << endl;
					}
					cout << "\nFollowers : \n";
					gp.printGraph();
					cout << "\n\n\nCommit : "; getline(cin, commit);
					c.commit_insertion(name, commit, c.head);
					++frok;
					Sleep(2000);
					break;
				}
				current = current->next;
			}
		}
		else if (check == 'V' || check == 'v')
		{
			system("cls");
			cout << "Name : " << loginame << endl;
			ifstream repositry;
			repositry.open(loginame + "repositry.txt");
			while (!(repositry.eof()))
			{
				getline(repositry, repositrydata);
				cout << repositrydata << endl;
			}
			cout << "Commits : \n";
			c.display();
			cout << "\nFrok count : " << frok << endl;
			cout << "\n\n\n1 Add file";
			cout << "\n2 Delete file\n";
			cout << "Choice : "; cin >> check;
			if (check == '1')
			{
				cin.ignore();
				cout << "Enter the Add : "; getline(cin, commit);
				ofstream repositry;
				repositry.open(loginame + "repositry.txt");
				repositry << commit << endl;
			}
			else if (check == '2')
			{
				ofstream repositry;
				repositry.open(loginame + "repositry.txt");
				repositry << " " << endl;
			}
			Sleep(2000);
		}
	} while (!(check == 'L' || check == 'l'));
}

