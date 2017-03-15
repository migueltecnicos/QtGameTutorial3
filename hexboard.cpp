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

void HexBoard::placeHexes(int x, int y, int cols, int rows)
{
    int X_SHIFT = 82;
    int Y_SHIFT = 41;

    for (size_t i = 0, n = cols; i < n; ++i)
    {
        Y_SHIFT = (i % 2 == 0)? 0: 41;

        createHexColumn(x + X_SHIFT * i, y + Y_SHIFT, rows);
    }
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
