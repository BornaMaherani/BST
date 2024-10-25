#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	struct Node *left, *right;
};
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void preOrder(Node* root)
{
    if (root != NULL) 
    {
        cout <<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inorder(Node* root)
{
    if (root != NULL) 
    {
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
    }
}
void postOrder(Node* root){
    if (root != NULL) 
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data<<" ";
    }
}
Node* insert(Node* node, int data){
	if (node == NULL)
		return newNode(data);
	if (data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else
	{
		node->right = insert(node->right, data);
	}
	return node;
}
Node* erase(Node* root, int n){
	if (root == NULL)
		return root;
	if (root->data < n) 
	{
		root->right = erase(root->right, n);
		return root;
	}
	else if (root->data > n) 
	{
		root->left = erase(root->left, n);
		return root;
	}

	if (root->right == NULL) 
	{
		Node* temp = root->left;
		delete root;
		return temp;
	}
	else if (root->left == NULL) 
	{
		Node* temp = root->right;
		delete root;
		return temp;
	}
	else 
	{
		Node* succParent = root;
		Node* succ = root->right;
		while (succ->left != NULL) 
		{
			succParent = succ;
			succ = succ->left;
		}
		if (succParent != root)
		{
			succParent->left = succ->right;
		}
		else
		{
			succParent->right = succ->right;
		}
		root->data = succ->data;
		delete succ;
		return root;
	}
}
int main()
{
	Node* root = NULL;
	string line;
	while (getline(cin, line))
	{
		if(line=="print_preorder")
		{
			if(root==NULL)
			{
				cout<<"empty\n";
				continue;
			}
			preOrder(root);
			cout<<"\n";
			continue;
			
		}
		else if(line=="print_postorder")
		{
			if(root==NULL)
			{
				cout<<"empty\n";
				continue;
			}
			postOrder(root);
			cout<<"\n";
			continue;
		}
		else if(line=="print_inorder")
		{
			if(root==NULL)
			{
				cout<<"empty\n";
				continue;
			}
			inorder(root);
			cout<<"\n";
			continue;
		}
		int position = line.find(" ");
		string temp = line.substr(0,position);
		int data = stoi(line.substr(position+1,line.length()-1));
		if(temp=="insert")
		{
			root = insert(root, data);
		}
		else if(temp=="erase")
			for(int i=0; i<1000; i++)
				root = erase(root,data);
	}
	return 0;
}
