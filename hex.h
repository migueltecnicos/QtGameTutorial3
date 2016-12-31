#ifndef HEX_H
#define HEX_H

#include <QGraphicsPolygonItem>

class Hex: public QGraphicsPolygonItem
{
public:
    // constructors
    Hex(QGraphicsItem *parent=NULL);

    // getters
    int getAttackOf(int side);

    // setters
    void setAttackOf(int side, int attack);
private:
    QString owner;
    int sideAttack[6];
};

#endif // HEX_H
