#ifndef EFEKTY_H_INCLUDED
#define EFEKTY_H_INCLUDED

void lustro_poziom(element* first);
void odbicie_prawej(element* first);

void lustro_poziom(element* first)
{
    char wybor;
    int i,j,bufor;
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
            bufor=zrodlo->obraz[j][i];
            zrodlo->obraz[j][i]=zrodlo->obraz[j][zrodlo->szer-1-i];
            zrodlo->obraz[j][zrodlo->szer-1-i]=bufor;
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
