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
    printf("Veuillez choisir l'action � effectuer\n");
    printf(" 1 - Creer un fichier \n");
    printf(" 2 - Inserer un enregistrement\n");
    printf(" 3 - Supprimer un enregistrement\n");
    printf(" 4 - Afficher un enregistrement\n");
    printf(" 5 - Afficher une page\n");
    printf(" 6 - Quitter le programme");
}

void Ui::choixMenu(){
    printf("Entrer le nombre : ");
    scanf("%d", &choix);
}


/*-------------------Setter / Getter------------------------------*/
int Ui::getChoix(){
    return choix;
}

/*--------------------Constructor---------------------------------*/
Ui::Ui(){
    if (alreadyCreated)
        cout << "Vous ne pouvez pas cr�er une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on d�clare l'objet cr��
    alreadyCreated = true;
}

Ui::~Ui()
{
    // Si on veut pouvoir recr�er la classe plus tard, on d�clare l'objet non-existant
    alreadyCreated = false;
}

/*--------------------------Singleton-----------------------------*/
bool Ui::alreadyCreated = false;
