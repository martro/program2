#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_01();
void funkcja_menu_02();
void funkcja_menu_43();
void funkcja_menu_05();
int menu_glowne();
void podkreslenie(void);
void zatwierdz(void);

void funkcja_menu_01()
{
    temp=wczytaj_z_pliku();
    lista=push(lista,temp);
}

void funkcja_menu_02()
{
    wyswietl(lista);
}

void funkcja_menu_43()
{
    char wybor;
    printf("\nJak odbic?:"
           "\n1 - w poziomie"
           "\n2 - w pionie\n");
    while((getchar()) != '\n');
    wybor=getchar();
    if (wybor=='1')
        lustro_poziom(lista);
    if (wybor=='2')
        lustro_pion(lista);
}

void funkcja_menu_05()
{
    zapisz_liste(lista);
    lista=clear(lista);
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
               "43 - LUSTRO"
               "\n"
               " 5 - ZAPISZ\n"
               "\n"
               " 6 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==1)||(wybor==2)||(wybor==31)||(wybor==32)||(wybor==33)||
                    (wybor==41)||(wybor==42)||(wybor==43)||(wybor==5)||(wybor==6))
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
        break;
    }
    case 2:
    {
        funkcja_menu_02();
        break;
    }
    case 43:
    {
        funkcja_menu_43();
        break;
    }
    case 5:
    {
        funkcja_menu_05();
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
