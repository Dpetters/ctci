#ifndef __Question_4_5__
#define __Question_4_5__

#include "TreeNode.h"

class Question_4_5
{
public:
	int run();
	bool isBst(TreeNode* &root, int start, int end);
private:
	void createMinimalBst(TreeNode* &root, int arr[], int start, int end);
};

#endif __Question_4_5__