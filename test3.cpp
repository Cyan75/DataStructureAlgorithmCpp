#include <iostream>

class GameEntry
{
public:
    GameEntry(const std::string &n = "Cyan", int s = 0);
    ~GameEntry();
    int getScore(void) const;
    std::string getName(void) const;

private:
    int score;
    std::string name;
};
GameEntry::GameEntry(const std::string &n, int s) : name(n), score(s)
{
}
std::string GameEntry::getName(void) const
{
    return name;
}
int GameEntry::getScore(void) const
{
    return score;
}
int main(void)
{
    GameEntry g;
    GameEntry *p = &g;
    std::cout << p->getName() << " " << p->getScore();
    return 0;
}
//1. (WHY) const member function
//2. (WHY) member funciton definition outside the class
//3. const before vs const behind