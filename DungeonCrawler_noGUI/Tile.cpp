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
    if (this->character != nullptr) {
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
    if (onLeave(destTile, who) != nullptr) {
        //save the result from onLeave - the actual left Tile
        Tile* actualleft = onLeave(destTile,who);

        //result from onLeave used in onEnter as Parameter
        //if (onEnter(actualleft, who) != nullptr) {
        if (destTile->onEnter(actualleft, who) != nullptr) {
            /**After both above-mentioned conditions are satisfied,
            *  We can set the attribute Character* of starting Tile and target Tile
            *  by doing:
            *  1. Character* attribute of destination Tile = who;
            *  2. Character* attribute of starting Tile = nullptr;
            *
            *  AGAIN: this is current Tile (actualleft)
            */
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
}

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
    return this; // return the pointer to the connected Portal if on Portal
}

Tile* Portal::onLeave(Tile *destTile, Character *who)
{
    return this;
}

void Portal::connectPortal(Portal *secondPort) {
    connectedPortal = secondPort;
    secondPort->connectedPortal = this;
}
/**********
bool Tile::moveTo(Tile *destTile, Character *who)
{
    //If leftable
    if (onLeave(this, who) != nullptr)
    //nullptr means it can not leave
    {
        **
         *  When the character can not leave the Tile, his previous position will be saved
         *  in previousTile
         *
         *  Which means his previous Tile will be the same (this is a current Tile he is standing on)

        //who->previousTile = this;

        //If enterable - betretbar
        if(destTile->onEnter(destTile, who) != nullptr)
        // nullptr means in this place is belegt von einem anderen Character
        {
            //move to new tiles, or to the next Portal
            who->currentTile = destTile->onEnter(destTile,who);

            this->character= nullptr;      //delete the character of the previousTile
            destTile->character = who;     //creates a link: which character is standing on this destTile

            //IN CASE of PORTAL
            if(destTile->onEnter(destTile, who) != destTile)
            {
               //if the character move into a portal, delete pCharacter in the first Portal
               //and move it to 2nd portal instead
                destTile->character = nullptr;
                destTile->onEnter(destTile, who)->character = who;
            }
            return true;
         }
        // If not enterable - nicht betretbar
        else
        {
            std::cout << "Unable to Enter here" << std::endl;
            return false;
        }
    }
    //
    std::cout << "Unable to leave" << std::endl;
    return false;
}

*/
