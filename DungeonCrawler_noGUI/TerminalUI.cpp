#include "TerminalUI.h"

TerminalUI::TerminalUI()
{
}

void TerminalUI::draw(Level *level) {
    for(int row{}; row < numRows; ++row){
        for(int col{}; col < numColumns; ++col){
            std::cout << level->getTile(row, col)->getCharacterTexture();
        }
        std::cout << std::endl;
    }
}
void Character::moveToTile(Level* currentLevel_in, int row, int col)
{
    if(row <= numRows-1 && col <= numColumns-1)
    {
        currentTile->moveTo(currentLevel_in->getTile(row, col), this);
    }
    else std::cout << "invalid movement" << std::endl;
}
int Character::move(Level* currentLevel_in)
{
    int movingKey{};
    int row = currentTile->getRow();
    int col = currentTile->getCol();

    std::cin >> movingKey;

    switch(movingKey)
    {
    case 1:
        this->moveToTile(currentLevel_in, row+1, col-1);
        break;
    case 2:
        this->moveToTile(currentLevel_in, row+1, col);
        break;
    case 3:
        this->moveToTile(currentLevel_in, row+1, col+1);
        break;
    case 4:
        this->moveToTile(currentLevel_in, row, col-1);
        break;
    case 5:
        break;
    case 6:
        this->moveToTile(currentLevel_in, row, col+1);
        break;
    case 7:
        this->moveToTile(currentLevel_in, row-1, col-1);
        break;
    case 8:
        this->moveToTile(currentLevel_in, row-1, col);
        break;
    case 9:
        this->moveToTile(currentLevel_in, row-1, col+1);
        break;
    case 0:
        return 0;
        break;
    default:
        std::cout << "Invalid Input!!" << std::endl;
        //move(currentLevel_in);
        break;
    }
    return movingKey;
}
