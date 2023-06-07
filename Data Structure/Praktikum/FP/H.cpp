/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */

#include <bits/stdc++.h>
using namespace std;

/* Node structure */

deque<string> path;
deque<int> INO;

struct BSTNode {
    BSTNode *left, *right;
    int height;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value, 1);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

    bool getheight(int value) {
        BSTNode *temp = __getHeight(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value){
            cout << "on level " << temp->height << endl;
            return true;
        }
        else
            return false;
    }
    bool PH(int value) {
        BSTNode *temp = fPH(_root, value);
        //cout << "we back bois" << endl;

        if (!temp){
            cout << "no " << value << endl;
            path.clear();
            return false;
        }
        if (temp->key == value){
            //cout << path.size() << " " << "here's the path: ";
            int size = path.size();
            for(int i = 0; i < size; i++){
                cout << path[i] << " ";
            }
            cout << endl;
            path.clear();
            return true;
        }
        else{
            cout << "no " << value << endl;
            path.clear();
            return false;
        }
    }
    void RK() {
        fRK(_root);
    }


private:
    // Utility Function

    BSTNode* fPH(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key){
                //cout << "go left " << endl;
                path.push_back("L");
                //cout << path.size() << endl;
                root = root->left;
            }
            else if (value > root->key){
                //cout << "go right" << endl;
                path.push_back("R");
                //cout << path.size() << endl;
                root = root->right;
            }
            else{
                //cout << "stop" << endl;
                path.push_back("S");
                //cout << path.size() << endl;
                return root;
            }
        }
        return root;
    }

    BSTNode* __getHeight(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __createNode(int value, int hCount) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->height = hCount;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value, int hCount) {
        if (root == NULL)
            return __createNode(value, hCount);
        
        if (value < root->key){
            hCount += 1;
            // cout << "before"<< root->height << endl;
            // root->height++;
            // cout << "after"<< root->height << endl;
            root->left = __insert(root->left, value, hCount);
        }
        else if (value > root->key){
            hCount += 1;
            // cout << "before" << root->height << endl;
            // root->height++;
            // cout << "after"<< root->height <<endl;
            root->right = __insert(root->right, value, hCount);
        }
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    void fRK(BSTNode *root) {
        if (root) {
            fRK(root->left);
            INO.push_back(root->key);
            fRK(root->right);
        }
    }
};

int main()
{
    BST set;
    set.init();

    while(1){
        char command[10];
        scanf("%s", command);
        int input;
        if (strcmp(command, "IN") == 0){
            cin >> input;
            set.insert(input);
        }
        else if (strcmp(command, "RK") == 0){
            cin >> input;
            set.RK();
            int size = INO.size();
            if(input < 1 || input > size){
                cout << -1 << endl;
                continue;
            }
            else{
                cout << INO[input - 1] << endl;
            }
            INO.clear();
        }
        else if (strcmp(command, "FD") == 0){
            cin >> input;
            if(!set.getheight(input)){
                cout << "no " << input << endl;
            }
        }
        else if (strcmp(command, "PH") == 0){
            cin >> input;
            set.PH(input);
        }
        else if (strcmp(command, "STOP") == 0){
            cout << "done" << endl;
            break;
        }
    }


    // set.insert(6);
    // set.insert(1);
    // set.insert(8);
    // set.insert(12);
    // set.insert(1);
    // set.insert(3);
    // set.insert(7);

    // set.traverseInorder();
    // puts("");

    // set.remove(1);
    // set.remove(6);
    // set.remove(8);
    // set.traverseInorder();
    // puts("");
    //return 0;
}