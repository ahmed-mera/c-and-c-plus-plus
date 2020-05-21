//
// Created by Ahmed on 18/03/2020.
//

#include "header.h"

bool leggi(char * nomeFile , VS_ALL * ves) {
    int i = 0;
    FILE * FP = fopen(nomeFile, "r");
    if(!FP) {
       printf("file non trovato :(\n");
        return false;
    }

    (*ves).count = 0;
    while (! feof(FP) ){
        fscanf(FP,"%d %d %d %f", &(*ves).vestiti[i].tipo, &(*ves).vestiti[i].taglia, &(*ves).vestiti[i].quantita, &(*ves).vestiti[i].prezzo);
        (*ves).count++;
    }
    fclose(FP);
    return true;
}

void estrai(unsigned int taglia, VS_ALL vestiti, VS_ALL * vestiti2){
    (*vestiti2).count = 0;
    for (int i = 0; i < vestiti.count ; ++i) {
        if(taglia == vestiti.vestiti[i].taglia){
            (*vestiti2).vestiti[(*vestiti2).count].taglia = vestiti.vestiti[i].taglia;
            (*vestiti2).vestiti[(*vestiti2).count].tipo = vestiti.vestiti[i].tipo;
            (*vestiti2).vestiti[(*vestiti2).count].prezzo = vestiti.vestiti[i].prezzo;
            (*vestiti2).vestiti[(*vestiti2).count].quantita = vestiti.vestiti[i].quantita;
            (*vestiti2).count++;
        }
    }
}

int quant(VS_ALL vestiti) { return vestiti.count;}

float prezzo(VS_ALL vestiti) {
    float sum = 0;
    for (int i = 0; i < vestiti.count ; ++i) {
        sum += vestiti.vestiti[i].prezzo;
    }
    return sum;
}

bool scrivi(char * nomeFile , VS_ALL vestiti) {
    FILE *FP = fopen(nomeFile, "a");
    if(!FP){ return false; }
    VS_ALL v;
    int count;
    float sum;
    for (int i = 0; i < vestiti.count ; ++i) {
        if(vestiti.vestiti[i].taglia >= 42 && vestiti.vestiti[i].taglia <= 54 ){
            estrai(vestiti.vestiti[i].taglia , vestiti , &v);
            count = quant(v);
            sum = prezzo(v);
            fprintf(FP , "%d\t %d\t %.2f\n" , vestiti.vestiti[i].taglia, count, sum);
        }
    }
    fclose(FP);
    return true;
}

void errore(int n, char * msg){
    printf("%s\n",msg);
    exit(n);
}
