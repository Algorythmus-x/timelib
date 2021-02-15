/**
 * Tag des Jahres
 * Autor: Armin
 * Datum: 08.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>

#include "tag_des_jahres.h"


int main(){
    int year = 0;
    int month = 0;
    int day = 0;
    input_date(&year, &month, &day);
    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
