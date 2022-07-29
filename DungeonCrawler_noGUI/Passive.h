#ifndef PASSIVE_H
#define PASSIVE_H

/** Passive and Active is nothing but Observer(passive) and Subject(active)
 *  For more details: https://en.wikipedia.org/wiki/Observer_pattern
 */

class Active;
class Passive
{
public:
    /**
     * @brief notify is a pure virtual method
     * @param source is a pointer of type Active,
     * and is used to determine, through which object
     * this action (event) was triggered (ausgelöst wurde)
     * --> is it a "this" in Active class?
     *
     * This method should be called when
     * there is an action(event) triggered for this passive object.
     */
    virtual void notify(Active* source) = 0;
};

#endif // PASSIVE_H
