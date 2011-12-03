#include "TestCoeur.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
/*------------------------Fonctions Membres----------------------------*/
void TestCoeur::testPlaceEnregistrement(){
    /*Initialisation des variables du coeur*/
        coeur.reinitialiser();
    /*Pr�paration des variables de tests*/
        vector<int> a;              //Liste des enregistrements � tester
        vector<int> n;              //Quelle est la valeur de n
        vector<int> next;           //Sur quelle page pointe next
        vector<int> occupation;     //Occupation des pages
        vector<int> nbBuckets;      //Num�ro du dernier bucket
        vector<int> nbDebordement;  //Nombre de page de d�bordement
        vector<int> ronde;          //Numero du bucket max de la ronde

        ifstream tests("/Users/clement/Documents/Clement/travail/BDD/Hachage/HachageCPP/tests.txt");
        if(tests){
            /*Ins�re les donn�es tests du fichier dans les diff�rentes variables*/
            string line;

            //Pour chaque ligne du fichier
            for(int i = 0; getline(tests, line); i++){
                stringstream linestream(line);
                //Pour chaque mot de la ligne
                switch(i){
                    case 0 :
                        ajouterA(a, linestream);
                        break;
                    case 1 :
                        ajouterA(n, linestream);
                        break;
                    case 2 :
                        ajouterA(next, linestream);
                        break;
                    case 3 :
                        ajouterA(occupation, linestream);
                        break;
                    case 4 :
                        ajouterA(nbBuckets, linestream);
                        break;
                    case 5 :
                        ajouterA(nbDebordement, linestream);
                        break;
                    case 6 :
                        ajouterA(ronde, linestream);
                        break;
                }

            }

            //On effectue les tests
            for(unsigned int i=0; i<a.size(); i++){
                //Donn�e d'entr�e du test
                char b[46] = "azerty";
                Enregistrement e(a[i], b);
                //test la m�thode
                coeur.placeEnregistrement(e);

                //V�rifie que les donn�es correspondent aux donn�es attendus
                if(coeur.m_n == n[i]){
                    if(coeur.m_occupation == (unsigned int)occupation[i]){
                        if(coeur.m_nbBuckets == nbBuckets[i]){
                            if((coeur.m_minDebordement - (NOMBRE_PAGE - 1)) == nbDebordement[i]){
                                if(coeur.m_next == next[i]){
                                    cout << "O";
                                }else{
                                    cout << "X" << endl;
                                    cout << "Echec du test : "<< endl << "next devrait valoir : " << next[i] << " Mais vaut : " << coeur.m_next << endl;
                                    cout << "Echec � l'�tape : " << i;
                                }
                            }else{
                                cout << "X" << endl;
                                cout << "Echec du test : "<< endl << "minDebordement devrait valoir : " << nbDebordement[i] + (NOMBRE_PAGE-1) << " Mais vaut : " << coeur.m_minDebordement << endl;
                                cout << "Echec � l'�tape : " << i;
                            }
                        }else{
                            cout << "X" << endl;
                            cout << "Echec du test : "<< endl << "nbBuckets devrait valoir : " << nbBuckets[i] << " Mais vaut : " << coeur.m_nbBuckets << endl;
                            cout << "Echec � l'�tape : " << i;
                        }
                    }else{
                        cout << "X" << endl;
                        cout << "Echec du test : "<< endl << "occupation devrait valoir : " << hex << occupation[i] << " Mais vaut : " << hex << coeur.m_occupation << endl;
                        cout << "Echec � l'�tape : " << i;
                    }
                }else{
                    cout << "X" << endl;
                    cout << "Echec du test : "<< endl << "n devrait valoir : " << n[i] << " Mais vaut : " << coeur.m_n << endl;
                    cout << "Echec � l'�tape : " << i;
                }

            }
        }
        else{
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    /*V�rification des r�sultats*/
}

void TestCoeur::ajouterA(vector<int>& vect, stringstream &linestream){
    int nb;
     while(linestream >> nb){
            //On enregistre la valeur dans le bon vector
            vect.push_back(nb);
    }
}

bool TestCoeur::verification(Coeur c, map<int, vector<int> > datas, int i){

}

/*Ajoute un test cr�er par l'utilisateur*/
void TestCoeur::ajouterTest(){
}

/*--------------------Constructor/Destructor----------------------*/

TestCoeur::TestCoeur()
{
    //ctor
}

TestCoeur::~TestCoeur()
{
    //dtor
}
