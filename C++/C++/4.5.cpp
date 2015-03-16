#include "4.5.h"
#include <string>
#include <iostream>

using namespace std;

int Question_4_5::run()
{
	//int arr[] = { 1, 2, 2, 4, 5, 6, 7, 8, 9 };    //Not a BST
	int arr[] = { 2, 2, 3, 4, 5, 6, 7, 8, 9 };    //is BST
	TreeNode* root;
	root = NULL;
	createMinimalBst(root, arr, 0, 8);
	cout << isBst(root, INT_MIN, INT_MAX);
	string s;
	cin >> s;
	return 0;
}

bool Question_4_5::isBst(TreeNode* &root, int start, int end)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data <= end && root->data >= start)
	{
		isBst(root->left, start, root->data) && isBst(root->right, root->data+1, end);
	}
	else
	{
		return false;
	}
}

void Question_4_5::createMinimalBst(TreeNode* &root, int arr[], int start, int end)
{
	if (start>end)
		return;
	if (root == NULL)
	{
		TreeNode *ptr = new TreeNode;
		int ind = start + (end - start) / 2;
		ptr->data = arr[ind];
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		createMinimalBst(root->left, arr, start, ind - 1);
		createMinimalBst(root->right, arr, ind + 1, end);
	}
}