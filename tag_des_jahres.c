#include <stdio.h>
#include <stdlib.h>
#include "tag_des_jahres.h"

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

int get_days_for_month(int month, int year){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(year) == 1){
        daysPerMonth[1] = 29;
    }
    return daysPerMonth[(month) - 1];
}

int exists_date(int day, int month, int year){
    if(is_leapyear(year) == -1){
        printf("Ungueltiges Jahr\n\n");
        return 0;
    }
    if(month <= 0 || month > 12){
        printf("Ungueltiger Monat\n\n");
        return 0;
    }
    else {
        //�berpr�fung ob Tag g�ltig ist
        if(day <= 0 || day > get_days_for_month(month, year)){
            printf("Ungueltiger Tag\n\n");
            return 0;
        }
        else {
            return 1;
        }
    }
}

void input_date(int *year, int *month, int *day){
    do{
        *day = 0;
        *month = 0;
        *year = 0;
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", year);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", month);
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", day);
        fflush(stdin);
    }
    while(exists_date(*day, *month, *year) != 1);

}

int day_of_the_year(int day, int month, int year){
    int sumDays = 0;
    for(int i = 1; i < month;i++){
        sumDays = sumDays + get_days_for_month(i, year);
    }
    sumDays = sumDays + day;
    return sumDays;
}
