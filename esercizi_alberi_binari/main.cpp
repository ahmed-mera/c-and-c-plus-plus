#include "tree.h"
static int count = 0;
int main() {
    tree TREE;
    
    TREE.readTreeFromFile(*& TREE.ROOT);
    cout << "\t\t\t albero acricato dal file\n\n" << endl;


    int choose = 1, enterValue , lvl;

            while (choose != 0){
                //menu
                cout << "\n1) Inserire un elemento"
                        "\n2) Visulizzaione dell'albero INORDER "
                        "\n3) Visulizzaione dell'albero POSTORDER "
                        "\n4) Visulizzaione dell'albero PREORDER "
                        "\n5) Cercare un elemento "
                        "\n6) Conta Foglia "
                        "\n7) Visulizzare la lista dei numeri duplicati "
                        "\n8) La media dei valore delle foglia "
                        "\n9) Somma dei valori di un levello "
                        "\n10) Salva l'albero "
                        "\n0) EXIT\n";
                cout << "scegli:_ ";
                cin >> choose;
                cin.ignore();

                switch (choose){
                    case 0:
                        TREE.saveTreeToFile(TREE.ROOT);
                        TREE.file.close();
                        TREE.saveListToFile(TREE.ROOT);
                        TREE.listFile.close();
                        cout << "a presto ;) " << endl;
                        exit(0);
                    case 1:
                        system("cls");
                        cout << "Inserire il numero :_";
                        cin >> enterValue;
                        cin.ignore();
                        TREE.ROOT = TREE.insert(TREE.ROOT,enterValue);
                        count = 0;
                        cout << "elemento inserito con successo ;) " << endl;
                        break;
                    case 2:
                        system("cls");
                        TREE.inorder(TREE.ROOT);
                        if(!count){
                            TREE.level = 0;
                            TREE.assignedLvl(TREE.ROOT); // assign level
                            count++;
                        }
                        break;
                   case 3:
                        system("cls");
                        TREE.postorder(TREE.ROOT);
                        if(!count){
                            TREE.level = 0;
                            TREE.assignedLvl(TREE.ROOT); // assign level
                            count++;
                        }
                        break;
                    case 4:
                        system("cls");
                        TREE.preorder(TREE.ROOT);
                        if(!count){
                            TREE.level = 0;
                            TREE.assignedLvl(TREE.ROOT); // assign level
                            count++;
                        }
                        break;
                    case 5:
                        system("cls");
                        cout << "Inserire il numero da ricercare :_";
                        cin >> enterValue;
                        cin.ignore();
                        lvl = TREE.search(TREE.ROOT , enterValue) ;
                        ( lvl != -1 ) ? cout << "elemnto in levello => " << lvl <<endl : cout << " elemento non esiste :(\n";
                        break;
                    case 6:
                        TREE.COUNTLEAVES(TREE.ROOT);
                        cout << "Foglia => " << TREE.countLeaves << endl;
                        break;
                    case 7:
                        system("cls");
                        TREE.showLists(TREE.ROOT);
                        break;
                    case 8:
                        system("cls");
                        cout << " la media delle foglia =" << TREE.averageLeaves() << endl;
                        break;
                    case 9:
                        system("cls");
                        cout << "Inserire il levello :_";
                        cin >> enterValue;
                        cin.ignore();

                        if(!count){
                            TREE.level = 0;
                            TREE.assignedLvl(TREE.ROOT); // assign level
                            count++;
                        }

                        TREE.sumValueLevel(TREE.ROOT, enterValue);
                        cout << " la somma = " << TREE.sumLevel << endl;
                        break;
                    case 10:
                        system("cls");
                        TREE.saveTreeToFile(TREE.ROOT);
                        TREE.file.close();
                        TREE.saveListToFile(TREE.ROOT);
                        TREE.listFile.close();
                        cout << " abero salvato ;) "<< endl;
                        break;
                    default:
                        cout << "numero non esiste :(\n" <<endl;
                        break;
                }
            }
//    for (int i = 0; i < 10; ++i) {
//         TREE.ROOT = TREE.insert(TREE.ROOT, i + 1);
//    }
//    TREE.ROOT = TREE.insert(TREE.ROOT,5);
//     TREE.insert(TREE.ROOT,51);
//     TREE.insert(TREE.ROOT,3);
//     TREE.insert(TREE.ROOT,2);
//     TREE.insert(TREE.ROOT,53);
//     TREE.insert(TREE.ROOT,50);
//
//
//    TREE.inorder(TREE.ROOT);
//    TREE.COUNTLEAVES(TREE.ROOT);
//    TREE.assignedLvl(TREE.ROOT);
//    cout<<endl<< TREE.sumValueLevel(TREE.ROOT , 1);
//    cout<<endl<< TREE.sumLevel;

//    cout << TREE.level << endl;
//    cout << TREE.ROOT->left->left->level << endl;
//    cout << TREE.ROOT->right->left->level<< endl;
    return 0;
}
