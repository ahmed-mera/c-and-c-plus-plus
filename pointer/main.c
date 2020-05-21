#include <stdio.h>

#define DIM 3

void pointer(int* p_arr[],int arr [],int dim);

int main(){
    int a [DIM] ;
    int* p_arr[DIM];

   pointer(p_arr, a, DIM);

	return 0;
}

void pointer(int* p_arr[],int arr [],int dim){
  int i;
	//carica l'array
    for(i = 0; i < DIM ; i++){
        arr[i] = DIM - i;
    }
	//assegnare gli indrizzi
    for(i = 0; i < DIM ; i++){
        p_arr[i] = &arr[i];
    }
	printf(" Number \t\t : \t\t address \n");

	//vissulizzare gli elementi
    for( i = 0; i < DIM ;i++)
	{
        printf("\t %d \t\t : \t\t %x \n",*p_arr[i],p_arr[i]);
	}

}

