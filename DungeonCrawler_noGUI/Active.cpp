#include "Active.h"

void Active::attach(Passive* other)
{
    observers.push_back(other);
}

//I don't really know how to delete an object from a vector in this generic situation
void Active::detach(Passive* other)
{
    for (unsigned long long i = 0; i < observers.size(); ++i)
    {
        if (observers.at(i) == other)
        {
            observers.erase(observers.begin() + i);
        }
    }
}

void Active::activate()
{
    for (int i = observers.size() - 1; i >= 0; --i) {
        observers.at(i)->notify(this);
    }
}
