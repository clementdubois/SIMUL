#include "Ui.h"
#include "Enregistrement.h"
#include <iostream>
using namespace std;

/*-------------------Fonctions Membres----------------------------*/
void Ui::gestionMenu(){
    afficheMenu();
    choixMenu();
}

void Ui::afficheMenu(){
    cout << "-----------------------------------------" << endl;
    cout << "| Veuillez choisir l'action a effectuer |" << endl;
    cout << "| 1 - Creer un fichier                  |" << endl;
    cout << "| 2 - Inserer un enregistrement         |" << endl;
    cout << "| 3 - Supprimer un enregistrement       |" << endl;
    cout << "| 4 - Afficher un enregistrement        |" << endl;
    cout << "| 5 - Afficher une page                 |" << endl;
    cout << "| 6 - Quitter le programme              |" << endl;
    cout << "| 7 - Lancer les tests                  |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Ui::choixMenu(){
    cout << "Entrer le nombre : ";
    cin >> choix;
}

Enregistrement Ui::nouvelEnregistrement(){
    Enregistrement e;

    cout << "Entrer le nombre A : ";
    cin >> e.m_a;
    cout << "Entrer le texte B : ";
    cin >> e.m_b;

    return e;
}

int Ui::rechercherEnregistrement(){
    int cle;

    cout << "Quelle est la cle des l'enregistrements recherches : ";
    cin >> cle;

    return cle;
}

int Ui::afficherPage(){
    int indexPage;

    cout << "Quelle page voulez-vous afficher : ";
    cin >> indexPage;

    return indexPage;
}


/*-------------------Setter / Getter------------------------------*/
int Ui::getChoix(){
    return choix;
}

/*--------------------Constructor/Destructor----------------------*/
Ui::Ui(){
    if (alreadyCreated)
        cout << "Vous ne pouvez pas créer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on dŽclare l'objet crŽŽ
    alreadyCreated = true;
}

Ui::~Ui()
{
    // Si on veut pouvoir recréer la classe plus tard, on déclare l'objet non-existant
    alreadyCreated = false;
}

/*--------------------------Singleton-----------------------------*/
bool Ui::alreadyCreated = false;
