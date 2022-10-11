#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

using namespace std;

class restau
{
private:
    //Partie client
    char nom[20];
    char prenom[20];
    int modepayement;
    //Partie menu
    int choix;
    int ent;
    int pla;
    int des;
    char pat;
    int mod;
    char nom_des_plat[50];
    //Partie prix
    float Prix_total = 0;
    float revenue = 0;
public:
    //Partie client
    void ajout_client();
    void affichage();
    //Partie menu
    void affiche_menu();
    int entree();
    int plat();
    int dessert();
    int modifier();
    //Partie affichage de la commande
    void affiche_commande();
    void affiche_info();
    void lire_fichier();
    float revenu();
};

class client
{
private:
    char* dt;
    int j,m,a,h;

public:
    void date_comannde();
};
#endif