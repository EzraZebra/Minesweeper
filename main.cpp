#include <QApplication>
#include "vensterimpl.h"
#include "goverdiag.h"
//
int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    VensterImpl win;
    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
