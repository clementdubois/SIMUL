#ifndef TESTCOEUR_H
#define TESTCOEUR_H
#include "Coeur.h"
using namespace std;
/*Classe qui permet de tester les méthodes de la classe coeur*/

class TestCoeur
{
    public:
        TestCoeur();
        virtual ~TestCoeur();
        void testPlaceEnregistrement(); //test la méthode placeEnregistrement

        void ajouterTest();
        bool verification(Coeur c, map<int, vector<int> > datas, int i);
        void ajouterA(vector<int>& vect, stringstream &linestream);

    protected:
    private:
        Coeur coeur; //La classe coeur que l'on va tester
};

#endif // TESTCOEUR_H
