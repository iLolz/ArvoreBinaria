//
// Created by Alencar Antônio on 31/03/19.
//

#ifndef TREENODE_H
#define TREENODE_H

template <class NODETYPE> class Tree; //declaração da árvore

template<class NODETYPE>
class TreeNode {
    friend class Tree <NODETYPE>;

public:
    TreeNode (const NODETYPE &d)
            : leftPtr ( 0 ), data(d), rigthPtr( 0 ){ }
    NODETYPE getData() const { return data;}
private:
    TreeNode<NODETYPE> *leftPtr;     ///Ponteiro árvore esquerda
    NODETYPE data;                  ///Dado do ponteiro
    TreeNode<NODETYPE> *rigthPtr;  ///Ponteiro árvore direita
};

#endif
