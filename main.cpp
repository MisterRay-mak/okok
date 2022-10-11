#include <iostream>
#include "restau.h"


using namespace std;

int main()
{
    //SetConsoleOutputCP(65001);


    int choix;
    int choix1;
    int choix2;
    int choix3;
    int i=0;
    int e;
    int j;
    int nb=0;
    int mod=0;
    restau restau1[50];
    client date;
//Demande a l'utilisateur entre client ou gerant
    do
    {
    cout<<"[--------------Acceuil---------------]"<<endl;
    cout<<"1. Client"<<endl;
    cout<<"2. Gerant"<<endl;
    cout<<"3. Quitter"<<endl;
        do {
        cout<<"Veuillez entrer un nombre entre 1 ou 2 ou 3: ";
        cin>>choix;
        if (choix == 1){
            do
            {
                cout<<"[------------MENU------------]";
                cout<<"\n";
                restau1[i].ajout_client();
                restau1[i].entree();
                restau1[i].plat();
                restau1[i].dessert();
                cout<<"*Voulez-vous 1.modifier ou 2.supprimer ou 3.valider votre commande: ";
                cin>>choix3;
                if (choix3 == 1)
                {
                    do {
                        mod = restau1->modifier();
                        if (mod == 1)
                        {
                            restau1->entree();
                            cout<<"\nVoulez vous continuer a modifier 1.oui ou 2.non : "<<endl;
                        cin>>j;
                    } else if (mod == 2)
                    {
                        restau1->plat();
                        cout<<"\nVoulez vous continuer a modifier 1.oui ou 2.non : "<<endl;
                        cin>>j;
                    } else if (mod == 3)
                    {
                        restau1->dessert();
                        cout<<"\nVoulez vous continuer a modifier 1.oui ou 2.non : "<<endl;
                        cin>>j;
                    }
                    }while (j == 1);
                }
                else if (choix3 == 3)
                {
                cout<<"Votre commande a bien etait pris en compte"<<endl;
                }
            restau1[i].affiche_commande();
            date.date_comannde();
            i++;
            cout<<"Voulez-vous continuer a passer des commandes ? 1.oui ou 2.non : ";
            cin>>choix2;
            }while (choix2 == 1);
        }
        else if (choix == 2)
        {
            string mdp = "tryit";
            string mdp1;
            for(e=3; e >= 0; e--)
            {
            cout<<"-------------------------------------"<<endl;
            cout<<"Entrez votre mot de passe: ";
            cin>>mdp1;
            if (mdp1 == mdp)
            {
                cout<<"Mot de passe correct !"<<endl;
                cout<<"[------------Gerant------------] \n";
                cout<<"\n";
                cout<<"1. Afficher les informations du client"<<endl;
                cout<<"2. Afficher les revenue du jour"<<endl;
                cout<<"Veuillez entrer un nombre entre 1 ou 2: ";
                cin>>choix1;
                if (choix1 == 1)
                {   
                    restau1[0].lire_fichier();
                }else if (choix1 == 2)
                {
                    float revenu_total = 0, rev = 0;
                    do
                    {
                        rev = restau1[nb].revenu();
                        revenu_total = rev + revenu_total;
                        nb++;
                    } while (nb != i);
                    cout<<"Le revenu total est de: "<<revenu_total<<endl;
                
                }
                break;
            }
            else{
                cout<<"mot de passe incorrect"<<endl;
                cout<<"il vous reste "<<e<<" essais"<<endl;
                }
            }
        }
        else if (choix>3) {
            cout<<"**Le choix que vous avez entrer est incorrect**"<<endl;
        }
        }while (choix>3);
        if (choix==3) {
            break;
        } 
    } while (choix2 == 2); 
}