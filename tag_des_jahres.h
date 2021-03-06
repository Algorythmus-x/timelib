/**
 * Tag des Jahres
 * Header Datei für ausgelagerte Funktionenen
 * Autor: Armin
 * Datum: 06.03.2021
 **/
#ifndef TAG_DES_JAHRES_H_INCLUDED
#define TAG_DES_JAHRES_H_INCLUDED

struct dateStruct {
    int day;
    int month;
    int year;
};
int day_of_the_year(struct dateStruct date);
int get_days_for_month(int month, int year);
int exists_date(struct dateStruct date);
struct dateStruct input_date();
int is_leapyear(int year);

#endif // TAG_DES_JAHRES_H_INCLUDED
