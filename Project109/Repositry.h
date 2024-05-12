#pragma once
#include <fstream> 
using namespace std;
struct Repositry_node
{
	int height;
	string repositryname;
	Repositry_node* right;
	Repositry_node* left;
	Repositry_node(string repositryname) 
	{
		this->repositryname = repositryname; right = left = NULL;
		height = -1;
	}
};
class Repositry_Account_Tree
{
public:
	string userdata;
	Repositry_node* root;
	Repositry_Account_Tree()
	{
		root = NULL;
	}
	int height(Repositry_node* root)
	{
		if (root == nullptr)
		{
			return -1;
		}
		return root->height;
	}
	int BalanceFactor(Repositry_node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return height(root->left) - height(root->right);
	}
	int Max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	Repositry_node* RotateRight(Repositry_node* root)
	{
		Repositry_node* x = root->left;
		Repositry_node* y = x->right;
		x->right = root;
		root->left = y;
		root->height = Max(height(root->left), height(root->right)) + 1; x->height = Max(height(x->left), height(x->right)) + 1;
		return x;
	}
	Repositry_node* RotateLeft(Repositry_node* root)
	{
		Repositry_node* x = root->right;
		Repositry_node* y = x->left;
		x->left = root;
		root->right = y;
		root->height = Max(height(root->left), height(root->right)) + 1; x->height = Max(height(x->left), height(x->right)) + 1;
		return x;
	}
	Repositry_node* insertion(string repositryname, Repositry_node*& root)
	{
		if (root == NULL)
		{
			root = new Repositry_node(repositryname);
		}
		else if (root->repositryname > repositryname)
		{
			insertion(repositryname, root->right);
		}
		else if (root->repositryname < repositryname)
		{
			insertion(repositryname, root->left);
		}
		else
		{
			return root;
		}
		if (BalanceFactor(root) > 1 && repositryname < root->left->repositryname)
		{
			return RotateRight(root);
		}
		if (BalanceFactor(root) < -1 && repositryname > root->right->repositryname)
		{
			return RotateLeft(root);
		}
		if (BalanceFactor(root) > 1 && repositryname > root->left->repositryname) 
		{
			root->left = RotateLeft(root->left);
			return RotateRight(root);
		}
		if (BalanceFactor(root) < -1 && repositryname < root->right->repositryname)
		{
			root->right = RotateRight(root->right);
			return RotateLeft(root);
		}
		return root;
	}
	void inorder(Repositry_node* root)
	{
		if (root != nullptr)
		{
			inorder(root->left);
			cout << root->repositryname << endl;
			ifstream repositry;
			repositry.open("repositry.txt");
			while (!(repositry.eof()))
			{
				getline(repositry, userdata);
				cout << userdata << endl;
			}
			inorder(root->right);
		}
	}
	void deletion(string deletable)
	{
		if (root == NULL)
		{
			cout << "There is no repositry\n";
		}
		else
		{
			while (root->right != NULL)
			{
				if (root->repositryname == deletable)
				{
					make_deletion(root);
				}
				root = root->right;
			}
		}
	}
	void make_deletion(Repositry_node* root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			Repositry_node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Repositry_node* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Repositry_node* successor = root->right;
			while (successor->left != NULL)
			{
				successor = successor->left;
			}
			make_deletion(successor);
		}
	}
	~Repositry_Account_Tree()
	{
		system("cls");
	}
};

