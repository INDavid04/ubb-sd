#include <iostream>
using namespace std;

class InsertIntoBST {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // BST comes from binary search tree
        if (root == nullptr) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        if (val > root -> val) {
            root -> left = insertIntoBST(root -> left, val);
        }
        if (val > root -> val) {
            root -> right = insertIntoBST(root -> right, val);
        }
        return root;
    }

    /// Varianta nerecursiva
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* currentNode;
        if (val < root -> val) {
            currentNode = root -> right;
        } else {
            currentNode = root -> right;
        }
        TreeNode* anteriorNode;
        anteriorNode = root;
        while (root !- nullptr) {
            anteriorNode = currentNode;
            if(val < currentNode -> val) {
                currentNode = currentNode -> left;
            } else {
                currentNode = currentNode -> right;
            }
            TreeNode* newNode = new TreeNode(val);
            if(newNode -> val < anteriorNode -> val) {
                anteriorNode -> left = newNode;
            }
            /// TODO: continue here;
        }
    }
}

class SerachKeyInBST {
    bool search(Node* root, int key) {

    }
}

int main() {
    /// leetcode701, link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
    /// techiedelight, link: https://www.techiedelight.com/?problem=SearchKeyInBST

    return 0;
}
