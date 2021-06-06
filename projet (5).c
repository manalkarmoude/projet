#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct Voiture
{
char marque[15];
char nomVoiture[15];
char couleur[7];
char EnLocation[4];
int idVoiture;
int nbplaces;
int prixJour;
} voiture;
typedef struct{
  int jj;
  int mm;
  int aa;
}date;
typedef struct contratLocation
{
 float numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int cout;
} contrat;
typedef struct Client
{
 char nom[20];
 char prenom[20];
 char cin[11];
 char adresse[15];
 int idClient;
 int telephone;

}client;
/*FIN DES STRUCTURES*/
/*PROTOTYPES DES FONCTIONS*/
void MenuPrincipal();
void gestionLocation();
void gestionClients();
/*FONCTIONS DU MENU GESTION DE CLIENTS*/
int RechClient(int id);
void ListerClients();
void AjouterClients();
void ModifClients();
void SupprimClients();
void gestionVoitures();
/*FONCTIONS  DU MENU GESTION DE VOITURES*/
int RechVoiture(int Id);
void ListerVoitures();
void AjoutVoiture();
void ModifVoiture();
void supprimVoiture();
///////////////////////////
void gestionLocation();
/*FONCTIONS DU MENU GESTION DE LOCATION */
void visualContrat();
void LouerVoiture();
void AjoutContrat();
void  ModifContrat();
void  RetournerVoiture();
void  SupprimContrat();
int RechContrat(int num);
void modifier_string(char* champ,char* v);
void Retour();

int main(){
    MenuPrincipal();
    return 0;
}
void MenuPrincipal(){
int choix;
char reponse;
do{
    system("cls");
	printf("\n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                           \xb3      MENU PRINCIPAL     \xb3");
	printf("\n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xdf");
    printf("\n");
	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbC");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xba     Gestion de location.................................1    \xba");
	printf("\n                       \xba     Gestion des  voitures................................2   \xba");
	printf("\n                       \xba     Gestion des clients..................................3   \xba");
	printf("\n                       \xba     Quitter le programme.................................4   \xba");

	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    do{
          printf("\n\n                           Votre choix:");
          scanf("%d",&choix);
        }while(choix<1 || choix>4);
        switch(choix){
        case 1 :
            gestionLocation();
            break;
        case 2 :
            gestionVoitures();
            break;
        case 3 :
            gestionClients();
            break;
        case 4 :
            exit(1);
            break;
        default:
            printf("Ce choix n'existe pas\n");
            break;
        }
        printf("\n Voulez-vous continuer O/N:\n");
        scanf("%s",&reponse);
        fflush(stdin);
    }while(reponse=='o' || reponse=='O');
}
void gestionLocation(){
    int choix;
    do{
            system("cls");
    printf("\n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                            \xb3 Location d'une Voiture      \xb3");
	printf("\n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n");
	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xba     Visualiser contrat.................................1     \xba");
	printf("\n                       \xba     Louer voiture......................................2     \xba");
	printf("\n                       \xba     Retourner voiture..................................3     \xba");
	printf("\n                       \xba     Modifier contrat...................................4     \xba");
	printf("\n                       \xba     Supprimer contrat..................................5     \xba");
	printf("\n                       \xba     Retour.............................................6     \xba");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
       do{
          printf("\n\n                                      Votre choix:   ");
          scanf("%d",&choix);
        }while(choix<1 || choix>6);
       switch(choix){
           case 1 : visualContrat();
           break;
          case 2 :  LouerVoiture();
           break;
          case 3 :  RetournerVoiture();
           break;
          case 4 :   ModifContrat();
           break;
          case 5 :  SupprimContrat();
           break;
          case 6 :  MenuPrincipal();
           break;
           }
    }while(choix<1 || choix>6);
}

void gestionVoitures(){
    int choix;
    do{
            system("cls");
	printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                        \xb3 Gestion des Voitures      \xb3");
	printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n");

	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xba     Liste des Voitures.................................1     \xba");
	printf("\n                       \xba     Ajouter voiture....................................2     \xba");
	printf("\n                       \xba     Modifier voiture...................................3     \xba");
	printf("\n                       \xba     Supprimer voiture..................................4     \xba");
	printf("\n                       \xba     Retour.............................................5     \xba");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

        do{
          printf("\n\tVotre choix:");
          scanf("%d",&choix);
        }while(choix<1 || choix>5);
       switch (choix){
   case 1 :  ListerVoitures();
           break;
   case 2 :  AjoutVoiture();
           break;

   case 3 :  ModifVoiture();
           break;
   case 4 :  supprimVoiture();
           break;
   case 5 : MenuPrincipal();
           break;
   default:
     printf("Ce choix n'existe pas\n");
     break;
       }
    }while(choix<1 || choix>5);
}
void gestionClients(){
int choix;
    do{
            system("cls");
    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                        \xb3 Gestion des Clients      \xb3");
	printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n");

	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xba     Liste des clients..................................1     \xba");
	printf("\n                       \xba     Ajouter client.....................................2     \xba");
	printf("\n                       \xba     Modifier client....................................3     \xba");
	printf("\n                       \xba     Supprimer client...................................4     \xba");
	printf("\n                       \xba     Retour.............................................5     \xba");
	printf("\n                       \xba                                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");


        do{
          printf("\n\tVotre choix:");
          scanf("%d",&choix);
        }while(choix<1 || choix>5);
       switch (choix){
   case 1 : ListerClients();
           break;
   case 2 : AjouterClients();
           break;
   case 3:  ModifClients();
           break;
   case 4 : SupprimClients();
           break;
   case 5: MenuPrincipal();
           break;
   default:
     printf("Ce choix n'existe pas\n");
     break;
       }
    }while(choix<1 || choix>5);
}
void Quitter(){
    exit(1);
}
int RechVoiture(int id){
    voiture p;
    FILE *F;
    F=fopen("Voitures.txt","r");
    do{
        fscanf(F,"%s %s %s %s %d %d %d \n",p.nomVoiture,p.marque,p.couleur,p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);
        fflush(stdin);
        if(p.idVoiture==id)
               {
                fclose(F);
               return 1;
               }
    }while(!feof(F));
    fclose(F);
    return -1;}

void ListerVoitures(){
        FILE *F;
        voiture p;
        F=fopen("Voitures.txt","r");

        while(!feof(F)){
                //LECTURE DANS LE FICHIER
           fscanf(F,"%s",p.nomVoiture);
           fscanf(F,"%s",p.marque);
           fscanf(F,"%s",p.couleur);
           fscanf(F,"%s",p.EnLocation);
           fscanf(F,"%d",&p.idVoiture);
           fscanf(F,"%d",&p.nbplaces);
           fscanf(F,"%d",&p.prixJour);

           //AFFFICHAGE

        printf("\nLa liste des voitures est:%s\n");
        printf("NOMVOITURE:%s\n",p.nomVoiture);
        printf("MARQUE:%s\n",p.marque);
        printf("COULEUR:%s\n",p.couleur);
        printf("ENLOCATION:%s\n",p.EnLocation);
        printf("IDVOITURE :%d \n",p.idVoiture);
        printf("NOMBREDEPLACES : %d \n",p.nbplaces);
        printf(" PRIXJOUR : %d \n",p.prixJour);

           }
           fclose(F);

           //gestionVoitures();

}
/*int  ListerVoitures(){
	char texte[256];
	FILE*liste_voiture=NULL;
	voiture V;
    liste_voiture=fopen("Voitures.txt","r");
    if(!liste_voiture){
      printf("ERROR");// Tester l’ouverture du fichier
	}
	else //l'ouverture a réussi ,aprés on lit le fichier puis on l'affiche selon la structure du fichier texte qu'on a déja saisi
	{

    printf("la listes des voitures : \n");

		while ( !feof(liste_voiture)){
	    	fscanf(liste_voiture,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,&V.idVoiture,V.nomVoiture,V.couleur,&V.nbplaces,&V.prixJour,V.EnLocation);
			printf("la marque est                  : %s\n",V.marque);
        	printf("le id     est                  : %d\n",V.idVoiture);
        	printf("le nom    est                  : %s\n",V.nomVoiture);
        	printf("la couleur est                 : %s\n",V.couleur);
        	printf("le nb de places est            : %d\n",V.nbplaces);
        	printf("le prix pour un jour est       : %d\n",V.prixJour);
        	printf(" En location                     : %s\n",V.EnLocation);
            printf("\n");
			printf("\n");
		}
	fclose(liste_voiture);
	}
return 0;
}*/
// AJOUTER UNE VOITURE
void AjoutVoiture(){
    voiture p;
    FILE *F;
    int id;
    F=fopen("Voitures.txt","a");
    printf("\n Entrez l'identifiant (ID) de la voiture:\n ");
    scanf("%d",&id);
    fflush(stdin);
    while(RechVoiture(id) == 1){
        printf("\n L'id de cette voiture existe deja:\n");
        printf("\n Entrer l'identifiant de la voiture:\n");
        scanf("%d",&id);
        fflush(stdin);
    }
    p.idVoiture=id;
    printf("  Le nom :\n");
    gets(p.nomVoiture);
    fflush(stdin);
    printf(" La marque :\n ");
    gets(p.marque);
    fflush(stdin);
    printf(" La couleur :\n");
    gets(p.couleur);
    fflush(stdin);
    printf("\n En location:\n");
    gets(p.EnLocation);
    fflush(stdin);
    printf("Nombre de places:\n");
    scanf("%d",&p.nbplaces);
    fflush(stdin);
    printf(" Prix jour:\n ");
    scanf("%d",&p.prixJour);
    fflush(stdin);
    fprintf(F,"%s %s %s %s %d %d %d \n",p.nomVoiture,p.marque,p.couleur,p.EnLocation,p.idVoiture,p.nbplaces,p.prixJour);
     fclose(F);
     //gestionVoitures();

}
//MODIFICATION DES INFORMATIONS D'UNE VOITURE
void ModifVoiture(){
    voiture p;
  char reponse='n';
  FILE *F,*file;

  int id;
  printf("Entrez l'Id de votre voiture a modifier:\n");
  scanf("%d",&id);
  fflush(stdin);
  if(RechVoiture(id)==1){
    printf("\nVoulez vous vraiment modifier o/n?");
    scanf("%c",&reponse);
    fflush(stdin);
    printf("%d",reponse);
      if(reponse=='o' || reponse=='O'){
        F=fopen("Voitures.txt","r");
        file=fopen("temp.txt","a");
        do{
           fscanf(F,"%s %s %s %s %d %d %d",p.nomVoiture,p.marque,p.couleur,p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);
           if(id == p.idVoiture){
            p.idVoiture=id;
                printf("\nVeuillez saisir  le nouveau nom de la voiture\n");
                scanf("%s",p.nomVoiture);
                 printf("\nEntrer la nouvelle marque : ");
                 scanf("%s",p.marque);
                 printf("\nEntrer sa nouvelle couleur :\n ");
                 scanf("%s",p.couleur);
                 printf("Est-ce que la voiture est en location :\n");
                 scanf("%s",p.EnLocation);
                printf("\nEntrer le nouveau nombre de places:\n ");
                scanf("%d",&p.nbplaces);
                printf("\nLe prix d'une journnee en DH\n:");
                scanf("%d",&p.prixJour);
                fprintf(file,"%s %s %s %s %d %d %d", p.nomVoiture,p.marque,p.couleur,p.EnLocation,p.idVoiture,p.nbplaces,p.prixJour);
                  }
              }while(!feof(F));
              fclose(file);
              fclose(F);
              remove("Voitures.txt");
              rename("temp.txt","Voitures.txt");
            printf("\n la modification de la voiture d'id : %d a ete effectue avec succes",p.idVoiture);
         }
         else{ printf("\nla modification a ehouee\n");}
    }
    else printf("Cette  voiture n'existe pas!\n");

}
//LA SUPPRISSION D'UNE VOITURE
void supprimVoiture(){
  char reponse;
  FILE *F,*file;
  voiture p;
  int id;
  printf("Entrez l'Id de votre voiture a supprimer:\n");
  scanf("%d",&id);
  fflush(stdin);
  if(RechVoiture(id)==1){
    printf("\netes vous sur de supprimer o/n?");
    scanf("%c",&reponse);
    fflush(stdin);
      if(reponse=='o' || reponse=='O'){
        F=fopen("Voitures.txt","r");
        file=fopen("temp.txt","a");
        do{
           fscanf(F,"%s %s %s %s %d %d %d",p.nomVoiture,p.marque,p.couleur,p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);
           if(id != p.idVoiture){
            fprintf(file,"%s %s %s %s %d %d %d",p.nomVoiture,p.marque,p.couleur,p.EnLocation,p.idVoiture,p.nbplaces,p.prixJour);
           }
        }while(!feof(F));
        fclose(file);
        fclose(F);
        remove("Voitures.txt");
        rename("temp.txt","Voitures.txt");
        printf("La supression a ete effectue avec succes:\n");
      }
     else{
            printf("La suppression a echoue:\n");
        }
  }
 else printf("Ce numero n'existe pas:\n");
}
// LA DEFINITIONS DES FONCTIONS DE MENU GESTION DES CLIENTS
// RECHERCHE D'UN CLIENT
int RechClient(int id){
   printf("id %d\n",id);
   system("pause");
   client c;
    FILE *F;
    F=fopen("Clients.txt","r");
    do{
        fscanf(F,"%s %s %s %s %d %d  \n",c.nom,c.prenom,c.cin,c.adresse,&c.idClient,&c.telephone);
        //fflush(stdin);
        if(c.idClient==id)
               {
                fclose(F);
               return 1;
               }
    }while(!feof(F));
    fclose(F);
    return -1;}
//AFFICHIER LA LISTE DES CLIENTS
void ListerClients(){
    FILE *F;
    client c;
    F=fopen("Clients.txt","r");
    if(F==NULL) printf("erreur\n");
    else{
    do
    {
    printf("----------------La liste des clients-------------- :\n\n");

        //LA LECTURE D'UN FICHIER

        fscanf(F,"%s",c.nom);
        fscanf(F,"%s",c.prenom);
        fscanf(F,"%s",c.cin);
        fscanf(F,"%s",c.adresse);
        fscanf(F,"%d",&c.idClient);
        fscanf(F,"%d",&c.telephone);
        //AFFICHAGE

        printf("Le nom du client:%s\n",c.nom);
        printf("Le prenom du client:%s\n",c.prenom);
        printf("Le cin est:%s\n",c.cin);
        printf("Son adresse :%s\n",c.adresse);
        printf("L'id du client %d\n",c.idClient);
        printf("Son numero de telephone %d\n",c.telephone);
        printf("\n");
    }while(!feof(F));}
    fclose(F);
}
//AJOUTER UN CLIENT DANS LA LISTE
void AjouterClients(){
   FILE *F=NULL;
	client c;
	int id;
    F=fopen("clients.txt","a");
    if(!F){
      printf("ERROR");
	}
	else
	{ printf("donner l id du CLIENT \n");
	  scanf("%d",&id);
	  fflush(stdin);
	   while(RechClient(id)==1){
	   	printf(" ce id existe deja \n");
	   	printf(" Enter une nouvelle valeur de  idCLIENT \n");
	   	scanf("%d",&id);
	   }
   c.idClient=id;
	printf("saisir le nom du client \n");
	scanf("%s",&c.nom);
	fflush(stdin);
	printf("saisir le prenom \n");
	scanf("%s",&c.prenom);
	fflush(stdin);
	printf("saisir le cin du client \n");
	scanf("%s",&c.cin);
	fflush(stdin);
    printf("saisir l adresse du client  \n");
	scanf("%s",&c.adresse);
	fflush(stdin);
	printf(" saisir le num du telephone \n");
	scanf("%d",&c.telephone);
	fflush(stdin);
	//ajouter  ce client a la fin du fichier
    fprintf(F,"%s\n%s\n%s\n%s\n%d\n%d\n",c.nom,c.prenom,c.cin,c.adresse,c.idClient,c.telephone);
	fclose(F);
	}

     gestionClients();
}
//MODIFICATION DES INFORMATIONS D'UN CLIENT
void ModifClients(){

FILE*F,*file;
int id;
client c;
printf("\n saisir le id du client a modifier \n");
scanf("%d",&id);
fflush(stdin);
	if(RechClient(id)==1){
	F=fopen("clients.txt","r");
	file=fopen("temp.txt","a");
	do{
	fscanf(F,"%s\n%s\n%s\n%s\n%d\n%d\n",c.nom,c.prenom,c.cin,c.adresse,&c.idClient,&c.telephone);// apres la lecture du fichier ligne par lingne on copie tout le fichier <clients> dans le fichier temporaire <tempClients> en modifiant le client avec l id saisi au debut
	    if(id==c.idClient){
	printf("Entrez le nom du client :\n");
	scanf("%s",&c.nom);
	fflush(stdin);
	printf("Donnez son prenom: \n");
	scanf("%s",&c.prenom);
	fflush(stdin);
	printf("Entrer l'id du client \n");
	scanf("%d",&c.idClient);
	fflush(stdin);
	printf("saisir le cin du client \n");
	scanf("%s",&c.cin);
	fflush(stdin);
    printf("saisir l adresse du client  \n");
	scanf("%s",&c.adresse);
	fflush(stdin);
	printf(" saisir le num du telephone \n");
	scanf("%d",&c.telephone);
	fflush(stdin);
		}
	// saisie les informations du clients dans le fichier en effectuant les modification ,
	fprintf(file,"%s\n%s\n%s\n%s\n%d\n%d\n",c.nom,c.prenom,c.cin,c.adresse,c.idClient,c.telephone);
	}while(!feof(F));
fclose(F);
fclose(file);
 // IL FAUT SUPPRIMER LE FICHIER "clients" ET LE REMPLACER AVEC LE FICHIER "tempClients" qui contient les informations qu'on veut traiter
remove("Clients.txt");
rename("temp.txt","Clients.txt");
}
	else{
	printf("ce id n'existe pas\n'");
	}

}
void SupprimClients(){
client c;
 int id;
 FILE *F,*file;
 printf("Entrez le id du client a supprimer \n");
 scanf("%d",&id);
 fflush(stdin);
	 if(RechClient(id)==1)
	 { FILE *file,*F;
	 F=fopen("Clients.txt","r");
	 file=fopen("temp.txt","a");
	 // dans la boucle au dessous on lit le fichier ligne par ligne sauf le id de client q'on souhaite supprimer apres on mis ses lignes dans un fichier temporaire
		 do{

	         fscanf(F,"%s\n%s\n%s\n%s\n%d\n%d\n",c.nom,c.prenom,c.cin,c.adresse,&c.idClient,&c.telephone);
			 if(id!=c.idClient){
			 fprintf(file,"%s\n%s\n%s\n%s\n%d\n%d\n",c.nom,c.prenom,c.cin,c.adresse,c.idClient,c.telephone);
			 }
		 }while(!feof(F));
	 fclose(file);
	 fclose(F);
	 remove("Clients.txt");
	 rename("tempClient.txt","Clients.txt");
	 printf("LA SUPPRESSION EST FAITE \n");
}
}
//FONCTIONS DU MENU LOCATIONS DE VOITURES
//void AjoutContrat()
void visualContrat()
{
contrat l;
FILE*F;
float  num;
printf("\n saisir le numero de contrat   :\n");
scanf("%f",&num);
fflush(stdin);
F=fopen("Contrats.txt","r");
	do{

	 fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&l.numContrat,&l.idVoiture,&l.idClient,&l.debut.jj,&l.debut.mm,&l.debut.aa,&l.fin.jj,&l.fin.mm,&l.fin.aa,&l.cout);
		if(l.numContrat==num){ // Si on trouve le numero de contrat on l'affiche


			printf("le numero de contrat           : %f\n",l.numContrat);
        	printf("le ID de voiture               : %d\n",l.idVoiture);
        	printf("le ID de client                : %d\n",l.idClient);
        	printf("la date de debut               : %d %d %d \n",l.debut.jj,l.debut.mm,l.debut.aa);
        	printf("la date de fin                 : %d %d %d \n",l.fin.jj,l.fin.mm,l.fin.aa);
        	printf("le cout est                    : %d\n",l.cout);
            printf("\n");
			printf("\n");
		}

	}while(!feof(F));
fclose(F);
}
//louer une voiture
void LouerVoiture()
{
contrat l;
client c;
voiture p;
int dispo=0,foundV=0,foundC=0 ; // j'ai utiliser ces variables juste pour verifier s'ils changeront aprés chaque teste
int IdV,IdC;
FILE*Fv;
FILE *Fcl;
FILE*Fco;
printf("LES INFORMATIONS DU CLIENT :");
printf("Entrez le Id de client \n");
scanf("%d",&IdC);
printf("LES INFORMATIONS SUR LA VOITURE :");
printf("saisir le ID de la voiture \n");
scanf("%d",&IdV);
//VERIFICATION POUR LE CLIENT
if(RechClient(IdC)==1){ //verifier si le ID du clients existe
	foundC=1;
}
else{
	printf("Ce client n'est pas enregistre, veuillez saisir vos information  a travers le menu de GESTION CLIENT\n");
}
//VERIFICATION DES INFOS DE VOITURE
Fv=fopen("Voitures.txt","r+");
fscanf(Fv,"%s %s %s %s %d %d %d",&p.nomVoiture,&p.marque,&p.couleur,&p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);
//printf("La couleur est :%s\n",p.couleur);
//printf("location de la voiture  est :%s\n",p.EnLocation);

if(RechVoiture(IdV)==1){ //verifier si le ID du voiture existe
foundV=1;
printf("found:%d",foundV);
printf("la voiture existe \n");
}
else{
	printf("cette voiture n'existe pas !!");
}
// verifier si la voiture existe ou non

if(strcmp(p.EnLocation,"non")==0 || strcmp(p.EnLocation,"NON")==0){
	    dispo=1;
	    printf("dispo:%d",dispo);
	    printf("en location:%s\n",p.EnLocation);
	    system("pause");}   // voiture disponible
else if(strcmp(p.EnLocation,"oui")==0 || strcmp(p.EnLocation,"OUI")==0){
		dispo=0;
}
printf("found:%d",foundV);
printf("dispo:%d",dispo);
system("pause");
if(dispo==0 && foundV==1){
printf(" La voiture n'est pas disponible \n ");
}
if(dispo==1 && foundV==1){ // si la voiture existe et disponible donc on vas creer un contrat

printf(" la voiture est  disponible vous pouvez creer un contrat : \n");
    Fco=fopen("Contrats.txt","a");
 	printf("*****Entrez les informations concernant le contrat:******\n\n");
  	printf("entrez le numero de contrat:\n");
  	scanf("%f",&l.numContrat);
	printf("entrez l' id de voiture:\n");
  	scanf("%d",&l.idVoiture);
  	printf("entrez l'id du client:\n");
    scanf("%d",&l.idClient);
  	printf("entrez date de debut:\n");
  	scanf("%d %d %d",&l.debut.jj,&l.debut.mm,&l.debut.aa);
  	printf("entrez date de fin :\n");
  	scanf("%d %d %d",&l.fin.jj,&l.fin.mm,&l.fin.aa);
  	printf("entrez cout:\n");
    scanf("%d",&l.cout);
// apres la creeation on ajoute le contrat au fichier <contrats>
fprintf(Fco,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",l.numContrat,l.idVoiture,l.idClient,l.debut.jj,l.debut.mm,l.debut.aa,l.fin.jj,l.fin.mm,l.fin.aa,l.cout);
printf("%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",l.numContrat,l.idVoiture,l.idClient,l.debut.jj,l.debut.mm,l.debut.aa,l.fin.jj,l.fin.mm,l.fin.aa,l.cout);
fclose(Fco);
 printf("********* le contrat est cree **********\n");
// On doit changer l etat de voiture, de non a oui car la voiture n'est plus dsponible apres la creation du contrat
/*rewind(Fv);
// on remet le curseur au début du fichier
fseek(Fv,-3,SEEK_END);
// on place le curseur à la fin du fichier puis on le deplace 3(le nomre de lettre de "non")lettre avant la position courante
fscanf(Fv,"%s\n",&p.EnLocation);
printf("en location:%s\n",p.EnLocation);*/
//fputs("oui",Fv);     // on ecrase "non" par "oui"

/*strcpy("p.EnLocation","oui");
fprintf(Fv,"%s\n %s \n%s \n%s\n %d\n %d\n %d\n",p.nomVoiture,p.marque,p.couleur,p.EnLocation,p.idVoiture,p.nbplaces,p.prixJour);
fscanf (Fv,"%s\n %s\n %s\n %s\n %d\n %d\n %d\n",&p.nomVoiture,&p.marque,&p.couleur,&p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);

printf("en location:%s\n",p.EnLocation);
           //AFFFICHAGE*/
           ModifVoiture();
fclose(Fv);
        /*printf("\nLa liste des voitures est:\n");
        printf("NOMVOITURE:%s\n",p.nomVoiture);
        printf("MARQUE:%s\n",p.marque);
        printf("COULEUR:%s\n",p.couleur);
        printf("ENLOCATION:%s\n",p.EnLocation);
        printf("IDVOITURE :%d \n",p.idVoiture);
        printf("NOMBREDEPLACES : %d \n",p.nbplaces);
        printf(" PRIXJOUR : %d \n",p.prixJour);
        system("pause");*/
//fclose(Fv);          //fermeture de fichier
}
}
int RechContrat(int num){
FILE *F;
contrat l;
F=fopen("Contrats.txt","r");
do{
fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&l.numContrat,&l.idVoiture,&l.idClient,&l.debut.jj,&l.debut.mm,&l.debut.aa,&l.fin.jj,&l.fin.mm,&l.fin.aa,&l.cout);
	printf("idVoiture :%d\n",l.idVoiture);
    printf("num:%d\n",num);
	if(l.idVoiture==num){

    fclose(F);
    return 1;
 	}
   }while(!feof(F));
fclose(F);
return -1;
}
void SupprimContrat(int idVoiture)
{
 contrat l;
 int id;
 FILE *file,*F;
 printf("Entrez l'id de la voiture louee a retourner : \n");
 scanf("%d",&id);
     printf("l'id de la voiture :%d\n",id);
	 if(RechContrat(id)==1){
        printf("id:%d",id);
       system("pause");

	 F=fopen("Contrats.txt","r");
	 file=fopen("temp.txt","a");
		 do{
	         fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&l.numContrat,&l.idVoiture,&l.idClient,&l.debut.jj,&l.debut.mm,&l.debut.aa,&l.fin.jj,&l.fin.mm,&l.fin.aa,&l.cout);
			 if(idVoiture!=l.idVoiture){
			 fprintf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",l.numContrat,l.idVoiture,l.idClient,l.debut.jj,l.debut.mm,l.debut.aa,l.fin.jj,l.fin.mm,l.fin.aa,l.cout);
			 }
		 }while(!feof(F));
	 fclose(file);
	 fclose(F);
	 remove("Contrats.txt");
	 rename("temp.txt","Contrats.txt");
	 }
	 else{
	 	printf("Desole,cet id n'existe pas:\n");
     }
}

void RetournerVoiture()
{
int idR;
FILE *F;
voiture p;
printf(" Saisir l' identifiant (ID) de la voiture a retourner \n");
scanf("%d",&idR);
F=fopen("Voitures.txt","r");
do{
//fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&V.marque,&V.idVoiture,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
fscanf(F,"%s\n %s \n%s\n %s\n %d\n %d \n%d \n",&p.nomVoiture,&p.marque,&p.couleur,&p.EnLocation,&p.idVoiture,&p.nbplaces,&p.prixJour);
printf("La voiture a retourner %d\n",idR);
printf("La voiture%d\n",p.idVoiture);
	if(p.idVoiture==idR){
	strcpy(p.EnLocation,"Non");
	// LA VOITURE N'EST PLUS DISPONIBLE DONC ON SUPPRIME LE CONTRAT
	printf("l'etat de la voiture a retourner (enlocation):%s",p.EnLocation);
	SupprimContrat(idR);
	}
}while(!feof(F));
}
date DateRetour( date D, int nbJ){
int som;
som=D.jj+nbJ;
	if(som>31){
	D.jj=60-som;
	D.mm=D.mm+1;
		if(D.mm>12){
		D.mm=1;
		D.aa=D.aa+1;
		}

	}
	else{
	D.jj=D.jj+nbJ;
	}
return D;
}
int rech(int Numrech){
FILE *F;
voiture V;
F=fopen("voitures.txt","r");
do{
fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,&V.idVoiture,V.nomVoiture,V.couleur,&V.nbplaces,&V.prixJour,V.EnLocation);//avec cette boucle on fait la lecture de tout le fichier ligne par ligne
fflush(stdin);
	if(V.idVoiture==Numrech){
    fclose(F);
    return 1;
 	}
   }while(!feof(F));
fclose(F);
return -1;
}
void ModifContrat()
{
FILE*F,*temp;
float id,idC;
int prix,OldCout,NewCout,aide,nbJ;
contrat cont;
date NewDate,dateDEBUT;
voiture V;
printf("\n saisir le numero du contrat a modifier \n");
scanf("%f",&idC);
printf("saisir le nombre de jours que vous voulez ajouter \n");
scanf("%d",&nbJ);
printf("saisir la date de debut \n");
scanf("%d %d %d \n",&dateDEBUT.jj,&dateDEBUT.mm,&dateDEBUT.aa);
F=fopen("contrats.txt","r+");
do{
fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jj,&cont.debut.mm,&cont.debut.aa,&cont.fin.jj,&cont.fin.mm,&cont.fin.aa,&cont.cout);
	if(cont.numContrat==idC){
		aide==cont.idVoiture;
		  OldCout==cont.cout;
			if(rech(aide)==1){
			prix=V.prixJour;
			NewCout==OldCout+(nbJ*prix); // le nouveau cout
			NewDate=DateRetour(dateDEBUT,nbJ);//date de retourne
			//on ajoute a la fin du fichier
			fprintf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jj,cont.debut.mm,cont.debut.aa,NewDate.jj,NewDate.mm,NewDate.aa,NewCout);
			}
	}
}while(!feof(F));
//Maintenant on aura 2 contrats de meme ID , donc on supprime le premier contrat avec ce ID
printf("Entrez le numero du contrat que vous voulez supprimer\n");
scanf("%d",&id);
F=fopen("contrats.txt","r");
temp=fopen("tempContrat.txt","a");
		 do{
	     fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jj,&cont.debut.mm,&cont.debut.aa,&cont.fin.jj,&cont.fin.mm,&cont.fin.aa,&cont.cout);
			 if(id!=cont.numContrat){
			 fprintf(temp,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jj,cont.debut.mm,cont.debut.aa,cont.fin.jj,cont.fin.mm,cont.fin.aa,cont.cout);
			 break; // une fois cette condition est verifier on arrete, donc on a supprimer le premier contrat qui contient le premier cout et date de retour
			 }

		 }while(!feof(F));
fclose(temp);
fclose(F);
remove("contrats.txt");
rename("tempContrat.txt","clients.txt");

}
int rechCont1(int Num){
FILE *F;
contrat cont;
F=fopen("contrats.txt","r");
do{
fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jj,&cont.debut.mm,&cont.debut.aa,&cont.fin.jj,&cont.fin.mm,&cont.fin.aa,&cont.cout);
fflush(stdin);
	if(cont.idVoiture==Num){
    fclose(F);
    return 1;
 	}
   }while(!feof(F));
fclose(F);
return -1;
}
void SupprimerCont(int IdVoiture)
{
 contrat cont ;
 int id;
 printf("Entrez le id de la voiture dont vous voulez retourner \n");
 scanf("%d",&id);
 fflush(stdin);
	 if(rechCont1(id)==1)
	 { FILE *temp,*F;
	 F=fopen("contarts.txt","r");
	 temp=fopen("tempContrat.txt","a");
		 do{
	     fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jj,&cont.debut.mm,&cont.debut.aa,&cont.fin.jj,&cont.fin.mm,&cont.fin.aa,&cont.cout);
			 if(IdVoiture!=cont.idVoiture){
			 fprintf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jj,cont.debut.mm,cont.debut.aa,cont.fin.jj,cont.fin.mm,cont.fin.aa,cont.cout);
			 }
		 }while(!feof(F));
	 fclose(temp);
	 fclose(F);
	 remove("contrats.txt");
	 rename("tempContrat.txt","contrats.txt");
	 }
	 else{
	 	printf("ce id n existe pas \n");
     }
}



