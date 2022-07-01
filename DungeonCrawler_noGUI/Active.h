#ifndef ACTIVE_H
#define ACTIVE_H

#include "iostream"
#include "vector"

#include "Passive.h"

class Active
{
public:
    Active(){};
    /**
     * @brief attach: adds passive-Pointer in the listPassive
     *
     * Important: a passive-pointer should appear only once in the list
     */
    void attach(Passive*);
    /**
     * @brief detach: removes passive-Pointer from the listPassive
     */
    void detach(Passive*);

    /**
     * @brief activate calls notify() Method of all Passive-Objects
     */
    void activate();
private:
    std::vector<Passive*> observers;
};


#endif // ACTIVE_H
