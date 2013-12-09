#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu_glowne();
void podkreslenie(void);
void zatwierdz(void);

int menu_glowne()
{
    int wybor;
    char blad_odczytu;

    do
    {
        blad_odczytu=1;
        while((getchar()) != '\n');
        podkreslenie();
        printf("WYBOR AKCJI PROGRAMU\n"
               "1 - WYSWIETL SYGNAL ZNAJDUJACY SIE W BUFORZE\n"
               "2 - ZALADUJ ZAPISANY SYGNAL DO BUFORA\n"
               "3 - ZAPISZ SYGNAL ZNAJDUJACY SIE W BUFORZE\n"
               "\n"
               "4 - GENERUJ SYGNAL\n"
               "5 - USTAW PARAMETRY SYGNALU\n"
               "6 - USUN SYGNAL Z BUFORA\n"
               "\n"
               "7 - ZASZUM SYGNAL\n"
               "8 - ODSZUM SYGNAL\n\n"
               "9 - GENERUJ WYKRES  [Google Charts]\n\n"
               "0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor>=0)&&(wybor<=10))
            {
                printf("Poprawnie odczytano. Twoj wybor to: %d\n",wybor);
                blad_odczytu=0;
                podkreslenie();
            }
            else
            {
                printf("Blad wyboru akcji. Wybierz ponownie.");
                blad_odczytu=1;
            }

        }
        else
        {
            printf("Blad wyboru akcji. Wybierz ponownie.");
            blad_odczytu=1;
        }
    }
    while (blad_odczytu==1);

    switch (wybor)
    {
    case 0:
    {
        break;
    }

    default:
    {
        break;
    }
    }

    return wybor;
}

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    while((getchar()) != '\n');
}

#endif // MENU_H_INCLUDED
