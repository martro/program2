#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

typedef struct element
{
    struct element *next;
    int dane;
} element;

element *lista=NULL;
element *temp;

element *clear(element *first);
element *push(element *first, element *newone);
element *tymczas(int dane);
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

element *tymczas(int dane)
{
    temp=(element *)malloc(sizeof(element));
    temp->next=NULL;
    temp->dane=dane;
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
            printf("[%d]->",first->dane);
            first=first->next;
        }
        while(first!=NULL);
        printf("NULL");
    }
}

#endif // STRUKTURA_H_INCLUDED
