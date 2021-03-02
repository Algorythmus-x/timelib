/**
 * Tag des Jahres
 * Autor: Armin
 * Datum: 08.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>

#include "tag_des_jahres.h"


int main(){
    struct dateStruct date;
    date = input_date();
    printf("Tag des Jahres: %i\n", day_of_the_year(date));
    return 0;
}

