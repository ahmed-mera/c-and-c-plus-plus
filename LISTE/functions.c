#include "header.h"
/* 1) function create nodo */

nodo* createNodo(){
        int value;
        nodo* newList = (nodo*)malloc(sizeof(nodo));
        printf("inserire il valore del nodo :_ ");
        scanf("%d",&value);
        newList->value = value;
        newList->POINTER = NULL;

    return newList;
}

/* 2) function insert front */

void insertFront (nodo* newList , nodo** head){
      newList->POINTER = *head;
     *head = newList;

}
/* 3) function insert back */

void insertBack (nodo* newList , nodo** head){

    if(*head == NULL){
        *head = newList;
    }else{
        nodo* scorri = *head;
        nodo* back ;
        while(scorri != NULL){
            back = scorri;
            scorri = scorri->POINTER;
            if( scorri == NULL ){
                back->POINTER = newList;
            }
        }
        free(scorri);
        //free(back);
    }
}

/* 4) function delete front*/

void deleteFront ( nodo** head){
       if(*head == NULL){
            printf("LISTA VUOTA :( \n\n");
        }else{
            nodo* HEAD = *head;
            nodo* HEAD_SUCC = HEAD->POINTER;
            *head = HEAD_SUCC;
            free(HEAD);
            //free(HEAD_SUCC);
        }

}

/* 5) function delete back*/

void deleteBack (nodo** head){
        if(*head == NULL){
            printf("LISTA VUOTA :( \n\n");
        }else{
            nodo* HEAD = *head;
            nodo* PREV_POIINTER ;
            if(HEAD->POINTER != NULL){
                while(HEAD->POINTER != NULL ){
                 PREV_POIINTER = HEAD;
                 HEAD = HEAD->POINTER;
                }
                //printf("%x \t %x\n",PREV_POIINTER, HEAD);
                PREV_POIINTER->POINTER = NULL;
            }else{
                *head = NULL;
            }
                free(HEAD);
          }

}


/*6) function menu*/
/*int menu (nodo** head){
    int choose;
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
        deleteFront(createNodo(), &head);
        break;
    case 4:
        deleteBack(createNodo(), &head);
        break;
    case 5:
        show(head);
        break;
    default:
        printf("Number Does not Exist :( try again \n\n");
        menu(&head);
        break;
    }

}*/

/*function show*/
void show(nodo* head){
           if(head == NULL){
            printf("LISTA VUOTA :( \n\n");
        }else{
            nodo* HEAD = head;
            while(HEAD != NULL){
                    printf("\t\t\t\t\t %x | %d \n\n", HEAD, HEAD->value);
                    HEAD = HEAD->POINTER;
            }
        }
}
