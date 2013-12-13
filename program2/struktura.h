#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#define NAZWA_PLIKU 30

typedef struct element
{
    struct element *next;
    int szer,wys,kolormax,tryb;
    int** obraz;
} element;



element *lista=NULL;
element *temp;

element* clear(element *first);
element* push(element *first, element *newone);
element* tymczas();
int pamiec_obraz(element* temp);
void pomin_komentarz(char znak, FILE *pFile);
element* wczytaj_z_pliku();
void wyswietl(element *first);

element* clear(element *first)
{
    if (first==NULL)
        return NULL;

    clear (first->next);
    free(first);
    return NULL;
}

int pamiec_obraz(element* temp)
{
    int i;
    temp->obraz=(int**)malloc(sizeof(int*)*temp->wys);
    for (i=0; i<temp->wys; i++)
        temp->obraz[i]=(int*)malloc(sizeof(int)*temp->szer);
    return 0;
}

element* push(element *first, element *newone)
{
    element *temp=first;

    if (first==NULL)
        return newone;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newone;
    return first;
}

void pomin_komentarz(char znak,FILE *pFile )
{
    if (znak=='#')
    {
        while (fgetc(pFile)!='\n');
        printf("\nkoment");
    }
}

element* tymczas()
{
    temp=(element *)malloc(sizeof(element));
    temp->next=NULL;
    temp->kolormax=0;
    temp->szer=0;
    temp->wys=0;
    temp->tryb=0;
    temp->obraz=0;
    return temp;
}

element* wczytaj_z_pliku()
{
    char nazwa[NAZWA_PLIKU],znak;
    int inttym,czy_param=1,x=0,y=0, litera_p=0,ilosc_danych=0,error=0,i=0;

    FILE * pFile;

    element* temp=tymczas();


    /*   if ((dtab->czy_wczytany)==0)
       {*/
    printf("\nPODAJ NAZWE PLIKU: ");
    scanf("%s",nazwa);
    pFile = fopen (nazwa,"r");


    if (pFile!=NULL)
    {
        printf("\nOTWORZONO PLIK\n");


        do
        {
            znak=fgetc(pFile);
            fseek(pFile,-1,SEEK_CUR);

            if (znak=='#')
            {
                while (fgetc(pFile)!='\n');
            }
            if (znak=='P')
            {
                fgetc(pFile);
                fscanf(pFile,"%d",&temp->tryb);
                printf("\n tryb: %d",temp->tryb);
                getchar();
                getchar();
                while (fgetc(pFile)!='\n');
                litera_p=1;
            }
            if ((znak!='#')&&(znak!='P'))
            {
                litera_p=2;
                error=1;
            }
        }
        while((litera_p==0)&&(znak!=EOF));


        if (error==0)
        {

            do //odczyt naglowka
            {
                znak=fgetc(pFile);
                fseek(pFile,-1,SEEK_CUR);

                if (znak=='#')
                {
                    while (fgetc(pFile)!='\n');
                    fseek(pFile,-1,SEEK_CUR);

                }

                if ((znak>='0')&&(znak<='9')&&(temp->szer==0))
                {
                 //   fseek(pFile,-1,SEEK_CUR);
                    printf("\nznak: %c\n",znak);
                    getchar();
                    getchar();
                    fscanf(pFile,"%d %d",&temp->szer,&temp->wys);

                    printf("\n\n\n\n szer: %d, wys %d",temp->szer,temp->wys);
                    getchar();
                    temp->szer=640;
                    getchar();

                    if (fgetc(pFile)!='\n')
                    {
                        error=1;
                        printf("\nBledny naglowek. Zle odczytane wymiary obrazka.");
                        czy_param=0;
                    }
                    fseek(pFile,-1,SEEK_CUR);

                    while (fgetc(pFile)!='\n');
                    fseek(pFile,-1,SEEK_CUR);
                }
                if ((znak>='0')&&(znak<='9')&&(temp->szer))
                {
                    fscanf(pFile,"%d ",&temp->kolormax);
                    printf("\n szer: %d, wys %d",temp->szer,temp->wys);
                    printf("\n kolorek %d",temp->kolormax);
                    fseek(pFile,-1,SEEK_CUR);
                  /*  if (fgetc(pFile)!='\n')
                    {
                        error=1;
                        printf("\nBledny naglowek. Zle odczytany kolor maksymalny.");
                        temp->kolormax=-1;
                        czy_param=0;
                    }*/
                    //fseek(pFile,-1,SEEK_CUR);
                }
            }
            while (temp->kolormax==0); //koniec odczytu naglowka
        }
        else
            printf("\nBledny naglowek. Zle odczytany parametr.");

        if ((czy_param)&&(error==0))
        {
            printf("\nProsze czekac. Trwa pobieranie pliku.\n");
            pamiec_obraz(temp);
            do //pobieranie zawartosci pliku
            {
                do
                {
                    znak=fgetc(pFile);
                  //  printf ("\n %d", znak);
                  //  getchar();
                }
                while ((((znak)<'0')||(znak>'9'))&&(znak!=EOF));
                fseek(pFile,-1,SEEK_CUR);


                if (znak!=EOF)
                {
                    if ((znak>='0')&&(znak<='9'))
                    {
                        if (fscanf(pFile,"%d",&inttym))
                        {
                            ilosc_danych++;
                        }
                        temp->obraz[y][x]=inttym;
                        printf(" [%d][%d]=%d=%d\n",y,x,temp->obraz[y][x],inttym);
                        //getchar();
                     //   getchar();
                        x++;
                        if (x==temp->szer)
                        {
                            x=0;
                            y++;
                        }
                    }

                }
            }
            while (znak!=EOF); //koniec pobierania zawartosci pliku

            if (ilosc_danych!=temp->szer*temp->wys)
            {
                printf("\nIlosc danych nie zgodna z wymiarami obrazka.");
                error=1;
            }

        }

        if (error)
        {
            printf("\nBlad odczytu. Dane nie zostaly wczytane. Plik zostanie zamkniety.");
            temp=NULL;
        }
        else
        {
            printf("Dane zaimportowane poprawnie.");
            printf("\nTryb: P%d ",temp->tryb);
            if (temp->tryb==2)
                printf(" obraz w skali odcieni szarosci");
            if (temp->tryb==5)
                printf(" obraz binarny");
            printf("\nSzerokosc: %d",temp->szer);
            printf("\nWysokosc:  %d",temp->wys);
            printf("\nKolormax:  %d\n",temp->kolormax);
        }
        fclose (pFile);

    }
    else
        printf("\nBLAD ODCZYTU PLIKU. (niepoprawnie wpisana nazwa lub plik nie istnieje)\n");
    /*   }
       else
           printf("\nW buforze znajduje sie juz sygnal. Aby wczytac nowy usun poprzedni.\n");*/

    for(i = 0; i < temp->wys; i++)
        free(temp->obraz[i]);
    free(temp->obraz);
    free(temp);
    return temp;
}

void wyswietl(element *first)
{
    if (first==NULL)
    {
        printf("Lista jest pusta.");
    }

    else
    {
        do
        {
//            printf("[%d]->",first->dane);
            first=first->next;
        }
        while(first!=NULL);
        printf("NULL");
    }
}

#endif // STRUKTURA_H_INCLUDED
