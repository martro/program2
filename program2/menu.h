#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_01();
void funkcja_menu_02();
void funkcja_menu_32();
void funkcja_menu_33();
void funkcja_menu_34();
void funkcja_menu_42();
void funkcja_menu_43();
void funkcja_menu_44();
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
void funkcja_menu_31()
{
    sobelxy(lista);
}
void funkcja_menu_32()
{
    kontrast(lista);
}
void funkcja_menu_33()
{
    krawedz(lista);
}
void funkcja_menu_34()
{
    zmniejsz_ostrosc(lista);
}
void funkcja_menu_42()
{
    char wybor;
    printf("\nJak obrocic?"
           "\n1 - w lewo"
           "\n2 - w prawo"
           "\n1 - pol obrot\n");
    while((getchar()) != '\n');
    wybor=getchar();

    if (wybor=='1')
    {
        obrot_lewo(lista);
    }
    if (wybor=='2')
    {
        obrot_prawo(lista);
    }
    if (wybor=='3')
    {
    }
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

void funkcja_menu_44()
{
    negatyw(lista);
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
               "31 - SOBEL\n"
               "32 - KONTRAST\n"
               "33 - KRAWEDZ\n"
               "34 - ZMNIEJSZ OSTROSC\n"
               "\n"
               "41 - ZMIANA ROZMIARU OBRAZU\n"
               "42 - ROTACJA OBRAZU\n"
               "43 - LUSTRO\n"
               "44 - NEGATYW\n"
               "\n"
               " 5 - ZAPISZ\n"
               "\n"
               " 6 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==1)||(wybor==2)||(wybor==31)||(wybor==32)||(wybor==33)||(wybor==34)||
                    (wybor==41)||(wybor==42)||(wybor==43)||(wybor==44)||(wybor==5)||(wybor==6))
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
    case 31:
    {
        funkcja_menu_31();
        break;
    }
    case 32:
    {
        funkcja_menu_32();
        break;
    }
    case 33:
    {
        funkcja_menu_33();
        break;
    }
    case 34:
    {
        funkcja_menu_34();
        break;
    }
    case 42:
    {
        funkcja_menu_42();
        break;
    }
    case 43:
    {
        funkcja_menu_43();
        break;
    }
    case 44:
    {
        funkcja_menu_44();
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
