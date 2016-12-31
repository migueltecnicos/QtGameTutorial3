#include "game.h"
#include "hex.h"

Game::Game(QWidget *parent)
{
    // Set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    // Set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);


}

void Game::start()
{
    // test code TODO remove
    Hex *hex = new Hex();
    scene->addItem(hex);
    hex->setPos(100,100);
}
