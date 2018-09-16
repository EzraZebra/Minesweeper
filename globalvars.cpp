QString goverc; //gewonnen of verloren?
int grx,gry,nb; //aantal vakjes/bommen
bool cxy[30][24], rcxy[30][24]; //houdt bij of een knopje al is ge(rechts)klikt
QPushButton *knopkes[30][24]; //buttons initialiseren
int xy[30][24]; //houdt aantal mijnen/locaties bommen bij per vakje
QLabel *vakskes[30][24]; //labels initialiseren
goverDiag * gover; //dialoog wanneer spel gedaan is
QTimer * timer; //klok initialiseren
