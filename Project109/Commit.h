#include<iostream>
#include<string> 
using namespace std;
struct commit_node
{
	string name;
	string comit;
	commit_node* next;
	commit_node()
	{
		this->name = name;
		this->comit = comit;
		next = nullptr;
	}
};
class commit_linkist
{
public:
	commit_node* head;
	commit_linkist()
	{
		head = nullptr;
	}
	void commit_insertion(string name, string commit, commit_node*& head) 
	{
		commit_node* temp = new commit_node();
		temp->name = name;
		temp->comit = commit;
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			commit_node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	void display()
	{
		commit_node* crr = head;
		while (crr != nullptr)
		{
			cout << crr->name << endl;
			cout << crr->comit << endl;
			crr = crr->next;
		}
		cout << endl;
	}
};
