#ifndef __Question_4_6__
#define __Question_4_6__

#include "TreeNode.h"

using namespace std;

class Question_4_6
{
public:
	int run();
	TreeNode* inOrderSuccessor(TreeNode* root, int data);
private:
	void createMinimalBst(TreeNode* &root, TreeNode* parent, int arr[], int start, int end);
};

#endif // __Question_4_6__