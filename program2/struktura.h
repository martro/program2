#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#define NAZWA_PLIKU 30

typedef struct element
{
    struct element *next;
    int dane;
} element;

typedef struct
{
    int czy_wczytany;
    int *tab;
} dane_programu;

element *lista=NULL;
element *temp;
dane_programu *dprog;

element *clear(element *first);
element *push(element *first, element *newone);
element *tymczas(int dane);
void pomin_komentarz(char znak, FILE *pFile);
void wczytaj_z_pliku(dane_programu *dtab);
void wyswietl(element *first);

element *clear(element *first)
{
    if (first==NULL)
        return NULL;

    clear (first->next);
    free(first);
    return NULL;
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

element *tymczas(int dane)
{
    temp=(element *)malloc(sizeof(element));
    temp->next=NULL;
    temp->dane=dane;
    return temp;
}

void wczytaj_z_pliku(dane_programu *dtab)
{
    char nazwa[NAZWA_PLIKU],znak;
    int inttym,szer=0,wys,czy_param=1,tryb,kolormax=0,licznik=0;

    FILE * pFile;

    if ((dtab->czy_wczytany)==0)
    {
        printf("\nPODAJ NAZWE PLIKU: ");
        scanf("%s",nazwa);
        pFile = fopen (nazwa,"r");


        if (pFile!=NULL)
        {
            printf("\nOTWORZONO PLIK\n");

            do //odczyt naglowka
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
                    fscanf(pFile,"%d",&tryb);
                    while (fgetc(pFile)!='\n');
                }
                if ((znak>='0')&&(znak<='9')&&(szer==0))
                {
                    fscanf(pFile,"%d %d",&szer,&wys);

                    if (fgetc(pFile)!='\n')
                    {
                        printf("bledny naglowek");
                        getchar();
                        getchar();
                        szer=-1;
                        wys=-1;
                        czy_param=0;
                    }
                    fseek(pFile,-1,SEEK_CUR);

                    while (fgetc(pFile)!='\n');
                    fseek(pFile,-1,SEEK_CUR);
                }
                if ((znak>='0')&&(znak<='9')&&(szer))
                {
                    fscanf(pFile,"%d ",&kolormax);
                    fseek(pFile,-1,SEEK_CUR);
                    if (fgetc(pFile)!='\n')
                    {
                        printf("bledny naglowek");
                        getchar();
                        getchar();
                        kolormax=-1;
                        czy_param=0;
                    }
                    fseek(pFile,-1,SEEK_CUR);
                }
            }
            while (kolormax==0); //koniec odczytu naglowka

            printf("\nTryb: P%d ",tryb);
            if (tryb==2)
                printf(" obraz w skali odcieni szarosci");
            if (tryb==5)
                printf(" obraz binarny");
            printf("\nSzerokosc: %d",szer);
            printf("\nWysokosc:  %d",wys);
            printf("\nKolormax:  %d\n",kolormax);
            getchar();
            getchar();

            if (czy_param)
            {
                do //pobieranie zawartosci pliku
                {
                    znak=fgetc(pFile);
                    fseek(pFile,-1,SEEK_CUR);

                    if (znak=='#')
                    {
                        while (fgetc(pFile)!='\n');
                        printf("\nkoment");
                    }
                    if (znak!='#')
                    {
                        if (licznik==0)
                            printf("\n");
                        fgetc(pFile);
                        fscanf(pFile,"%d",&inttym);
                        printf("%d ",inttym);
                        licznik++;
                        licznik=licznik%szer;
                    }
                    dprog->czy_wczytany=1;
                }
                while (znak!=EOF); //koniec pobierania zawartosci pliku
            }
            else
                printf("\nNiepoprawny naglowek. Dne nie zostaly wczytane.");

            fclose (pFile);

        }
        else
            printf("\nBLAD ODCZYTU PLIKU. (niepoprawnie wpisana nazwa lub plik nie istnieje)\n");
    }
    else
        printf("\nW buforze znajduje sie juz sygnal. Aby wczytac nowy usun poprzedni.\n");
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
            printf("[%d]->",first->dane);
            first=first->next;
        }
        while(first!=NULL);
        printf("NULL");
    }
}

#endif // STRUKTURA_H_INCLUDED
