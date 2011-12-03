#ifndef UI_H
#define UI_H

#include "Enregistrement.h"

class Ui
{
    public:
        Ui();
        ~Ui();
        void gestionMenu();
        int getChoix();
        Enregistrement nouvelEnregistrement();
        int rechercherEnregistrement();
        int afficherPage();

    protected:
    private:
        void afficheMenu();
        void choixMenu();

        static bool alreadyCreated;
        int choix;
};

#endif // UI_H
