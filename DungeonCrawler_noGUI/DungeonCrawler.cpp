#include "DungeonCrawler.h"

DungeonCrawler::DungeonCrawler()
{
    currentLevel = new Level();
    abstractUI = new TerminalUI;
}

void DungeonCrawler::play() {
    Character* character1 = new Character;
    currentLevel->placeCharacter(character1, 4, 3);
    while(true)
    {
        abstractUI->draw(currentLevel);
        Character* tempCharacter = currentLevel->listCharacters.at(0);
        int out = tempCharacter->move(currentLevel);
        if (out == 0){
            return;
        }
    }
}
