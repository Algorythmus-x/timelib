/**
 * Tag des Jahres
 * Autor: Armin
 * Datum: 25.01.2021
 **/

#include <stdio.h>
#include <stdlib.h>

int year = 0;
int month = 0;
int day = 0;
int day_of_the_year(int day, int month, int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
void input_date();
int is_leapyear(int year);


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
        //Überprüfung ob Tag gültig ist
        if(day <= 0 || day > get_days_for_month(month, year)){
            printf("Ungueltiger Tag\n\n");
            return 0;
        }
        else {
            return 1;
        }
    }
}

void input_date(){
    do{
        day = 0;
        month = 0;
        year = 0;
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", &year);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", &month);
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &day);
        fflush(stdin);
    }
    while(exists_date(day, month, year) != 1);
    
}

int day_of_the_year(int day, int month, int year){
    int sumDays = 0;
    for(int i = 1; i < month;i++){
        sumDays = sumDays + get_days_for_month(month, year);
    }
    sumDays = sumDays + day;
    return sumDays;
}

int main(){
    input_date();
    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
