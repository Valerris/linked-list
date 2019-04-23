#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QString>

struct link
{
    QString data;
    link* next;
    link* prev;
};

class LinkedList
{
private:
    link* first;
    link* end;
    int size;
public:
    LinkedList();
    void Add(QString item, int pos);
    void Remove(int pos);
    QString* Display();
    QString* DisplayReverse();
    int Cnt();
};

#endif // LINKEDLIST_H
