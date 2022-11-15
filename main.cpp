/*****************************************************************************
*** NAME : Jacob Zenner                                                    ***
*** CLASS : CSc 300                                                        ***
*** ASSIGNMENT : 6                                                         ***
*** DUE DATE : 11/16/2022                                                  ***
*** INSTRUCTOR : GAMRADT                                                   ***
******************************************************************************
*** DESCRIPTION : This program implements a Binary Search Tree which uses  ***
*** the memeber functions from BST.cpp and includes the class from BST.h   ***
*****************************************************************************/
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main()
{
    TNode *ptr, *ptr2;
    
    BST tree;
    tree.insert("Alpha");
    tree.insert("Alpha");
    tree.insert("Bravo");
    tree.insert("Charlie");
    tree.insert("Delta");
    tree.insert("Echo");
    tree.insert("Foxtrot");
    cout << "Pre View" << endl;
    tree.preView();
    cout << endl << endl << "In View" << endl;
    tree.inView();
    cout << endl << endl << "Post View" << endl;
    tree.postView();

    cout << endl << "Checking search" << endl;
    ptr = tree.search("Alpha");
    if(ptr != nullptr)
        cout << endl << ptr->element << endl << endl;

    cout << endl << "Checking search" << endl;
    ptr = tree.search("Not");
    if(ptr != nullptr)
         cout << endl << ptr->element << endl << endl;

    tree.remove("Bravo");
    tree.remove("Not");
    cout << endl << "Printing tree after removals" << endl << endl;
    tree.preView();

    BST treeCopy(tree);
    cout << endl << endl << "printing copied tree plus G, H" << endl;
    treeCopy.insert("Golf");
    treeCopy.insert("Hotel");
    treeCopy.remove("Golf");
    treeCopy.preView();

    cout << endl << endl << "printing old tree" << endl;
    tree.preView();

    tree.~BST();
    treeCopy.~BST();
    cout << endl << endl << "Calling destructor and printing both" << endl;
    tree.inView();
    treeCopy.inView();
}
