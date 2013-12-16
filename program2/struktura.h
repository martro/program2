#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#define NAZWA_PLIKU 30

typedef struct element
{
    char* nazwa_pliku;;
    struct element *next;
    int szer,wys,kolormax,tryb;
    int czy_zmieniony;
    int** obraz;
} element;



element *lista=NULL;
element *temp;

element* clear(element *first);
element* czysc_obraz(element* bierzacy);
element* tymczas();
int pamiec_strukt(element* temp);
void pomin_komentarz(char znak, FILE *pFile);
element* pozycja(int poz,element* first);
element* push(element *first, element *newone);
element* wczytaj_z_pliku();
int rozmiar(element* first);
void wyswietl(element *first);
void zapisz_bufor();
element* zapisz_liste(element* first);

element* clear(element *first)
{
    int i;
    if (first==NULL)
        return NULL;

    clear (first->next);

    for(i = 0; i < first->wys; i++)
        free(first->obraz[i]);
    free(first->obraz);
    free(first->nazwa_pliku);
    free(first);
    return NULL;
}

element* czysc_obraz(element* bierzacy)
{
    int i;
    for(i = 0; i < bierzacy->wys; i++)
        free(bierzacy->obraz[i]);
    free(bierzacy->obraz);
    return NULL;
}


int pamiec_strukt(element* temp)
{
    int i;
    temp->obraz=(int**)malloc(sizeof(int*)*temp->wys);
    for (i=0; i<temp->wys; i++)
        temp->obraz[i]=(int*)malloc(sizeof(int)*temp->szer);
    temp->nazwa_pliku=(char*)malloc(sizeof(char)*NAZWA_PLIKU);
    return 0;
}

void pomin_komentarz(char znak,FILE *pFile )
{
    if (znak=='#')
    {
        while (fgetc(pFile)!='\n');
        printf("\nkoment");
    }
}

element* pozycja(int poz, element* first)
{
    int maks,i;
    maks=rozmiar(first)-1;

    poz--;

    if (poz>maks)
    {
        printf("Podana liczba jest za duza.\n");
        return NULL;
    }
    else if(poz<0)
    {
        printf("Blad. Pozycja musi byc dodatnia.\n");
        return NULL;
    }

    for (i=0; i<poz; i++)
        first = first->next;

    printf("\n\nNazwa pliku: %s\n", first->nazwa_pliku);


    return first;
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

element* tymczas()
{
    temp=(element *)malloc(sizeof(element));
    temp->next=NULL;
    temp->kolormax=0;
    temp->szer=0;
    temp->wys=0;
    temp->tryb=0;
    temp->obraz=0;
    temp->nazwa_pliku=0;
    temp->czy_zmieniony=0;
    return temp;
}

element* wczytaj_z_pliku()
{
    char znak;
    char* nazwa;
    int inttym,czy_param=1,x=0,y=0, litera_p=0,ilosc_danych=0,error=0,i=0;


    nazwa=(char*)malloc(sizeof(char)*NAZWA_PLIKU);
    FILE * pFile;
    element* temp=tymczas();

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

                if (znak=='#')
                {
                    while (fgetc(pFile)!='\n');
                }

                if ((znak>='0')&&(znak<='9')&&(temp->szer==0))
                {
                    fseek(pFile,-1,SEEK_CUR);
                    fscanf(pFile,"%d %d",&temp->szer,&temp->wys);
                }

                if ((znak>='0')&&(znak<='9')&&(temp->szer==0))
                {
                    fscanf(pFile,"%d %d",&temp->szer,&temp->wys);

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
                    fseek(pFile,-1,SEEK_CUR);
                }
            }
            while (temp->kolormax==0); //koniec odczytu naglowka
        }
        else
            printf("\nBledny naglowek. Zle odczytany parametr.");

        if ((czy_param)&&(error==0))
        {
            printf("\nProsze czekac. Trwa pobieranie pliku.\n");
            pamiec_strukt(temp);
            do //pobieranie zawartosci pliku
            {
                do
                {
                    znak=fgetc(pFile);
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
            for(i = 0; i < temp->wys; i++)
                free(temp->obraz[i]);
            free(temp->obraz);
            return NULL;
        }
        else
        {
            printf("Dane zaimportowane poprawnie.");
            printf("\nTryb: P%d ",temp->tryb);
            if (temp->tryb==2)
                printf(" obraz w skali odcieni szarosci\n");
            if (temp->tryb==5)
                printf(" obraz binarny\n");
            printf("\nSzerokosc: %d",temp->szer);
            printf("\nWysokosc:  %d",temp->wys);
            printf("\nKolormax:  %d\n",temp->kolormax);
            temp->next=0;
            temp->nazwa_pliku=nazwa;
            nazwa="\n";
            printf("\nnazwa pliku: %s",temp->nazwa_pliku);
        }
        fclose (pFile);

    }
    else
    {
        printf("\nBLAD ODCZYTU PLIKU. (niepoprawnie wpisana nazwa lub plik nie istnieje)\n");
        return NULL;
    }

    free(nazwa);
    return temp;
}

int rozmiar(element* first)
{
    int i=0;
    while(first!=NULL)
    {
        i++;
        first = first->next;
    }
    return i;
}

void wyswietl(element *first)
{
    int i=0;
    if (first==NULL)
    {
        printf("\nLista jest pusta.");
    }

    else
    {
        printf("Nr\tmodyf\tnazwa\n");
        printf("-------------------------\n");
        do
        {
            i++;
            printf("%d\t",i);
            if (first->czy_zmieniony==0)
                printf("NIE");
            if (first->czy_zmieniony==1)
                printf("TAK");
            printf("\t%s\n",first->nazwa_pliku);
            first=first->next;
        }
        while(first!=NULL);
        printf("-------------------------\n");
    }
}
void zapisz_bufor(element* temp)
{
    int i,j;
    char wybor;
    char* nazwa;
    FILE * pFile;
    nazwa=(char*)malloc(sizeof(char)*NAZWA_PLIKU);

    if (1)
    {
        printf("\nZapis pliku %s",temp->nazwa_pliku);
        printf("\nWybierz akcje:"
               "\n1 - nadpisz"
               "\n2 - nowa nazwa\n");
        while((getchar()) != '\n');
        wybor=getchar();
        printf("\nwybor: %d\n",wybor);
        if (wybor=='1')
            nazwa=temp->nazwa_pliku;
        else
        {
            printf("\nPODAJ NAZWE PLIKU (rozszerzenie: .pgm): ");
            scanf("%s",nazwa);
        }

        printf("\nZapisywanie pod nazwa: %s",nazwa);
        pFile = fopen (nazwa,"w");

        if (pFile!=NULL)
        {
            fprintf(pFile,"P%d\n",temp->tryb);
            fprintf(pFile,"%d %d\n", temp->szer, temp->wys);
            fprintf(pFile,"%d\n",temp->kolormax);


            for (j=0; j<temp->wys; j++)
            {
                for (i=0; i<temp->szer; i++)
                    fprintf(pFile,"%d ",temp->obraz[j][i]);
            }
            free(nazwa);
            fclose (pFile);
            printf("\nZAPISANO\n");
        }
    }
}
element* zapisz_liste(element* first)
{
    int i;

    for(i=0; i<rozmiar(lista); i++)
    {
        if (first->czy_zmieniony)
        zapisz_bufor(first);
        first=first->next;
    }

    return NULL;
}


#endif // STRUKTURA_H_INCLUDED
