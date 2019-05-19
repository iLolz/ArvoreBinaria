
///TESTANDO A CLASSE TREE

#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

int treeModule() {

    Tree<char> intTree;
    char intVal, switchOp, searchValue;

    do {
        cout << "\nSelecione uma opção\n"
                "\n1)Inserir na árvore"                     ///implementado
                "\n2)Remover da árvore"                     ///implementado
                "\n3)Procurar na árvore"                    ///implementado
                "\n4)Percorrer árvore (inOrder)"            ///implementado
                "\n5)Percorrer árvore (Largura)"            ///implementado
                "\n6)Altura da árvore"                      ///implenebtado
                "\n7)Balanceamento DSW"
                "\n8)Sair";

        cin >> switchOp;

        switch (switchOp) {
            case '1':
                cout << "Digite 10 valores:" << endl;
                for (int i = 0; i < 10; i++) {
                    cin >> intVal;
                    intTree.insertNode(intVal);
                }
                break;
            case '2':
                cout << "Digite o valor a ser removido:" << endl;
                cin >> searchValue;
                intTree.removeData(searchValue);
                break;
            case '3':
                ///Pesquisa
                cin >> searchValue;
                intTree.searchTree(searchValue);
                break;
            case '4':
                ///Percorrer inOrder
                cout << "Percorrendo inOrder: ";
                intTree.inOrderTraversal();
                break;
            case '5':
                cout << "Exibindo por nível: " << endl;
                intTree.inOrderLevel();
                break;
            case '6':
                ///Altura da arvore
                intTree.treeHeigth();
                break;
            case '7':
                intTree.applyDSW();
                break;
            case '8':
                return 0;
                break;
            default:
                cout << "Opção inválida!\n\n";
                break;
        }

    } while (switchOp != '0');

    return 0;
}