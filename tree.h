///Definindo a TreeNode

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
#include "treenode.h"
#include <vector>
#include <math.h>

using namespace std;

template<class NODETYPE>
class Tree {
public:
    Tree();

    void insertNode(const NODETYPE &val);

    void inOrderTraversal() const;

    void searchTree(const NODETYPE &data);

    void removeData(const NODETYPE &data);

    void inOrderLevel();

    void treeHeigth();

    void applyDSW();

private:
    TreeNode<NODETYPE> *rootPtr;

    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);

    void searchTreeHelper(TreeNode<NODETYPE> *, const NODETYPE &);

    void inOrderHelper(TreeNode<NODETYPE> *) const;

    void inOrderLevelHelper(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *removeDataHelper(TreeNode<NODETYPE> *, NODETYPE) const;

    int treeHeigthHelper(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *valorMinimoNo(TreeNode<NODETYPE> *node) const;

    void printGivenLevel(TreeNode<NODETYPE> *, int level);

    ///FUNÇÕES PARA O DSW

    void applyDSWHelper(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *leftRotate(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *rightRotate(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *createBackbone(TreeNode<NODETYPE> *);

    int nodeCount(TreeNode<NODETYPE> *);

    TreeNode<NODETYPE> *balanceTree(TreeNode<NODETYPE> *, int nNo);

};

template<class NODETYPE>
void Tree<NODETYPE>::applyDSW() {

    TreeNode<NODETYPE> *root = rootPtr;
    applyDSWHelper(root);
}

template<class NODETYPE>
Tree<NODETYPE>::Tree() { rootPtr = 0; }

template<class NODETYPE>
void Tree<NODETYPE>::treeHeigth() {
    int size = treeHeigthHelper(rootPtr);
    std::cout << size << " é a altura da árvore!\n";
}


template<class NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const { inOrderHelper(rootPtr); }

template<class NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value) {
    insertNodeHelper(&rootPtr, value);
}

template<class NODETYPE>
void Tree<NODETYPE>::searchTree(const NODETYPE &data) {
    searchTreeHelper(rootPtr, data);
}

template<class NODETYPE>
void Tree<NODETYPE>::inOrderLevel() {
    inOrderLevelHelper(rootPtr);
}

template<class NODETYPE>
void Tree<NODETYPE>::removeData(const NODETYPE &data) {

    rootPtr = removeDataHelper(rootPtr, data);
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
            cout << "Item " << data << " encontrado na árvore!\n\n";
        } else if (ptr->data > data) {
            searchTreeHelper(ptr->leftPtr, data);
        } else if (ptr->data < data) {
            searchTreeHelper(ptr->rigthPtr, data);
        }
    } else {
        cout << "Item " << data << " não encontrdado! \n\n";
    }
}

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

    if (root == 0)
        return 0;
    else {
        int lHeight = treeHeigthHelper(root->leftPtr);
        int rHeight = treeHeigthHelper(root->rigthPtr);

        return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    }
}


///Remover Item
template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::removeDataHelper(TreeNode<NODETYPE> *root, NODETYPE data) const {

    if (root == 0)
        return root;
    if (data < root->getData())
        root->leftPtr = removeDataHelper(root->leftPtr, data);
    else if (data > root->getData())
        root->rigthPtr = removeDataHelper(root->rigthPtr, data);
    else {
        if (root->leftPtr == NULL) {
            TreeNode<NODETYPE> *aux = root->rigthPtr;
            free(root);
            return aux;
        } else if (root->rigthPtr == 0) {
            TreeNode<NODETYPE> *aux = root->leftPtr;
            free(root);
            return aux;
        }

        TreeNode<NODETYPE> *aux = valorMinimoNo(root->rigthPtr);

        root->data = aux->getData();

        root->rigthPtr = removeDataHelper(root->rigthPtr, aux->data);
    }
    return root;
}

///PAra fazer rotação procura o menor valor
template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::valorMinimoNo(TreeNode<NODETYPE> *node) const {

    TreeNode<NODETYPE> *current = node;

    while (current->leftPtr)
        current = current->leftPtr;

    return current;
}
///Fim do Remover Item

///Mostra pela linha
template<class NODETYPE>
void Tree<NODETYPE>::inOrderLevelHelper(TreeNode<NODETYPE> *root) {

    int h;
    h = treeHeigthHelper(root);
    for (int i = 1; i <= h; i++) {
        cout << "Nível: " << i << endl;
        printGivenLevel(root, i);

    }
}

template<class NODETYPE>
void Tree<NODETYPE>::printGivenLevel(TreeNode<NODETYPE> *root, int level) {
    if (root == 0)
        return;
    if (level == 1)
        cout << root->data << endl;
    else if (level > 1) {
        printGivenLevel(root->leftPtr, level - 1);
        printGivenLevel(root->rigthPtr, level - 1);
    }
}
///Fim do Mostra pela linha

///Inicio do balanceamentoDSW
///Pegar o vetor ordernado

template<class NODETYPE>
void Tree<NODETYPE>::applyDSWHelper(TreeNode<NODETYPE> *ptr) {
    ptr = createBackbone(ptr);

    int size = nodeCount(ptr);

    ptr = balanceTree(ptr, size);

    inOrderLevelHelper(ptr);
}

template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::leftRotate(TreeNode<NODETYPE> *root) {
    if (root->rigthPtr != 0) {
        TreeNode<NODETYPE> *rightChild = root->rigthPtr;
        root->rigthPtr = rightChild->rigthPtr;
        rightChild->rigthPtr = rightChild->leftPtr;
        rightChild->leftPtr = root->leftPtr;
        root->leftPtr = rightChild;

        NODETYPE temp = root->data;
        root->data = rightChild->data;
        rightChild->data = temp;
    }

    return root;
}

template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::rightRotate(TreeNode<NODETYPE> *root) {

    if (root->leftPtr != 0) {
        TreeNode<NODETYPE> *leftChild = root->leftPtr;
        root->leftPtr = leftChild->leftPtr;
        leftChild->leftPtr = leftChild->rigthPtr;
        leftChild->rigthPtr = root->rigthPtr;
        root->rigthPtr = leftChild;

        NODETYPE temp = root->data;
        root->data = leftChild->data;
        leftChild->data = temp;
    }
    return root;
}

template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::createBackbone(TreeNode<NODETYPE> *root) {

    while (root->leftPtr != 0) {
        root = rightRotate(root);
    }
    if (root->rigthPtr != 0) {
        root->rigthPtr = createBackbone(root->rigthPtr);
    }
    return root;
}

template<class NODETYPE>
int Tree<NODETYPE>::nodeCount(TreeNode<NODETYPE> *root) {

    if (root == 0)
        return 0;
    int i = 1;
    while (root->rigthPtr != 0) {
        root = root->rigthPtr;
        i++;
    }
    return i;
}

template<class NODETYPE>
TreeNode<NODETYPE> *Tree<NODETYPE>::balanceTree(TreeNode<NODETYPE> *root, int nNo) {
    int nRotations = floor(log2(nNo));

    TreeNode<NODETYPE> *newRoot = root;

    for (int i = 0; i < nRotations; i++) {
        newRoot = leftRotate(newRoot);
        root = newRoot->rigthPtr;
        for (int j = 0; j < nNo / 2 - 1; j++) {
            root = leftRotate(root);
            root = root->rigthPtr;
        }
        nNo = floor (nNo / 2);
    }
    return newRoot;
}



///Fim do mostra pela linha

#endif
