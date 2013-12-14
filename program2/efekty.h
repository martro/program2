#ifndef EFEKTY_H_INCLUDED
#define EFEKTY_H_INCLUDED

void lustro_pion(element* first);
void lustro_poziom(element* first);
void obrot_180(element* first);
void obrot_lewo(element* first);
void obrot_prawo(element* first);
void odbicie_prawej(element* first);

void lustro_poziom(element* first)
{
    char wybor;
    int i,j,bufor,polowa;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKtory plik odbic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);
    polowa=zrodlo->szer/2;

    for(j=0; j<zrodlo->wys; j++)
        for(i=0; i<polowa; i++)
        {
            bufor=zrodlo->obraz[j][i];
            zrodlo->obraz[j][i]=zrodlo->obraz[j][zrodlo->szer-1-i];
            zrodlo->obraz[j][zrodlo->szer-1-i]=bufor;
        }
    zrodlo->czy_zmieniony=1;
}

void lustro_pion(element* first)
{
    char wybor;
    int i,j,bufor,polowa;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKtory plik odbic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);
    polowa=zrodlo->wys/2;

    for(j=0; j<polowa; j++)
        for(i=0; i<zrodlo->szer; i++)
        {
            bufor=zrodlo->obraz[j][i];
            zrodlo->obraz[j][i]=zrodlo->obraz[zrodlo->wys-1-j][i];
            zrodlo->obraz[zrodlo->wys-1-j][i]=bufor;
        }
}

void obrot_lewo(element* first)
{
    char wybor;
    element* temp;
    int k,l,i;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKtory plik obrocic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    for (i=1; i<=3; i++)
    {
        zrodlo=pozycja(wybor,lista);

        temp=tymczas(lista);
        temp->szer=zrodlo->wys;
        temp->wys=zrodlo->szer;
        pamiec_strukt(temp);


        for(k=0; k<temp->wys; k++)
            for(l=0; l<temp->szer; l++)
                temp->obraz[k][l]=zrodlo->obraz[temp->szer-1-l][k];
        czysc_obraz(zrodlo);
        zrodlo->obraz=temp->obraz;
        zrodlo->szer=temp->szer;
        zrodlo->wys=temp->wys;
    }
}

void obrot_prawo(element* first)
{
    char wybor;
    element* temp;
    int k,l;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKtory plik obrocic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);

    temp=tymczas(lista);
    temp->szer=zrodlo->wys;
    temp->wys=zrodlo->szer;
    pamiec_strukt(temp);


    for(k=0; k<temp->wys; k++)
        for(l=0; l<temp->szer; l++)
            temp->obraz[k][l]=zrodlo->obraz[temp->szer-1-l][k];
    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;

}

void odbicie_prawej(element* first)
{
    char wybor;
    int i,j;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKtory plik odbic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);

    for(j=0; j<zrodlo->wys; j++)
    {
        for(i=0; i<zrodlo->szer; i++)
        {
            printf("%d ",zrodlo->obraz[j][i]);
        }
        printf("\n");
    }

    printf("\n");

    for(j=0; j<zrodlo->wys; j++)
    {
        for(i=0; i<zrodlo->szer; i++)
        {
            zrodlo->obraz[j][i]=zrodlo->obraz[j][zrodlo->szer-1-i];
        }
        printf("\n");
    }
    printf("\n");

    for(j=0; j<zrodlo->wys; j++)
    {
        for(i=0; i<zrodlo->szer; i++)
        {
            printf("%d ",zrodlo->obraz[j][i]);
        }
        printf("\n");
    }

    getchar();
    getchar();

}


#endif // EFEKTY_H_INCLUDED
