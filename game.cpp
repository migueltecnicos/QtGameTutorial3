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
    drawGUI();
}

void Game::drawPanel(int x, int y, int width, int heigh, QColor color, double opacity)
{
    // Draws a panel at the specified location with the specified properties
    QGraphicsRectItem *panel = new QGraphicsRectItem(x, y, width, heigh);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity); //1-opaco, 0 transparente
    scene->addItem(panel);
}

void Game::drawGUI()
{
    // draw the left panel
    drawPanel(0, 0, 150, 768, Qt::darkCyan, 1);

    // draw the rigth panel
    drawPanel(874, 0, 150, 768, Qt::darkCyan, 1);

    // place player1 text
    QGraphicsTextItem *p1 = new QGraphicsTextItem("Player 1's Cards: ");
    p1->setPos(25, 0);
    scene->addItem(p1);

    // place player2 text
    QGraphicsTextItem *p2 = new QGraphicsTextItem("Player 2's Cards: ");
    p2->setPos(875+25, 0);
    scene->addItem(p2);

    // place whosTurnText
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("PLAYER1"));
    whosTurnText->setPos(490, 0);
    scene->addItem(whosTurnText);


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

QString Game::getWhosTurn()
{
    return this->whosTurn_;

}

void Game::setWhosTurn(QString player)
{
    whosTurn_ = player;

    // change the QGraphicsTextItem
    whosTurnText->setPlainText(QString("Turn: ") + whosTurn_);

}
