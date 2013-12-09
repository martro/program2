#include <stdio.h>
#include <stdlib.h>
#include "struktura.h"


int main()
{
    int i;
    element *lista=NULL;
    element* temp;

    for (i=0; i<10; i++)
    {
        temp=(element *)malloc(sizeof(element));
        temp->next=NULL;
        temp->dane=i;
        lista=push(lista,temp);
    }

    wyswietl(lista);
    lista=clear(lista);
    wyswietl(lista);
    //wskaznik na dowolny element listy to iterator
    fflush(stdin);
    getchar();
    return 0;
}
