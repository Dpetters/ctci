#include "4.3.h"
#include "TreeNode.h"
#include <iostream>
#include <string>

using namespace std;

void Question_4_3::createBst(TreeNode* &root, int sortedArray[], int start, int end)
{
	if (start > end)
	{
		return;
	}
	if (root == NULL)
	{
		TreeNode* tmp = new TreeNode;
		int midway = start + (end - start) / 2;
		tmp->data = sortedArray[midway];
		tmp->left = NULL;
		tmp->right = NULL;
		root = tmp;
		createBst(root->left, sortedArray, start, midway-1);
		createBst(root->right, sortedArray, midway+1, end);
	}
}

int Question_4_3::run()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	TreeNode* root;
	root = NULL;
	createBst(root, arr, 0, 8);
	cout << root->left->data << " " << root->data << " " << root->right->data << '\n';
	string s;
	cin >> s;
	return 0;
}