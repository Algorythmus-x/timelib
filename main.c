/**
 * Tag des Jahres
 * Errechnet nach eingabe eines Datums den Tag des Jahres
 * Autor: Armin
 * Datum: 06.03.2021
 **/

#include <stdio.h>
#include <stdlib.h>

#include "tag_des_jahres.h"

//Main funktion, hier startet das Programm.
//Die finale Ausgabe findet hier statt.
int main(){
    struct dateStruct date;
    date = input_date();
    printf("Tag des Jahres: %i\n", day_of_the_year(date));
    return 0;
}

