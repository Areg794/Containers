#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    std::cout << std::endl;

    return 0;
}
