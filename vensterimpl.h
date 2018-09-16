#ifndef VENSTERIMPL_H
#define VENSTERIMPL_H

//
#include "ui_dialog.h"
#include <QContextMenuEvent>
//

class VensterImpl : public QDialog, public Ui::Venster
{
Q_OBJECT
public:
    VensterImpl( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    void bordSetup(int x, int y);
    void spelSetup();
    void resetSpel(bool nieuwSpel);

public slots:
    void buttonclick();
    void klok();
    void opnieuwSpel();
    void nieuwSpel();
    void resize();
    void maxMijn();

protected:
    void contextMenuEvent( QContextMenuEvent *event );
};

#endif // VENSTERIMPL_H
