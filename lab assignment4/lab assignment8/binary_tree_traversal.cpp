/*Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using a recursive approach. 
*/

#include <iostream>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a binary tree
Node* createTree() {
    int value;

    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1) {
        return NULL;
    }

    Node* newNode = new Node();

    newNode->data = value;

    cout << "Enter left child of " << value << endl;
    newNode->left = createTree();

    cout << "Enter right child of " << value << endl;
    newNode->right = createTree();

    return newNode;
}

// Pre-order: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

// In-order: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Post-order: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

int main() {
    cout << "Create Binary Tree:\n";

    Node* root = createTree();

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}
