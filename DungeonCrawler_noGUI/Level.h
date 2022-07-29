#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <array>
#include <vector>
#include <Character.h>
#include <Tile.h>
class Tile;
class Character;

static const int numRows = 10; // Höhe des Levels
static const int numColumns = 10; //Breite des Levels
class Level
{
public:

    /**
     * @brief Standard constructor
     * creates a map 4x4 and a pair of Portals for testing purpose
     */
    Level();

    /**
     * @brief Destructor of class Level
     *
     * all the dynamic Resources (Tiles, Character, etc.) which are created
     * will be correctly destroyed
     *
     * That means to delete all Elements of listCharacters vector
     * as well as all Tiles in stage - 2 dimentional array
     */
    ~Level();

    /**
     * @brief Level copy constructor
     * @param level
     */
    Level( const Level& level );
    /**
     * @brief getTile returns bach the pointer to the Tile Object at the given coordinates
     * @param row
     * @param col
     * @return pointer
     */
    Tile* getTile( int row, int col );

    const Tile* getTile( int row, int col ) const;// const version of Tile* getTile

    /**
     * @brief placeCharacter initialises Level:
     * puts the Character on the Tile object at the given coordinates
     *
     * --> To put the Character on a specific Tile means
     * to assign the address (the pointer) of the specific Tile on the Character
     * (Character should consist some attributes,
     * among those there should be one of type Tile*)
     *
     *
     * should take place without calling onEnter method
     */
    void placeCharacter( Character *c, int row, int col );



//private:

    /**
     * @brief stage
     * List of Characters (Array aus Figuren)
     */
    std::vector<Character*> listCharacters;


//    const int numRows = 6;// Höhe des Levels
//    const int numColumns = 6;//Breite des Levels
    /**
     * @brief stage(Spielwelt) is a matrix from Tile pointers,
     * on which Character can move
     * that matrix : 2 dimentional Array from Tiles (aus Kacheln)
     */
    std::array<std::array<Tile*, numRows>, numColumns> stage;
    void makeFloor();
    void makeWall();
    void makePortal();
    void makeSwitchDoor();
};

#endif // LEVEL_H
