/**
*Laboratorium Programowanie w C
*Program obslugujacy grafike pgm
*Prowadzacy: mgr inz. Mariusz Ostrowski
*Marcin Trojan 205608 MTR W-10
    */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "struktura.h"
#include "efekty.h"
#include "menu.h"



int main()
{
    int dzialaj;
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

    getchar();
    return 0;
}
