/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 6                                                        ***
*** DUE DATE : 11/16/2022                                                 ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This cpp file contains the member functions for the     *** 
*** BST class                                                             ***
****************************************************************************/
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************************
*** FUNCTION BST                                                          ***
*****************************************************************************
*** DESCRIPTION : This function is the constructor for the class          ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
BST::BST() : root(nullptr){}

/****************************************************************************
*** FUNCTION BST                                                          ***
*****************************************************************************
*** DESCRIPTION : This function is the copy constructor for the class     ***
*** that calls the private memeber function copy                          ***
*** INPUT ARGS  : BST & old                                               ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
BST::BST(const BST &old) : root(nullptr)
{
    copy(old.root);
}

/****************************************************************************
*** FUNCTION ~BST                                                         ***
*****************************************************************************
*** DESCRIPTION : This function is the destructor for the class           ***
*** that calls the private memeber function destroy                       ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
BST::~BST()
{
    destroy(root);
}

/****************************************************************************
*** FUNCTION insert                                                       ***
*****************************************************************************
*** DESCRIPTION : This function inserts an element into the tree.         ***
*** It uses the private memeber function insert to complete the operation  ***
*** INPUT ARGS  : const TElement element                                  ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void BST::insert(const TElement element)
{
    insert(element, root);
}

/****************************************************************************
*** FUNCTION remove                                                       ***
*****************************************************************************
*** DESCRIPTION : This function deletes an element from the tree.         ***
*** It uses the private memeber function remove to complete the operation ***
*** INPUT ARGS  : const TElement element                                  ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void BST::remove(const TElement element)
{
    remove(element, root);
}

/****************************************************************************
*** FUNCTION search                                                       ***
*****************************************************************************
*** DESCRIPTION : This function searches for an element in the tree.      ***
*** It uses the private memeber function search to complete the operation ***
*** INPUT ARGS  : const TElement element                                  ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : TNodePtr                                                *** 
****************************************************************************/
TNodePtr BST::search(const TElement element)const
{
    return search(element, root);
}

/****************************************************************************
*** FUNCTION preView                                                      ***
*****************************************************************************
*** DESCRIPTION : This function views the tree with a pre order traversal ***
*** It uses the private member function preView to complete the operation ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void BST::preView()const
{
    cout << "BEGIN -> ";
    preView(root); 
    cout << "END" << endl;
}

/****************************************************************************
*** FUNCTION inView                                                       ***
*****************************************************************************
*** DESCRIPTION : This function views the tree with a in order traversal  ***
*** It uses the private member function inView to complete the operation  ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void BST::inView()const
{
    cout << "BEGIN -> ";
    inView(root);
    cout << "END" << endl;
}

/****************************************************************************
*** FUNCTION postView                                                     ***
*****************************************************************************
*** DESCRIPTION : This function views the tree with a post order traversal***
*** It uses the private member function postView to complete the operation***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void BST::postView()const
{
    cout << "BEGIN -> ";
    postView(root);
    cout << "END" << endl;
}

void BST::copy(const TNodePtr old)
{
    if(old != nullptr)
    {
        insert(old->element);
        copy(old->left);
        copy(old->right);
    }
}

void BST::destroy(TNodePtr & tree)
{
    if(tree == nullptr)
    {
        delete tree;
    }
    else
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
    tree = nullptr;
}

void BST::removeNode(TNodePtr & tree)
{
    TNodePtr temp;
    if(!tree->left && !tree->right)
    {
        delete tree;
        tree = nullptr;
    }
    else if(tree->left && !tree->right)
    {
        temp = tree;
        tree = tree->left;
        delete temp;
        temp = nullptr;
    }
    else if(!tree->left && tree->right)
    {
        temp = tree;
        tree = tree->right;
        delete temp;
        temp = nullptr;
    }
    else
    { 
        findMinNode(tree->left, temp);
        tree -> element = temp ->element;
        delete temp;
        temp = nullptr;
    }
}

void BST::findMinNode(TNodePtr & tree, TNodePtr & temp)
{
    if(tree->right == nullptr)
    {
        temp = tree;
        tree = tree ->left;
    }
    else findMinNode(tree->right, temp);
}

void BST::insert(const TElement element, TNodePtr & tree)
{
    if(tree == nullptr)
    {
        tree = new(std::nothrow)TNode;
        if(!tree)
        {
            cout << "Memory not allocated from new function." << endl;
            return;
        }
        else tree->element = element;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else
    {
        if(element < tree->element)
            insert(element, tree->left);
        else if(element > tree->element) 
            insert(element, tree->right);
    }
}

void BST::remove(const TElement element, TNodePtr& tree)
{
    if(tree == nullptr)
    {
        cout << "Element " << element << " was not found. No remove performed." << endl; 
        return;
    }   
    else if(element == tree->element)
        removeNode(tree);
    else if(element < tree->element)
        remove(element, tree->left);
    else if(element > tree->element) 
        remove(element, tree->right);
}

TNodePtr BST::search(const TElement element, const TNodePtr tree)const
{
    TNodePtr temp;
    if(tree == nullptr)
    {
        cout << "Element " << element << " was not found in the search" << endl;
        temp = tree;
        return temp;
    }
    else if(element == tree->element)
    {
        temp = tree;
        return temp;
    }
    else if(element < tree->element)
        return search(element, tree->left);
    else if(element > tree->element)
        return search(element, tree->right);
    else return nullptr;
} 

void BST::preView(const TNodePtr tree)const
{
    if (tree == nullptr)
         return;
    cout << tree->element << " -> ";
    preView(tree->left);
    preView(tree->right);

}

void BST::inView(const TNodePtr tree)const
{
    if (tree == nullptr)
        return;
    inView(tree->left);
    cout << tree->element << " -> ";
    inView(tree->right);
}

void BST::postView(const TNodePtr tree)const
{
    if (tree == nullptr)
        return;
    postView(tree->left);
    postView(tree->right);
    cout << tree->element << " -> ";
}
