#ifndef UI_H
#define UI_H


class Ui
{
    public:
        Ui();
        ~Ui();
        void gestionMenu();
    protected:
    private:
        void afficheMenu();
        int choixMenu();
        void redirectionMenu(int choix);
        void nouvelEnregistrement();

        static bool alreadyCreated;
};

#endif // UI_H
