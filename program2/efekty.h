#ifndef EFEKTY_H_INCLUDED
#define EFEKTY_H_INCLUDED

void lustro_pion(element* first);
void lustro_poziom(element* first);
void obrot_180(element* first);
void obrot_lewo(element* first);
void obrot_prawo(element* first);
void odbicie_prawej(element* first);
void sobelx(element* first);

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

void sobelx(element* first)
{
    char wybor;
    element* temp;
    int a,b,c,d,e,f,g,h,i,k,l;
    element* zrodlo;

    wyswietl(lista);
    printf("\nSobel x. Ktory plik?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);

    /*  printf("a=%d",a);
      getchar();
      getchar();*/


    temp=tymczas(lista);
    temp->szer=zrodlo->szer-2;
    temp->wys=zrodlo->wys-2;
    pamiec_strukt(temp);

  //   printf("a=%d",zrodlo->obraz[-1][-1]);
      getchar();
      getchar();

    for(k=1; k<temp->wys-1; k++)
    {
        for(l=1; l<temp->szer-1; l++)
        {
            printf("ok [%d][%d]\n",k,l);
            a=zrodlo->obraz[k-1][l-1];
            b=zrodlo->obraz[k-1][l  ];
            c=zrodlo->obraz[k-1][l+1];
          //  d=zrodlo->obraz[k  ][l-1];
         //   e=zrodlo->obraz[k  ][l  ];
        //    f=zrodlo->obraz[k  ][l+1];
            g=zrodlo->obraz[k+1][l-1];
            h=zrodlo->obraz[k+1][l  ];
            i=zrodlo->obraz[k+1][l+1];

            temp->obraz[k-1][l-1]=a-g;
            temp->obraz[k-1][l  ]=b-h;
            temp->obraz[k-1][l+1]=c-i;
            temp->obraz[k  ][l-1]=2*a-2*g;
            temp->obraz[k  ][l  ]=2*b-2*h;
            temp->obraz[k  ][l+1]=2*c-2*i;
            temp->obraz[k+1][l-1]=a-g;
            temp->obraz[k+1][l  ]=b-h;
            temp->obraz[k+1][l+1]=c-i;
        }
    }

    printf("dotad jest ok\n");
    getchar();
    getchar();
    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;

}


#endif // EFEKTY_H_INCLUDED
