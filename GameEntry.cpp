#include <string>

//------header file
class GameEntry
{
public:
    GameEntry(const std::string &n = "", int s = 0);
    std::string getName() const;
    int getScore() const;

private:
    std::string name;
    int score;
};
//-----------

//------implementation file
GameEntry::GameEntry(const std::string &n, int s) : name(n), score(s) {}
std::string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }
//------

//-----header file
class Scores
{
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry &e);
    GameEntry remove(int i) { throw(IndexOutOfBounds); }

private:
    int maxEntries;     //desired maximum entries
    int numEntries;     //actual number of entries
    GameEntry *entries; //array of game entries
};
//-----------

//------implementation file
Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0; //initially no elements
}
Scores::~Scores()
{
    delete[] entries;
}
void Scores::add(const GameEntry &e) //add an game entry object
{
    int newScore = e.getScore();
    if (numEntries == maxEntries) //the array is full
    {
        if (newScore <= entries[maxEntries - 1].getScore()) //smaller than the lowest score of the original standing
        {
            return;
        }
        else
            numEntries++;
        int i = numEntries - 2; //the nest lowest score
        while (i >= 0 && newScore > entries[i].getScore())
        {
            entries[i + 1] = entries[i]; //shift to the right
            i--;
        }
        entries[i + 1] = e;
    }
}
GameEntry Scores::remove(int i) throw(IndexOutOfBounds)
{
    if ((i < 0) || (i > numEntries))
        throw IndexOutOfBounds("Invalid Index");
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j];
    numEntries--;
    return e;
}
//-----------