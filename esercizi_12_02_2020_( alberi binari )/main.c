#include "header.h"

int main(){
    NODE root = NULL;
    root = readFile(root);

    printf("inorder ===>");
    inorder(root);
    printf("\n");

    printf("preorder ===>");
    preorder(root);
    printf("\n");

    printf("postorder ===>");
    postorder(root);
    printf("\n");


    return 0;
}