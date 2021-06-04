#include <string>
class StringNode
{
private:
    std::string elem; //element value
    StringNode *next; //next item in the list

    friend class StringLinkedList; //access to StringLinked List
};

class StringLinkedList
{ // alinked list of strings
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;                  //is empty
    const std::string &front() const;    //get front element
    void addFront(const std::string &e); //add to front of the list
    void removeFront();                  //remove front item list
private:
    StringNode *head; //pointer to the head of list
};
StringLinkedList::StringLinkedList() : head(NULL) {}
StringLinkedList::~StringLinkedList()
{
    while (!empty())
    {
        removeFront(); //destroys the whole list
    }
}
bool StringLinkedList::empty() const
{
    return head == NULL;
}
const std::string &front()
{
    return head->elem;
}
void addFront(const std::string &e)
{
    StringNode *v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
}
void StringLinkedList::removeFront()
{
    StringNode *old = head;
    head = old->next;
    delete old;
}