//Shreya Gogini
//ShelterBST.h
//Purpose : header file that holds the methods for the ShelterBST class
//          and it initializes the pets and nodes for the binary search tree

#include <iostream>

using namespace std;

//pet constructor
struct Pet {
    string name;
    int age;
};

//ShelterBST class with all methods
class ShelterBST{
    //TreenNode Struct with pet pointer and left+right node pointers
    struct TreeNode {
        Pet* pet; 
        TreeNode* left;
        TreeNode* right;
    };    
    //initializing the root node
    TreeNode* root;

    //PRIVATE FUNCTIONS
    TreeNode* insert(TreeNode*, Pet*); //insert into tree
    TreeNode* search(TreeNode *, string);//search the tree
    TreeNode* parent(TreeNode*, string);//find the parent of a node
    TreeNode* predecessor(TreeNode*, string);//find the predecessor of a node
    TreeNode* deleteNode(TreeNode*, string);
    TreeNode* destroyTree(TreeNode*);//destroy the entire tree
    TreeNode* findRightMost(TreeNode*);//finds the rightmost node

    public:

    ShelterBST(); //class constructor

    int numberOfNodes(TreeNode*);//find the total number of nodes in tree
    int internalNodes(TreeNode*);//find the number of internal nodes in tree
    int nodesAtGivenLevel(TreeNode*, int);//find the # of nodes at X level
    int height(TreeNode*);//find the height of the tree
    bool isBalanced(TreeNode*);//check if the tree is balanced

    //TRAVERSALS
    void inorder(TreeNode*);//inorder traversal
    void preorder(TreeNode*);//preorder traversal
    void postorder(TreeNode*);//postorder traversal

    //ACCESSOR METHODS
    void insertPet(string, int);//calls insert function
    void nodeDelete(string);//calls delete node function
    void treeDestroy();//calls destroy tree function
    void searchPet(string);//calls the search function
    void inorderDisplay();//calls the inorder function
    void postorderDisplay();//calls the postorder function
    void preorderDisplay();//calls the preorder function
    void findParent(string);//calls the parent function
    void findPredecessor(string);//calls the predecessor function
    int totalNodes();//calls the number of nodes function
    int totalNodesAtValue(int);//calls the nodes at level function
    bool balance();//calls the balanced function
    int findHeight();//calls the height function
    int getInternal();//calls the internal nodes function

    void runtests();//calls the function to run the tests
};
