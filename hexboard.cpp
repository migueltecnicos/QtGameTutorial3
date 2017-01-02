#include "hexboard.h"
#include "game.h"

extern Game *game;

HexBoard::HexBoard()
{

}

QList<Hex *> HexBoard::getHexes()
{
    return hexes;
}

void HexBoard::placeHexes()
{
    //
    createHexColumn(100,100,5);
}

void HexBoard::createHexColumn(int x, int y, int numOfRows)
{
    // Create a column of Hexes at the specified location
    // with the specified number of rows
    for (size_t i = 0, n = numOfRows; i < n; ++i)
    {
        Hex *hex = new Hex();
        hex->setPos(x, y + 82 * i);
        hexes.append(hex);
        game->scene->addItem(hex);
    }
}
