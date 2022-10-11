#include <iostream>
#include "restau.h"
#include <string>
#include <fstream>
#include <ctime>


using namespace std;

//Fonction qui ajoute des clients
void restau::ajout_client()
{
    cout<<"------------Client------------ \n";
    cout<<"Entrer votre nom: ";
    cin>>nom;
    cout<<"Entrer votre prenom: ";
    cin>>prenom;
    do {
    cout<<"Veillier choisir votre mode de payement 1.CB ou 2.Especes: ";
    cin>>modepayement;
    if (modepayement>2)
    {
        cout<<"**Le choix que vous avez entrer est incorrect**"<<endl;
    }
    }while (modepayement>2);
}

//Fonction qui affiche le menu
int restau::entree()
{
    cout<<"-----------Entree------------ \n";
    cout<<"1. Carpaccio de boeuf fraichement tranche: 8,5 euro"<<endl;
    cout<<"2. Bruschetta saumon (2 pieces): 5,5 euro"<<endl;
    cout<<"3. Bouchee a la reine: 8,5 euro"<<endl;
    do {
    cout<<"*Veuillez choisir votre entree entre 1 a 3: ";
    cin>>ent;
    if (ent>3)
    {
        cout<<"**Le choix que vous avez entrer est incorrect**"<<endl;
    }
    }while (ent>3);
    return ent;
}
int restau::plat()
{
    cout<<"------------Plat------------ \n";
    cout<<"1. Pizza Diavolata: 11 euro \n Tomate, sauce picant, Mozarella, jambon et viande hachee"<<endl;
    cout<<"2. Escalope Florentina: 15 euro \n Escalope, Aubergine, sauce napolitaine, Mozarella Al forno"<<endl;
    cout<<"3. Pates Pesto Aux choix: Tagliatelles.Penne ou Spaghetti: 10 euro \n Basilic, copeaux de Parmesan, pignons de pin"<<endl;
    do {
    cout<<"*Veuillez choisir votre plat entre 1 a 3: ";
    cin>>pla;
    if (pla == 3)
    {
        cout<<"*Veuillez choisir la pates entre 1.Tagliatelles ou 2.spaghetti: ";
        cin>>pat;
    }else if (pla>3)
    {
        cout<<"**Le choix que vous avez entrer est incorrect**"<<endl;
    }
    }while (pla>3);
    return pla;
}
int restau::dessert()
{
    cout<<"------------Dessert------------ \n";
    cout<<"1. Tiramisu: 5 euro "<<endl;
    cout<<"2. Moelleux au chocolat: 5 euro"<<endl;
    cout<<"3. Cafe gourmand: 5 euro"<<endl;
    cout<<"4. Boissons Cafe: 1,9 euro"<<endl;
    cout<<"5. Bouteille d'eau: 4,9 euro"<<endl;
    cout<<"6. Demi-bouteille d'eau: 3 euro"<<endl;
    do {
    cout<<"*Veuillez choisir votre dessert entre 1 a 6: ";
    cin>>des;
    if (des>6)
    {
        cout<<"**Le choix que vous avez entrer est incorrect**"<<endl;
    }
    }while (des>6);
    return des;
}

int restau::modifier()
{
    cout<<"\nVeuillez choisir se que vous voulez modifier entre 1.l'entree, 2.le plat, 3.le dessert: ";
    cin>>mod;
    return mod;
}

//Fonction qui affiche la commande passer et qui l'ecrit dans un fichier texte
void restau::affiche_commande()
{   
    ofstream fichier("information.txt", ios::in | ios::out | ios::app );
    if(fichier)
    {
    cout<<"---------------------------------------- \n";
    fichier<<"---------------------------------------- \n";
    cout<<"--------------Votre Commande est :------------ \n";
    fichier<<"--------------Votre Commande est :------------ \n";
    cout<<"Nom: "<<nom<<endl;
    fichier<<"Nom: "<<nom<<endl;
    cout<<"Prenom: "<<prenom<<endl;
    fichier<<"Prenom: "<<prenom<<endl;
    if (modepayement == 1)
    {
        cout<<"Mode de payement: CB"<<endl;
        fichier<<"Mode de payement: CB"<<endl;
    }
    else if (modepayement == 2){
        cout<<"Mode de payement: Espace"<<endl;
        fichier<<"Mode de payement: Espace"<<endl;
    }
    cout<<"---------------------------------------- \n";
    fichier<<"---------------------------------------- \n";
switch (ent)
{
case 1:
    cout<<"Votre entree est un: Carpaccio de boeuf fraichement tranche"<<endl;
    fichier<<"Votre entree est un: Carpaccio de boeuf fraichement tranche"<<endl;
    Prix_total += 8.5;
    break;
case 2:
    cout<<"Votre entree est un: Bruschetta saumon (2 pieces)"<<endl;
    fichier<<"Votre entree est un: Bruschetta saumon (2 pieces)"<<endl;
    Prix_total += 5.5;
    break;
case 3:
    cout<<"Votre entree est un: Bouchee a la reine"<<endl;
    fichier<<"Votre entree est un: Bouchee a la reine"<<endl;
    Prix_total += 8.5;
}

switch (pla)
{
case 1:
    cout<<"Votre plat est un(e): Pizza Diavolata"<<endl; 
    fichier<<"Votre plat est un(e): Pizza Diavolata"<<endl;
    Prix_total += 11.0;
    break;
case 2:
    cout<<"Votre plat est un(e): Escalope Florentina"<<endl; 
    fichier<<"Votre plat est un(e): Escalope Florentina"<<endl;
    Prix_total += 15.0;
    break;
case 3:
    cout<<"Votre plat est un(e): Pates Pesto"<<endl; 
    fichier<<"Votre plat est un(e): Pates Pesto"<<endl; 
    if (pat == 1)
    {
        cout<<"Votre plat a pour pates: Tagliatelles.Penne"<<endl;
        fichier<<"Votre plat a pour pates: Tagliatelles.Penne"<<endl;
    }
    else{
        cout<<"Votre plat a pour pates: Spaghetti"<<endl;
        fichier<<"Votre plat a pour pates: Spaghetti"<<endl;
    }
    Prix_total += 10.0;
    break;
}

switch (des)
{
case 1:
    cout<<"Votre dessert est un(e): Tiramisu"<<endl;
    fichier<<"Votre dessert est un(e): Tiramisu"<<endl;
    Prix_total += 5.0;
    break;
case 2:
    cout<<"Votre dessert est un(e): Moelleux au chocolat"<<endl;
    fichier<<"Votre dessert est un(e): Moelleux au chocolat"<<endl;
    Prix_total += 5.0;
    break;
case 3:
    cout<<"Votre dessert est un(e): Cafe gourmand"<<endl;
    fichier<<"Votre dessert est un(e): Cafe gourmand"<<endl;
    Prix_total += 5.0;
    break;
case 4:
    cout<<"Votre dessert est un(e): Boissons Cafe"<<endl;
    fichier<<"Votre dessert est un(e): Boissons Cafe"<<endl;
    Prix_total += 1.9;
    break;
case 5:
    cout<<"Votre dessert est un(e): Bouteille d’eau"<<endl;
    fichier<<"Votre dessert est un(e): Bouteille d’eau"<<endl;
    Prix_total += 4.9;
    break;
case 6:
    cout<<"Votre dessert est un(e): Demi-bouteille d’eau"<<endl;
    fichier<<"Votre dessert est un(e): Demi-bouteille d’eau"<<endl;
    Prix_total += 3.0;
    break;
}
    cout<<"\n";
    fichier<<"\n";
    cout<<"Prix total: "<<Prix_total<<"€"<<endl;
    fichier<<"Prix total: "<<Prix_total<<"€"<<endl;
    }
    else cout<<"Erreur"<<endl;
}

void client::date_comannde()
{
    time_t now = time(0);
    dt = ctime(&now);
    tm *ltm = localtime(&now);
    
    ofstream fichier("information.txt", ios::out | ios::app);
    if(fichier)
    {
    cout<<"Commande passer le: "<<dt<<endl;
    fichier<<"Commande passer le: "<<dt<<endl;
    }
}

//Fonction qui lit le contenu du fichier texte et qui le stock dans une chaine de caractère
void restau::lire_fichier()
{
    ifstream fichier("information.txt", ios::in);
    if(fichier)
    {
        string info;
        while(getline(fichier, info))
        {
            cout<<info<<endl;
        }
    }
}
//Fonction qui return le prix_total du client
float restau::revenu()
{
    return Prix_total;
};