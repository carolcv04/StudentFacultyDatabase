#ifndef LAZYBST_H
#define LAZYBST_H
#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename K, typename T>
class TreeNode{

    public:
        TreeNode();
        TreeNode(K key, T* data); //creates a node that stores a key and a object
        virtual ~TreeNode();

        K key;
        T* data;
        TreeNode<K,T> *left;
        TreeNode<K,T> *right;
};

template <typename K, typename T>
TreeNode<K,T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
    data = NULL;
}

template <typename K, typename T>
TreeNode<K,T>::TreeNode(K k, T* obj){
    left = NULL;
    right = NULL;
    key = k;
    data = obj;
}

template <typename K, typename T>
TreeNode<K,T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <typename K, typename T>
class LazyBST{
    public:
        LazyBST();
        virtual ~LazyBST();

        void insert(K value, T* obj);
        void insertNode(K value, T* obj);
        void rebuildTree(TreeNode<K,T> *node); //rebuilds the tree with the nodes in the list
        bool contains(K value); //search method
        bool deleteNode(K k); //deletion
        TreeNode<K,T>* getSuccessor(TreeNode<K,T> *d);
        T* getData(K key);

        bool isEmpty();
        T* getMin(); 
        T* getMax();

        void printTree(); //prints the tree
        void printTreeFile(ofstream& output); //prints the tree to a file
        void printTreeHelper(TreeNode<K,T>* node, ofstream& output); //allows to access the root to print the tree
        void destroyRecursive(TreeNode<K,T>* node); //destroys the tree
        void recPrint(TreeNode<K,T> *node);

        int getRightTreeDepth(TreeNode<K,T>* node); //gets the highest depth at the right side of the tree
        int getLeftTreeDepth(TreeNode<K,T>* node); //gets the highest depth at the left side of the tree
        int calculateTreeDepth(TreeNode<K,T>* node); //calculates the total tree depth
        int getTreeDepthDifference(); //get method
        TreeNode<K,T>* getArrayMedian(); //gets the median node

        void rebalanceTree(); //rebalnces the tree if the depth is > 1.5
        void inOrderTraversal(TreeNode<K,T>* node);
        void inOrder(TreeNode<K,T>* node);
        void addNodeToList(TreeNode<K,T>* node);

    private:
        LinkedList<TreeNode<K,T>*>* ascendingNodes;
        TreeNode<K,T>* root;
        TreeNode<K,T>* median; 
        int m_findMedian;
        int size;
};

template <typename K, typename T>
LazyBST<K,T>::LazyBST(){
    root = NULL;
}

template <typename K, typename T>
LazyBST<K,T>::~LazyBST(){
    destroyRecursive(root);
}

template <typename K, typename T>
void LazyBST<K,T>::recPrint(TreeNode<K,T> *node){

    if(node == NULL){
        return;
    }

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <typename K, typename T>
void LazyBST<K,T>::printTree(){
    inOrder(root);
}

template <typename K, typename T>
bool LazyBST<K,T>::isEmpty(){
    return(root == NULL);
}

template <typename K, typename T>
T* LazyBST<K,T>::getMin(){

    //gets the lowest value on the tree
    if(isEmpty())
        return NULL;

    TreeNode<K,T>* current = root;
    while(current->left != NULL){
        current = current->left;
    }

    return &(current->key);
}

template <typename K, typename T>
T* LazyBST<K,T>::getData(K value){
    //gets the object that is assigned with the value
    if(isEmpty())
        return NULL;
    
    TreeNode<K,T> *current = root;

    while(current->key != value){
        if(value < current->key)
            current = current->left;
        else
            current = current->right;
        
        if (current == NULL)
            return NULL;
    }
    return current->data;
}

template <typename K, typename T>
T* LazyBST<K,T>::getMax(){

    //gets the highest value on the tree
    if(isEmpty())
        return NULL;

    TreeNode<K,T>* current = root;
    while(current->right != NULL){
        current = current->right;
    }

    return &(current->key);
}

template <typename K, typename T>
void LazyBST<K,T>::insert(K value, T* obj){

    //traverses the tree to see where the node is to be inserted
    TreeNode<K,T>* node = new TreeNode<K,T>(value, obj);

    if((isEmpty())){
        root = node;
    }else{
        //find where it goes
        TreeNode<K,T> *current = root;
        TreeNode<K,T> *parent = NULL;

        while(true){
            parent = current;

            if(value < current->key){
                //to the left
                current = current->left;

                if(current == NULL){
                    //insertion point (leaf)
                    parent->left = node;
                    break;
                }
            }else{
                //to the right
                current = current->right;

                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <typename K, typename T>
void LazyBST<K,T>::insertNode(K value, T* obj){
    //inserts the nodes to the tree
    insert(value, obj);
    ++size;

    if(getTreeDepthDifference() > 1.5){
        rebalanceTree();
    }
}

template <typename K, typename T>
void LazyBST<K,T>::rebuildTree(TreeNode<K,T>* node){
    //inserts the nodes back to the tree
    insert(node->key, node->data);
}

//search O(log n)
template <typename K, typename T>
bool LazyBST<K,T>::contains(K value){
    //checks if the node is within the tree
    if(isEmpty())
        return false;
    
    TreeNode<K,T> *current = root;

    while(current->key != value){
        if(value < current->key)
            current = current->left;
        else
            current = current->right;
        
        if (current == NULL)
            return false;
    }
    return true;
}

template <typename K, typename T>
bool LazyBST<K,T>::deleteNode(K k){
    //deletes a node from the BST
    if((isEmpty())){
        return false;
    }

    TreeNode<K,T> *current = root;
    TreeNode<K,T> *parent = root;
    bool isLeft = true;

    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
            return false;
    }

    //we found node to be deleted 

    /* node to be deleted is a leaf*/
    if(current->left == NULL && current->right == NULL){
        if(current == root)
            root = NULL;
        else if(isLeft)
            parent->left = NULL;
        else 
            parent->right = NULL;
    }

    /* node to be deleted has 1 child*/
    else if(current->right == NULL){
        //has one child an its a left child 

        if(current == root)
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }

    /* node to be deleted has 1 child*/
    else if(current->left == NULL){
        //has one child an its a right child 

        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    /* node has two children now we cry*/
    else{
        TreeNode<K,T> *successor = getSuccessor(current);

        if(current == root)
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;
        
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    delete current;
    --size;

    if(getTreeDepthDifference() > 1.5){
        rebalanceTree();
    }

    return true;
}

template <typename K, typename T>
void LazyBST<K,T>::destroyRecursive(TreeNode<K,T>* node){
    if(node != NULL){
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
    }
}

template <typename K, typename T>
TreeNode<K,T>* LazyBST<K,T>::getSuccessor(TreeNode<K,T> *d){
    //who the sucessors parent 
    //whos sucessor 
    //whos current

    TreeNode<K,T> *sp = d;
    TreeNode<K,T> *sucessor = d;
    TreeNode<K,T> *current = d->right;

    while(current != NULL){
        sp = sucessor;
        sucessor = current;
        current = current->left;
    }

    //once we get here we found the sucessor
    //check if th sucessor is the descendant of the right child
    if(sucessor != d->right){
        sp->left = sucessor->right;
        sucessor->right = d->right;
    }
    return sucessor;

}

template <typename K, typename T>
int LazyBST<K,T>::getRightTreeDepth(TreeNode<K,T>* node) {
    //gets the max depth of the right tree
    if (node == NULL) {
        return 0; // Return 0 for an empty subtree
    }
    return max(getRightTreeDepth(node->left), getRightTreeDepth(node->right)) + 1;
}

template <typename K, typename T>
int LazyBST<K,T>::getLeftTreeDepth(TreeNode<K,T>* node) {
    //gets the max depth of the left tree
    if (node == NULL) {
        return 0; // Return 0 for an empty subtree
    }
    return max(getLeftTreeDepth(node->left), getLeftTreeDepth(node->right)) + 1;
}

template <typename K, typename T>
int LazyBST<K,T>::getTreeDepthDifference(){
    if (root == NULL){
        return 0; // Return 0 for an empty subtree
    }
    return abs(getLeftTreeDepth(root->left) - getRightTreeDepth(root->right));
}

template <typename K, typename T>
TreeNode<K,T>* LazyBST<K,T>::getArrayMedian(){

}


template <typename K, typename T>
void LazyBST<K,T>::rebalanceTree(){

    if (isEmpty() || getTreeDepthDifference() <= 1.5) {
        return;
    }

    //creates a list, and adds the elements in ascending order
    ascendingNodes = new LinkedList<TreeNode<K,T>*>();
    inOrderTraversal(root);

    //destroys the previous tree
    destroyRecursive(root);
    root = median;
    m_findMedian = 0;

    //adds the nodes back to the tree in a balanced fashion
    int numNodes = ascendingNodes->getSize();
    for(int i = 0; i < numNodes; ++i){
        TreeNode<K,T>* node = ascendingNodes->removeFront();
        rebuildTree(node);
    }

    //deletes the list
    delete ascendingNodes;
    ascendingNodes = NULL;
}

template <typename K, typename T>
void LazyBST<K,T>::inOrderTraversal(TreeNode<K,T>* node){
    //adds nodes to the list in ascending order
    if(node == NULL)
        return;
    inOrderTraversal(node->left);
    addNodeToList(node);
    inOrderTraversal(node->right);
}

template <typename K, typename T>
void LazyBST<K,T>::inOrder(TreeNode<K,T>* node){
    //prints all the object information in ascending order. 
    if(node == NULL)
        return;
    inOrder(node->left);

    node->data->printInfo();
    std::cout << std::endl;

    inOrder(node->right);
}

template <typename K, typename T>
void LazyBST<K,T>::addNodeToList(TreeNode<K,T>* node){

    int medianIndex = (size/2); //the median value based on the amount of nodes in the tree
    TreeNode<K,T>* newNode = new TreeNode<K,T>(node->key, node->data); 

    //once the list is at the median index, it will asign it as the median
    if(medianIndex == m_findMedian){
        median = newNode;
        ++m_findMedian;
        return;
    }
    //if not, it will be inserted to the list
    ascendingNodes->insertBack(newNode);
    ++m_findMedian;
}

template<typename K, typename T>
void LazyBST<K,T>::printTreeFile(ofstream& output){
    printTreeHelper(root, output); //prints the tree starting from the root in order
}

template<typename K, typename T>
void LazyBST<K,T>::printTreeHelper(TreeNode<K,T>* node, ofstream& output){
    if (node != nullptr) {
        //in order traversal
        printTreeHelper(node->left, output);
        node->data->printToFile(output);
        output << std::endl;
        printTreeHelper(node->right, output);
    }
}

#endif