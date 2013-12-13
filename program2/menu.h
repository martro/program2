#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_01();
int menu_glowne();
void podkreslenie(void);
void zatwierdz(void);

void funkcja_menu_01()
{
    wczytaj_z_pliku();
<<<<<<< HEAD
<<<<<<< HEAD
    printf("odczyt: %d.............",temp->kolormax);
=======
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
=======
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
}

void funkcja_menu_02(element* first, element* newone)
{
<<<<<<< HEAD
<<<<<<< HEAD
    int i;
printf("odczyt: %d",temp->kolormax);
lista=push(lista,temp);
printf("odczyt: %d",lista->kolormax);

    for(i = 0; i < temp->wys; i++)
    wyswietl(lista);
        free(temp->obraz[i]);
    free(temp->obraz);
    free(temp);
getchar();
=======
    /*element* temp=malloc(sizeof(element));
    temp=(element *)malloc(sizeof(element));*/
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
=======
    /*element* temp=malloc(sizeof(element));
    temp=(element *)malloc(sizeof(element));*/
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
}

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
               " 1 - WCZYTAJ OBRAZ\n"
               " 2 - WYSWIETL OBRAZY\n"
               "\n"
               "31 - FILTR PIERWSZY\n"
               "32 - FILTR DRUGI\n"
               "33 - FILTR TRZECI\n"
               "\n"
               "41 - ZMIANA ROZMIARU OBRAZU\n"
               "42 - ROTACJA OBRAZU\n"
               "\n"
               " 5 - ZAPISZ\n"
               "\n"
               " 6 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==1)|(wybor==2)|(wybor==31)|(wybor==32)|(wybor==33)|(wybor==41)|(wybor==42)|(wybor==5)|(wybor==6))
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
    case 1:
    {
        funkcja_menu_01();
<<<<<<< HEAD
<<<<<<< HEAD
        break;
    }
    case 2:
    {
        funkcja_menu_02(lista,temp);
=======
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
=======
>>>>>>> 4b7d866aeb5098e99f2325fa4cfcd2c7f3f0061f
        break;
    }
    case 6:
    {
        return 0;
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
