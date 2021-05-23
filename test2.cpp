#include <iostream>
class Polygon
{
public:
    Polygon(short &width, short &height)
    {
        w = width;
        h = height;
    }
    //void setLength(short &width, short &height);
    virtual float area(void);

protected:
    short w;
    short h;
};
class Rectangle : public Polygon
{
public:
    Rectangle(short &width, short &height) : Polygon(width, height)
    {
    }
    float area(void)
    {
        return (w * h);
    };
};

int main(void)
{
    short a = 10;
    short b = 20;
    Rectangle rec(a,b);
    std::cout<<rec.area()<<std::endl;
    return 0;
}