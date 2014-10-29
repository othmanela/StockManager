#include <stdio.h>
#include <stdlib.h>

#include"tp3.h"

void menu ()

{
printf ("\n\nBonjour saississez l'operation que vous souhaitez realiser \n");
printf ("----------------------------------------------------------------------------- \n");
printf(" 1* Lecture des donnees a partir d'un fichier \n");
printf(" 2* Ajouter un nouvel article non existant dans votre magasin \n");
printf(" 3* Afficher les caracteristiques des articles du stock disponible \n");
printf(" 4* Afficher les caracteristiques des articles du stock epuise \n");
printf(" 5* Afficher les caracteristiques des articles de l'ensemble du stock \n");
printf(" 6* Supprimer un article au choix \n");
printf(" 7* Rechercher un article par identifiant, libelle et/ou categorie \n");
printf(" 8* Rechercher un article par quantite \n");
printf(" 9* Rechercher un article par prix unitaire \n");
printf("10* Gerer les commandes clients \n");
printf("11* Approvisionner le stock\n");
printf("12* Supprimer l'ensemble du stock \n");
printf("13* Quitter \n");
printf("-----------------------------------------------------------------------------\n");

}

int main()
{


    Liste_stock_dispo = CreeListeArticles();
    Liste_stock_epuise= CreeListeArticles();
    Liste_Requetes = CreeListeRequetes();

    Requete* r1;
    Article* a1;


    int i=0,id_A=0;
    int qte_min=0, qte_max=0;
    float pu_min=0, pu_max=0;
    char cat[50];
    char lib[50];
    char* nomfichier="stock.txt";

while(i!=13)

{

system("cls");
menu();
printf("entrez votre choix : ");
scanf("%d",&i);


switch (i)
{
    case 1 :
            LireFichier(nomfichier);
            break;

    case 2 :
            a1 = CreeArticle();
            AjoutArticle(Liste_stock_dispo, a1);
            system("pause");
            break;

    case 3 :
            printf("\nVoici l'etat du stock disponible\n\n");
            AfficheStock(Liste_stock_dispo);
            system("pause");
            break;
    case 4 :
            printf("\nVoici l'etat du stock epuise\n\n");
            AfficheStock(Liste_stock_epuise );
            system("pause");
            break;
     case 5 :
            printf("\nVoici l'etat du stock disponible\n\n");
            AfficheStock(Liste_stock_dispo);
            printf("\nVoici l'etat du stock epuise\n\n");
            AfficheStock(Liste_stock_epuise);
            system("pause");
            break;
    case 6 :

            printf("\nEntrez l' ID de l'article a supprimer\n");
            scanf("%d", &id_A);
            SupprimeArticle(Liste_stock_dispo, id_A);
            break;

    case 7 :
            printf("\nSaisissez la valeur -1 pour ignorer le parametre ID lors de la recherche, ou le mot IGNORE pour ignorer les parametres libelle ou categorie\n");
            printf("entrez l' ID de l'article à rechercher\n");
            scanf("%d",&id_A);
            printf("\nEntrez le nom du libelle\n");
            scanf("%s",lib);
            printf("\nEntrez le nom de la categorie\n");
            scanf("%s", cat);
            AfficheStock(RechercheArticleParCritere(Liste_stock_dispo,id_A,lib,cat));
            system("pause");

            break;

    case 8 :
            printf("\nNous allons rechercher les articles dans un intervalle de quantite souhaitee. Saisissez la quantité minimale \n");
            scanf("%d", &qte_min);
            printf("\nSaisissez la quantite maximale\n");
            scanf("%d", &qte_max);
            AfficheStock(RechercheParQuantite(Liste_stock_dispo,qte_min,qte_max));
            system("pause");

            break;

    case 9 :
            printf("\nNous allons rechercher les articles dans un intervalle de prix unitaire souhaité. Saisissez le prix minimal  ");
            scanf("%f", &pu_min);
            printf("\nSaisissez le prix unitaire maximal  \n");
            scanf("%f", &pu_max);
            AfficheStock(RechercheParPrixUnitaire (Liste_stock_dispo, pu_min ,pu_max));
            system("pause");
            break;

    case 10 :

            r1 = CreeRequete();
            AjoutRequete(Liste_Requetes,r1);
            AfficheStockRequetes(Liste_Requetes);
            VendreArticles(Liste_Requetes);
            printf("Voici l'etat du stock disponible\n");
           AfficheStock(Liste_stock_dispo);
           printf("Voici l'etat du stock epuise\n");
           AfficheStock(Liste_stock_epuise);
           system("pause");
            break;

    case 11 :
            AfficheStockRequetes(Liste_Requetes);
            ApprovisionnerMagasin(Liste_Requetes);
             printf("Voici l'etat du stock disponible\n");
           AfficheStock(Liste_stock_dispo);
           printf("Voici l'etat du stock epuise\n");
           AfficheStock(Liste_stock_epuise);
           system("pause");
            break;

    case 12 :
            SupprimeStock(Liste_stock_dispo);
            SupprimeStock(Liste_stock_epuise);
            break;
    case 13 :
            printf("\n\nA bientot!\n\n");
            break;

}
}
}

