/* name: Gurudeta Singh
 * project: Binary Trees
 * class: CS 2500
 * Description: This program will read in a file and store/count words by going through
 * the tree using traversals.
 */
#ifndef BINARYTREES_H_
#define BINARYTREES_H_

using namespace std;

struct TreeNode
{
	int wordCount;
	string word;
	struct TreeNode *left, *right;
};

typedef struct TreeNode *TREEPTR;

class BinaryTrees
{
	public:
		TREEPTR root;

		void create();
		void destroy(TREEPTR&);
		bool empty();
		bool full();
		void insert(TREEPTR&, string, int&);
		void preorder(TREEPTR);
		void postorder(TREEPTR);
		void inorder(TREEPTR);
		int depth(TREEPTR);
		TREEPTR search(TREEPTR, string);
};

#endif /* BINARYTREES_H_ */
