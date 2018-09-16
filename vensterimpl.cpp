#include "vensterimpl.h"
#include "goverdiag.cpp"
#include <cmath>
#include <QTimer>
#include <QTime>

//

VensterImpl::VensterImpl( QWidget * parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setupUi(this);

    timer = new QTimer(this); //klok maken
    connect(timer, SIGNAL(timeout()), this, SLOT(klok())); //elke seconde tijd updaten

    connect(hoogteEdit, SIGNAL(textChanged(QString)), this, SLOT(maxMijn()));
    connect(breedteEdit, SIGNAL(textChanged(QString)), this, SLOT(maxMijn()));
    connect(grootteBtn, SIGNAL(clicked()), this, SLOT(resize())); //knop om grid aan te passen

    grx=9; gry=9; nb=10; //grootte bord+aantal mijnen

    bordSetup(0, 0); //venster en grid aanpassen
}

void VensterImpl::bordSetup(int x, int y)
{
    int vgrx = grx*20, vgry = gry*20; //grootte grid in pixels

    labelFrame->setFixedSize(vgrx, vgry); //grootte grid in pixels instellen
    this->setFixedSize(vgrx+320, vgry+70); //grootte venster instellen

    //klok en aantal overgebleven mijnen verplaatsen
    mijnbLabel->move(20, vgry+30);
    mOverLabel->move(55, vgry+35);
    klokLabel->move(vgrx-50, vgry+30);
    tOverLabel->move(vgrx-15, vgry+35);

    //opties grootte grid verplaatsen
    grootteLabel->move(vgrx+40, 20);
    kleinLabel->move(vgrx+40, 50);
    medLabel->move(vgrx+40, 110);
    grootLabel->move(vgrx+40, 170);
    aangLabel->move(vgrx+170, 50);
    hoogteLabel->move(vgrx+195, 75);
    breedteLabel->move(vgrx+195, 100);
    mijnenLabel->move(vgrx+195, 125);
    hoogteEdit->move(vgrx+280, 75);
    breedteEdit->move(vgrx+280, 100);
    mijnenEdit->move(vgrx+280, 125);
    grootteBtn->move(vgrx+205, 195);

    //aanmaken/aanpassen grid
    QFont font("Arial", 12, QFont::Bold); //font vakskes
    for(int i=0; (i<grx || i<x); ++i) for(int j=0; (j<gry || j<y); ++j) //huidig grid/aan te maken grid afgaan
    {
        if(i>=x || j>=y) //als aan te maken grid > huidig grid => grid vergroten
        {
            vakskes[i][j] = new QLabel(labelFrame, 0); //vakske maken
            vakskes[i][j]->setGeometry(i*20, j*20, 20, 20); //grootte vakske
            vakskes[i][j]->setFont(font); //font instellen
            vakskes[i][j]->setFrameShape(QFrame::WinPanel); //vorm
            vakskes[i][j]->setFrameShadow(QFrame::Sunken); //schaduw
            vakskes[i][j]->setAlignment(Qt::AlignCenter); //alignment
            vakskes[i][j]->show();

            knopkes[i][j] = new QPushButton(labelFrame); //knopke maken
            knopkes[i][j]->setGeometry(i*20, j*20, 20, 20); //grootte vakske
            knopkes[i][j]->setFocusPolicy(Qt::NoFocus); //geen focus
            knopkes[i][j]->show();
            connect(knopkes[i][j], SIGNAL(clicked()), this, SLOT( buttonclick() )); //knopke verbergen als aangeklikt
        }
        if(i>=grx || j>=gry) //als aan te maken grid < huidig grid => grid verkleinen
        {
            vakskes[i][j]->~QLabel(); //vakske verwijderen
            knopkes[i][j]->~QPushButton(); //knopke verwijderen
        }
    }

    spelSetup(); //opzet van het spel
}

void VensterImpl::spelSetup()
{
    mOverLabel->setText(QString::number(nb)); //aantal overblijvende mijnen herinstellen
    tOverLabel->setText("0"); //tijd op 0 zetten

    QTime timeSeed = QTime::currentTime();

    srand(timeSeed.second()); //random number seed
    for(int i=0; i<nb;) //n bommen plaatsen
    {
        int x = rand()%grx, //willekeurig x coordinaat
            y = rand()%gry; //willekeurig y coordinaat

        if(xy[x][y]!=9) //als in dit vakje nog geen bom staat
        {
            xy[x][y] = 9; //er een bom in zetten
            ++i; //en verder gaan met loop
        }
    }

    for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j)
    {
        cxy[i][j] = false; //vakjes zijn nog niet geklikt
        rcxy[i][j] = false; //of gerechtsklikt

        //aantal omringende bommen invullen
        if(xy[i][j] != 9) //als huidig veld geen bom is
        {
            xy[i][j] = 0; //op nul zetten

            for(int l=-1; l<=1; ++l) for(int k=-1; k<=1; ++k) //elk omringend veld
                if((i+l)>=0 && (i+l)<grx && (j+k)>=0 && (j+k)<gry) //niet buiten bord?
                    if(xy[i+l][j+k] == 9) ++xy[i][j]; //als het een bom is => eentje bij huidig veld telle
        }

        QString bmn; //aantal omringende bommen
        if(xy[i][j]!=0 && xy[i][j]!=9) bmn = QString::number(xy[i][j]); //geen 0en weergeven
            else bmn = "";
        vakskes[i][j]->setText(bmn);

        ///////////////////
        //BEGIN opmaak vakskes
        ///////////////////
        if(xy[i][j]==9) vakskes[i][j]->setPixmap(QPixmap("img/mijn.png"));
            else
            {
                QPalette pal; //BEGIN tekstkleur
                QColor kleur;
                switch(xy[i][j])
                {
                    case 1:
                        kleur = QColor(Qt::blue);
                        break;

                    case 2:
                        kleur = QColor(Qt::darkGreen);
                        break;

                    case 3:
                        kleur = QColor(Qt::red);
                        break;

                    case 4:
                        kleur = QColor(Qt::cyan);
                        break;

                    case 5:
                        kleur = QColor(Qt::magenta);
                        break;

                    case 6:
                        kleur = QColor(Qt::darkYellow);
                        break;

                    case 7:
                        kleur = QColor(Qt::darkCyan);
                        break;

                    case 8:
                        kleur = QColor(Qt::darkMagenta);
                        break;
                }

                pal.setColor( QPalette::WindowText, kleur );
                vakskes[i][j]->setPalette( pal ); //EINDE tekstkleur
            }
        ///////////////////
        //EINDE opmaak vakskes
        ///////////////////
    }
}

void VensterImpl::resetSpel(bool nieuwSpel)
{
    for(int i=0; i<grx; ++i)for(int j=0; j<gry; ++j)
    {
        if(cxy[i][j])
        {
            knopkes[i][j]->show(); //alle vakjes verbergen
            if(!nieuwSpel)
            {
                cxy[i][j] = false; //is nog niet op geklikt
                if(xy[i][j] == 9) vakskes[i][j]->setPixmap(QPixmap("img/mijn.png"));
            }
        }

        if(rcxy[i][j]) //als gerechtsklikt
        {
            if(!nieuwSpel) rcxy[i][j] = false; //of gerechtsklikt
            knopkes[i][j]->setIcon(QIcon("")); //vlag verbergen
            connect(knopkes[i][j], SIGNAL(clicked()), this, SLOT( buttonclick() )); //kunt terug klikken op knopke
        }

        if(xy[i][j] == 9) knopkes[i][j]->setIcon(QIcon(""));

        if(nieuwSpel)
        {
            if(xy[i][j] == 9) vakskes[i][j]->setPixmap(QPixmap("")); //mijn-icoontje verbergen
            xy[i][j] = 0; //alle vakjes leegmaken
        }
    }
}

void VensterImpl::maxMijn()
{
    int b = breedteEdit->text().toInt(),
        h = hoogteEdit->text().toInt();

    if(b>=9 && b<=30 && h>=9 && h<=24)
    {
        QString maxMijn = QString::number(floor(b*h*.85));
        mijnenLabel->setText("Mijnen (10-"+maxMijn+"):");
    }
}

void VensterImpl::resize() //grootte grid aanpassen
{
    //nieuw spel
    resetSpel(true);
    timer->stop();

    int x=grx, y=gry; //vorige grootte grid bewaren
    if(kleinLabel->isChecked()) //als klein is gekozen
    {
        grx=9; gry=9; nb=10;
    }
        else if(medLabel->isChecked()) //als medium is gekozen
        {
            grx=16; gry=16; nb=40;
        }
        else if(grootLabel->isChecked()) //als groot is gekozen
        {
            grx=30; gry=16; nb=99;
        }
        else if(aangLabel->isChecked()) //als aangepaste grootte is gekozen
        {
            int b = breedteEdit->text().toInt(),
                h = hoogteEdit->text().toInt(),
                m = mijnenEdit->text().toInt();
            if(b>=9 && b<=30 && h>=9 && h<=24 && m>10 && m<=floor(b*h*.85))
            {
                grx=b; gry=h; nb=m;
            }
        }

    bordSetup(x, y);
}

void VensterImpl::contextMenuEvent( QContextMenuEvent *event ) //rechtsklik op knopke
{
    if(event->reason() == QContextMenuEvent::Mouse) //als rechtsklik plaatsvond
    {
        int xmin, xmax, ymin, ymax, ex, ey;
        QPoint  btnpos, evtpos;

        for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j) //elk knopke afgaan
        {
            btnpos = knopkes[i][j]->pos(); //positie huidig knopke
            xmin = 21 + btnpos.x(); //minimum x-coordinaat positie knopke
            xmax = xmin + knopkes[i][j]->width()-2; //maximum x-coordinaat positie knopke
            ymin = 21 + btnpos.y(); //minimum y-coordinaat positie knopke
            ymax = ymin + knopkes[i][j]->height()-2;  //maximum y-coordinaat positie knopke

            evtpos = event->pos(); //positie klik
            ex = evtpos.x(); //x-coordinaat positie rechtsklik
            ey = evtpos.y(); //y-coordinaat positie rechtsklik

            if(ex >= xmin && ex <= xmax && ey >= ymin && ey <= ymax) //als klik binnen huidig knopke ligt
            {
                int mOver = mOverLabel->text().toInt();
                if(!rcxy[i][j]) //als er nog geen vlag op huidig knopke sta
                {
                    knopkes[i][j]->setIcon(QIcon("img/vlag.png")); //vlag-icoontje instellen
                    disconnect(knopkes[i][j], SIGNAL(clicked()), this, SLOT( buttonclick() )); //kunt niet meer klikken op knopke
                    rcxy[i][j] = true; //er staat een vlagske op knopke
                    mOverLabel->setText(QString::number(mOver-1));
                } else
                    {
                        knopkes[i][j]->setIcon(QIcon("")); //vlag-icoontje verwijderen
                        connect(knopkes[i][j], SIGNAL(clicked()), this, SLOT( buttonclick() )); //kunt terug klikken op knopke
                        rcxy[i][j] = false; //er staat geen vlagske op knopke
                        mOverLabel->setText(QString::number(mOver+1));
                    }
                break;
            }
        }
    }
}

void VensterImpl::buttonclick() //klik op knopke
{
    int ax[grx*gry], ay[grx*gry], //houdt bij in welke vakjes een 0 staat: "0-vakjes geheugen"
    x=0, y=0; //coordinaten
    bool gedaan=false;

    if(!timer->isActive()) //als de klok nog niet gestart is
    {
        timer->start(1000);
        tOverLabel->setText("1");
    }

    for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j) //alle knopjes afgaan
    if(knopkes[i][j] == QObject::sender()) //als de sender (knopke waarop geklikt is) gevonden is:
    {
        x=i; y=j; //coordinaten instellen
        break; //sender gevonden -> loop moet niet meer verder gaan
    }

    knopkes[x][y]->hide(); //geklikt knopke verbergen
    cxy[x][y] = true; //knopke is geklikt

    if(xy[x][y]==9) //als op een bom geklikt
    {
        for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j) //alle vakjes afgaan
            if(xy[i][j]==9 && !rcxy[i][j])
            {
                knopkes[i][j]->hide(); //vakjes met bommen blootleggen
                cxy[i][j] = true;
            }
            else if(xy[i][j]!=9 && rcxy[i][j])
            {
                knopkes[i][j]->setIcon(QIcon("img/gmijn.png"));
            }

        vakskes[x][y]->setPixmap(QPixmap("img/mijnd.png")); //mijn waarop geklikt is rood maken
        gedaan = true;
        goverc = "You lost!"; //tekst dialoog instellen
    }
        else if(xy[x][y] == 0) //als gekozen vak 0 is: alle aansluitende 0-vakjes openen
        {
            ax[0]=x; ay[0]=y; //eerste 0-vakje = gekozen vakje
            int k=1; //teller 0-vakjes geheugen
            for(int l=0; l<k; ++l) //herhalen tot er geen aangrenzende nullen meer zijn
                for(int i=-1; i<=1; ++i) for(int j=-1; j<=1; ++j) //alle omliggende vakjes controleren
                    if((ax[l]+i)>=0 && (ax[l]+i)<grx && (ay[l]+j)>=0 && (ay[l]+j)<gry) //niet buiten bord?
                        if(!cxy[(ax[l]+i)][(ay[l]+j)] && !rcxy[(ax[l]+i)][(ay[l]+j)]) //als huidig vakje al is aangeklikt of rechtsgeklikt, is verdergaan niet nodig
                        {
                            knopkes[(ax[l]+i)][(ay[l]+j)]->hide(); //knopke verbergen
                            cxy[(ax[l]+i)][(ay[l]+j)] = true;
                            if(xy[(ax[l]+i)][(ay[l]+j)] == 0) //als huidig vakje = 0...
                            {
                                ax[k] = (ax[l]+i); //...opslaan in 0-vakjes geheugen
                                ay[k] = (ay[l]+j);
                                ++k;
                            }
                        }
        }

    if(!gedaan)
    {
        gedaan=true;//initialiseren op gewonnen
        for(int i=0; i<grx && gedaan; ++i) for(int j=0; j<gry && gedaan; ++j) //alle vakjes controleren zolang gedaan=true
            if(!cxy[i][j] && xy[i][j]!=9) gedaan = false; //is vakje geen mijn én niet aangeklikt? -> niet gewonnen

        if(gedaan)
        {
            mOverLabel->setText("0");
            goverc = "You won!"; //tekst dialoog instellen
            for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j)
                if(xy[i][j] == 9 && !rcxy[i][j]) knopkes[i][j]->setIcon(QIcon("img/mijn.png"));
        }
    }

    if(gedaan)
    {
        timer->stop(); //klok stoppen
        gover = new goverDiag(); //dialoog creeren

        connect(gover->opnieuwBtn, SIGNAL(clicked()), this, SLOT(opnieuwSpel()));
        connect(gover->nieuwBtn, SIGNAL(clicked()), this, SLOT(nieuwSpel()));

        gover->tijdLabel->setText(gover->tijdLabel->text() + tOverLabel->text() + " seconden");
        gover->setWindowFlags(Qt::CustomizeWindowHint); //attributen
        gover->setWindowFlags(Qt::WindowTitleHint); //attributen
        gover->setWindowModality(Qt::ApplicationModal);
        gover->show(); //dialoog starten
        gover->raise();
        gover->activateWindow();
    }
}

void VensterImpl::opnieuwSpel()
{
    resetSpel(false);
    mOverLabel->setText(QString::number(nb));
    tOverLabel->setText("0");
    gover->close(); //venster sluiten
}

void VensterImpl::nieuwSpel()
{
    resetSpel(true);
    this->spelSetup();
    gover->close(); //venster sluiten
}

void VensterImpl::klok()
{
    int time = tOverLabel->text().toInt()+1;
    tOverLabel->setText(QString::number(time));
}
