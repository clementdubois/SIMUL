#include <iostream>
#include "Enregistrement.h"
#include "Page.h"
#include "Fichier.h"
#include "Coeur.h"
#include "Ui.h"
#include "Bucket.h"
#include "TestCoeur.h"
#include <vector>
#include <map>

using namespace std;

int main()
{
    //Coeur coeur;
    Ui ui;
    Page p;
    Coeur coeur;
    Enregistrement e;
    map<int, Page> pages;
    //TestCoeur tests;

    bool quit=false;

    while(!quit){
        ui.gestionMenu();

        switch(ui.getChoix()){
        case 1 :
            //creationFichier();
            break;
        case 2 :
            e = ui.nouvelEnregistrement();
            coeur.placeEnregistrement(e);
            cout << coeur << endl;
            break;
        case 3 :
            printf("Choix : 3 \n");
            break;
        case 4 :
            int cle;
            cle = ui.rechercherEnregistrement();
            coeur.trouverEnregistrement(cle);
            break;
        case 5 :
            int indexPage;
            indexPage = ui.afficherPage();
            cout << coeur.trouverPage(indexPage);
            break;
        case 6 :
            coeur.placeEnregistrement(Enregistrement(7, "a"));
            coeur.placeEnregistrement(Enregistrement(12, "az"));
            coeur.placeEnregistrement(Enregistrement(5, "aze"));
            coeur.placeEnregistrement(Enregistrement(3, "azer"));
            coeur.placeEnregistrement(Enregistrement(20, "azert"));
            coeur.placeEnregistrement(Enregistrement(6, "azerty"));
            coeur.placeEnregistrement(Enregistrement(10, "azertyu"));
            coeur.placeEnregistrement(Enregistrement(4, "azertyui"));

            cout << coeur;
            break;
        case 7 :
            //tests.testPlaceEnregistrement();
            break;
        default :
            quit = true;
        }
    }

    return 0;
}
