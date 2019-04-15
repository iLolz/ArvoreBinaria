///Definindo a TreeNode

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
#include "treenode.h"
using namespace std;

template<class NODETYPE>
class Tree {
public:
    Tree();

    void insertNode(const NODETYPE &val);

    void inOrderTraversal() const;

    void searchTree(const NODETYPE &data);

    void removeData(const NODETYPE &data);

    void treeHeigth();
private:
    TreeNode<NODETYPE> *rootPtr;

    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);

    void searchTreeHelper(TreeNode<NODETYPE> *, const NODETYPE &);

    void inOrderHelper(TreeNode<NODETYPE> *) const;

    bool removeDataHelper(TreeNode<NODETYPE> *, NODETYPE) const;

    int treeHeigthHelper(TreeNode<NODETYPE>*);


};

template<class NODETYPE>
Tree<NODETYPE>::Tree() { rootPtr = 0; }

template <class NODETYPE>
void Tree<NODETYPE>::treeHeigth()  {
    int size = treeHeigthHelper(rootPtr);
    std::cout<<size<<" é a altura da árvore!\n";
}

template<class NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value) {
    insertNodeHelper(&rootPtr, value);
}

template<class NODETYPE>
void Tree<NODETYPE>::searchTree(const NODETYPE &data) {
    searchTreeHelper(rootPtr, data);
}

template <class NODETYPE>
void Tree<NODETYPE>::removeData(const NODETYPE &data){

    if(removeDataHelper(&data)){
        cout << "Valor: " <<data<<" removido com sucesso!"<<endl;
    } else {
        cout << "Valor: "<<data<<" não pode ser removido!"<<endl;
    }
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
int Tree<NODETYPE>::treeHeigthHelper(TreeNode<NODETYPE> *root) {

    if (root == nullptr)
        return 0;
    else {
        int lHeight = treeHeigthHelper(root->leftPtr);
        int rHeight = treeHeigthHelper(root->rigthPtr);

        return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    }
}

template<class NODETYPE>
bool Tree<NODETYPE>::removeDataHelper(TreeNode<NODETYPE> *root, NODETYPE data) const {

    if (root == nullptr)
        return false;
    else {
        if(root->getData() == data){
            TreeNode<NODETYPE> auxRoot(0);

            auxRoot.getData();
        }
    }
}








#endif
