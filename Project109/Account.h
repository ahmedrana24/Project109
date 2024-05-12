#pragma once
#ifndef ACCOUNT_H 
#define ACCOUNT_H 
#include <iostream> 
#include <fstream> 
#include <Windows.h> 
#include <string> 
using namespace std;
struct account_node
{
	string name, password;
	bool visibl;
	account_node* next;
	account_node()
	{
		name = " ";
		password = " ";
		visibl = false;
		next = nullptr;
	}
};
class account_linklist
{
public:
	account_linklist() {}
	void account_detail_insertion(string name, string password, bool visibl, account_node*& head) {
		account_node* newNode = new account_node();
		newNode->name = name;
		newNode->password = password;
		newNode->visibl = visibl;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			account_node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void displayList(account_node*& current)
	{
		ofstream account;
		account.open("account.txt");
		account_node* s = current;
		while (s != nullptr)
		{
			account << "Name :" << s->name << "\nPassword " << s->password << endl;
			s = s->next;
		}
	}
};
#endif 

