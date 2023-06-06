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

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

deque<int> res;
deque<int> endresult;
int it;

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
            _root = __insert(_root, value);
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

    bool theJob(int value) {
        BSTNode *temp = bruh(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }
    BSTNode* theActualJob(BSTNode *root) {
        while (root != NULL){
            // if (root->left == NULL){
            //     res.push_back(root->key);
            // }
            // else if(root->right == NULL){
            //     res.push_back(root->key);
            // }
            if(root->left == NULL && root->right == NULL){
                break;
            }
            else if(root->left == NULL && root->right != NULL){
                res.push_back(root->key);
                root = root->right;
            }
            else if(root->right == NULL && root->left != NULL){
                res.push_back(root->key);
                root = root->left;
            }
        }
        // while (root != NULL) {
        //     if (value < root->key)
        //         root = root->left;
        //     else if (value > root->key)
        //         root = root->right;
        //     else
        //         return root;
        // }
        return root;
    }

private:
    // Utility Function
    BSTNode* bruh(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else{
                if(root->right == NULL && root->left != NULL){
                    endresult.push_back(root->key);
                }
                else if(root->left == NULL && root->right != NULL){
                    endresult.push_back(root->key);
                }
                // if(root->left == NULL && root->right == NULL){
                //     res.erase(res.begin() + it);
                // }
                // if(root->right != NULL && root->left != NULL){
                //     res.erase(res.begin() + it);
                // }
                return root;
            }
        }
        return root;
    }

    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
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

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
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
            res.push_back(root->key);
            // printf("%d ", root->key);
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
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int command;
        cin >> command;
        if(command == 15){
            int input;
            cin >> input;
            set.insert(input);
        }
        else if(command == 04){
            int input;
            cin >> input;
            set.remove(input);
        }
        else if(command == 89){
            set.traverseInorder();
            int size = res.size();
            for(it = 0 ; it < size; it++){
                set.theJob(res[it]);
            }
            // if(res.size() == 0){
            //     cout << "Use whatever means you must to control our population. Just do it." << endl;
            // }
            if(endresult.size() > 0){
                for(int j = 0; j < endresult.size(); j++){
                    cout << endresult[j] << " " ;
                }
                cout << endl;
            }
            else {
                cout << "Use whatever means you must to control our population. Just do it." << endl;
            }
            res.clear();
            endresult.clear();
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
    return 0;
}