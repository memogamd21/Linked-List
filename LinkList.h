#ifndef LINKLIST_H
#define LINKLIST_H


class LinkList
{
    public:
        struct node {
        int data;
        node* next;
};

struct llist{
    node* head;
    node* tail;
    int counter;
};
        int data;
        node* next;
        node* head;
        node* tail;
        int counter;
        llist* createlist();
        bool insertatBeginning(llist* h, int x);
        void printrecursively(node* p;
        llist* InsertatEnd(llist* i, int y);
        llist* InsertatMiddle(llist* t, int q, int n);
        bool DeletefromBeginning(llist* u);
        bool DeletefromEnd(llist* z);
        llist* DeletefromMiddle(llist* a, int n);
        void printlist(llist* b);
        llist* intersection(llist* p1, llist* p2);
        llist* unionoflists(llist* P1, llist* P2);
        llist* reverselist(llist* k);
    protected:

    private:
};

#endif // LINKLIST_H
