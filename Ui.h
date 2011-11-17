#ifndef UI_H
#define UI_H


class Ui
{
    public:
        int choix;

        Ui();
        ~Ui();
        void gestionMenu();
    protected:
    private:
        void afficheMenu();
        void choixMenu();
        void redirectionMenu();
        void nouvelEnregistrement();

        static bool alreadyCreated;
};

#endif // UI_H
