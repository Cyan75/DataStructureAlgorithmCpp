#include <string>
typedef std::string Elem;
class CNode
{ //doubly linked list node
private:
    Elem elem;               //node element value
    CNode *next;             //next node in list
    friend class CircleList; //allow DLinkedList access
};
class CircleList
{
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem &front() const;
    const Elem &back() const;
    void advance();
    void add(const Elem &e);
    void remove();

private:
    CNode *cursor;
};
CircleList::CircleList() : cursor(NULL) {}
CircleList::~CircleList()
{
    while (!empty())
    {
        remove();
    }
}
bool CircleList::empty() const
{
    return cursor == NULL;
}
const Elem &CircleList::back() const
{ //element at cursor
    return cursor->elem;
}
const Elem &CircleList::front() const
{ //element following cursor
    return cursor->next->elem;
}
void CircleList::advance()
{ //advance cursor
    cursor = cursor->next;
}
void CircleList::add(const Elem &e)
{                         //add after cursor
    CNode *v = new CNode; //create a new node
    v->elem = e;
    if (cursor == NULL)
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CircleList::remove()
{                              // remove node after cursor
    CNode *old = cursor->next; //the node being removed
    if (old == cursor)
    {
        cursor == NULL;
    }
    else
    {
        cursor->next = old->next; //link out the old node
    }
    delete old;
}