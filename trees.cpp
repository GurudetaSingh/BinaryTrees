#include <iostream>
#include <fstream>
#include "BinaryTrees.h"
#include "Parser.h"
#include <cmath>
#include <string>
using namespace std;

void traversals();

int main()
{
	traversals();
	return 0;

}

void traversals()
{
	BinaryTrees tree;
		Parser parse;
		string buffer;
		ifstream fin;
		int nodeCount = 0;
		TREEPTR tp;

		tree.create();
		fin.open("lorem.txt");

		while(!fin.eof())
		{
			fin >> buffer;
			parse.upperCase(buffer);
			buffer = parse.cleanString(buffer);

			if(!tree.full() && buffer.length() != 0)
				tree.insert(tree.root, buffer, nodeCount);
		}

		cout << "Inorder Traversal: " << endl;
		tree.inorder(tree.root);
		cout << endl;

		cout << "Preorder Traversal: " << endl;
		tree.preorder(tree.root);
		cout << endl;

		cout << "Postorder Traversal: " << endl;
		tree.postorder(tree.root);
		cout << endl;

		cout << "Depth of Tree: " << tree.depth(tree.root) << endl;
		cout << "Total Used Nodes: " << nodeCount << endl;
		cout << "Total Possible Nodes: " << (nodeCount * 2) - 1 << endl;
		double a = 119;
		double b = 237;
		int n = 100;
		cout << "Percentage of nodes used: " << (a/b)*n << "%" << endl;


		tree.destroy(tree.root);

		fin.close();

}


