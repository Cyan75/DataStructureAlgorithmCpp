#include <string>
typedef std::string Elem;
class DNode
{ //doubly linked list node
private:
    Elem elem;                //node element value
    DNode *prev;              //previous node in list
    DNode *next;              //next node in list
    friend class DLinkedList; //allow DLinkedList access
};
class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem &front() const;    //get front element
    const Elem &back() const;     //get back element
    void addFront(const Elem &e); //add from front
    void addBack(const Elem &e);  //add from back
    void removeFront();           //remove from front
    void removeBack();            //remove from back
private:                          //local type definitions
    DNode *header;                //list sentinels
    DNode *trailer;

protected:                             //local utilities
    void add(DNode *v, const Elem &e); //insert new node before v
    void remove(DNode *v);             //remove node v
};
DLinkedList::DLinkedList()
{
    header = new DNode; //create sentinels
    trailer = new DNode;
    header->next = trailer; //have them point to each other
    trailer->prev = header;
}
DLinkedList::~DLinkedList()
{
    while (!empty())
    {
        remoteFront(); //remove all but sentinels
    }
    delete header; //remove the sentinels
    delete trailer;
}
bool DLinkedList::empty() const
{
    return (header->next == trailer);
}
const Elem &DLinkedList::front() const
{
    return header->next->elem;
}
const Elem &DLinkedList::back() const
{
    return trailer->prev->elem;
}
void DLinkedList::add(DNode *v, const Elem &e)
{ //insert new node before `v`
    DNode *u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}
void DLinkedList::addFront(const Elem &e)
{
    add(header->next, e);
}
void DLinkedList::addBack(const Elem &e)
{
    add(trailer, e);
}
void DLinkedList::remove(DNode *v)
{
    DNode *u = v->prev;
    DNode *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
void DLinkedList::removeFront()
{
    remove(header->next);
}
void DLinkedList::removeBack()
{
    remove(trailer->prev);
}