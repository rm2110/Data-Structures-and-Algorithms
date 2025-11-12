#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insertNode(int value) {
        Node* newNode = new Node(value);

        // if tree is empty
        if (root == NULL) {
            root = newNode;
            cout << "Root created!\n";
            return;
        }

        // Level order insertion using queue
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                cout << "Inserted " << value << " to left of " << temp->data << endl;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                cout << "Inserted " << value << " to right of " << temp->data << endl;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Traversals
    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelOrder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Level Order Traversal: ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << "\n";
    }

    void printInorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\n";
    }

    void printPreorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << "\n";
    }

    void printPostorder() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << "\n";
    }
};

int main() {
    BinaryTree tree;
    int option, value;

    cout << "------ Binary Tree Menu ------\n";
    cout << "0. Exit\n"
         << "1. Insert Node\n"
         << "2. Inorder Traversal\n"
         << "3. Preorder Traversal\n"
         << "4. Postorder Traversal\n"
         << "5. Level Order Traversal\n";

    while (true) {
        cout << "\nEnter option: ";
        cin >> option;

        switch (option) {
            case 0:
                exit(EXIT_SUCCESS);

            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insertNode(value);
                break;

            case 2:
                tree.printInorder();
                break;

            case 3:
                tree.printPreorder();
                break;

            case 4:
                tree.printPostorder();
                break;

            case 5:
                tree.levelOrder();
                break;

            default:
                cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}
