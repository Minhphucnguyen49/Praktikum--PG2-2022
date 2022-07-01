#include "Level.h"

void Level::makeFloor()
{
    for(int row{}; row < numRows; ++row ) {
        for(int col = 0; col < numColumns; ++col){
            stage[row][col] = new Floor(this, row, col);
        }
    }
}

void Level::makeWall()
{
    for(int row = 0; row < numRows; ++row ) {
        for(int col = 0; col < numColumns; ++col){
            if (row == 0 || row == numRows-1)
            {
                stage[row][col] = new Wall(this, row, col);
            }
            if (row >= 1 && row <= numColumns)
            {
                stage[row][0] = new Wall(this, row, col);
                stage[row][numColumns-1] = new Wall(this, row, col);
            }
            std::cout << std::endl;
        }
    }
}

void Level::makePortal()
{
    int row_P1 = 2, col_P1 = 2;
    int row_P2 = 5, col_P2 = 5;

    stage[row_P1][col_P1] = new Portal(this, row_P1, col_P1);
    stage[row_P2][col_P2] = new Portal(this, row_P2, col_P2);

    /* stage[][] is Tile*, it does not have Portal's function like setConnectedPortal();
    * But Portal is actually a Tile (Portal inherits from class Tile)
    * => down cast stage(type Tile*) to P1/2 (type Portal*)
    */
    Portal* P1 = dynamic_cast<Portal*>(stage[row_P1][col_P1]);
    Portal* P2 = dynamic_cast<Portal*>(stage[row_P2][col_P2]);

    P1->setConnectedPortal(P2);
    P2->setConnectedPortal(P1);

    /*  Simon's version
     *
        delete stage[row_P1][col_P1];
        delete stage[row_P2][col_P2];

        Portal* P1   = new Portal(this, row_P1, col_P1);
        stage[row_P1][col_P1] = P1;


        Portal* P2   = new Portal(this, row_P2, col_P2);
        stage[row_P2][col_P2] = P2;
        P1->setConnectedPortal(P2);
        P2->setConnectedPortal(P1);
    */
}

void Level::makeSwitchDoor()
{
    int row_s = 4, col_s = 4;
    stage[row_s][col_s] = new Switch(this, row_s, col_s);

    int row_d = 4, col_d = 7;
    stage[row_d][col_d] = new Door(this, row_d, col_d);

    /**
     * @brief dynamic cast upcast
     */
    Active* sw = dynamic_cast<Active*>(stage[row_s][col_s]);
    Passive* door = dynamic_cast<Passive*>(stage[row_d][col_d]);

    sw->attach(door);
}

Level::Level()
{
    // Character's position should also be initialised here too

    //Floor objects anlegen
    makeFloor();

    //Wall objects anlegen, indem some objects of Floor will be overwritten
    makeWall();

    //a pair of Portals are to be created
    makePortal();


    //this->placeCharacter()
    makeSwitchDoor();

    int row_p = 5, col_p = 5;
    stage[row_p][col_p] = new Pit(this, row_p, col_p);
    int row_p2 = 5, col_p2 = 6;
    stage[row_p2][col_p2] = new Pit(this, row_p2, col_p2);

}

Level::~Level()
{
    for(unsigned int i{}; i < listCharacters.size(); i++) {
        delete listCharacters.at(i);
    }
    for(int row{}; row < numRows; ++row ) {
        for(int col{}; col < numColumns ; ++col) {
            delete stage[row][col];
        }
    }
}

Level::Level( const Level& level )
{

}

Tile* Level::getTile(int row, int col)
{
    return stage[row][col];
}

const Tile* Level::getTile(int row, int col) const
{
    return stage[row][col];
}

void Level::placeCharacter(Character *c, int row, int col)
{
    /** Just like linked list
     *  Character must know on which Tile he is standing on
     *  (currentTile of Character should be assigned with the given Tile)
     *  and
     *  Tile must know which Character is standing on it
     *  (character of Tile - here is a element in Level:
     *  std::array<std::array<Tile*, numRows>, numColumns> stage;
     *
     *  IN Character there is a "currentTile" Attribute
     *  IN Tile there is a "character" Attribute
     */

    //c->level = this;
    Tile* temp = stage[row][col];
    c->setTile(temp);
    //c->setTile(this->getTile(row,col));
    temp->setCharacter(c);
    listCharacters.push_back(c);
}

