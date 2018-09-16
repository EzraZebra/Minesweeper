#include <iostream>
#include <cstdlib>
#include <cctype> //case sensitivity
using namespace std;
void spel(int, int, int, int[], int[]); //spel functie prototype

main()
{
	////////////////////////////////////
	// Grootte grid vragen en instellen
	////////////////////////////////////
	char gr;
	bool error=false;
	int grx,gry,nb;
	cout << "Grootte grid: -(N)ormaal \n              -(G)root \n              -(E)norm \n              -(A)angepast\n"; //grootte grid?
	do
	{		
		cout << "(N/G/E/A): "; cin >> gr; gr = tolower(gr);
		cin.clear(); //fout verwijderen
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
		if(!cin.good()) error = true;
	} while(error || (gr!='n' && gr!='g' && gr!='e' && gr!='a'));
	
	switch(gr)
	{
		case 'n':
			grx = 9, //breedte: 9
			gry = 9, //hoogte: 9
			nb = 10; // aantal bommen
			break;
		
		case 'g':
			grx = 16, //breedte: 16
			gry = 16, //hoogte: 16
			nb = 40; // aantal bommen
			break;
			
		case 'e':
			grx = 16, //breedte: 16
			gry = 30, //hoogte: 30
			nb = 99; // aantal bommen
			break;
			
		case 'a':
			int nbmax;
			bool error=false;
			
			do
			{
				cout << "Breedte (2-19): "; cin >> grx;
				if(!cin.good() || !(grx>=2 && grx<=19))
				{
					cin.clear(); //fout verwijderen
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
					error=true;
				} else error=false;
			} while(error);

			do
			{
				cout << "Hoogte (2-140): "; cin >> gry;
				if(!cin.good() || !(gry>=2 && gry<=140))
				{
					cin.clear(); //fout verwijderen
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
					error=true;
				} else error=false;
			} while(error);
			
			nbmax = grx*gry-1;
			
			do
			{
				cout << "Aantal mijnen (1-" << nbmax << "): "; cin >> nb;
				if(!cin.good() || !(nb>=1 && nb<=nbmax))
				{
					cin.clear(); //fout verwijderen
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
					error=true;
				} else error=false;
			} while(error);
			break;
	}
	
	int bx[nb], by[nb]; //coordinaten bommen initialiseren	
	srand((unsigned)time(0)); //random number seed
	for(int i=0; i<nb;) //n bommen plaatsen
	{
		int x = rand()%grx, //willekeurig x coordinaat
			y = rand()%gry; //willekeurig y coordinaat
		
		bool mijn=false; //staat er al een mijn op deze coordinaten?
		for(int j=0; j<=i && !mijn; ++j) //alle voorgaande coordinaten controleren, zolang huidige coordinaten niet gevonden worden
			if(bx[j]==x && by[j]==y) mijn=true; //als x en y hetzelfde zijn: coordinaten al gebruikt

		if(!mijn) //coordinaten niet gebruikt: huidige coordinaten plaatsen
		{			
			bx[i] = x; //x-coordinaat bom
			by[i] = y; //x-coordinaat bom
			++i; //verder gaan met loop
		}
	}
		
	spel(grx, gry, nb, bx, by); //spel functie aanroepen
}

void spel(int grx, int gry, int nb, int bx[], int by[]) //spel functie
{	
	////////////////////////////////////
	// Grid klaarmaken
	////////////////////////////////////
	int xy[grx][gry],  //grid
		x=-1,y=-1; //coordinaten
	bool cxy[grx][gry], //grid: clicked?
		 rcxy[grx][gry]; //grid: rechtsklik?
	char rl;
	

	for(int i=0; i<nb; ++i) xy[bx[i]][by[i]] = 9; //n bommen plaatsen
	
	for(int i=0; i<grx; ++i) for(int j=0; j<gry; ++j) // aantal omringende bommen invullen
	{
		cxy[i][j] = false; //veld is nog niet aangeklikt
		rcxy[i][j] = false; //veld is nog niet rechtsgeklikt
		if(xy[i][j] != 9) //als huidig veld geen bom is
		{
			xy[i][j] = 0; //op null zetten
			
			for(int l=-1; l<=1; ++l) for(int k=-1; k<=1; ++k) //elk omringend veld
				if((i+l)>=0 && (i+l)<grx && (j+k)>=0 && (j+k)<gry) //niet buiten bord?
					if(xy[i+l][j+k] == 9) ++xy[i][j]; //als het een bom is => eentje bij huidig veld telle
		}
	}

	////////////////////////////////////
	// Spel zelf
	////////////////////////////////////
	bool win=false;
	for(bool gover=false; !gover;) //zolang het spel niet voorbij is
	{
		////////////////////////////////////
		// BEGIN Bord tekenen
		////////////////////////////////////
		cout << endl;						//x-coordinaten weergeven
		for(int i=1; i<=grx; ++i)
		{
			cout << "  " << i; if(i<=9) cout << " ";
		}
		cout << endl;
		for(int i=0; i<grx; ++i) cout << "----"; cout << "-" << endl; //bovenste lijn
		
		for(int k=0; k<gry; ++k) //horizontale herhaling
		{
			cout << "|";
			for(int j=0; j<grx; ++j) //vertikale herhaling
			{
				cout << " ";
				if(cxy[j][k]) cout << xy[j][k]; //inhoud weergeven als aangeklikt
				else if(rcxy[j][k]) cout << "?"; //als rechtsgeklikt vraagteken weergeven
				else cout << " "; //anders niks weergeven
				cout << " |";	
			}
			if(k<99) cout << " "; if(k<9) cout << " "; cout << k+1; //y-coordinaten weergeven
			if(grx<19) cout << endl; for(int i=0; i<grx; ++i) cout << "----"; cout << "-" << endl; //bovenste lijn
		}
		////////////////////////////////////
		// EINDE Bord tekenen
		////////////////////////////////////
		
		if(xy[x][y] == 9 && rl=='l') //als een bom is aangeklikt
		{
			gover = true; //spel voorbij
			cout << "BOEM!" << endl; //game-over boodschap
		}
		else if(win) //anders als gewonnen
		{
			gover = true; //spel voorbij
			cout << "Gewonnen!" << endl; //gewonnen boodschap
		}	
		else //anders volgende zet vragen
		{
			do
			{
				cout << "Links of rechtsklik (R/L): "; cin >> rl; rl = tolower(rl); //naar lower case voor while voorwaarde
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			} while(rl!='r' && rl!='l');
			
			do //x vragen + foutcontrole
			{
				bool error=false; //fout?
				do 
				{
					cout << "x: "; cin >> x; x--; //x-- voor array-logica
					if(!cin.good() || !(x>=0 && x<grx)) //als geen geheel getal van 1 tot 9 gegeven is
					{
						cout << "Geef een getal van 1 tot " << grx << "." << endl; //fout: 1 tot 9
						error = true; //fout!
						cin.clear(); //fout verwijderen
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
					} else error = false; //anders geen fout!
				} while(error); //zolang er fout is
				
				do //y vragen + foutcontrole
				{
					cout << "y: "; cin >> y; y--; //y-- voor array-logica
					if(!cin.good() || !(y>=0 && y<gry)) //als geen geheel getal gegeven is
					{
						cout << "Geef een getal van 1 tot " << gry << "." << endl; //fout: 1 tot 9
						error = true; //fout!
						cin.clear(); //fout verwijderen
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
					} else error = false; //anders geen fout!
				} while(error); //zolang er fout is
				
				if(cxy[x][y]) cout << "Al aangeklikt." << endl; //boodschap als al aangeklikt
			} while(cxy[x][y]); //herhalen tot een nieuw vak wordt gekozen
			
			if(rl == 'r') if(rcxy[x][y]) rcxy[x][y] = false; else rcxy[x][y] = true; //als rechtsklik: vraagteken verwijderen of plaatsen
			else if(rl == 'l') //anders als linksklik
			{
				cxy[x][y] = true; //coordinaten = clicked
			
				if(xy[x][y] == 0) //als gekozen vak 0 is: alle aansluitende 0-vakjes openen
				{
					int ax[grx*gry], ay[grx*gry]; //0-vakjes bijhouden
					ax[0]=x; ay[0]=y; //eerste 0-vakje = gekozen vakje
					int k=1; //teller 0-vakjes geheugen
					for(int l=0; ((ax[l])>=0 && (ax[l])<grx && (ay[l])>=0 && (ay[l])<gry); ++l) //herhalen tot er geen aangrenzende nullen meer zijn
						for(int i=-1; i<=1; ++i) for(int j=-1; j<=1; ++j) //alle omliggende vakjes controleren
							if(!cxy[(ax[l]+i)][(ay[l]+j)] && !rcxy[(ax[l]+i)][(ay[l]+j)]) //als huidig vakje al is aangeklikt, is verdergaan niet nodig
								if((ax[l]+i)>=0 && (ax[l]+i)<grx && (ay[l]+j)>=0 && (ay[l]+j)<gry) //niet buiten bord?
								{
									cxy[(ax[l]+i)][(ay[l]+j)] = true; //huidig vakje = clicked
									if(xy[(ax[l]+i)][(ay[l]+j)] == 0) //als huidig vakje = 0...
									{									
										ax[k] = (ax[l]+i); //...opslaan in 0-vakjes geheugen
										ay[k] = (ay[l]+j);
										++k;
									}
								}
				}
			}
		
			//gewonnen?
			win=true; //initialiseren op gewonnen
			for(int i=0; i<grx && win; ++i)for(int j=0; j<gry && win; ++j) //alle vakjes controleren zolang win=true
				if(!cxy[i][j] && xy[i][j]!=9) win = false; //is vakje geen mijn én niet aangeklikt? -> niet gewonnen
		}
	}
	bool error=false;
	char opn;
	cout << "\n-(N)ieuw spel \n-(O)pnieuw \n-(S)toppen \n"; //hoe verdergaan?
	do
	{		
		cout << "(N/O/S): "; cin >> opn; opn = tolower(opn);
		cin.clear(); //fout verwijderen
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //fout verwijderen
		if(!cin.good()) error = true;
	} while(error || (opn!='n' && opn!='o' && opn!='s'));
	switch(opn)
	{
		case 'n': //nieuw spel -> main aanroepen
			main();
			break;
		
		case 'o': //opnieuw -> spel aanroepen met zelfde grootte bord
			spel(grx, gry, nb, bx, by);
			break;
			
		case 's': //stoppen -> programma eindigen
			cout << endl << "Bedankt voor het spelen..." << endl;
			system("pause");
	}
}
