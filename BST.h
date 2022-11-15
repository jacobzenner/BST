/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 6                                                        ***
*** DUE DATE : 11/16/2022                                                 ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This program defines a binary search tree where you     ***
*** have insert, remove, search, and different types of view functions    ***
****************************************************************************/
#pragma once
#include <string>

typedef std::string TElement; 
struct TNode;
typedef TNode * TNodePtr; 

struct TNode {
TElement element;
TNodePtr left, right; 
};

class BST { 
    public:

        /****************************************************************************
        *** FUNCTION BST                                                          ***
        *****************************************************************************
        *** DESCRIPTION : This function is the constructor for the BST class      ***
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        BST();

        /****************************************************************************
        *** FUNCTION BST                                                          ***
        *****************************************************************************
        *** DESCRIPTION : This function is the copy constructor for the BST class ***
        *** that calls the private memeber function copy                          ***
        *** INPUT ARGS  : BST & old                                               ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        BST( const BST & );

        /****************************************************************************
        *** FUNCTION ~BST                                                         ***
        *****************************************************************************
        *** DESCRIPTION : This function is the destructor for the BST class       ***
        *** that calls the private memeber function destroy                       ***
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        ~BST();

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
        void insert( const TElement );

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
        void remove( const TElement ); 

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
        TNodePtr search( const TElement ) const; 

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
        void preView() const;

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
        void inView() const;

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
        void postView() const;
private:
        TNodePtr root;
        void copy( const TNodePtr );
        void destroy( TNodePtr & );
        void removeNode( TNodePtr & );
        void findMinNode( TNodePtr &, TNodePtr & );
        void insert( const TElement, TNodePtr & );
        void remove( const TElement, TNodePtr & );
        TNodePtr search( const TElement, const TNodePtr ) const; void preView( const TNodePtr ) const;
        void inView( const TNodePtr ) const;
        void postView( const TNodePtr ) const;
};