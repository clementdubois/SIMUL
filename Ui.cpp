#include "Ui.h"
#include "Enregistrement.h"
#include <iostream>
using namespace std;

/*-------------------Fonctions Membres----------------------------*/
void Ui::gestionMenu(){
    afficheMenu();
    choixMenu();
    redirectionMenu();
}

void Ui::afficheMenu(){
    printf("Veuillez choisir l'action ˆ effectuer\n");
    printf(" 1 - Creer un fichier \n");
    printf(" 2 - Inserer un enregistrement\n");
    printf(" 3 - Supprimer un enregistrement\n");
    printf(" 4 - Afficher un enregistrement\n");
    printf(" 5 - Afficher une page\n");
}

void Ui::choixMenu(){
    printf("Entrer le nombre : ");
    scanf("%d", &choix);
}

void Ui::redirectionMenu(){

    switch(choix){
        case 1 :
            //creationFichier();
            break;
        case 2 :
            nouvelEnregistrement();
            break;
        case 3 :
            printf("Choix : 3 \n");
            break;
        case 4 :
            printf("Choix : 4 \n");
            break;
        case 5 :
            printf("Choix : 5 \n");
            break;
        case 6 :
            printf("Choix : 6 \n");
            break;
    }
}

void Ui::nouvelEnregistrement(){
    Enregistrement e;

}


/*--------------------Constructor---------------------------------*/
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
