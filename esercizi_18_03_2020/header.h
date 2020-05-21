//
// Created by Ahmed on 18/03/2020.
//

#ifndef ESERCIZI_18_03_2020_HEADER_H
#define ESERCIZI_18_03_2020_HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windef.h>

#define  MAX 20
#define  NAMEFILE "vestiti.txt"
#define  TOTAL "TOTALI.txt"
static char  arrayType [][20] = {"camicia","pantalone", "maglia"} ;
static int dim = 0;

typedef struct vestito {
    unsigned int tipo;
    unsigned int taglia;
    unsigned int quantita;
    float prezzo;
}VS;


typedef struct Vestiti {
    VS vestiti[MAX];
    int count;
}VS_ALL;


bool leggi(char * nomeFile , VS_ALL * ves);

void estrai(unsigned int taglia, VS_ALL vestiti, VS_ALL * vestiti2);

int quant(VS_ALL vestiti);

float prezzo(VS_ALL vestiti);

bool scrivi(char * nomeFile , VS_ALL vestiti);

void errore(int n, char *msg);
#endif //ESERCIZI_18_03_2020_HEADER_H

