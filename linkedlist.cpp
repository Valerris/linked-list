#include "linkedlist.h"

LinkedList::LinkedList()
{
    first = NULL; end = NULL; size = 0;
}
void LinkedList::Add(QString item, int pos)
{
    link* newElem = new link;
    newElem->data = item;
    newElem->next = first;
    if(first == NULL)
    {
        newElem->next = NULL;
        newElem->prev = NULL;
        first = end = newElem;
        size++;
    }
    else if (pos == 1)
         {
             first->prev = newElem;
             newElem->next = first;
             newElem->prev = NULL;
             first = newElem;
             size++;
         }
         else if (pos > size)
                {
                    end->next = newElem;
                    newElem->prev = end;
                    newElem->next = NULL;
                    end = newElem;
                    size++;
                }
                else {
                    link* current = first;
                    for(int i = 0; i < (pos - 1); i++) { current = current->next; }
                    newElem->next = current;
                    newElem->prev = current->prev;
                    (current->prev)->next = newElem;
                    current->prev = newElem;
                    size++;
                    }

}
void LinkedList::Remove(int pos)
{
    if(pos == 1 && size == 1)
    {
        link* newElem = first;
        first = NULL;
        end = NULL;
        delete newElem;
        size--;
    }
    else if (pos == 1 && size > 1)
    {
        link* newElem = first;
        (first->next)->prev = NULL;
        first = first->next; // начальным элементом делаем узел №2
        delete newElem;
        size--;
    }
    else if (pos >= size)
    {
        link* newElem = end;
        (end->prev)->next = NULL;
        end = end->prev;
        delete newElem;
        size--;
    }
    else
    {
        link* current = first;
        for(int i = 0; i < (pos - 1); i++) { current = current->next; }
        (current->next)->prev = current->prev;
        (current->prev)->next = current->next;
        delete current;
        size--;
    }
}
QString* LinkedList::Display()
{
    link* current = first;
    QString* mas = new QString[size];
    while(current)
    {
    *mas += current->data + " ";
    current = current->next;
    }
    return mas;
}
QString* LinkedList::DisplayReverse()
{
    link* current = end;
    QString* mas = new QString[size];
    while(current)
    {
    *mas += current->data + " ";
    current = current->prev;
    }
    return mas;
}
int LinkedList::Cnt()
{
    return size;
}
