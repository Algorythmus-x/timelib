/**
 * Tag des Jahres
 * Autor: Armin
 * Datum: 25.01.2021
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year){

    return 0;
}

int is_leapyear(int year){
    if(year < 1582){
        return -1;
    }
    if(year % 4 == 0){  //Prüft ob jahr ohne rest durch 4 teilbar ist
        if(year % 100 == 0){    //Prüft ob jahr ohne rest durch 100 teilbar ist
            if(year % 400 == 0){    //Prüft ob jahr ohne rest durch 400 teilbar ist
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int main(){
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
