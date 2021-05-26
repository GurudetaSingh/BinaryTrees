#include <iostream>
#include <cstddef>
#include <string>
#include "BinaryTrees.h"
using namespace std;

// Creates the initial tree by setting the root equal to null
void BinaryTrees::create()
{
	root = NULL;

}

// Destroys the tree by going through and deleting each subtree
void BinaryTrees::destroy(TREEPTR &subtree)
{
	if(subtree != NULL)
	{
		destroy(subtree->left);
		destroy(subtree->right);
		delete subtree;
		subtree = NULL;
	}
}

// Boolean check to see of the tree is empty
bool BinaryTrees::empty()
{
	return (root == NULL);

}

// Boolean check to see of there is space in memory for more nodes
bool BinaryTrees::full()
{
	TREEPTR temp;

	temp = new TreeNode;
	if(temp == NULL)
		return true;
	else
		return false;

	delete temp;

}

// Insert new words as new nodes, adds to word count, and tracks total node count
void BinaryTrees::insert(TREEPTR& subtree, string word, int& nodeCount)
{
	if(subtree == NULL)
	{
		subtree = new TreeNode;
		subtree->wordCount = 1;
		nodeCount++;
		subtree->word = word;
		subtree->left = NULL;
		subtree->right = NULL;
	}
	else if(subtree->word.compare(word) == 0)
		subtree->wordCount++;
	else if(subtree->word.compare(word) > 0)
	{
		insert(subtree->left, word, nodeCount);
	}

	else
	{
		insert(subtree->right, word, nodeCount);
	}
}

// Prints out the Inorder traversal of the tree
// In order will recurse left first, then visit the current node, then it will recurse right
void BinaryTrees::inorder(TREEPTR subtree)
{
	if(subtree != NULL)
	{
		inorder(subtree->left);
		cout << subtree->word;
		cout << ": " << subtree->wordCount << endl;
		inorder(subtree->right);
	}
}


// Prints out the preorder traversal of the tree
// First you visit the current node, then you recurse left, then you recurse right
void BinaryTrees::preorder(TREEPTR subtree)
{
	if(subtree != NULL)
	{
		cout << subtree->word;
		cout << ": " << subtree->wordCount << endl;
		preorder(subtree->left);
		preorder(subtree->right);
	}
}


// Prints out the postorder traversal of the tree
// First you recurse left, then recurse right, then visit the current node
void BinaryTrees::postorder(TREEPTR subtree)
{
	if(subtree != NULL)
	{
		postorder(subtree->left);
		postorder(subtree->right);
		cout << subtree->word;
		cout << ": " << subtree->wordCount << endl;
	}
}


// Counts the total depth of the tree
int BinaryTrees::depth(TREEPTR subtree)
{
	int left, right;

	if(subtree == NULL)
	{
		return 0;
	}
	else
	{
		left = depth(subtree->left);
		right = depth(subtree->right);

		if(left > right)
			return left + 1;
		else
			return right + 1;
	}
}

// Performs a search on the tree to determine if a given string is present
TREEPTR BinaryTrees::search(TREEPTR subtree, string key)
{
	if(subtree == NULL)
		return NULL;
	else if(subtree->word.compare(key) == 0)
		return subtree;
	else if(subtree->word > key)
		return search(subtree->left, key);
	else
		return search(subtree->right, key);

}
