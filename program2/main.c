#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    struct element *next;
    int dane;
} element;

element *clear(element *first);
element* push(element *first, element *newone);
void wyswietl(element *first);

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
        } while(first!=NULL);
        printf("NULL");
    }
}
