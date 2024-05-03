//Shreya Gogini
//ShelterBST.cpp
//Purpose : Has all the function details for the methods listed in the header
//          file. The functions that the user can choose from are listed here
//          with their subsequent functionalities

#include <iostream>
#include "ShelterBST.h"

using namespace std;

/* SheterBST.cpp Class definitions */
//desc : constructor for the ShelterBST class
//pre : root is initialized in the .h file
//post : root is set to nullptr
ShelterBST::ShelterBST(){
    root = nullptr;
}

//desc : deallocates the memory for the entire tree
//pre : root exists and the memory is allocated correctly
//post : returns nullptr once the tree is destroyed
ShelterBST :: TreeNode* ShelterBST :: destroyTree(TreeNode *root){
    if(root == nullptr){
        return nullptr;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root->pet;
    delete root;
    return nullptr;
}

//desc : calls the destroyTree function since root is private
//pre : function exists and root is accessible
//post : if tree is deleted, prints output
void ShelterBST :: treeDestroy(){
    if(!root){
        cout << "Tree is already empty" << endl;
    }
    else if(destroyTree(root) == nullptr){
        cout << "Tree has been destroyed" << endl;
    }
}

//desc : inserts a new node into the binary search tree
//pre : tree exists and pet is initialized
//post : new node is added to the correct spot based on name
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet){
   //if there is no root node, this value becomes the start
    if(!root){
      return new TreeNode{pet, nullptr, nullptr}; 
	}
    //checks for duplicates
    if(root->pet->name == pet->name){
        cout << "Error: Found a duplicate in tree" << endl;
    }
    //processes the right nodes
	//checks all the nodes on the right to see where to insert
	if(pet->name > root->pet->name){
	  root->right = insert(root->right, pet);
	}
    //processes the left node
    //checks all the nodes on the left to see where to insert
	else if(pet->name < root->pet->name){
	  root->left = insert(root->left, pet);
    }
    return root;
}

//desc : calls the insert function with pet name and age
//pre : pet constructor exists and works
//post : new pet is added to the tree
void  ShelterBST :: insertPet(string name, int age){
    Pet *new_pet = new Pet{name, age};
    root = insert(root, new_pet);
}

//desc : searches for a certain pet by name in the tree
//pre : root is initialized and tree is traversable
//post : returns the node with the data of the pet
ShelterBST::TreeNode* ShelterBST::search(TreeNode *root, string name){
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->pet->name == name)
      return root;

    // Key is greater than root's key
    if (root->pet->name < name)
      return search(root->right, name);

    // Key is smaller than root's key
    return search(root->left, name);
}

//desc : calls the search function
//pre : funciton exists in the class
//post : prints output based on if the pet is found
void ShelterBST :: searchPet(string name){
    if(search(root, name) == nullptr){
        cout << name << " not found." << endl;
    }
    else{
        cout << search(root, name)->pet->name << " " 
             << search(root, name)->pet->age << endl;
    }
}

//desc : looks for the parent node of the current node
//pre : node exists and is initialized
//post : returns parent node
ShelterBST :: TreeNode *ShelterBST::parent(TreeNode *root, string name){
    //base case
    if(root == nullptr){
        return nullptr;
    }
    //if only root node
    if(root ->left == nullptr && root->right == nullptr){
        return nullptr;
    }
    //only one child
    if((root->left != nullptr && root->left->pet->name == name)
        ||(root->right != nullptr && root->right->pet->name == name)){
        return root;
    }
    //traverses to find parent and recursively calls the function
    if(root->pet->name > name){
        return parent(root->left, name);
    }
    if(root->pet->name < name){
        return parent(root->right, name);
    }
    return nullptr;
}

//desc : calls the parent function
//pre : the current node exists
//post : prints output based on return value from parent function
void ShelterBST :: findParent(string name){
    TreeNode *temp = parent(root, name);
    if(temp == nullptr){
        cout << "The pet you entered is the parent node." << endl;
    }
    cout << temp->pet->name <<" "
         << temp->pet->age << endl;
}

//desc : finds the predecessor of the current node
//pre : the current node exists in the tree
//post : returns the node of the preodecessor
ShelterBST :: TreeNode *ShelterBST :: predecessor(TreeNode *root,string name){
    //base case
    if(root == nullptr){
        return nullptr;
    }
    //finds the rightmost node
    if(root->left != nullptr){
        TreeNode *temp = root;
        while(temp->right != nullptr){
            temp=temp->right;
        }
        return temp;
    }
    //returns the parent of the current node if it is the predecessor
    else if(parent(root, name) != nullptr && parent(root, name) == root){
        return parent(root,name);
    }
    //otherwise finds the current node and finds what the next node
    //would be in an inorder sequence
    else{
        TreeNode *p = parent(root, name);
        TreeNode *current = root;

        while(p != nullptr && p->left == current){
            current = p;
            p = parent(p, p->pet->name);
        }
        //returns node
        return p;
    }
    
}

//desc : calls the predecessor function
//pre : pet name exists in the tree
//post : prints predecessor result
void ShelterBST :: findPredecessor(string name){
   // TreeNode *temp = search(root, name);
    TreeNode *result = predecessor(root, name);
    cout << "The inorder predecessor of " << name << " is:" ;
    cout << result->pet->name << " " << result->pet->age << endl;
    
}
//desc : deletes a node from the tree and replaces 
//pre : root exists and valid name is provided
//post : none aside from description
ShelterBST :: TreeNode* ShelterBST :: deleteNode(TreeNode*root, string name){
    //searching for the node to delete and saving the parent node
    TreeNode *nodeDel = search (root, name);
    TreeNode *nodePar = parent(root, name);
    //if the node doesn't exist, returns nullptr
    if(nodeDel == nullptr){
        return root;
    }
    //if the node we have to delete only has one/zero children
    if(nodeDel->left == nullptr){
        TreeNode *temp = nodeDel->right;
        //root node
        if(nodePar == nullptr){
            root = temp;
        }
        //left child
        else if(nodePar->left == nodeDel){
            nodePar->left = temp;
        }
        //right child
        else{
            nodePar ->right = temp;
        }
        //deleting the node to delete
        delete nodeDel;
        return root;
    }
    else if(nodeDel ->right == nullptr){
        TreeNode *temp = nodeDel->left;
        //root node
        if(nodePar == nullptr){
            root = temp;
        }
        //left child
        else if(nodePar->left == nodeDel){
            nodePar->left = temp;
        }
        //right child
        else{
            nodePar->right = temp;
        }
        //deleting node
        delete nodeDel->pet;
        delete nodeDel;
        return root;
    }
    //print output
    cout << "Deleted node: " << nodeDel->pet->name << " " << nodeDel->pet->age << endl;

    //get predecessor to replace
    TreeNode *pre = findRightMost(nodeDel->left);
    nodeDel->pet = pre->pet;
    nodeDel->left = deleteNode(nodeDel->left, pre->pet->name);

    return root;
    
    
}

//desc : gets the rightmost node of the tree
//pre : root is initialized
//post : returns the current root which is the rightmost
ShelterBST :: TreeNode *ShelterBST :: findRightMost(TreeNode *root){
    TreeNode* current = root;
    while(current != nullptr && current->left != nullptr){
        current = current->left;
    }
    return current;
}

//desc : calls the deleteNode function
//pre : node exists in the tree
//post : node is removed from tree
void ShelterBST :: nodeDelete(string name){
    deleteNode(root, name);
    //cout << "Deleted Node: " << temp->pet->name << " " << temp->pet->age;
}

//desc : prints the tree in inorder traversal
//pre : tree exists with nodes
//post : none aside from description
void ShelterBST :: inorder(TreeNode*root){
    if (root != nullptr){
        
        // First recur on left child
        inorder(root->left);
    
        // Then print the data of node
        cout << root->pet->name << " " << root->pet->age << endl;
 
        // Now recur on right child
        inorder(root->right);
    }
}

//desc : calls the inorder function
//pre : root is initialized
//post : none aside from description
void ShelterBST :: inorderDisplay(){
    inorder(root);
}

//desc : prints the tree in preorder traversal
//pre : tree exists with nodes
//post : none aside from description
void ShelterBST :: preorder(TreeNode*root){
    if (root != nullptr){
 
        // First print data of node
        cout << root->pet->name << " " << root->pet->age << endl;
    
        // Then recur on left subtree
        preorder(root->left);
    
        // Now recur on right subtree
        preorder(root->right); 
    }
}

//desc : calls the preorder function
//pre : root is initialized
//post : none aside from description
void ShelterBST :: preorderDisplay(){
    preorder(root);
}

//desc : prints the tree in postorder traversal
//pre : tree exists with nodes
//post : none aside from description
void ShelterBST :: postorder(TreeNode*root){
    if (root != nullptr){
 
        // First recur on left subtree
        postorder(root->left);
    
        // Then recur on right subtree
        postorder(root->right);
    
        // Now deal with the node
        cout << root->pet->name << " " << root->pet->age << endl;
    }
}

//desc : calls the postorder function
//pre : root is initialized
//post : none aside from description
void ShelterBST :: postorderDisplay(){
    postorder(root);
}

//desc : finds the number of internal nodes in the tree
//pre : root exists in the tree
//post : returns an integer for the number of internal nodes
int ShelterBST :: internalNodes(TreeNode* root){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return 0; //only one node in BST or when we reach a leaf node
    }
    //recursively iterates until we reach a leaf node
    return 1 + internalNodes(root->left) + internalNodes(root->right);
    
}

//desc : calls the internalNodes function
//pre : root exists
//post : returns the integer for the number of nodes
int ShelterBST :: getInternal(){
    return internalNodes(root);
}

//desc : finds the height of the tree
//pre : tree exists with root node
//post : returns int with tree height
int ShelterBST :: height(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    //iterates on both sides to find the max height
    int left_side, right_side;
    left_side = height(root->left);
    right_side = height(root->right);

    //whichever side is greater in height return
    if(left_side >= right_side){
        return left_side + 1;
    }
    else {
        return right_side + 1;
    }

    //return 0;
}

//desc : calls the height function
//pre : tree exists
//post : returns height - 1 since height starts with 0
int ShelterBST :: findHeight(){
    return height(root)-1;
}

//desc : checks if the tree is balanced (height of sides differ by 1)
//pre : root node exists
//post : returns bool variable for the tree's balance
bool ShelterBST :: isBalanced(TreeNode *root){
    int right, left;
    if(root == nullptr){
        return true;
    }
    //finds the height of both sides
    right = height(root->right);
    left = height(root->left);

    //checks condition for a balanced tree
    if((right-left <= 1 || left-right <=1) 
        && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }

    return false;
}

//desc : calls the balance function
//pre : tree root is initialized
//post : returns bool variable for whether the tree is balanced
bool ShelterBST :: balance(){
    return isBalanced(root);
}

//desc : finds the total number of nodes in the tree
//pre : root node is initialized
//post : retuns the number of nodes in subtrees + the root node
int ShelterBST :: numberOfNodes(TreeNode* root){
    if (root == NULL)
        return 0;
    //counts nodes in left and right subtrees
    int left = numberOfNodes(root->left);
    int right = numberOfNodes(root->right);
 
    return 1 + left + right;
    
}

//desc : calls the numberOfNodes function
//pre : tree exists
//post : returns the integer with the number of nodes
int ShelterBST :: totalNodes(){
    return numberOfNodes(root);
}

//desc : finds the total nodes at a certain level
//pre : root node exists and tree is initialized
//post : returns the number of nodes at given level
int ShelterBST :: nodesAtGivenLevel(TreeNode* root, int level){
    //base cases
    if(root == nullptr){
        return -1;
    }
    if(level == -1){
        return 1;
    }
    //finds the numbers of nodes on the left and right subtrees at the level
    else{
        int left = nodesAtGivenLevel(root->left, level - 1);
        int right = nodesAtGivenLevel(root->right, level -1);
        return left + right;
    }
    return 0;
}

//desc : calls the nodesAtGivenValue function
//pre : tree exists and valid input is provided
//post : integer value is returned
int ShelterBST :: totalNodesAtValue(int level){
    return nodesAtGivenLevel(root, level-1);
}

//desc : function that tests all the commands
//pre : class is defined
//post : all commands are run
void ShelterBST :: runtests(){
    cout << endl;
    //inserting 10 pets with 1 duplicate
    insertPet ("Link", 7);
    insertPet ("Link", 7);//duplicate
    insertPet ("Max", 10);
    insertPet ("Charlie", 1);
    insertPet ("Donut", 3);
    insertPet ("Lily", 4);
    insertPet ("Claire", 9);
    insertPet ("Arlo", 2);
    insertPet ("Sally", 20);
    insertPet ("Mark", 99);


    //searching for a pet
    cout <<"Found the pet: ";
    searchPet("Charlie");     

    //find the parent of a node
    cout << "The parent node is: ";
    findParent("Lil1y");

    //find the predecessor
    findPredecessor("Claire");

    //delete a node in the tree
    //deleteNode(root, "Claire");

    //find the number of nodes in the tree
    cout << "Total number of nodes: " << totalNodes() << endl;

    //find the number of internal nodes
    cout << "There are " << getInternal() << " internal nodes." << endl;

    //find the number of nodes at a given level
    cout << "The total nodes at level 1: " << totalNodesAtValue(1) << endl;

    //find the height of the tree
    cout << "The height of the tree is " << findHeight() << endl;

    //find if the tree is balanced
    if(balance()){
        cout << "The current tree is balanced." << endl;
    }
    else{
        cout << "The current tree is not balanced." << endl;
    }
    cout << endl;

    // inorder display
    cout << "Inorder Display:" << endl;
    inorderDisplay();
    cout << endl;
    // preorder display
    cout << "Preorder Display:" << endl;
    preorderDisplay();
    cout << endl;
    // postorder display
    cout << "Postorder Display:" << endl;
    postorderDisplay();
    cout << endl;

    nodeDelete("Max");
    inorderDisplay();
    cout << endl;

    //destroy the tree after completion
    treeDestroy();
    cout << endl;

}

