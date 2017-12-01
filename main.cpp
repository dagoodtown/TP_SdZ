#include <iostream>
#include <fstream>
#include <string>
#include "melange.h"
#include <ctime>
#include <cstdlib> // Bibliothèque pour utiliser la fonction aléatoire



using namespace std;

/* PLAN

1. on demande combien de joueur : 1 ou 2 ?


2. on demande la difficulté : facile (10 chances max ; 1 point / mot) intermédiaire (5 chances max ;2 point/mot) difficile (2 chances max 5point /mots) ?

2.  Si 2 joueurs :
                    - joueur1 donne le mot et joueur2 devinne puis on inverse ;
                    - on donne le score et on demande si on recommence ;
    Si 1 joueur :
                    - on pioche un mot dans le dictionnaire, on mélange et le joueur devine ;
                    - on donne le score et on demande si on recommence ;
                    - on demande le nom et on enregistre le meilleur score le cas échéant ;

*/

int main()

{
   bool continuePartie (1);
   int nombreJoueur(2), niveau (1), chance (10), points (10), score (0);
   string motMystere, motTentative;

   cout << "----- NOMBRE DE JOUEUR.SE -----" << endl << endl
   << "(1) 1 Joueur.se" << endl
   << "(2) 2 Joueur.ses" << endl <<endl
   << "Combien de joueur.se ?"<<endl<< endl;

   cin >> nombreJoueur ;

   cout << endl << "----- NIVEAU -----" << endl << endl << endl

   << "(1)  FACILE ......... 10 chances ---- 1pt/mot" <<endl
   << "(2)  INTERMEDIAIRE ... 5 chances ---- 2pt/mot" <<endl
   << "(3)  DIFFICILE ....... 2 chances ---- 5pt/mot" <<endl<<endl
   << "Quel est le niveau ?" <<endl<<endl;

   cin >> niveau;

   if (niveau==1)    // En fonction du niveau, on associe un nombre de chance
    {chance=10;
     points=1;}
   else if (niveau==2)
    {chance=5;
     points=2;}
   else if (niveau==3)
    {chance=2;
     points=5;}


    if (nombreJoueur==2)
    {
      while(continuePartie==1)
      {

            cout << "----- Joueur.se_1 -----"<<endl<<"Indiquez un mot et appuyer sur entrée pour valider"<<endl<<endl;   //1 : On demande de saisir un mot
            cin >> motMystere;
            cout << "Merci"
            <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
            <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
            <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
            <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout << "----- Joueur.se_2 ----- "
            <<endl<<endl<< "==>   " << melangeMot(motMystere)<<" ?"<<endl<<endl<<"Quel est ce mot mystère ? Vous avez " << chance << " chances."<<endl<<endl; // 2 : On mélange avec la fonction
            cin >> motTentative;
            cout<<endl;

        while (motMystere!=motTentative&&chance>1)
        {
                chance-=1;

                cout<<"Ce n'est pas le mot correct. Il vous reste "<< chance << " chances." << endl<<endl;
                cout<< "Quel est le mot mystère ?" << endl;
                cin>> motTentative;
                cout<<endl;
        }

        if(motMystere==motTentative)
        {score += points;
         cout << "Bravo ! Votre score est : " << score << " points."<<endl;}

        // Vérifier le meilleur score et enregistrer le cas échéant.


        else
        {
        cout<<endl<<endl<<" ---GAME OVER---"<<endl<<endl
        << "Votre score est : " << score << " points."<<endl;
        }

        cout<< "Voulez-vous rejouer ?" << endl<<endl
        << "(1) Oui"<< endl
        << "(0) Non" <<endl;

        cin >> continuePartie;
    }


    }
    if (nombreJoueur==1) // Partie à 1 joueur
    {
    while (continuePartie==1)
    {
        ifstream fichier("fichiers/dico.txt");  //Ouverture d'un fichier en lecture
        if(fichier)
        {

            fichier.seekg(0, ios::end);  //On se déplace à la fin du fichier pour connaître la taille
            int taille;
            taille = fichier.tellg();
            cout << "Taille du fichier : "<<taille<<" octets."<< endl;

            srand(time(0));

            int positionMot = rand() % taille; //on détermine la position du mot à extraire entre 0 et la taille du fichier
            cout<<"Un nombre au hasard : "<<positionMot<<endl;

            string mot;
            fichier >> mot;

        }

    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
       // lecture du fichier source et choix aléatoire d'un motMystère



        cout<< "==>   " << melangeMot(motMystere)<<" ?"
        <<endl<<endl<<"Quel est ce mot mystère ? Vous avez " << chance << " chances."<<endl<<endl; // 2 : On mélange avec la fonction
        cin >> motTentative;
        cout<<endl;


        while (motMystere!=motTentative&&chance>1)
        {
                chance-=1;

                cout<<"Ce n'est pas le mot correct. Il vous reste "<< chance << " chances." << endl<<endl;
                cout<< "Quel est le mot mystère ?" << endl;
                cin>> motTentative;
                cout<<endl;
        }

        if(motMystere==motTentative)
        {score += points;
         cout << "Bravo ! Votre score est : " << score << " points."<<endl;}

        // Vérifier le meilleur score et enregistrer le cas échéant.


        else
        {
        cout<<endl<<endl<<" ---GAME OVER---"<<endl<<endl
        << "Votre score est : " << score << " points."<<endl;
        }


    cout<< "Voulez-vous rejouer ?" << endl<<endl
        << "(1) Oui"<< endl
        << "(0) Non" <<endl;

        cin >> continuePartie;

    }
    }

    return 0;
}
