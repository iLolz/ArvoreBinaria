
///TESTANDO A CLASSE TREE

#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

int main() {

    Tree<char> intTree;
    char intVal, switchOp, searchValue;

    do {
    cout << "\nSelecione uma opção"
            "\n1)Inserir na árvore"                     ///implementado
            "\n2)Procurar na árvore"                    ///implementado
            "\n3)Percorrer árvore (inOrder)"            ///implementado
            "\n4)Percorrer árvore (Largura)"            //Não implementado
            "\n5)Altura da árvore\n";                   //Não implementado

    cin >> switchOp;

    switch (switchOp) {
        case '1':
            cout << "Digite 10 valores inteiros:" << endl;
            for (int i = 0; i < 10; i++) {
                cin >> intVal;
                intTree.insertNode(intVal);
            }
            break;
        case '2':
            cin >> searchValue;
            intTree.searchTree(searchValue);
                ///PEsquisa
            break;
        case '3':

            cout << "Percorrendo inOrder: ";
            intTree.inOrderTraversal();
            break;
        case '4':
            ///Percorre Largura (Pela "linha" )
            break;
        case '5':
            ///Altura da arvore
            /* erro
             *Undefined symbols for architeture x86_...
             */
            //intTree.treeHeight();
            break;
    }
}while (switchOp!= '0');

    return 0;
}