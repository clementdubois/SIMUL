#include <iostream>
#include "Enregistrement.h"
#include "Page.h"
#include "Fichier.h"
#include "Coeur.h"
#include "Ui.h"
#include "Bucket.h"
#include <vector>

using namespace std;

int main()
{
    //Coeur coeur;
    Ui ui;
    Bucket b;
    b.addPage(Page());
    b.addPage(Page());

    cout << b << endl;

    bool quit=false;

    while(!quit){
        ui.gestionMenu();

        switch(ui.getChoix()){
        case 1 :
            //creationFichier();
            break;
        case 2 :
//            coeur.placeEnregistrement(ui.nouvelEnregistrement());
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
        default :
            quit = true;
        }
    }

    return 0;
}
