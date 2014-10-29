

#ifndef TP3_H
#define TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// d�finition des structures

typedef struct Art
{
    int id;                          // identificateur unique d�un article > 0
    char  libelle [50];       	  // libell� de l'article (son nom)
    float PU;                  	  // prix unitaire > 0
    int qte;                   	   // quantit� de l�article pr�sente dans le stock > = 0
    char  categorie [50];  			// cat�gorie de l'article (alimentaire, hygi�ne, textile, papeterie, etc.)
    struct Art * nextArticle;
}Article;

typedef Article * ListeArticles;

typedef struct Req
{
    int idArticle;          // identificateur de l�article
    int qte;                  // quantit� � retirer ou � ajouter dans le stock correspondant � idArticle
    struct Req * nextRequete;
}Requete ;

typedef Requete * ListeRequetes;

// d�claration des variables globales utilis�es





// prototypes de fonctions
ListeArticles CreeListeArticles();
ListeRequetes CreeListeRequetes();
Article* CreeArticle();//cette fonction a été ajouté
Requete* CreeRequete();//cette fonction a été ajouté

ListeArticles Liste_stock_dispo;
ListeArticles Liste_stock_epuise;
ListeRequetes Liste_Requetes;//ajoutée

void AjoutArticle(ListeArticles liste, Article *a);
void AjoutRequete(ListeRequetes liste, Requete *req);
void AfficheStock(ListeArticles liste) ;

void AfficheStockRequetes(ListeRequetes liste);//fonction ajoutée pour tester liste stock requete
void SupprimeStock(ListeArticles l) ;
void SupprimeRequetes(ListeRequetes liste) ;
void SupprimeArticle(ListeArticles l, int id_Article) ;
ListeArticles RechercheArticleParCritere(ListeArticles liste, int id, char* libelle, char* categorie) ;
ListeArticles RechercheParQuantite(ListeArticles liste, int qte_min, int qte_max) ;
ListeArticles RechercheParPrixUnitaire (ListeArticles liste, float prix_min , float prix_max) ;

void MiseAJourArticle(int id, int quantite) ;
void VendreArticles(ListeRequetes liste) ;
void ApprovisionnerMagasin(ListeRequetes liste) ;
void LireFichier(char* nomfichier);



#endif




