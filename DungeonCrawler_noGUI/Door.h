/*
#ifndef DOOR_H
#define DOOR_H

#include "Tile.h"
#include "Passive.h"
#include "Switch.h"

**
 * @brief The Door class
 * in closed state(|): reacts like Wall - d.h. unenterable
 * in opened state(_): reacts like normal Floor Tile
 *
class Door : virtual public Tile, public Passive
{
public:
    Door(Level* stage,  int row, int col)
        : Tile(stage, row, col)
    {
        //connectedPortal = port;
        character = nullptr;
        currentLevel = stage;
        texture = "|";//Wall
    }
    Tile* onLeave( Tile *destTile, Character *who ) override;
    Tile* onEnter( Tile* fromTile, Character* who ) override;
    void notify( Active* source ) override;
    bool doorState();
private:
    bool state = false;// closed - Wall
};

bool Door::doorState()
{
    return state;
}
void Door::notify(Active *source)
{
    // if true: make Wall --> Floor
    if (state == false) {
        state = true;
    }
    state = false;
}
Tile* Door::onLeave(Tile *destTile, Character *who)
{

    return this;
}

Tile* Door::onEnter(Tile* fromTile, Character* who)
{
    if (doorState()) //door open
    {
        return this;// behaves like a Floor Tile
    }
    return nullptr;// door close --> behaves like a Wall Tile
}

#endif // DOOR_H
*/
