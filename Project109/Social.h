#pragma once
#include"Account.h" 
using namespace std;
struct Node
{
	string data;
	Node* next;
	Node(const string& data)
	{
		this->data = data;
		next = nullptr;
	}
};
class Graph
{
private:
	Node* head;
	int size;
public:
	Graph()
	{
		head = nullptr;
		size = 0;
	}
	void addEdge(const string& data)
	{
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		size++;
	}
	void printGraph()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void deletevectex(const string& name)
	{
		while (head != nullptr && head->data == name) {
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
		if (head == nullptr)
		{
			return;
		}
		Node* current = head;
		while (current->next != nullptr)
		{
			if (current->next->data == name)
			{
				Node* temp = current->next;
				current->next = current->next->next; delete temp;
				size--;
			}
			else
			{
				current = current->next;
			}
		}
	}
	~Graph()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
};

