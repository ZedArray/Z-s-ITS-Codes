// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    C++ conversion oleh BAYU LAKSANA
    28-03-2020
    Struktur Data 2020
    For C++
*/

// #include <stdlib.h>
// #include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct AVLNode {
    int data;
    int price;
    char myname[100];
    AVLNode *left, *right;
    int height;
    int actualHeight;
};

int maxHeight;

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value, int p, char n[100]) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        //cout << "insertion 1: " << value << endl;
        newNode->data = value;
        //cout << "insertion 2: " << p << endl;
        newNode->price = p;
        //cout << "insertion 3: " << n << endl;
        //strcpy(newNode->myname, n);
        //cout << n << endl;
        strcpy(newNode->myname, n);
        //newNode->myname = n;
        //cout << "insertion 4" << endl;
        newNode->height =1;
        //cout << "insertion 5" << endl;
        newNode->left = newNode->right = NULL;
        //cout << "i have come" << endl;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value, int p, char n[100]) {
        
        if(node==NULL)
            return _avl_createNode(value, p, n);
        if(value < node->data){
            //cout << "go left" << endl;
            node->left = _insert_AVL(node->left,value, p, n);
        }
        else if(value > node->data){
            //cout << "go right" << endl;
            node->right = _insert_AVL(node->right,value, p, n);
        }
        
        //cout << value << endl;
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
        while(1){
            int balanceFactor=_getBalanceFactor(node);
            //cout << balanceFactor << endl;
            
            if(balanceFactor > 1 && value < node->left->data){
                cout << "LCR" << endl;
                return _leftCaseRotate(node);
            }
            if(balanceFactor > 1 && value > node->left->data){
                cout << "LRCR" << endl;
                return _leftRightCaseRotate(node);
            }
            if(balanceFactor < -1 && value > node->right->data){
                cout << "RCR" << endl;
                return _rightCaseRotate(node);
            }
            if(balanceFactor < -1 && value < node->right->data){
                cout << "RLCR" << endl;
                return _rightLeftCaseRotate(node);
            }
            if(balanceFactor >= -1 && balanceFactor <= 1){
                break;
            }
        }
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }

    void insert(int value, int p, char n[100]) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value, p, n);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }

    bool get(int value) {
        AVLNode *temp = look(_root, value);
        if (temp == NULL){
            cout << "404 NOT FOUND" << endl;
            return false;
        }
        
        if (temp->data == value) {
            cout << "Item Found at page " << temp->actualHeight << endl;
            cout << "Item detail: id=" << temp->data << ", name=" << temp->myname << ", price=" << temp->price << endl;
            // cout << "~~~THE LINE BELOW IS THE DATA OF " << value << "~~~" << endl;
            // cout << temp->data << endl;
            // cout << temp->myname << endl;
            // cout << temp->price << endl;
            // cout << temp->height << endl;
            // cout << "END OF DATA" << endl;
            return true;
        }
        else return false;
    }

    AVLNode* look(AVLNode *root, int value) {
        int page = 0;
        while (root != NULL) {
            page++;
            //cout << root->data << endl;
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else{
                root->actualHeight = maxHeight - page + 1;
                return root;
            }
        }
        return root;
    }

    int heightCounter(AVLNode *root, int value, int hCount) {
        while (root != NULL) {
            hCount++;
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return hCount;
        }
        return 0;
    }

    int getMaxHeight(int value) {
        int hCount = 0;
        int temp = heightCounter(_root, value, hCount);
        if (temp == 0)
            return 0;
        
        if (temp > 0) return temp;
        else return 0;
    }
    
};


int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
    list<int> list;

    while(1){
        int id, price;
        char name[100];
        cin >> id >> price;
        scanf("%s", name);
        getchar();
        if (id == 0 && price == 0 && name[0] == '0'){
            //cout << "bye 1" << endl;
            break;
        }
        else{
            //cout << "hi 1" << endl;
            set.insert(id, price, name);
            list.push_back(id);
        }
    }
    list.sort();
    maxHeight = max(set.getMaxHeight(list.front()), set.getMaxHeight(list.back()));
    cout << "max Hiehg" << maxHeight << endl;

    while(1){
        int input;
        cin >> input;
        if (input == 0){
            break;
        }
        else{
            set.get(input);
        }
    }

    // set.insert(6);
    // set.insert(611);
    // set.insert(7);
    // set.insert(612);
    // set.insert(12);
    // set.insert(4);

    // set.inorder();
    // printf("\n");

    // set.remove(4);
    // set.remove(612);
    
    // set.inorder();
    // printf("\n");
    return 0;
}
/* 
1 1000 Rejoice
2 2000 Pantene
3 3000 Dove
4 4000 Head&Shoulder
5 5000 Sunsilk
6 6000 LOreal
7 7000 Garnier
8 8000 Ponds
9 9000 Garnier
10 10000 Dettol
0 0 0
11
3
2
4
10
0 
*/