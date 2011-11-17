#include "Ui.h"
#include "Enregistrement.h"
#include <iostream>
using namespace std;

/*-------------------Fonctions Membres----------------------------*/
void Ui::gestionMenu(){
    int choix;

    afficheMenu();
    choix = choixMenu();
    redirectionMenu(choix);
}

void Ui::afficheMenu(){
    printf("Veuillez choisir l'action à effectuer\n");
    printf(" 1 - Créer un fichier \n");
    printf(" 2 - Inserer un enregistrement\n");
    printf(" 3 - Supprimer un enregistrement\n");
    printf(" 4 - Afficher un enregistrement\n");
    printf(" 5 - Afficher une page\n");
}

int Ui::choixMenu(){
    int choix = 0;
    printf("Entrer le nombre : ");
    scanf("%d", &choix);
    return choix;
}

void Ui::redirectionMenu(int choix){

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
        cout << "Vous ne pouvez pas créer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on déclare l'objet créé
    alreadyCreated = true;
}

Ui::~Ui()
{
    // Si on veut pouvoir recréer la classe plus tard, on déclare l'objet non-existant
    alreadyCreated = false;
}

/*--------------------------Singleton-----------------------------*/
bool Ui::alreadyCreated = false;
