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
    cout << "Veuillez choisir l'action ˆ effectuer" << endl;
    cout << " 1 - Creer un fichier"                 << endl;
    cout << " 2 - Inserer un enregistrement"        << endl;
    cout << " 3 - Supprimer un enregistrement"      << endl;
    cout << " 4 - Afficher un enregistrement"       << endl;
    cout << " 5 - Afficher une page"                << endl;
    cout << " 6 - Quitter le programme"             << endl;
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


/*-------------------Setter / Getter------------------------------*/
int Ui::getChoix(){
    return choix;
}

/*--------------------Constructor/Destructor----------------------*/
Ui::Ui(){
    if (alreadyCreated)
        cout << "Vous ne pouvez pas crŽer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on dŽclare l'objet crŽŽ
    alreadyCreated = true;
}

Ui::~Ui()
{
    // Si on veut pouvoir recrŽer la classe plus tard, on dŽclare l'objet non-existant
    alreadyCreated = false;
}

/*--------------------------Singleton-----------------------------*/
bool Ui::alreadyCreated = false;
