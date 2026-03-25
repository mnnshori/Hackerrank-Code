#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    // Private helper: Recursive insertion
    Node* insertHelper(Node* current, int data) {
        if (current == nullptr) {
            return new Node(data);
        }

        if(data < current->data) {
            current->left = insertHelper(current->left, data);
        } else if(data > current->data) {
            current->right = insertHelper(current->right, data);
        }
        return current;
    }

    // Private helper: Recursive In-order traversal.
    void inOrderHelper(Node* current) {
        if (current == nullptr) {
            return;
        }
        inOrderHelper(current->left);
        cout << current->data << " ";
        inOrderHelper(current->right);
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Public API: User doesn't need to know about "Node*"
    void insert(int data) {
        this->root = insertHelper(root, data);
    }

    void display() {
        inOrderHelper(root); 
        cout << "\n";
    }
};

int main() {
    BinarySearchTree* myTree = new BinarySearchTree();
    int data;
    cout << "Enter values (Enter -1 to stop): \n";
    while (cin >> data && data != -1)  {
        myTree->insert(data);
    }

    cout << "Sorted Binary Search Tree elements: ";
    myTree->display();
    
    return 0;
}