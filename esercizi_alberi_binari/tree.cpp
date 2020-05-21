//
// Created by Ahmed on 20/02/2020.
//

#include "tree.h"

tree::tree() {
    /* initialize my variables */
    tree::countNodes = 0;
    tree::countLeaves = 0;
    tree::sumLeaves = 0;
    tree::level = 0;
//    tree::avg = 0;
    tree::sumLevel = 0;
    this->ROOT = nullptr;
}

tree::NODE tree::creatNode(int value) {
    NODE newNode = new struct node;
    newNode->value = value;
    if(! this->countNodes)
        newNode->level = this->level++;
    newNode->left = nullptr;
    newNode->right = nullptr;
    tree::countNodes++; // count node

    return newNode;
}

list <int> tree::createList(list<int> List , int value) {
    List.push_back(value);
    return List;
}

void tree::preorder(tree::NODE root) {
    if (root == nullptr)
        return;
    cout << root->value << " \t";
    preorder(root->right);
    preorder(root->left);
}

void tree::postorder(tree::NODE root) {
    if(root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " \t";
}

void tree::inorder(tree::NODE root) {
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->value << " \t";
    inorder(root->right);
}

int tree::search(tree::NODE root, int value) {
    if (root == nullptr )
        return -1;
    if (root->value == value)
        return root->level; // element is found
    if (root->value > value)
        return search(root->left , value);
    if (root->value < value)
        return search(root->right, value);
}

tree::NODE tree::insert(tree::NODE root , int value ) {
    if (root == nullptr) {
        return creatNode(value);
    }
    if(root->value == value){
        root->list = createList(root->list,value);
        return root;
    }
    if (root->value > value) {
        root->left = insert(root->left, value);
    }

    if (root->value < value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void tree::saveTreeToFile(NODE root) {
    if(root != nullptr){

        if(! tree::file.is_open())
            tree::file.open("tree.txt", ios::out);

//    tree::file.write((char *) &root->value , sizeof(int));
        tree::file << root->value << " ";

        saveTreeToFile(root->right);
        saveTreeToFile(root->left);

    }

}

void tree::saveListToFile(tree::NODE root) {
    if(root != nullptr) {
        if(! tree::listFile.is_open())
            tree::listFile.open("list.txt", ios::out);

        if(! root->list.empty()){ // check if list exist
            for (auto i : root->list) {
//                tree::listFile.write((char *) &i , sizeof(int));
                tree::listFile << i << " ";
            }
        }
        saveListToFile(root->right);
        saveListToFile(root->left);
    }

}


void tree::readTreeFromFile(NODE & root) {
    int num = 0;
    //check file if opn or not
    if(! tree::listFile.is_open())
        tree::listFile.open("list.txt", ios::in) ;

    //check file if opn or not
    if(! tree::file.is_open())
        tree::file.open("tree.txt", ios::in);

    while (! tree::file.eof()){ // read value of file
//        tree::file.read((char *) &num , sizeof(int));
        tree::file >> num;
        root = tree::insert(root , num);
    }

    while (! tree::listFile.eof()){ //read list value from file
        tree::listFile >> num;
//        tree::listFile.read((char *) num , sizeof(int));

        root = tree::insert(root , num);
    }
     tree::file.close(); //close file
    tree::listFile.close();
}

void tree::COUNTLEAVES(NODE root) {
    if (root == nullptr) return;
    if(root->right == nullptr && root->left == nullptr ){
        this->countLeaves++;
        this->sumLeaves += root->value;
    }

    COUNTLEAVES(root->left);
    COUNTLEAVES(root->right);
}

void tree::showLists(tree::NODE root) {
    if(root == nullptr) return;
    if(!root->list.empty()){
        cout << "Node is number = " << root->value << " => ";
        for (auto i : root->list) {
            cout << i << " \t";
        }
        cout << endl;
    }
    showLists(root->left);
    showLists(root->right);
}

float tree::averageLeaves() { return ( (float ) this->sumLeaves / (float) this->countLeaves ); }

void tree::assignedLvl(tree::NODE root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)  ) return;
    if(root->left)
        root->left->level = this->level++;
    if(root->right)
        root->right->level = (root->left) ? root->left->level : this->level++;
    assignedLvl(root->left);
    assignedLvl(root->right);
}

int tree::sumValueLevel(NODE root ,int Level) {
        if (root == nullptr || root->level > Level) return 1;
        if(root->level == Level)
            this->sumLevel += root->value;
        sumValueLevel(root->left , Level);
        sumValueLevel(root->right , Level);
}



