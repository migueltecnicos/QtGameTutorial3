#include "game.h"
#include <button.h>

Game::Game(QWidget *parent)
    :QGraphicsView(parent)
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
    // Clear the screen
    scene->clear();

    // test code TODO remove
    hexBoard = new HexBoard();
    hexBoard->placeHexes(100, 100, 5, 5);
}

void Game::displayMainMenu()
{
    // Create the title text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Hex Warz"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);

    int xPos = this->width() / 2 - titleText->boundingRect().width() / 2;
    int yPos = 150;
    titleText->setPos(xPos, yPos);
    scene->addItem(titleText);

    // Create the play button
    Button *playButton = new Button(QString("Play"));
    xPos = this->width() / 2 - playButton->boundingRect().width() / 2;
    yPos = 275;
    playButton->setPos(xPos, yPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    // Create the quit button
    Button *quitButton = new Button(QString("Quit"));
    xPos = this->width() / 2 - quitButton->boundingRect().width() / 2;
    yPos = 350;
    quitButton->setPos(xPos, yPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}
