#ifndef GOVERDIAG_H
#define GOVERDIAG_H

//
#include "ui_gover.h"
//

class goverDiag : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
    goverDiag( QWidget * parent = 0, Qt::WindowFlags f = 0 );

protected:
    bool eventFilter( QEvent *event );

};
#endif // GOVERDIAG_H
