#include "Coeur.h"
#include <math.h>
#include <iostream>
using namespace std;

/*------------------------Fonctions Principales----------------------------*/
void Coeur::placeEnregistrement(Enregistrement enr){

    //On hache l'entier de l'enregistrement pour obtenir la cle du bucket
    int cleHashage = hachage(enr.m_a, m_n);
    //Si le bucket n'existe pas encore, on utilise la fonction de hachage pr�c�dente
    if(cleHashage > m_nbBuckets){
        cleHashage = hachage(enr.m_a, m_n - 1);
    }
    int clePage = cleHashage;

    /*On cherche l'index de la premi�re page du bucket qui contient un enregistrement libre
        ou le cas �ch�ant la derni�re page du bucket*/
    clePage = premierePageNonRemplieBucket(clePage);

    //Si la page est pleine (derni�re page du bucket) mais qu'elle n'a pas de page suivante
    int precedente=-1; // pour garder une trace de la page qui pr�c�de une page de d�bordement
    if(m_pages[clePage].estPleine()){
        //On cr�er la page de debordement
        int pageDeb = ajouterPageDebordement(clePage);
        //On cr�er un nouveau bucket
        ajouterBucket(m_nbBuckets+1);
        //On ins�re l'enregistrement e dans un espace vide de la page
        m_pages[pageDeb].insererEnregistrement(enr);

        if(m_next == 0)
            m_n++;

        //On passe par chaque page du bucket pour le rehacher
        clePage = m_next;
        do{
            if(precedente == clePage)
                clePage = m_pages[clePage].getPageDebordement();

            //Pour chaque enregistrement de la page
            for(int i=0; i<NOMBRE_ENREGISTREMENT; i++){

                //Si il y a un enregistrement, on le r�hache
                if(!m_pages[clePage].estLibre(i)){

                    //On r�cup�re l'enregistrement � r�hacher
                    Enregistrement aRehacher = m_pages[clePage].getEnregistrement(i);
                    //On enl�ve l'enregistrement de la page
                    m_pages[clePage].supprimerEnregistrement(i);
                    //On rehache l'enregistrement
                    int rehach = hachage(aRehacher.m_a, m_n);

                    //Si le bucket rehach n'existe pas on rehach avec la fonction pr�c�dente
                    if(m_pages.find(rehach) == m_pages.end()){
                        rehach = hachage(aRehacher.m_a, m_n - 1);
                    }

                    //On place l'enregistrement � sa nouvelle position
                    rehach = premierePageNonRemplieBucket(rehach);
                    //Si la page est toujours pleine...

                    if(m_pages[rehach].estPleine()){
                        //On cr�er la page de d�bordement
                        rehach = ajouterPageDebordement(rehach);
                    }

                    //On ins�re l'enregistrement
                    m_pages[rehach].insererEnregistrement(aRehacher);
                }

            }

            //Si la page est vide et qu'il s'agissait d'une page de d�bordement, on la supprime
            if(m_pages[clePage].estVide() && isDebordement(clePage)){
                int suivante = supprimerPage(clePage);

                if(suivante != -1)
                    m_pages[precedente].ajouterPageDebordement(suivante);
                else
                    m_pages[precedente].supprimerPageDebordement(suivante);
            }

            if(m_pages[clePage].debord()){
                precedente = clePage;
            }
            else //Si la page ne d�borde pas, on sort de la boucle
                break;

        }while(m_pages[clePage].debord());

        //On g�re le next
        //Si il est au bout de la ronde, on le remet � 0
        if(m_next == (m_ronde-1)){
            m_next = 0;
            m_ronde <<= 1;
        }else{ //Sinon on incr�ment le next
            m_next += 1;
        }

    }else{
        //On ins�re l'enregistrement e dans un espace vide de la page
        m_pages[clePage].insererEnregistrement(enr);
    }
}

/*Trouve toute les occurences d'un enregistrement ayant l'index a
* @param a valeur a de l'enregistrement recherch�
* @return vector ou le premier �l�ment est l'index de la page et les suivants le num�ro de l'enregistrement dans la page
*/
vector<Enregistrement> Coeur::trouverEnregistrement(int a){
    //On hache l'entier de l'enregistrement pour obtenir la cle du bucket
    int numPage = hachage(a, m_n);
    //Si le bucket n'existe pas encore, on utilise la fonction de hachage pr�c�dente
    if(numPage > m_nbBuckets){
        numPage = hachage(a, m_n - 1);
    }
    Page p;
    int precedente = numPage;
    vector<Enregistrement> results;

    do{
        p=m_pages[numPage];
        for(int n=0; n<NOMBRE_ENREGISTREMENT; n++){
            if(!p.estLibre(n) && p.getEnregistrement(n).m_a == a)
                results.push_back(p.getEnregistrement(n));
        }

        precedente = numPage;
        if(p.debord())
            numPage = m_pages[numPage].getPageDebordement();

    }while(precedente != numPage);

    for(int i=0; i<results.size(); i++)
        cout << results[i] << endl;

    return results;
}
/*------------------------Fonctions Membres----------------------------*/
Page Coeur::trouverPage(int cle){
        return m_pages[cle];
}

/*Cr�er un bucket */
Page Coeur::ajouterBucket(int numBucket){
    //On indique le bucket existant maximum
    m_nbBuckets++;
    //On cr�er la premi�re page du bucket
    return ajouterPage(numBucket);
}

/*Ajoute une page*/
Page Coeur::ajouterPage(int numPage){
    //Met le bit d'occupation � 1
    pageOccupee(numPage);
    //Creer et renvoit la page
    return m_pages[numPage];
}

/*Ajoute une page de d�bordement � la page numPage et renvoit son index*/
int Coeur::ajouterPageDebordement(int numPage){
    //On indique qu'on utilise la page minDebordement
    ajouterPage(m_minDebordement);
    //Modifier les informations de la page parente pour indiquer une page d�bordement
    m_pages[numPage].ajouterPageDebordement(m_minDebordement);
    //On indique que la prochaine page de d�bordement devra se situer sur la page pr�c�dente
    m_minDebordement--;
    //On renvoit l'index de la page de d�bordement
    return m_minDebordement+1;
}

//La page est elle une page de d�bordement ?
bool Coeur::isDebordement(int numPage){
    return numPage > m_nbBuckets;
}
// On indique que la page numPage n'est plus utilis�e
int Coeur::supprimerPage(int numPage){
    m_occupation -= pow(2,numPage);
    //Si la page � supprimer avait une page de d�bordement, on renvoit son index
    if(m_pages[numPage].debord())
        return m_pages[numPage].getPageDebordement();
    else
        return -1;
}

/*Hache l'entier a par la fonction de hachage n*/
int Coeur::hachage(int a, int n){
    return a % (int)pow(2,(double)n);
}

bool Coeur::estLibre(int n){
    return (!(m_occupation >> n & 1));
}

/*On met le bit d'occupation de la page � l'index numPage � 1*/
void Coeur::pageOccupee(int numPage){
    /*Seulement si la page est encore consid�r�e comme libre*/
    if(estLibre(numPage))
        m_occupation += pow(2, numPage);
}

/*Retourne la premi�re page d'un bucket ou il reste au moins un emplacement libre
    OU retourne la derni�re page du bucket
*/
int Coeur::premierePageNonRemplieBucket(int numPage){
    Page p = m_pages[numPage];
    //Tant que la page est pleine et qu'on a une page de d�bordement ...
        while(p.estPleine() && p.debord()){
            //... On teste la page de d�bordement
            numPage = p.getPageDebordement();
            p = m_pages[numPage];
        }

        return numPage;
}

/*Remet le coeur � l'�tat initial*/
void Coeur::reinitialiser(){
    m_n=0;              //La fonction de hachage
    m_next = 0;        // Le pointeur next
    m_ronde = 1;
    m_occupation = 1;

    m_pages.clear(); //On vide toutes les pages
    ajouterBucket(0);     //On cr�er la premi�re page du premier bucket
    m_nbBuckets = 0;    //Le nombre de bucket (le bucket 0 existe)
    m_minDebordement = NOMBRE_PAGE - 1;
}

/*----------------------Affichage ------------------*/
void Coeur::afficher(ostream &out) {
    out << "==============================================" << endl;
    out << "|     n     |     next     |    occupation    | "<< endl;
    out << "----------------------------------------------" << endl;
    out << "|     "<< m_n<< "     |      "<< m_next << "       |       "<< m_occupation<< "        |" << endl;
    out << "==============================================" << endl;

    out << "===============" << endl;
    out << "||   PAGES   ||" << endl;
    out << "===============" << endl;

    //On affiche chaque page utilis�e
    for(int i=0; i<=m_nbBuckets; i++){
        out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BUCKET  : " << i << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        out << "| " << i << " : " << endl;
        out << m_pages[i];

        //Chaque page de d�bordement
        for(int j = i; m_pages[j].debord();){
            j=m_pages[j].getPageDebordement();
            out << "--------" << endl;
            out << j << " : " << endl;
            out << "--------" << endl;
            out << m_pages[j];
        }
        out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
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

    m_n=0;              //La fonction de hachage
    m_next = 0;        // Le pointeur next
    m_ronde = 1;

    //On cr�er la premi�re page du premier bucket
    ajouterBucket(0);
    m_nbBuckets = 0;    //Le nombre de bucket (le bucket 0 existe)
    m_minDebordement = NOMBRE_PAGE - 1;
    m_occupation = 1;
}

Coeur::~Coeur()
{
}

