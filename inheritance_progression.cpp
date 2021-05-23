#include <iostream>

class Progression
{
public:
    Progression(const int &size, const int &first, const int &change); 
    int size;
    int change;
    void print(void);
    virtual void setCur(int &change);
    int getCur(void)
    {
        return cur;
    }

protected:
    int first = 1;
    int cur = first;
};
class Arithmatic : public Progression
{
    Progression::Progression(const int &size, const int &first, const int &change)
    {
        Arithmatic();
    }
    void setCur(int &size, int &increment)
    {
        for (short i = 0; i < size; ++i)
        {
            cur += increment;
        }
    }
};
class Geometric : public Progression
{
    void setCur(int &size, int &base)
    {
        for (short i = 0; i < size; ++i)
        {
            cur *= base;
        }
    }
};
int main(void)
{
}