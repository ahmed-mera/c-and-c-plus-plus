#include "header.h"

int main() {
    VS_ALL v;
    if ( leggi(NAMEFILE,&v) == TRUE)
    {
        if (scrivi(TOTAL, v) == FALSE)
            errore(2,"Impossibile scrivere il file TOTALI.TXT");
        exit(0);
    }else {
        errore(1,"Impossibile leggere il file VESTITI.TXT");
}


    return 0;
}
