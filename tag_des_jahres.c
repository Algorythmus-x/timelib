#include <stdio.h>
#include <stdlib.h>
#include "tag_des_jahres.h"

int is_leapyear(int year){
    if(year < 1582 || year > 2400){
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

int get_days_for_month(int month, int year){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(year) == 1){
        daysPerMonth[1] = 29;
    }
    return daysPerMonth[(month) - 1];
}

int exists_date(struct dateStruct date){
    if(is_leapyear(date.year) == -1){
        printf("Ungueltiges Jahr\n\n");
        return 0;
    }
    if(date.month <= 0 || date.month > 12){
        printf("Ungueltiger Monat\n\n");
        return 0;
    }
    else {
        //Überprüfung ob Tag gültig ist
        if(date.day <= 0 || date.day > get_days_for_month(date.month, date.year)){
            printf("Ungueltiger Tag\n\n");
            return 0;
        }
        else {
            return 1;
        }
    }
}

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

int day_of_the_year(struct dateStruct date){
    int sumDays = 0;
    for(int i = 1; i < date.month; i++){
        sumDays = sumDays + get_days_for_month(i, date.year);
    }
    sumDays = sumDays + date.day;
    return sumDays;
}
