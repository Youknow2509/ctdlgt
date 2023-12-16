
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(){
            left = right = NULL;
        };
        Node(int data){
            this->data = data;
            left = right = NULL;
        };
};

class Tree{
    public:
        Node* insert(Node *root, int data);
        Node* search(Node *root, int data);
        Node* deleteNode(Node *root, int data);
        Node* findMin(Node *root);
        void showTree(Node *root);
        int calculateDepth(Node *root);
};

void Tree::showTree(Node *root){
    if(root == NULL){
        return;
    }
    else{
        showTree(root->left);
        cout << root->data << " ";
        showTree(root->right);
    }
}

Node* Tree::insert(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

Node* Tree::search(Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == data){
        return root;
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

Node* Tree::findMin(Node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return findMin(root->left);
    }
}

Node* Tree::deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else{
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int Tree::calculateDepth(Node *root){
    if(root == NULL){
        return -1;
    }
    else{
        return max(calculateDepth(root->left), calculateDepth(root->right)) + 1;
    }
}

int main(){

    Tree tree;
    Node *root = NULL;
    root = tree.insert(root, 10);
    root = tree.insert(root, 5);
    root = tree.insert(root, 15);
    root = tree.insert(root, 20);
    root = tree.insert(root, 2);
    root = tree.insert(root, 4);

    tree.showTree(root);
    cout << endl;

    cout << "Delete 10" << endl;
    root = tree.deleteNode(root, 10);

    tree.showTree(root);
    cout << endl;

    return 0;
}