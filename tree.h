///Definindo a TreeNode

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
#include "treenode.h"

using std::endl;

template<class NODETYPE>
class Tree {
public:
    Tree();

    void insertNode(const NODETYPE &val);

    void inOrderTraversal() const;

    void searchTree(const NODETYPE &data);

   // void treeHeight();
private:
    TreeNode<NODETYPE> *rootPtr;

    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);

    void searchTreeHelper(TreeNode<NODETYPE> *, const NODETYPE &);

    void inOrderHelper(TreeNode<NODETYPE> *) const;

   // int treeHeightHelper(TreeNode<NODETYPE>*);

   // int bigger(int a, int b);

};

template<class NODETYPE>
Tree<NODETYPE>::Tree() { rootPtr = 0; }

template<class NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value) {
    insertNodeHelper(&rootPtr, value);
}

template<class NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(
        TreeNode<NODETYPE> **ptr, const NODETYPE &val) {

    if (*ptr == 0) {///árvore vazia
        *ptr = new TreeNode<NODETYPE>(val);
        assert(*ptr != 0);
    } else if (val < (*ptr)->data) {
        insertNodeHelper(&((*ptr)->leftPtr), val);

    } else if (val > (*ptr)->data) {
        insertNodeHelper(&((*ptr)->rigthPtr), val);
    } else {
        std::cout << "Valor " << val << " duplicado" << std::endl;
    }
}
/*template<class NODETYPE>
int Tree<NODETYPE>::treeHeightHelper(TreeNode<NODETYPE> *ptr) {

    if(ptr == 0){
        return  0;
    }
    int leftHeight = treeHeightHelper(ptr->leftPtr);
    int rightHeight = treeHeightHelper(ptr->rigthPtr);

    return (1 + bigger(rightHeight, leftHeight));
}
int bigger( int a, int b){
    return ((a > b) ? a : b);
}
*/
template<class NODETYPE>
void Tree<NODETYPE>::searchTreeHelper(
        TreeNode<NODETYPE> *ptr, const NODETYPE &data) {

    if (ptr != 0) {
        if (ptr->data == data) {
            std::cout << "Objeto \'" << data << "\' está na árvore!\n";
            return;
        } else if (ptr->data > data) {
            searchTreeHelper(ptr->leftPtr, data);
        } else if (ptr->data < data) {
            searchTreeHelper(ptr->rigthPtr, data);
        }
    } else {
        std::cout << "Objeto não encontrado na árvore\n";
    }
}

template<class NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const { inOrderHelper(rootPtr); }

template<class NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *ptr) const {

    if (ptr != 0) {
        inOrderHelper(ptr->leftPtr);
        std::cout << ptr->data << ' ';
        inOrderHelper(ptr->rigthPtr);
    }
}

template<class NODETYPE>
void Tree<NODETYPE>::searchTree(const NODETYPE &data) {
    searchTreeHelper(rootPtr, data);
}
/*
template <class NODETYPE>
void Tree<NODETYPE>::treeHeight()  {
    std::cout<<treeHeightHelper(rootPtr)<<" é a altura da árvore!\n";
}
*/

#endif
