#ifndef UI_H
#define UI_H


class Ui
{
    public:
        Ui();
        ~Ui();
        void gestionMenu();
        int getChoix();
    protected:
    private:
        void afficheMenu();
        void choixMenu();

        static bool alreadyCreated;
        int choix;
};

#endif // UI_H
