#include"Header.h" 
using namespace std;
int main()
{

	system("color 3");
	account_node* root = nullptr;
	int choice;
	string friends;
	do 
	{
		cout << "---------GITHUB SIMULATION------------" << endl;
		cout << "\nIf you have any account " << endl;
		cout << endl << "1. SignIn ";
		cout << endl << "2. logIn ";
		cout << endl << "3. Exit" << endl;
		cout << "\nSelect ( 1 or 2 ) : "; 
		cin >> choice;
		cin.ignore();
		system("cls");
		Account ac;

		if (choice == 1)
		{
			ac.creataccount(root);
			cout << "\nYour account has been created \n";
			Sleep(2000);
		}
		else if (choice == 2)
		{
			system("cls");
			cout << "\nDo you want to login? \n";
			check_login_information(root);
		}
		system("cls");
	} while (choice != 3);
	system("pause");
	return 0;
}

