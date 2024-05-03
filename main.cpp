//Shreya Gogini
//assignment3.cpp
//Purpose : runs the ShelterBST class by creating an object to call
//          the functions. Asks user for choice when calling the functions

#include <iostream>
#include "ShelterBST.h"

using namespace std;

int main(){
    //creates an instance of the class ShelterBST
    ShelterBST tree;

    bool repeat = true;//variable to continue prompting user
    int choice;//saves users choice
    string pet_name;//gets pet_name from user
    int pet_age;//gets pet_age from user

    //do/while loop runs one instance of the prompt,
    //         then continues based on user input
    do{
        cout << "Welcome to my implementation of ShelterBST" << endl;
        cout << "Please choose the operation you want:" << endl;
        cout << "1. Insert a Node" << endl;
        cout << "2. Search a Value" << endl;
        cout << "3. Delete a Node" << endl;
        cout << "4. View the tree in InOrder" << endl;
        cout << "5. View the tree in PreOrder" << endl;
        cout << "6. View the tree in PostOrder" << endl;
        cout << "7. See the Parent of a Node" << endl;
        cout << "8. See the Predecessor of a Node" << endl;
        cout << "9. See the Number of Nodes in the tree" << endl;
        cout << "10. See the Number of Nodes at a Given Location" << endl;
        cout << "11. See the Number of Internal Nodes" << endl;
        cout << "12. See the Height of the Tree" << endl;
        cout << "13. Check if the tree is balanced" << endl;
        cout << "14. Run the test function" << endl;
        cout << "15. Destroy the Tree" << endl;
        cout << "16. End the Program" << endl;

        cin >> choice;
        
        //variable to use when int input is needed
        int num;

        //based on user's choice, runs through the switch statement
        switch(choice){
            //insert a pet
            case 1:
                cout << "Please enter the name of the pet: ";
                cin >> pet_name;
                cout << endl << "Please enter the age of the pet: ";
                cin >> pet_age;
                cout << endl;
                tree.insertPet(pet_name, pet_age);
                break;
            //search for a pet
            case 2:
                cout << "Please enter the name of the pet you want to search for: ";
                cin >> pet_name;
                tree.searchPet(pet_name);
                cout << endl;
                break;
            //delete a pet
            case 3:
                cout <<"Please enter the name of the pet to remove: ";
                cin >> pet_name;
                tree.nodeDelete(pet_name);
                cout << endl;
                break;
            //view the tree in inorder
            case 4:
                cout << "InOrder Display: " << endl;
                tree.inorderDisplay();
                break;
            //view the tree in preorder
            case 5:
                cout << "PreOrder Display: " << endl;
                tree.preorderDisplay();
                break;
            //view the tree in postorder
            case 6:
                cout << "PostOrder Display: " << endl;
                tree.postorderDisplay();
                break;
            //see the parent node of a pet
            case 7:
                cout << "Please enter the name of the pet to see the parent node: ";
                cin >> pet_name;
                tree.findParent(pet_name);
                cout << endl;
                break;
            //see the predecessor of a node
            case 8:
                cout << "Please enter the name of the pet to see the predecessor: ";
                cin >> pet_name;
                tree.findPredecessor(pet_name);
                break;
            //see the number of total nodes
            case 9:
                cout << "There are " << tree.totalNodes() << " nodes in the tree." << endl;
                break;
            //see the nodes at a given level
            case 10:
                cout << "Please enter the level to get the nodes: ";
                cin >> num;
                cout << endl;
                cout << "There are " << tree.totalNodesAtValue(num) << " nodes at Level " << num << endl;
                break;
            //see the number of internal nodes
            case 11:
                cout <<"The number of internal nodes is: " << tree.getInternal() << endl;
                break;
            //see the height of the tree
            case 12:
                cout << "The height of the tree is: " << tree.findHeight() << endl;
                break;
            //see if the tree is balanced
            case 13:
                if(tree.balance()){
                    cout << "The current tree is balanced." << endl;
                }
                else{
                    cout << "The current tree is not balanced." << endl;
                }
                break;
            //run tests
            case 14:
                cout << "Running tests..." << endl;
                tree.runtests();
                break;
            //destroys the tree
            case 15:
                cout << "Destroying tree..." << endl;
                tree.treeDestroy();
                break;
            //ends the loop
            case 16:
                repeat = false;
                break;
            //checks for invalid input, ends the program
            default:
                cout << "Error. Invalid Input." << endl;
                repeat = false;
                break;
        }
    }while(repeat);

    return 0;
    
}
