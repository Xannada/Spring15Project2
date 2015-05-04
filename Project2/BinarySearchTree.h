#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include "MainHeader.h"

class bTree
{
    private:
        // Node for tree
        struct node
        {
            stadiumNode data;
            node *left;
            node *right;
        };

        node *root;

        // Actual insertion method
        void inorder(node *tree);

    public:
        // Default constructor
        bTree();

        // Method to insert into tree
        void insertStadium(stadiumNode *data);
        void insertTeam(stadiumNode *data);
        void insertCapacity(stadiumNode *data);

        // Method to to inorder traverse of tree
        void inorder();

};

#endif // BINARYSEARCHTREE_H
