/**
 * Tag des Jahres
 * Datei, in der die Funktionen stehen die ben�tigt werden
 * Autor: Armin
 * Datum: 06.03.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include "tag_des_jahres.h"

/** Bekommt eine Jahreszahl �bergeben und �berpr�ft diese dann, ob es sich um ein Schaltjar handelt oder nicht.
 *  Returned -1 wenn es sich um ein ungltiges Jahr handelt.
 *  Returned 1 wenn es sich um ein Schaltjahr handelt.
 *  Returned 0 wenn es kein Schaltjahr ist.
 **/
int is_leapyear(int year){
    if(year < 1582 || year > 2400){
        return -1;
    }
    if(year % 4 == 0){  //Pr�ft ob jahr ohne rest durch 4 teilbar ist
        if(year % 100 == 0){    //Pr�ft ob jahr ohne rest durch 100 teilbar ist
            if(year % 400 == 0){    //Pr�ft ob jahr ohne rest durch 400 teilbar ist
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

/** Errechnet die Tage die ein Monat hat, dazu werden Monat und Jahr �bergeben.
 *  Returned die Anzahl von Tagen die ein Monat hat.
 **/
int get_days_for_month(int month, int year){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //Wenn Schaltjahr wird Februar auf 29 Tage gesetzt
    if(is_leapyear(year) == 1){
        daysPerMonth[1] = 29;
    }
    return daysPerMonth[(month) - 1];
}

/** �berpr�ft, ob das angegebene Datum exsistiert. Das gesammte Datum wird ein einem struct dateStruct �bergeben.
 *  Returned 0 wenn Datum nicht g�ltig.
 *  Returned 1 wenn Datum ist g�ltig.
 **/
int exists_date(struct dateStruct date){
    //�berpr�ft ob Jahr g�ltig ist
    if(is_leapyear(date.year) == -1){
        printf("Ungueltiges Jahr\n\n");
        return 0;
    }
    //�berpr�ft ob Monat g�ltig ist
    if(date.month <= 0 || date.month > 12){
        printf("Ungueltiger Monat\n\n");
        return 0;
    }
    else {
        //�berpr�fung ob Tag g�ltig ist
        if(date.day <= 0 || date.day > get_days_for_month(date.month, date.year)){
            printf("Ungueltiger Tag\n\n");
            return 0;
        }
        else {
            return 1;
        }
    }
}

/** Liest die Eingaben des Nutzers mit Aufforderung ein.
 *  Datum wird so lange eingelesen bis es ein g�ltiges Datum eingegeben wurde.
 *  Returned ein struct dateStruct, in dem das eingegebene Datum gespeichert wird.
 **/
struct dateStruct input_date(){
    struct dateStruct date;
    do{
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", &date.year);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", &date.month);
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &date.day);
        fflush(stdin);
    }
    while(exists_date(date) != 1);
    return date;
}

/** Errechnet den Tag des Jahres. Das gesammte Datum wird ein einem struct dateStruct �bergeben.
 *  Returned die Anzahl von Tagen die das Jahr schon hat nach dem eingegebenen Datum.
 **/
int day_of_the_year(struct dateStruct date){
    int sumDays = 0;
    for(int i = 1; i < date.month; i++){
        sumDays = sumDays + get_days_for_month(i, date.year);
    }
    sumDays = sumDays + date.day;
    return sumDays;
}
