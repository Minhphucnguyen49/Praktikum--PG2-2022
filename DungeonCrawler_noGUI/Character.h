#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <Tile.h>
#include <Level.h>
#include <Controller.h>

class Tile;

class Character
{
public:
    Character();
    std::string getTexture();

    /**
     * @brief setTile is a setter Method
     * It changes the Tile* of Character (currentTile)
     * when a movement takes place
     */
    void setTile(Tile* destination);


    /**
     * @brief move will move the Character in a direction that is given by user
     *
     * This method will ask user in which direction the Character should go
     * Interupts are keys 1 - 9 (just like in the keybord: 8 is nach oben, etc.)
     * 5 means to stand still (bleiben stehen)
     * 0 means to stop the Programm
     *
     * @return the keys 1-9 (that's why integer), which was typed in by user
     */
    int move(Level* currentLevel_in);
    void moveToTile(Level* currentLevel_in, int row, int col);

//private:
    std::string characterTexture;
    Level* level;
    Tile* currentTile;
    Controller* pController;

};

#endif // CHARACTER_H
