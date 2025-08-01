/*
Source: https://www.techiedelight.com/?problem=InsertKeyIntoBST
Given the root of a binary search tree (BST) and an integer k, insert k into the BST. The solution should not rearrange the existing tree nodes and insert a new node with the given key at its correct position in BST.

Input: Below BST, k = 16

		  15
		/	 \
	   /	  \
	  /		   \
	 10		   20
	/  \		 \
   /	\	 	  \
  8		12		  25

Output:

		  15
		/	 \
	   /	  \
	  /		   \
	 10		   20
	/  \	  /  \
   /	\	 /	  \
  8		12	16	  25

You may assume that the key does not exist in the BST.

*/

class Solution
{
public:

	/*
		A BST node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/

	void insert(Node* &root, int k)
	{
		// Write your code here...
		if (root == nullptr) {
			root = new Node(k);
		} else if (k < root->data) {
			insert(root->left, k);
		} else {
			insert(root->right, k);
		}
	}
};
