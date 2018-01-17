#include "LinkList.h"
#include <iostream>
#include <cstdlib>

using namespace std;


LinkList::llist* LinkList::createlist(){
     llist* temp = new llist();
     temp->head = NULL;
     temp->tail->next = NULL;
     temp->counter = 0;
    return temp;
}
bool LinkList::insertatBeginning(llist* h, int x){
    node* temp2 = new node();
    if(temp2 == NULL){return false;}
    else {
    temp2->data = x;
    temp2->next = h->head;
    h->head = temp2;
    h->counter ++;
    return true;
    }
}
LinkList::llist* LinkList::InsertatEnd(llist* i, int y){
    node* temp3 = new node();
    temp3->data = y;
    temp3->next = NULL;
    node* currentnode = i->head;
    while(currentnode != NULL ){
        currentnode = currentnode->next;
    }
    currentnode->next = temp3;
    i->counter ++;
    return i;
}
LinkList::llist* LinkList::InsertatMiddle(llist* t, int q, int n){
    node* addednode = new node();
    addednode->data = q;
    if(n==1){
        addednode->next = t->head;
        t->head = addednode;
        t->counter ++;
        return t;
    }
    node* currentnode = t->head;
    for(int i=0; i<n-2; i++){
        currentnode = currentnode->next;
    }
    addednode->next = currentnode->next;
    currentnode->next = addednode;
    t->counter ++;
    return t;
}
bool LinkList::DeletefromBeginning(llist* u){
    node* deletednode = u->head;
    if(deletednode == NULL){
        return false;
    }
    u->head = deletednode->next;
    free(deletednode);
    u->counter --;
    return true;
}
bool LinkList::DeletefromEnd(llist* z){
    node* currentnode = z->head;
    if(currentnode == NULL){
        return false;
    }else if (currentnode->next == NULL){
        delete currentnode;
        z->head = NULL;
        return true;
    }else {
        node* lastelement = currentnode;
        while(currentnode != NULL){
            lastelement = currentnode;
            currentnode = currentnode->next;
        }
        z->tail = lastelement;
        delete currentnode;
        z->counter --;
        return z;
    }
}
LinkList::llist* LinkList::DeletefromMiddle(llist* a, int n){
    node* currentnode = a->head;
    for(int i=0; i<n-2; i++){
        currentnode = currentnode->next;
    }
    node* temp = currentnode->next;
    currentnode->next = temp->next;
    free(temp);
    a->counter --;
    return a;
}
void LinkList::printlist(llist* b){
    node* current = b->head;
    if(current == NULL){
        cout << "The list is Empty " << endl;
    }
    cout << "the list is " << current->data << "\t";
    while(current != NULL){
        current = current->next;
        cout << current->data << "\t";
    }
}
LinkList::llist* LinkList::intersection(llist* p1, llist* p2){
    llist* interslist = createlist();
    node* l1ptr = p1->head ; node* l2ptr = p2->head;
    while(l1ptr != NULL && l2ptr != NULL){
        if(l1ptr->data < l2ptr->data){
            l1ptr = l1ptr->next;
        }else if(l2ptr->data < l1ptr->data){
            l2ptr = l2ptr->next;
        }else {
            InsertatEnd(interslist,l1ptr->data);
            l1ptr = l1ptr->next;
            l2ptr = l2ptr->next;
        }
    }
    return interslist;
}
LinkList::llist* LinkList::unionoflists(llist* P1, llist* P2){
    llist* unionlist = createlist();
    node* L1ptr = P1->head; node* L2ptr = P2->head;
    while(L1ptr != NULL && L2ptr != NULL){
        if(L1ptr->data < L2ptr->data){
            unionlist = InsertatEnd(unionlist, L1ptr->data);
            L1ptr = L1ptr->next;
        }else if(L2ptr->data < L1ptr->data){
            unionlist = InsertatEnd(unionlist, L2ptr->data);
            L2ptr = L2ptr->next;
        }else {
            unionlist = InsertatEnd(unionlist, L2ptr->data);
            L2ptr = L2ptr->next;
            L1ptr = L1ptr->next;
        }
    }
    return unionlist;
}
LinkList::llist* LinkList::reverselist(llist* k){
    node* currnode;
    node* nexnode;
    node* prevnode;
    currnode = k->head;
    prevnode = NULL;
    while(currnode != NULL){
        nexnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nexnode;
    }
    k->head = prevnode;
    return k;
}
void LinkList::printrecursively(node* p){
    if(p == NULL){
        return;
    }
    cout << p->data << "\t";
    printrecursively(p->next);
}
void LinkList::printreverselt(node* O){
    if(o == NULL){
        return;
    }
    printreverselt(O->next);
    cout << O->data << "\t";

}
