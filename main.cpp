/*******************************************
*AURORE: Napolitano Christian              *
*DATA CREAZIONE: 14/01/2019                *
*DATA ULTIMA MODIFICA: 10/02/2019          *
*PROGRAMMA: Battaglia navale               *
*CLASSE: 4IC                               *
*VERSIONE: 7                               *
*******************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define Mare 10
#define Vuoto 0
#define Nave 1
#define Colpito 2

using namespace std;

int campo[Mare][Mare]; //Griglia di battaglia formata da 10 per 10
int campo2[Mare][Mare]; //Griglia per le navi del computer
int riga; //Serve per gestire le righe della griglia
int colpisci; //Serve per vedere l'utente quanti navi colpisce
int spara; //Serve per vedere quante navi colpisce il computer
int uscita; 	  //Serve per far decidere all'utente se rimanere o uscire dal programma
int scelta; //Serve per gestire le scelte dell'utente nel menu
int controllo=0; //Serve per controllare se l'utente ha inserito le navi
int colonna; //Serve per gestire le colonne della griglia;
int infreg; //Serve per gestire il menu delle info e del regolamento
int cont; //Serve per far procedere dopo l'esempio del campo in funzione inserimento navi
void titolo (void); //Funzione per gestire il titolo dl programma
void riempimento_campo (void); //Serve per riempire il campo prima che l'utente inserisca le navi
void menu (void); //Funzione per gestire il menu del programma
void pulizia_schermo (void); //Serve per pulire lo schermo
void verifica_menu (void); //Funzione per verificare le scelte del menu
void inseriscinavi (void); //Funzione che gestisce l'inserimento delle navi nel campo da parte dell'utente
void inseriscipc (void); //Funzione che gestisce l'inserimento delle navi nel campo da parte del computer
void chiudere_gioco (void); //Funzione per chiudere gioco dal menu
void info_regole (void); //Funzione che gestisce le informazione del software
void partita (void); //Funzione per inizire la partita
void stampa_campo (void); //Funzione che stampa un campo di prova

int main()
{
    do			   //Il ciclo "do while" permette di ripetere il programma per il numero di volte desiderato
	{
    titolo();
    menu();
    cin >> scelta;
    verifica_menu();
			switch(scelta)
			{
				case 0:
                    chiudere_gioco();
					break;

				case 1:
				    inseriscipc();
                    riempimento_campo();
					inseriscinavi();
					controllo++;
					break;

				case 2:
					partita();
					break;

				case 3:
				    info_regole();
					break;
			}
			if(scelta !=0) //Serve per vedere che scelta ha eseguito l'utente per far chiudere il programma se l'utente ha inserito 0
				{
					cout << "\nInserire un qualsiasi numero per riaccedere al menu, 0 per chiudere: " << endl;
					cin >> uscita;
					pulizia_schermo();
				}
				else
				{
					return 0;
				}
	}while(uscita != 0);
    return 0;
}
void titolo (void) //Funzione che contiene e gestisce il titolo
{
	cout <<"\t ******* ******* *       ******* * ******* ******* *" << endl;
	cout <<"\t *       *     * *       *     * * *       *       *" << endl;
	cout <<"\t *       *     * *       ******* * ******* *       *" << endl;
	cout <<"\t *       *     * *       *       *       * *       *" << endl;
	cout <<"\t ******* ******* ******* *       * ******* ******* *" << endl;
	cout <<"\t                                                 *       *******       **    * ******* *       * *******" << endl;
	cout <<"\t                                                 *       *     *       * *   * *     *  *     *  *" << endl;
	cout <<"\t                                                 *       *******       *  *  * *******   *   *   ****" << endl;
	cout <<"\t                                                 *       *     *       *   * * *     *    * *    *" << endl;
	cout <<"\t                                                 ******* *     *       *    ** *     *     *     *******\n\n" << endl;
}





void verifica_menu (void) //Verifica che la scelta dell'utente nel menu sia da 0 a 5 tramite un if
{
	if(scelta>4 || scelta<0)
	{
		pulizia_schermo();
		titolo();
		cout << "Mi dispiace... Il numero inserito non e' corretto!\n\n" << endl;
		cout << "Inserire un numero compreso tra 0 e 4!\n" << endl;
	}
}



void inseriscinavi(void)
{
    int contatore=5;
    int i;
    pulizia_schermo();
    titolo();
    cout << "Vi mostro un campo di esempio!\n" << endl;
    stampa_campo();
    cout << "Inserisci qualsiasi valore per continuare o 0 per terminare la sezione!\n" <<endl;
    cin >> cont;
    if (cont!=0)
    {
        pulizia_schermo();
        titolo();
        cout << "\t\tBenvenuto inizia a posizionare le tue navi!\n\n" << endl;
        cout << "Per inserire la nave scegli la riga e la colonna , con i numeri da 0 a 9!\n\n";
        for(i=1; i<=5; i++)
        {
            cout << "\t\tHai a disposizione: " << contatore << " navi!\n\n";
            cout << "Inserisci la riga dove vuoi inserire la nave:" << endl;
            cin >> riga;
            cout << "Inserisci la colonna dove vuoi inserire la nave:" << endl;
            cin >> colonna;
            if(campo[riga][colonna]==Vuoto)
            {
                campo[riga][colonna]=Nave;
                contatore=contatore-1;
            }
            else
            {
                cout << "\t\tIn questa poizione gia' e' stata inserita una nave!\n" << endl;
                cout << "Inserisci una nuova riga dove vuoi inserire la nave:" << endl;
                cin >> riga;
                cout << "Inserisci luna nuova colonna dove vuoi inserire la nave:" << endl;
                cin >> colonna;
                campo[riga][colonna]=Nave;
                contatore=contatore-Nave;
            }
        }
        pulizia_schermo();
        titolo();
        cout << "\t\tPerfetto, hai finito di posizionare le navi!\n\n";
        cout << "Dove e' presente il numero 1, indica che e' posizionata una nave!\n\n";
        int j;
        int x;
        for(j=0; j<=9; j++ )
        {
            cout << "\t\t";
            for(x=0; x<=9; x++)
            {
                cout << " " << campo[j][x];
            }
            cout << "\n" << endl;
        }
        cout << "Adesso che hai visto le tue navi posizionate nel campo, torna nel menu per iniziare a giocre!\n\n" << endl;
    }
   /* else
    {
        chiudere_gioco();
    }*/
}




void menu (void) //Funzione che contiene e gestisce il menu
{
	cout << "\t\t*************************************************************************************\n" << endl;
	cout << "\t\t* 1) POSIZIONA NAVI     *			              * 3) INFO E REGOLE    *\n\n" << endl;
	cout << "\t\t* 2) INIZIA A GIOCARE   *                                     * 0) ESCI DAL GIOCO   *\n\n" << endl;
	cout << "\t\t*************************************************************************************\n\n\n" << endl;
	cout << "Fare una scelta inserendo di seguito il numero corrispondete al comando desiderato: " << endl;
}


void chiudere_gioco (void) //Serve per chiudere gioco intesa come programma dal menu
{
	pulizia_schermo();
	titolo();
	cout << "\t\t\t\t\t\t******************\n" << endl;
	cout << "\t\t\t\t\t\t*  ARRIVEDERCI!  *\n" << endl;
	cout << "\t\t\t\t\t\t******************\n\n" << endl;
}

void riempimento_campo (void) //Serve per riempire il campo prima che l'utente inserisce le navi
{
    int j;
    int x;
    for(j=0; j<=9; j++ )
    {
        for(x=0; x<=9; x++)
        {
                campo[j][x]=Vuoto;
        }
    }
}


void inseriscipc (void) //Funzione che gestisce l'inserimento navi del computer
{
    int x;
    int j;
    pulizia_schermo();
	titolo();
    campo2[1][9]=Nave;
    campo2[0][5]=Nave;
    campo2[7][3]=Nave;
    campo2[4][1]=Nave;
    campo2[8][7]=Nave;
    /*for(j=0; j<=9; j++ )
    {
        cout << "\t\t";
        for(x=0; x<=9; x++)
        {
                cout << "  " << campo2[j][x];
        }
     cout << "\n" << endl;
    }*/
}


void pulizia_schermo (void) //Serve per pulire lo schermo
{
    system("cls");
}

void info_regole (void) //Serve per gestire le informazioni e il regolamento del software
{
    pulizia_schermo();
    titolo();
    cout <<"\tBenvenuto, per visualizzare le informazioni del software inserire in volere 3, per visualizzare il regolemento del gioco inserice 5\n" << endl;
    cin>> infreg;
    if(infreg==3)
    {
        pulizia_schermo();
        titolo();
        cout <<"Stai giocado alla settima versione del software, presto ci saranno' altri aggiornameni tieniti pronto!\n" << endl;
        cout <<"L'autore del software e' Napolitano Christian!\n" << endl;
    }
    else
    {
        pulizia_schermo();
        titolo();
        cout <<"Con questo software, si puo' giocare alla battaglia navale contro il compute!" << endl;
        cout <<"Bisogna posizionarsi le proprie navi, e dopo si puo' iniziare a giocare la partite!" << endl;
        cout <<"Si hanno a disposizione 5 colpi ciascuono, chi colpisce piu' navi vince!" << endl;
    }
}

void partita(void)
{
    int i,j,x;
    int colpi=5; //Serve per gestoire i 5 colpi dell'utente
    pulizia_schermo();
    titolo();
    if(controllo==0)
    {
        cout <<"Mi dispiace ma devi inserire prima le tue navi per poter giocare!\n\n" << endl;
    }
    else
    {
        controllo=0;
        cout <<"\t\t\tPerfetto, ora che hai posizionato le tue navi possiamo iniziare la partita!\n\n" << endl;
        cout <<"Hai a disposizione 5 colpi, dopo i tuoi colpi spara il computer!\n\n\n" << endl;
        for(i=1;i<=5;i++)
        {
            cout << "\t\tHai a disposizione ancora: " << colpi << " colpi!\n\n";
            cout <<"Inserisci il numero della riga a cui vuoi sparare" << endl;
            cin >> riga;
            cout <<"Inserisci il numero della colonna a cui vuoi sparare" << endl;
            cin >> colonna;
            colpi=colpi-1;
            if(campo2[riga][colonna]==1)
            {
                campo2[riga][colonna]=Colpito;
                cout <<"\t\t\tPERFETTO HAI COLPITO LA NAVE DEL COMPUTER!\n\n\n" << endl;
                colpisci++;
            }
            else
            {
                cout <<"\t\t\tMi dispiace ma hai mancato il colpo!\n\n\n" << endl;
            }
        }
        system ("PAUSE");
        pulizia_schermo();
        titolo();
        colpi=5;
        cout << "\t\t\tPerfetto ora spara il computer!\n\n" << endl;
        for(i=1; i<=5; i++)
        {
            cout << "\t\tIl computer ha a  disposizione ancora: " << colpi << " colpi!\n\n";
            riga=i;
            colonna=i;
            colpi=colpi-1;
            if(campo[riga][colonna]==1)
            {
                campo[riga][colonna]=Colpito;
                cout <<"IL COMPUTER HA COLPITO LE TUE NAVI!\n\n\n" << endl;
                spara++;
            }
            else
            {
                cout <<"Il computer non ha colpito le tue navi!\n\n\n" << endl;
            }
        }
        system("PAUSE");
        pulizia_schermo();
        titolo();
        cout <<"\t\tEcco il tuo campo, dove e' presente il valore 2 significa che il computer ha colpito le navi!\n\n" << endl;
        for(j=0; j<=9; j++ )
        {
            cout << "\t\t";
            for(x=0; x<=9; x++)
            {
                cout << " " << campo[j][x];
            }
            cout << "\n" << endl;
        }
        system("PAUSE");
        pulizia_schermo();
        titolo;
        if(spara==colpisci)
        {
            titolo();
            cout <<"Mi dispiace ma la partita e' finita in parita', tu e il computer avete colpito lo stesso numeri di navi!\n\n" << endl;
            cout <<"Il computer ha colpito: " << spara << " navi!\n" << endl;
            cout <<"Tu hai colpito: " << colpisci << " navi!\n" <<endl;
            spara=0;
            colpisci=0;
        }
        else if(spara<colpisci)
        {
            titolo();
            cout <<"Complimenti, hai vinto!\n" << endl;
            cout <<"Il computer ha colpito: " << spara << " navi!\n" << endl;
            cout <<"Tu hai colpito: " << colpisci << " navi!\n" <<endl;
            spara=0;
            colpisci=0;
        }
        else
        {
            titolo();
            cout <<"Mi dispiace ma hai perso, il computer ha colpito piu navi!\n" << endl;
            cout <<"Il computer ha colpito: " << spara << " navi!\n" << endl;
            cout <<"Tu hai colpito: " << colpisci << " navi!\n" <<endl;
            spara=0;
            colpisci=0;
        }
    cout <<"\n\n\t\tLa partita e' terminata, per rigiocare bisogna riaccedere al menu!\n\n" << endl;
    }
}


void stampa_campo (void) //Funzione che stampa un campo di prova
{
    cout <<"\t\t    0  1  2  3  4  5  6  7  8  9\n" << endl;
    cout <<"\t\t 0  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 1  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 2  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 4  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 5  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 6  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 7  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 8  #  #  #  #  #  #  #  #  #  #\n" << endl;
    cout <<"\t\t 9  #  #  #  #  #  #  #  #  #  #\n" << endl;
}
