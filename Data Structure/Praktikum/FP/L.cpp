#include <bits/stdc++.h>
using namespace std;

/* Node structure */

deque<pair<int, int>> storage;

struct BSTNode {
    BSTNode *left, *right;
    int key;
    int height;
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

    void insert(int value, int hCount) {
        if (!find(value)) {
            _root = __insert(_root, value, hCount);
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

private:
    // Utility Function
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
            hCount++;
            root->left = __insert(root->left, value, hCount);
        }
        else if (value > root->key){
            hCount++;
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
            storage.push_back(make_pair(root->height, root->key));
            //printf("%d ", root->key);
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

int main()
{
    BST set;
    set.init();
    int input;
    while(cin >> input) {
        set.insert(input, 0);
    }
    set.traverseInorder();

    //cout << endl;
    sort(storage.begin(), storage.end());
    // for(int i = 0; i < storage.size(); i++){
    //     cout << storage[i].first << " " << storage[i].second << endl;
    // }
    for(int i = 0; i <= storage.back().first; i++){
        int temp = storage[i].second;
        for(int j = 1 ; j < storage.size(); j++){
            // if(i == 0){
            //     cout << storage[i].second << endl;
            //     break;
            // }
            if(i == storage[j].first){
                temp = storage[j].second;
            }
            if(temp < storage[j].second && i == storage[j].first){
                temp = storage[j].second;
            }
        }
        cout << temp << " ";
    }
    cout << endl;

}