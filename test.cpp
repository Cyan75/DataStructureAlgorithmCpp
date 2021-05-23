#include <iostream>
class ThisIsBasClass
{
public:
    ThisIsBasClass(short &y);
    void setVal(short x);
    short getVal(void);

private:
    short a;
};
void ThisIsBasClass::setVal(short x)
{
    a = x;
}
ThisIsBasClass::ThisIsBasClass(short &y)
{
    a = y;
}
short ThisIsBasClass::getVal(void)
{
    return a;
}
int main(void)
{
    short a = -10;
    short b = -20;
    ThisIsBasClass thisIsObject_1(b);
    ThisIsBasClass *p_1 = &thisIsObject_1;
    //p_1->setVal(10);
    std::cout << p_1->getVal() << std::endl;
    p_1->setVal(20);
    std::cout << p_1->getVal() << std::endl;

    return 0;
}