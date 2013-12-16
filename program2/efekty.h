#ifndef EFEKTY_H_INCLUDED
#define EFEKTY_H_INCLUDED

void kontrast(element* first);
void krawedz(element* first);
void lustro_pion(element* first);
void lustro_poziom(element* first);
void obrot_180(element* first);
void obrot_lewo(element* first);
void obrot_prawo(element* first);
void odbicie_prawej(element* first);
void negatyw(element* first);
void zmniejsz_ostrosc(element* first);
void sobelx(element* first);
void sobely(element* first);
void sobelxy(element* first);


void kontrast(element* first)
{
    char wybor;
    int i,j,wartosc;
    long int suma=0;
    double srednia;
    int calk_srednia;
    element* zrodlo;


    wyswietl(lista);
    printf("\nKontrast ktorego obrazu?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);

    for(j=0; j<zrodlo->wys; j++)
        for(i=0; i<zrodlo->szer; i++)
        {
            suma+=zrodlo->obraz[j][i];
        }
    srednia=suma/zrodlo->wys/zrodlo->szer;
    calk_srednia=srednia;
    printf("\nsrednia: %d\n",calk_srednia);
    getchar();
    getchar();


    for(j=0; j<zrodlo->wys; j++)
        for(i=0; i<zrodlo->szer; i++)
        {
            wartosc=zrodlo->obraz[j][i]-zrodlo->kolormax/2;
            if(wartosc>0)
                zrodlo->obraz[j][i]=zrodlo->obraz[j][i]*4;
            else if(wartosc<0)
                zrodlo->obraz[j][i]=zrodlo->obraz[j][i]/4;

            if (zrodlo->obraz[j][i]<0)
                zrodlo->obraz[j][i]=0;
            if (zrodlo->obraz[j][i]>zrodlo->kolormax)
                zrodlo->obraz[j][i]=zrodlo->kolormax;

        }
    zrodlo->czy_zmieniony=1;
}

void krawedz(element* first)
{
    char wybor;
    element* temp;
    int i,j;
    int wspolczynnik=150,warunek;
    element* zrodlo;

    wyswietl(lista);
    printf("\nKrawedzie. Ktory plik?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);


    temp=tymczas(lista);
    temp->szer=zrodlo->szer;
    temp->wys=zrodlo->wys;
    pamiec_strukt(temp);

   for(j=0; j<temp->wys; j++) //wyzerowanie temp
    {
        for(i=0; i<temp->szer; i++)
        {
            temp->obraz[j][i]=zrodlo->kolormax;
        }
    }

    for(j=0; j<zrodlo->wys; j++) //binaryzacja zrodla
    {
        for(i=0; i<zrodlo->szer; i++)
        {
            if (zrodlo->obraz[j][i]>wspolczynnik)
                zrodlo->obraz[j][i]=zrodlo->kolormax;else
                zrodlo->obraz[j][i]=0;

        }
    }


    for(j=1; j<temp->wys-1; j++) //w prawo
    {
        for(i=1; i<temp->szer-1; i++)
        {
            warunek=0;
            if (zrodlo->obraz[j][i]!=zrodlo->obraz[j][i+1])
                warunek=1;
            if (zrodlo->obraz[j][i]!=zrodlo->obraz[j][i-1])
                warunek=1;
            if (zrodlo->obraz[j][i]!=zrodlo->obraz[j+1][i])
                warunek=1;
            if (zrodlo->obraz[j][i]!=zrodlo->obraz[j-1][i])
                warunek=1;

            if (warunek==1)
                temp->obraz[j][i]=0;
            if (warunek==0)
                temp->obraz[j][i]=zrodlo->kolormax;
        }
    }

    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;
    zrodlo->czy_zmieniony=1;
}

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
    zrodlo->czy_zmieniony=1;
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
    zrodlo->czy_zmieniony=1;
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
    zrodlo->czy_zmieniony=1;
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

    zrodlo->czy_zmieniony=1;
}

void negatyw(element* first)
{
    char wybor;
    int i,j;
    element* zrodlo;


    wyswietl(lista);
    printf("\nNegatyw ktorego obrazu?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);


    for(j=0; j<zrodlo->wys; j++)
        for(i=0; i<zrodlo->szer; i++)
        {
            zrodlo->obraz[j][i]=zrodlo->kolormax-zrodlo->obraz[j][i];
        }
    zrodlo->czy_zmieniony=1;
}

void sobelx(element* first)
{
    char wybor;
    element* temp;
    int a,b,c,g,h,i,k,l;
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
    zrodlo->czy_zmieniony=1;
}

void sobely(element* first)
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
            d=zrodlo->obraz[k  ][l-1];
            e=zrodlo->obraz[k  ][l  ];
            f=zrodlo->obraz[k  ][l+1];
            g=zrodlo->obraz[k+1][l-1];
            h=zrodlo->obraz[k+1][l  ];
            i=zrodlo->obraz[k+1][l+1];

            temp->obraz[k-1][l-1]=a+2*d+g;
            temp->obraz[k-1][l  ]=b+2*e+h;
            temp->obraz[k-1][l+1]=c+2*f+i;
            temp->obraz[k  ][l-1]=0;
            temp->obraz[k  ][l  ]=0;
            temp->obraz[k  ][l+1]=0;
            temp->obraz[k+1][l-1]=-a-2*d-g;
            temp->obraz[k+1][l  ]=-b-2*e-h;
            temp->obraz[k+1][l+1]=-c-2*f-i;
        }
    }

    printf("dotad jest ok\n");
    getchar();
    getchar();
    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;
    zrodlo->czy_zmieniony=1;
}

void sobelxy(element* first)
{
    double rzecz;
    int calk;
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
            a=zrodlo->obraz[k-1][l-1];
            b=zrodlo->obraz[k-1][l  ];
            c=zrodlo->obraz[k-1][l+1];
            d=zrodlo->obraz[k  ][l-1];
            e=zrodlo->obraz[k  ][l  ];
            f=zrodlo->obraz[k  ][l+1];
            g=zrodlo->obraz[k+1][l-1];
            h=zrodlo->obraz[k+1][l  ];
            i=zrodlo->obraz[k+1][l+1];

            rzecz=sqrt(pow((a-g),2.)     +pow((a+2*d+g),2.));
            calk=rzecz;
            temp->obraz[k-1][l-1]=calk;

            rzecz=sqrt(pow((b-h),2.)     +pow((b+2*e+h),2.));
            calk=rzecz;
            temp->obraz[k-1][l  ]=calk;

            rzecz=sqrt(pow((c-i),2.)     +pow((c+2*f+i),2.));
            calk=rzecz;
            temp->obraz[k-1][l+1]=calk;

            rzecz=sqrt(pow(2*a-2*g,2.));
            calk=rzecz;
            temp->obraz[k  ][l-1]=calk;

            rzecz=sqrt(pow(2*b-2*h,2.));
            calk=rzecz;
            temp->obraz[k  ][l  ]=calk;

            rzecz=sqrt(pow((2*c-2*i),2.));
            calk=rzecz;
            temp->obraz[k  ][l+1]=calk;

            rzecz=sqrt(pow((a-g),2.)     +pow((-a-2*d-g),2.));
            calk=rzecz;
            temp->obraz[k+1][l-1]=calk;

            rzecz=sqrt(pow((b-h),2.)     +pow((-b-2*e-h),2.));
            calk=rzecz;
            temp->obraz[k+1][l  ]=calk;

            rzecz=sqrt(pow((c-i),2.)     +pow((-c-2*f-i),2.));
            calk=rzecz;
            temp->obraz[k+1][l+1]=calk;
        }
    }

    printf("dotad jest ok\n");
    getchar();
    getchar();
    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;
    zrodlo->czy_zmieniony=1;
}
void zmniejsz_ostrosc(element* first)
{
    double rzecz;
    int calk;
    char wybor;
    element* temp;
    int a,b,c,d,e,f,g,h,i,k,l;
    element* zrodlo;

    wyswietl(lista);
    printf("\nKrawedzie. Ktory plik?\n");
    while((getchar()) != '\n');
    wybor=getchar();
    wybor=wybor-48;

    printf("wybor: %d",wybor);

    zrodlo=pozycja(wybor,lista);


    temp=tymczas(lista);
    temp->szer=zrodlo->szer-2;
    temp->wys=zrodlo->wys-2;
    pamiec_strukt(temp);

    for(k=1; k<temp->wys+1; k++)
    {
        for(l=1; l<temp->szer+1; l++)
        {
            a=zrodlo->obraz[k-1][l-1];
            b=zrodlo->obraz[k-1][l  ];
            c=zrodlo->obraz[k-1][l+1];
            d=zrodlo->obraz[k  ][l-1];
            e=zrodlo->obraz[k  ][l  ];
            f=zrodlo->obraz[k  ][l+1];
            g=zrodlo->obraz[k+1][l-1];
            h=zrodlo->obraz[k+1][l  ];
            i=zrodlo->obraz[k+1][l+1];

            rzecz=a+b+c+d+e+f+g+h+i;
            rzecz=rzecz/9;
            calk=rzecz;

            //     if (e>=calk)
            temp->obraz[k-1][l-1]=calk;

            //     if (e<calk)
            //          temp->obraz[k-1][l-1]=0;

            /*    if ((e>=a)&&(e>=b)&&(e>=c)&&(e>=d)&&(e>=f)&&(e>=g)&&(e>=h)&&(e>=i))
                     temp->obraz[k-1][l-1]=zrodlo->kolormax;
                 if ((e<a)||(e<b)||(e<c)||(e<d)||(e<f)||(e<g)||(e<h)||(e<i))
                     temp->obraz[k-1][l-1]=0;*/
        }
    }


    printf("dotad jest ok\n");
    getchar();
    getchar();
    czysc_obraz(zrodlo);
    zrodlo->obraz=temp->obraz;
    zrodlo->szer=temp->szer;
    zrodlo->wys=temp->wys;
    zrodlo->czy_zmieniony=1;
}

#endif // EFEKTY_H_INCLUDED
