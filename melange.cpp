#include "melange.h"
#include <string>
#include <iostream>

#include <ctime>
#include <cstdlib> // Bibliothèque pour utiliser la fonction aléatoire


using namespace std;


string melangeMot(string motMystere)

{
    string motMelange ;


while (motMystere.size()!=0)

            {


            srand(time(0));

            int position = rand() % motMystere.size(); // on tire une lettre au hasard entre 0 et le nombre de lettre du mot indiqué (size)

            motMelange+=motMystere[position];

            motMystere.erase(position, 1);  // Retire la lettre de la position

            }


    return motMelange;

}
