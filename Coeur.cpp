#include "Coeur.h"
#include <math.h>
#include <iostream>
using namespace std;


/*------------------------Fonctions Membres----------------------------*/
void Coeur::placeEnregistrement(Enregistrement enr){

    //On hache l'entier de l'enregistrement pour obtenir la cle du bucket
    int cleHashage = hachage(enr.m_a);
    int clePage = cleHashage;

        //On vérifie que la première page du bucket 'cle' existe
        Page p = m_pages[clePage];
        if(estLibre(clePage))
            m_occupation += pow(2, clePage);


        cout << "0 : clePage:: " << clePage << endl;
        cout << "1 : occupation :: " << m_occupation << endl;

        //Tant que la page est pleine et qu'on a une page de débordement ...
        cout << "PLEINE : " << p.estPleine();
        while(p.estPleine() && p.debord()){
            //... On teste la page de débordement
            clePage = p.getPageDebordement();
            cout << "pas rentré" << endl;
            p = m_pages[clePage];
        }


        //Si la page est pleine mais qu'elle n'a pas de page suivante
        if(p.estPleine()){
            cout << "pas rentrer est pleine" << endl;
            //On créer la page de debordement
                m_pages[m_minDebordement];
                //On indique qu'on utilise la page minDebordement
                m_occupation += pow(2, m_minDebordement);
                //On ajoute une page de débordement à la page du tableau
                m_pages[clePage].ajouterPageDebordement(m_minDebordement);

            //On insère l'enregistrement e dans un espace vide de la page
                m_pages[m_minDebordement].insererEnregistrement(enr);
            //On indique que la prochaine page de débordement devra se situer sur la page précédente
                m_minDebordement--;

            //On rehache le bucket qui commence avec la page pointé par next
                p = m_pages[m_next];
                clePage = m_next;
                //On passe par chaque page du bucket
                do{
                    //Pour chque enregistrement de la page
                    for(int i=0; i<NOMBRE_ENREGISTREMENT; i++){
                        //Si l'enregistrement est utilisé on le réhache
                        if(!p.estLibre(i)){
                            //On récupère l'enregistrement à réhacher
                            Enregistrement aRehacher = m_pages[clePage].getEnregistrement(i);
                            //On enlève l'enregistrement de la page
                            m_pages[clePage].supprimerEnregistrement(i);
                            //On rehache l'enregistrement
                            int rehach = hachage(aRehacher.m_a);
                            //On place l'enregistrement à sa nouvelle position
                                while(m_pages[rehach].estPleine() && m_pages[rehach].debord()){
                                    rehach = m_pages[rehach].getPageDebordement();
                                }
                                //Si la page est toujours pleine...
                                if(m_pages[rehach].estPleine()){
                                    //On créer la page de débordement
                                    m_pages[rehach].ajouterPageDebordement(m_minDebordement);
                                    rehach = m_minDebordement;
                                    //On indique qu'on utilise la page minDebordement
                                    m_occupation += pow(2, m_minDebordement);
                                    m_minDebordement--;
                                }
                                //On insère l'enregistrement
                                m_pages[rehach].insererEnregistrement(aRehacher);
                        }
                    }
                    clePage = p.getPageDebordement();
                    p = m_pages[clePage];

                }while(p.debord());

                //On gère le next
                    //Si il est au bout de la ronde, on le remet à 0 et on incrément la fonction de hachage
                    if(m_next == (pow(2,m_n)-1)){
                        m_next = 0;
                        m_n += 1;
                    }else{ //Sinon on incrément le next
                        m_next += 1;
                    }

        }else{
            //On insère l'enregistrement e dans un espace vide de la page
            cout << "Entrer ELSE" << endl;
            m_pages[clePage].insererEnregistrement(enr);
            cout << "Occupation apres insertion : " << m_occupation << endl;
        }


}

int Coeur::trouverPage(int cle){
   return 0;
}

void Coeur::creerPageDebordement(){

}

/*Hache l'entier a par la fonction de hachage n*/
int Coeur::hachage(int a){
    return a % (int)pow(2,(double)m_n);
}

bool Coeur::estLibre(int n){
    return (!(m_occupation >> n & 1));
}


/*----------------------Affichage ------------------*/
void Coeur::afficher(ostream &out) {
    out << "==============================================" << endl;
    out << "|     n     |     next     |    occupation    | "<< endl;
    out << "----------------------------------------------" << endl;
    out << "|      "<< m_n<< "      |       "<< m_next << "      |       "<< m_occupation<< " |      " << endl;
    out << "==============================================" << endl;

    out << "===============" << endl;
    out << "||   PAGES   ||" << endl;
    out << "===============" << endl;

    //On affiche chaque page utilisée
    for(int i=1, lequel=0; i<256; i*=2, lequel++){
        if(m_occupation & i){
            out << lequel << " : " << endl;
            out << "--------------------------------------------"     << endl;
            out << m_pages[lequel];
            out << "--------------------------------------------"     << endl;
        }
    }
}

ostream& operator<<(ostream& out, Coeur coeur){
    coeur.afficher(out);
    return out;
}


/*--------------------Getter / Setter ----------------------*/

map<int, Page> Coeur::getPages(){
    return m_pages;
}

/*--------------------Constructor/Destructor----------------------*/
Coeur::Coeur(){
    cout << "constuctor" << endl;
    if (m_alreadyCreated)
        cout << "Vous ne pouvez pas creer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on declare l'objet cree
    m_alreadyCreated = true;

    m_n=0;
    m_next = 0;
    m_ronde = 0;

    m_maxDirect = 0;
    m_minDebordement = NOMBRE_PAGE - 1;
}

Coeur::~Coeur()
{
    // Si on veut pouvoir recreer la classe plus tard, on declare l'objet non-existant
    m_alreadyCreated = false;
}

bool Coeur::m_alreadyCreated = false;
