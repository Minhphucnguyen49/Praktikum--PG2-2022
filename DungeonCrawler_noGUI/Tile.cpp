#include "Tile.h"


std::string Tile::getTexture()
{
    return texture;
}

std::string Tile::getCharacterTexture() {
    if(hasCharacter()) {
        return "X";
    }
    else return getTexture();
}

bool Tile::hasCharacter()
{   //if Character locates on Tile --> true
    // Character on Tile <=> attribue, pointer character of Tile != nullptr
    if (this->pCharacter != nullptr) {
        return true;
    }
    return false;
}

int Tile::getRow() const {
    return row;
}

int Tile::getCol() const {
    return column;
}

bool Tile::moveTo(Tile *destTile, Character *who)
{
    /**After both above-mentioned conditions (leftable and enterable) are satisfied,
    *  We can set the attribute Character* of starting Tile and target Tile
    *  by doing:
    *  1. Character* attribute of destination Tile = who;
    *  2. Character* attribute of starting Tile = nullptr;
    *
    *  AGAIN: this is current Tile (actualleft)
    */

    Tile* actualleft = this->onLeave(this,who);
    if (actualleft == nullptr) {
        std::cout << "can not leave this Tile" << std::endl;
        return false;
    }

    Tile* enteredTile = destTile->onEnter(actualleft,who);
    if (enteredTile == nullptr) {
        std::cout << "can not enter this Tile!" << std::endl;
        return false;
    }
    actualleft->setCharacter(nullptr);
    enteredTile->setCharacter(who);//großer Unterschied: destTile->setCharacter();
    who->setTile(enteredTile);//update Tile* in Character

    return true;
/************************************************************
    if (onLeave(destTile, who) != nullptr) {
        //save the result from onLeave - the actual left Tile
        Tile* actualleft = onLeave(destTile,who);

        //result from onLeave used in onEnter as Parameter
        //if (onEnter(actualleft, who) != nullptr) {
        if (destTile->onEnter(actualleft, who) != nullptr) {

            destTile->character = who;
            this->character = nullptr;

            //update Tile* in Character
            who->currentTile = destTile;


//            destTile->character->characterTexture = who->characterTexture;
//            destTile->character->level = who->level;
            return true;

        }
        else {
            std::cout << "can not enter this Tile!" << std::endl;
            return false;
        }
    }
    std::cout << "can not leave this Tile" << std::endl;
    return false;
******************************************************************/
}

/*
 * Golden rule:
 * enterable or leftable: return this;
 * unable to enter or leave: return nullptr;
 */


/**
 * Floor onLeave & onEnter implementation
 */
Tile* Floor::onEnter(Tile *fromTile, Character *who)
{
     // return "this" if on Floor "."
        return this;

}

Tile* Floor::onLeave(Tile *destTile, Character *who)
{
    return this;
}

/**
 * Wall onLeave & onEnter  implementation
 */
Tile* Wall::onEnter(Tile *fromTile, Character *who)
{
    // return "nullptr" if on Wall
    return nullptr;

}

Tile* Wall::onLeave(Tile *destTile, Character *who)
{
    return this;
}

/**
 * Portal onLeave & onEnter implementation
 */
Tile* Portal::onEnter(Tile *fromTile, Character *who)
{
    return connectedPortal; // return the pointer to the connected Portal if on Portal

}

void Portal::setConnectedPortal(Portal *newConnectedPortal)
{
    connectedPortal = newConnectedPortal;
}

Tile* Portal::onLeave(Tile *destTile, Character *who)
{
    return this;
}

/**
 * @brief Switch
 */

void Switch::switchDoor()
{
    if (!doorSwitch) {
        texture = "!";
        doorSwitch = true;
    } else {
        texture = "?";
        doorSwitch = false;
    }

    // activate the Event --> This method call notify in Passive,
    //and therefore call the overriden version in Door class
    activate();

}

Tile* Switch::onLeave(Tile *destTile, Character *who)
{
    switchDoor();
    return this;
}

Tile* Switch::onEnter(Tile* fromTile, Character* who)
{
    return this;
}

/**
 * @brief Door
 * @return
 */
bool Door::doorState()
{
    return state;
}
void Door::notify(Active *source)
{
    // if true: make Wall --> Floor
    if (state == false) {
        texture = "_";
        state = true;
    }
    else {
        texture = "|";
        state = false;
    }

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

/**
 * @brief Pit
 */
Tile* Pit::onLeave(Tile* destTile, Character *who)
{
    if ( typeid(*destTile).name() == typeid(Pit).name() )
    {
        return this;
    }
    if ( typeid(*destTile).name() == typeid(Ramp).name() )
    {
        return this;
    }
    return nullptr;
}

Tile* Pit::onEnter(Tile* destTile, Character *who)
{
    return this;
}
/**
 * @brief Ramp
 */
Tile* Ramp::onLeave(Tile *destTile, Character *who)
{
    return this;

}

Tile* Ramp::onEnter(Tile *destTile, Character *who)
{
    return this;
}
