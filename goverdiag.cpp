#include "goverdiag.h"
#include "globalvars.cpp"

//

goverDiag::goverDiag( QWidget * parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setupUi(this);
    this->installEventFilter(this);
    goverLabel->setText(goverc); //gewonnen/verloren tekst instellen
    this->setWindowTitle(goverc);
    connect(sluitBtn, SIGNAL(clicked()), qApp, SLOT(closeAllWindows())); //als op Sluiten geklikt wordt, programma sluiten
}

bool goverDiag::eventFilter( QEvent *event )
{
    if( QEvent::KeyPress == event->type() && Qt::Key_Escape == ( (QKeyEvent*)event )->key() )
        return true; //ignore the event

    return false;
}
//
