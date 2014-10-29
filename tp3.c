

#include"tp3.h"


ListeArticles CreeListeArticles()
{
    Article* liste =(Article*)malloc(sizeof(Article));
    liste->nextArticle= liste;
    return liste;
}

ListeRequetes CreeListeRequetes()
{
    Requete* liste =(Requete*)malloc(sizeof(Article));
    liste->nextRequete= liste;
    return liste;
}

Article* CreeArticle()
{
    Article *a=malloc(sizeof(Article));
    printf("\nEntrer les caracteristiques d'un article : \n");

    printf("\nEntrer l'ID: ");
    scanf("%d",&(a->id));

    printf("\nEntrer le libelle: ");
    scanf("%s",&(a->libelle));

    printf("\nEntrer le Prix : ");
    scanf("%f",&(a->PU));

    printf("\nEntrer la quantite : ");
    scanf("%d",&(a->qte));

    printf("\nEntrer la categorie : ");
    scanf("%s",&(a->categorie));

    return a;
}
Requete* CreeRequete()
{
    Requete *req=malloc(sizeof(Requete));
    printf("\nEntrer les caracteristiques d'une requete : \n");

    printf("\nEntrer l'ID: ");
    scanf("%d",&(req->idArticle));

    printf("\nEntrer la quantite : ");
    scanf("%d",&(req->qte));
    return req;


}
void AjoutArticle(ListeArticles liste, Article *a)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide \n");
        return;
    }
    else {
                ListeArticles ltest=RechercheArticleParCritere(liste, a->id, "IGNORE", "IGNORE");
                if (ltest->nextArticle!= ltest)
                {
                    printf("\n\L'identifiant de l'article est deja existant, cet article ne sera pas ajoute a la liste\n");
                    return;

                }

                if (liste->nextArticle== liste)// si notre liste ne contient que la sentinelle l'element a inserer forcement juste apres la sentinelle
                {
                    liste->nextArticle=a;
                    a->nextArticle=liste;
                    return;

                }
                else {/* si la liste contient au moins un element, il faut la parcourir pour trouver la place de l'element
                    a inserer de tel sorte a ce que les articles soient classés par ordre de prix decroissant*/
                    Article* tmp=(Article*)malloc(sizeof(Article));
                    tmp=liste;


                    while (tmp->nextArticle!=liste && tmp->nextArticle->PU > a->PU)
                    {
                        tmp=tmp->nextArticle;
                    }
                    a->nextArticle=tmp->nextArticle;
                    tmp->nextArticle=a;


                }

    }

}

void AjoutRequete(ListeRequetes liste, Requete *req)
{
     if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide\n");
        return;
    }
    else {
                if (liste->nextRequete== liste)// si on insere le premier element celui ci est forcement juste apres la sentinelle
                {
                    liste->nextRequete=req;
                    req->nextRequete=liste;
                    return;

                }
                else {// la liste contient au moins un element, on insere notre nouvelle requete en debut de liste, juste apres la sentinelle
                    req->nextRequete=liste->nextRequete;
                    liste->nextRequete=req;
                    return;

                }

    }
}


void AfficheStock(ListeArticles liste)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide\n");
        return;
    }
    if (liste->nextArticle==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return;
    }
    else// si notre liste est pleine on la parcourt et on affiche chaque article avec ses caracteristiques
    {
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        printf("|Identifiant \t| Libelle         \t| Prix Unitaire \t| Quantite \t| Categorie                     \t|");
        printf("\n");
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        Article* tmp=(Article*)malloc(sizeof(Article));
        tmp=liste->nextArticle;
        while (tmp !=liste )
                    {
                        printf ("\n|      %d      \t|    %s        \t|        %.2f        \t|     %d     \t|     %s                    \t|\n", tmp->id, tmp->libelle, tmp->PU,tmp->qte, tmp->categorie);
                        tmp=tmp->nextArticle;
                    }
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }

}
//Cette fonction n'est pas demander
void AfficheStockRequetes(ListeRequetes liste)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide\n");
        return;
    }
    if (liste->nextRequete ==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return;
    }
    else
    {
        printf("-----------------------------------------------------------------------------------------");
        printf("\n");
        printf("|Identifiant \t| Quantite \t|");
        printf("\n");
        printf("-----------------------------------------------------------------------------------------");
        printf("\n");
        Requete* tmp=(Requete*)malloc(sizeof(Requete));
        tmp=liste->nextRequete;
        while (tmp !=liste )
                    {
                        printf ("\n|      %d      \t|      %d     \t|\n", tmp->idArticle, tmp->qte);
                        tmp=tmp->nextRequete;
                    }
        printf("-----------------------------------------------------------------------------------------");
    }

}
void SupprimeStock(ListeArticles l)
{
    if (l==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide\n");
        return;
    }
    if (l->nextArticle==l)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return;
    }
    // on parcourt la liste et on supprime les articles un par un
    Article* tmp=(Article*)malloc(sizeof(Article));
    tmp=l->nextArticle;
    while (tmp !=l )
                    {

                        l->nextArticle=tmp->nextArticle;
                        free(tmp);
                        tmp=l->nextArticle;
                    }


}

void SupprimeRequetes(ListeRequetes liste)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle
    {
        printf("\nListe invalide\n");
        return;
    }
    if (liste->nextRequete==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return;
    }
    // on parcourt la liste et on supprime les requetes une par une
    Requete* tmp=(Requete*)malloc(sizeof(Requete));
    tmp=liste->nextRequete;
    while (tmp !=liste )
                    {

                        liste->nextRequete=tmp->nextRequete;
                        free(tmp);
                        tmp=liste->nextRequete;
                    }

}

void SupprimeArticle(ListeArticles l, int id_Article)
{
     if (l==NULL)
    {
        printf("\nListe invalide\n");
        return;
    }
    if (l->nextArticle==l)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return;
    }
    else{

            Article* tmp=(Article*)malloc(sizeof(Article));
            tmp=l->nextArticle;
            Article* tmp2=(Article*)malloc(sizeof(Article));
            tmp2=l;

            while ( (tmp->id != id_Article) && (tmp->nextArticle !=l) )
                            {
                                tmp2=tmp;
                                printf("%d \n", tmp->id);
                                tmp=tmp->nextArticle;

                            }

            if (tmp->id == id_Article)
            {
                tmp2->nextArticle=tmp->nextArticle;
                free(tmp);
                printf("l'article a ete supprime \n\n");

            }
            else{
                    if (tmp->nextArticle==l)
                    {
                        printf("l'article que vous desirez supprimer n'est pas existant\n\n");

                    }
            }


        }
}

ListeArticles RechercheArticleParCritere(ListeArticles liste, int id, char* libelle, char* categorie)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle on retourne NULL
    {

        return NULL;
    }
    if (liste->nextArticle==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        return liste;// on retourne cette meme liste qui ne contient que la sentinelle
    }
    Article* tmp=malloc(sizeof(Article));
    tmp = liste->nextArticle;
    ListeArticles la= CreeListeArticles();
    char s[]="IGNORE";// on crée un char s qu l'on pourra envoyer directement a la fonction strcmp
    while ( tmp != liste)
                {

                    if((id==-1) && (strcmp(libelle, s) == 0) && (strcmp(categorie, s) == 0) ){
                        return liste;
                    }

                    if(
                          ((id==-1) && (strcmp(libelle, s) == 0) && (strcmp(tmp->categorie, categorie) == 0) )
                       || ((id==-1) && (strcmp(tmp->libelle, libelle) == 0) && (strcmp(categorie, s) == 0) )
                       || ((id==-1) && (strcmp(tmp->libelle, libelle) == 0) && (strcmp(tmp->categorie, categorie) == 0) )
                       || ((tmp->id==id) && (strcmp(libelle, s) == 0) && (strcmp(categorie, s) == 0) )
                       || ((tmp->id==id) && (strcmp(libelle, s) == 0) && (strcmp(tmp->categorie, categorie) == 0) )
                       || ((tmp->id==id) && (strcmp(tmp->libelle, libelle) == 0) && (strcmp(categorie, s) == 0) )
                       || ((tmp->id==id) && (strcmp(tmp->libelle, libelle) == 0) && (strcmp(tmp->categorie, categorie) == 0) )
                       )

                       {
                            /*ici on est obligé de copier l'article pointé par tmp dans tmp2. En effet si on envoie
                            directement tmp a la fontion AjoutArticle() celle ci va modifier le pointeur de tmp->nextArticle et
                            dans ce cas nous ne pouront plus acceder au autres elements de notre liste d'articles*/
                            Article* tmp2=(Article*)malloc(sizeof(Article));
                            tmp2->id=tmp->id;
                            strcpy(&(tmp2->categorie), &(tmp->categorie));
                            strcpy(&(tmp2->libelle), &(tmp->libelle));
                            tmp2->PU=tmp->PU;
                            tmp2->qte=tmp->qte;

                            AjoutArticle(la, tmp2);

                        }


                    tmp = tmp->nextArticle;

                }

    return la;// retourne un pointeur sur la liste qui contient les elements trouvées

}


ListeArticles RechercheParQuantite(ListeArticles liste, int qte_min, int qte_max)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle on retourne NULL
    {
        printf("\nListe invalide\n");
        return NULL;
    }
    if (liste->nextArticle==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return liste;
    }
    ListeArticles la= CreeListeArticles();
    Article* tmp=(Article*)malloc(sizeof(Article));
    tmp=liste->nextArticle;
    while (tmp !=liste )
                {
                    if ((tmp->qte >= qte_min) && (tmp->qte <= qte_max))// on en peut pas envoyer tmp car il contient un pointeur sur le reste de la liste, on cree don un autre pointeur tmp2 que l'on envoie a la liste
                        {
                            /*De meme, ici on est obligé de copier l'article pointé par tmp dans tmp2. En effet si on envoie
                            directement tmp a la fontion AjoutArticle() celle ci va modifier le pointeur de tmp->nextArticle et
                            dans ce cas nous ne pouront plus acceder au autres elements de notre liste d'articles*/
                            Article* tmp2=(Article*)malloc(sizeof(Article));
                            tmp2->id=tmp->id;
                            strcpy(&(tmp2->categorie), &(tmp->categorie));
                            strcpy(&(tmp2->libelle), &(tmp->libelle));
                            tmp2->PU=tmp->PU;
                            tmp2->qte=tmp->qte;
                            AjoutArticle(la, tmp2);

                        }
                    tmp=tmp->nextArticle;
                }
    if (la->nextArticle==la)
    {
        printf("Aucun resultat n'a ete trouvee : ");

    }
    return la;
}

ListeArticles RechercheParPrixUnitaire (ListeArticles liste, float prix_min , float prix_max)
{
    if (liste==NULL)//cas ou la liste est vide et ne contient meme pas de sentinelle on retourne NULL
    {
        printf("\nListe invalide\n");
        return NULL;
    }
    if (liste->nextArticle==liste)// cas ou il n'y a que la sentinelle dans la liste
    {
        printf("\nLa liste est vide\n");
        return liste;
    }
    ListeArticles la= CreeListeArticles();
    Article* tmp=(Article*)malloc(sizeof(Article));
    tmp=liste->nextArticle;
    while (tmp !=liste )
                {
                    if ((tmp->PU >= prix_min) && (tmp->PU <= prix_max))// on en peut pas envoyer tmp car il contient un pointeur sur le reste de la liste, on cree don un autre pointeur tmp2 que l'on envoie a la liste
                        {
                             /*Encore une fois, ici on est obligé de copier l'article pointé par tmp dans tmp2. En effet si on envoie
                            directement tmp a la fontion AjoutArticle() celle ci va modifier le pointeur de tmp->nextArticle et
                            dans ce cas nous ne pouront plus acceder au autres elements de notre liste d'articles*/
                            Article* tmp2=(Article*)malloc(sizeof(Article));
                            tmp2->id=tmp->id;
                            strcpy(&(tmp2->categorie), &(tmp->categorie));
                            strcpy(&(tmp2->libelle), &(tmp->libelle));
                            tmp2->PU=tmp->PU;
                            tmp2->qte=tmp->qte;
                            AjoutArticle(la, tmp2);

                        }
                    tmp=tmp->nextArticle;
                }
    if (la->nextArticle==la)
    {
        printf("Aucun resultat n'a ete trouvee : ");

    }
    return la;

}


void MiseAJourArticle(int id, int quantite)
{
    Article* tmp=(Article*)malloc(sizeof(Article));

    tmp= Liste_stock_dispo->nextArticle;

	while(tmp!=Liste_stock_dispo){// tant que l'on est pas arrivée a la fin de la liste_stock_dispo


            if(tmp->id==id){// si on trouve l'id que l'on recherche on met a jour sa quantité
			tmp->qte=quantite;
			if (quantite==0)//si la quantité est nul on l'ajout dans liste_stock_epuisé et on le supprime de liste_stock_dispo
            {
                Article* tmp2=(Article*)malloc(sizeof(Article));
                tmp2->id=tmp->id;
                strcpy(&(tmp2->categorie), &(tmp->categorie));
                strcpy(&(tmp2->libelle), &(tmp->libelle));
                tmp2->PU=tmp->PU;
                tmp2->qte=0;
                AjoutArticle(Liste_stock_epuise, tmp2);

                SupprimeArticle(Liste_stock_dispo, tmp->id);
            }
		}

		tmp=tmp->nextArticle;

	}


	tmp= Liste_stock_epuise->nextArticle;


	while(tmp!=Liste_stock_epuise){// tant que l'on est pas arrivée a la fin de la liste_stock_epuisé

		if(tmp->id==id){
			if (quantite>0)
            {
                Article* tmp2=(Article*)malloc(sizeof(Article));
                tmp2->id=tmp->id;
                strcpy(&(tmp2->categorie), &(tmp->categorie));
                strcpy(&(tmp2->libelle), &(tmp->libelle));
                tmp2->PU=tmp->PU;
                tmp2->qte=quantite;
                AjoutArticle(Liste_stock_dispo, tmp2);

                SupprimeArticle(Liste_stock_epuise, tmp->id);
            }
		}

		tmp=tmp->nextArticle;

	}

}

void VendreArticles(ListeRequetes liste)
{
    Requete* tmp=malloc(sizeof(Requete));
    tmp=liste->nextRequete;
    int newquantite=0;
    Article* tmp2=(Article*)malloc(sizeof(Article));


    while (tmp!=liste)
    {
        tmp2=RechercheArticleParCritere(Liste_stock_dispo, tmp->idArticle, "IGNORE", "IGNORE")->nextArticle;
        if (tmp2->nextArticle==tmp2)//si la fonction rechercheArticleParCritere nous renvoie la liste qui ne contient que la sentinelle
        {
                    printf("\nL'article dont l'identifiant est %d n'est pas existant dans la liste\n", tmp->idArticle);
        }
        else
        {

            printf("\nREQUETE %d %d PRESENT %d\n",tmp2->id,tmp->qte,tmp2->qte);
                    newquantite= (tmp2->qte)-(tmp->qte);
                    if (newquantite>=0)
                    {
                        printf("\nRESTANT %d\n",newquantite);
                        MiseAJourArticle(tmp->idArticle, newquantite);
                    }else
                    {
                        printf("La quantité disponible est inferieur a la demande");
                    }

        }
        tmp=tmp->nextRequete;
    }

}
void ApprovisionnerMagasin(ListeRequetes liste)
{
    Requete* tmp=malloc(sizeof(Requete));
    tmp=liste->nextRequete;
    int newquantite=0;
    Article* tmp2=(Article*)malloc(sizeof(Article));


    while (tmp!=liste)
    {
        tmp2=RechercheArticleParCritere(Liste_stock_dispo, tmp->idArticle, "IGNORE", "IGNORE")->nextArticle;
        if (tmp2->nextArticle==tmp2)//si la fonction rechercheArticleParCritere nous renvoie la liste qui ne contient que la sentinelle
        {
                    printf("\nL'article dont l'identifiant est %d n'est pas existant dans la liste\n", tmp->idArticle);
        }
        else
        {

                    newquantite= (tmp2->qte)+(tmp->qte);
                    MiseAJourArticle(tmp->idArticle, newquantite);


        }


        tmp2=RechercheArticleParCritere(Liste_stock_epuise, tmp->idArticle, "IGNORE", "IGNORE")->nextArticle;
        if (tmp2->nextArticle==tmp2)//si la fonction rechercheArticleParCritere nous renvoie la liste qui ne contient que la sentinelle
        {
                    printf("\nL'article dont l'identifiant est %d n'est pas existant dans la liste\n", tmp->idArticle);
        }
        else
        {

                    newquantite= (tmp2->qte)+(tmp->qte);
                    MiseAJourArticle(tmp->idArticle, newquantite);


        }


        tmp=tmp->nextRequete;
    }

}


void LireFichier(char* nomfichier)
{
    FILE* pfile;
      char temp[100];
      Article *nouveaunoeud;

      SupprimeStock(Liste_stock_dispo);
      SupprimeStock(Liste_stock_epuise);

      if((pfile=fopen(nomfichier,"r"))!=NULL){
          fscanf(pfile,"%s",temp);
          fscanf(pfile,"%s",temp);
          fscanf(pfile,"%s",temp);
          fscanf(pfile,"%s",temp);
          fscanf(pfile,"%s",temp);
          nouveaunoeud= (Article *) malloc(sizeof(Article));
          while(fscanf(pfile,"%d",&nouveaunoeud->id)!=EOF){
              fscanf(pfile,"%s",nouveaunoeud->libelle);
              fscanf(pfile,"%f",&nouveaunoeud->PU);
              fscanf(pfile,"%d",&nouveaunoeud->qte);
              fscanf(pfile,"%s",nouveaunoeud->categorie);

              nouveaunoeud->nextArticle=NULL;
              AjoutArticle(Liste_stock_dispo,nouveaunoeud);
              nouveaunoeud=(Article *) malloc(sizeof(Article));

          }
          fclose(pfile);
      }
      else
          printf("Error open file %s",nomfichier);
}


