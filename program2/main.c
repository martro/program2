/**
*Laboratorium Programowanie w C
*Program obslugujacy grafike pgm
*Prowadzacy: mgr inz. Mariusz Ostrowski
*Marcin Trojan 205608 MTR W-10
    */
#include <stdio.h>
#include <stdlib.h>
#include "struktura.h"
#include "menu.h"


int main()
{
    int dzialaj;
    dprog = (dane_programu *)malloc(sizeof(dane_programu));
    dprog->czy_wczytany=0;
    printf("Laboratorium Programowanie w C\n"
           "Program generujacy sygnaly\n"
           "Prowadzacy: mgr inz. Mariusz Ostrowski\n"
           "Marcin Trojan 205608 MTR W-10\n");

    do
    {

        dzialaj=menu_glowne();
        zatwierdz();
    }
    while (dzialaj);


    free(dprog);
    getchar();
    return 0;
}
