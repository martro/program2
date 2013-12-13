#ifndef EFEKTY_H_INCLUDED
#define EFEKTY_H_INCLUDED

element* odbicie_lustrzane poziom(element* first);
{
    element* temp=tymczas();
    wyswietl(lista);
    printf("\nKtory plik odbic?\n");
    while((getchar()) != '\n');
    wybor=getchar();
        temp=pozycja(wybor-1);
    pamiec_strukt(temp);


    for(i=0; i<temp->wys;i++)
        free(temp->obraz[i]);
    free(temp->obraz);
    free(temp->nazwa_pliku);
    free(temp);

}


#endif // EFEKTY_H_INCLUDED
