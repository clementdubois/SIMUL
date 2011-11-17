#include <iostream>
#include "Enregistrement.h"
#include "Page.h"
#include "Fichier.h"
#include "Coeur.h"
#include "Ui.h"

using namespace std;

int main()
{
    Coeur coeur;
    Ui ui;
    Enregistrement e;
    Page p;
    Fichier f;

    ui.gestionMenu();

    cout << sizeof(e.m_b) << " " << sizeof(f.m_pages[0].m_enregistrements[0]) << endl;
    return 0;
}


