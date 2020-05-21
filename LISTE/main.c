#include "header.h" //include the header

int main()
{
    nodo* head = NULL ;
    int choose;
    while(choose != 0){
    printf(" 0) EXIT\n 1) INSERT A HEAD\n 2) INSERT A TAIL\n 3) DELETE FROM HEAD\n 4) DELETE FROM TAIL\n 5) SHOW LISTA\n Choose a number:_");
    scanf("%d",&choose);
    switch(choose){
    case 0 :
        return 0;
        break;
    case 1 :
        insertFront(createNodo(), &head);
        break;
    case 2 :
        insertBack(createNodo(), &head);
        break;
     case 3 :
        deleteFront(&head);
        break;
    case 4:
        deleteBack(&head);
        break;
    case 5:
        show(head);
        break;
    default:
        printf("Number Does not Exist :( try again \n\n");
        break;
    }
    printf("\n\n");
}

    return 0;
}



