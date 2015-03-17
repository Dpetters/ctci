#include "4.6.h"
#include <iostream>
#include <string>

using namespace std;

void Question_4_6::createMinimalBst(TreeNode* &root, TreeNode* parent, int arr[], int start, int end)
{
	if (start>end)
		return;
	if (root == NULL)
	{
		TreeNode *ptr = new TreeNode;
		int ind = start + (end - start) / 2;
		ptr->data = arr[ind];
		ptr->parent = parent;
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		createMinimalBst(root->left, root, arr, start, ind - 1);
		createMinimalBst(root->right, root, arr, ind + 1, end);
	}
}

int Question_4_6::run()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	TreeNode* root;
	root = NULL;
	createMinimalBst(root, NULL, arr, 0, 8);
	TreeNode* searchedTreeNode = inOrderSuccessor(root, 7);
	cout << searchedTreeNode->data << '\n';
	string s;
	cin >> s;
	return 0;
}

TreeNode* Question_4_6::inOrderSuccessor(TreeNode* root, int data)
{
	TreeNode* dataNode = root;
	while (dataNode->data != data)
	{
		if (data < dataNode->data && dataNode->left != NULL)
		{
			dataNode = dataNode->left;
		}
		else if (data > dataNode->data && dataNode->right != NULL)
		{
			dataNode = dataNode->right;
		}
		else
		{
			return NULL;
		}
	}
	TreeNode* next = NULL;
	if (dataNode->right != NULL)
	{
		next = dataNode->right;
		while (next->left != NULL)
		{
			next = next->left;
		}
		return next;
	}
	else
	{
		next = dataNode;
		while (next->parent != NULL)
		{
			next = next->parent;
			if (next->data > data)
			{
				return next;
			}
		}
		return NULL;
	}
}