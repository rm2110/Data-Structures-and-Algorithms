#include <iostream>
#include <queue>   
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(NULL), right(NULL) {}
};

Node* root = NULL;

void addNode(int a) {
    Node* newnode = new Node(a);

    if (root == NULL) {
        root = newnode;
        return;
    }

    Node* curr = root;
    Node* parent = NULL;

    while (curr != NULL) {
        parent = curr;

        if (a < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (a < parent->value)
        parent->left = newnode;
    else
        parent->right = newnode;
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL) return;
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void BFS() {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "BFS (Level Order): ";

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->value << " ";

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
    cout << "\n";
}

void printTree() {
    if (root == NULL) {
        cout << "Empty tree!\n";
        return;
    }

    cout << "Inorder (DFS): ";
    inorder(root);
    cout << "\nPreorder (DFS): ";
    preorder(root);
    cout << "\nPostorder (DFS): ";
    postorder(root);
    cout << "\n";
}

Node* findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

Node* deleteNode(Node* node, int key) {
    if (node == NULL)
        return node;

    if (key < node->value)
        node->left = deleteNode(node->left, key);
    else if (key > node->value)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        } else if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
    return node;
}

int main() {
    int option;

    cout << "0. Exit\n"
         << "1. Add Node\n"
         << "2. Print (Inorder / Preorder / Postorder)\n"
         << "3. Delete Node\n"
         << "4. BFS Traversal\n";

    while (true) {
        cout << "\nEnter option: ";
        cin >> option;

        switch (option) {
            case 0:
                exit(EXIT_SUCCESS);

            case 1: {
                int x;
                cout << "Enter Value: ";
                cin >> x;
                addNode(x);
                cout << "Node added!\n";
                break;
            }

            case 2:
                printTree();
                break;

            case 3: {
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                cout << "Node deleted (if existed)!\n";
                break;
            }

            case 4:
                BFS();
                break;

            default:
                cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}
