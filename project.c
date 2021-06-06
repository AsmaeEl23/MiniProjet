#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//les fonctions
	void choixUtilisateur(void);
//menu
	void menuClient(void);
	void menuAdmine(void);
// les fonctions principale
	void Location(void);
	void GestionVoitures(void);
	void GestionClients(void);
//Location
	void ajouuterContrat(void);
	void VisualiserContrat(void);
	void LouerVoiture(void);
	void RetournerVoiture(void);
	void ModifierContrat(void);
	void SupprimerContrat(int Ncon);
	int  findco(int Ncon);
//Gestion des voitures
	void ListeVoitures(void);
	void AjouterVoiture(void);
	void ModifierVoiture(void);
	void SupprimerVoiture(void);
	int  findv(int id);
// Gestion Clients
	void ListeClients(void);
	void AjouterClient(void);
	void ModifierClient(void);
	void SupprimerClient(void);
	int  findc(int id);
//les structes
	typedef struct Voiture {
     
		int  idVoiture; 
    	char marque[15];
	    char nomVoiture[15];
		char couleur[7];
		int  nbplaces;
		int  prixJour;
		char EnLocation[4];
		 
		}Voiture;
	typedef struct date{
		int jj;
		int mm;
		int an;
	
	}date;
	typedef struct contratLocation{ 
    
		float numContrat;
        int idVoiture;
	    int idClient;
		date debut;
		date fin;
		int cout;
			
		}Contrat;
	typedef struct client{
	     
		int idClient;
	    char nom[20];
		char prenom[20];
	    char cin[10];
		char adresse[15];
		char telephone[12];
		
		}Client;
	// choix utilisateur
	void choixUtilisateur(void){
		int choix;
	
		system("cls");
		printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                      \xb3 Menu Principal   \xb3");
		printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
		printf("\n");
	
		printf("\n                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                     \xba                                                         \xba");
		printf("\n                     \xba     Admine........................................1     \xba");
		printf("\n                     \xba     Client........................................2     \xba");
		printf("\n                     \xba                                                         \xba");
		printf("\n                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
		printf("\n\n                                      Votre choix  :  ");
		scanf("%d", &choix);
		while(choix<1||choix>2){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
			
		}
		if(choix==1){
			menuAdmine();
		}else if(choix==2) {
			menuClient();
		}
	
	}
	// menu Client
	void menuClient(void){
		
		int choix;
		
			system("cls");
			printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                                        \xb3 Client           \xb3");
			printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		
			printf("\n");
		
			printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n                       \xba                                                         \xba");
			printf("\n                       \xba     Ajouter Client................................1     \xba");
			printf("\n                       \xba     Liste voiture.................................2     \xba");
			printf("\n                       \xba     Louer voiture.................................3     \xba");
			printf("\n                       \xba     Retourner voiture.............................4     \xba");
			printf("\n                       \xba     Quitter.......................................5     \xba");
			printf("\n                       \xba                                                         \xba");
			printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                      Votre choix  :  ");
			scanf("%d",&choix);
			
		while(choix<1||choix>5){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
		}
			switch(choix)
			{
		case 1 : AjouterClient();
					break;
		case 2 : ListeVoitures();
					break;
		case 3 : LouerVoiture();
					break;
		case 4 : RetournerVoiture();
					break;			
		case 5 : choixUtilisateur();
					break;
	}
}
	//	menu Admine
	void menuAdmine(void){
		int choix;
		system("cls");
			system("cls");
			printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                                      \xb3 Admine           \xb3");
			printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			printf("\n");
			printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
			printf("\n                       \xba                                                         \xba");
			printf("\n                       \xba     Location......................................1     \xba");
			printf("\n                       \xba     Gestion voitures..............................2     \xba");
			printf("\n                       \xba     Gestion clients...............................3     \xba");
			printf("\n                       \xba     Quitter.......................................4     \xba");
			printf("\n                       \xba                                                         \xba");
			printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
			printf("\n\n                                      Votre choix  :  ");
			
			scanf("%d",&choix);
		while(choix<1||choix>4){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
		}
			switch(choix){
		case 1 : Location();
					break;
		case 2 : GestionVoitures();
					break;
		case 3 : GestionClients();
					break;
		case 4 : choixUtilisateur();
					break;
			}
		
	}
	
	void Location(void){
		int choix;
		system("cls");
		printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                      \xb3 Location d'une Voiture   \xb3");
		printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		printf("\n");
		printf("\n                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
		printf("\n                     \xba                                                              \xba");
		printf("\n                     \xba     Ajouter contrat....................................1     \xba");
		printf("\n                     \xba     Visualiser contrat.................................2     \xba");
		printf("\n                     \xba     Louer voiture......................................3     \xba");
		printf("\n                     \xba     Retourner voiture..................................4     \xba");
		printf("\n                     \xba     Modifier contrat...................................5     \xba");
		printf("\n                     \xba     Retour.............................................6     \xba");
		printf("\n                     \xba                                                              \xba");
		printf("\n                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
		printf("\n\n                                        Votre choix  :  ");
	    scanf("%d", &choix);
		while(choix<1||choix>6){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
			
		}
		
			switch(choix){
		case 1 : ajouuterContrat();
					break;
		case 2 : VisualiserContrat();
					break;
		case 3 : LouerVoiture();
					break;
		case 4 : RetournerVoiture();
					break;
		case 5 : ModifierContrat();
					break;
		case 6 : choixUtilisateur();
					break;
			}
		
	}
	
	void GestionVoitures(){
		int choix;

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
		printf("\n\n                                          Votre choix  :  ");
		scanf("%d",&choix);
		while(choix<1||choix>5){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
			
		}
		
			switch(choix){
		case 1 : ListeVoitures();
					break;
		case 2 : AjouterVoiture();
					break;
		case 3 : ModifierVoiture();
					break;
		case 4 : SupprimerVoiture();
					break;
		case 5 : choixUtilisateur();
					break;
			}
	}
	
	void GestionClients(void){
		int choix;
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
		printf("\n\n                                          Votre choix  :  ");
	
		scanf("%d", &choix);
		while(choix<1||choix>5){
			printf("\n\n                                      Erreur !! __ Votre choix  :\n");
			scanf("%d",&choix);
			
		}
		
			switch(choix){
		case 1 : ListeClients();
					break;
		case 2 : AjouterClient();
					break;
		case 3 : ModifierClient();
					break;
		case 4 : SupprimerClient();
					break;
		case 5 : choixUtilisateur();
					break;
			}

	}
	//les variables gloale
	Voiture v;
	Client c;
	Contrat co;
	
	//Location
	
	void ajouuterContrat(){
		FILE *fco;
    int numc;
    system("cls");
    if(fco==NULL) printf("\n                   !!erreur\n");
    else{
    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                        \xb3 Ajouter contrat         \xb3");
	printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    
	printf("\n    __Entrez Numero de contrat :");
    scanf("%d",&numc);
    fco=fopen("contrat.txt","a");
    while(findco(numc)==1){
        printf("\n   **Cette contrat deja existe**");
        printf("\n    __Entrez N contrat :");
        scanf("%d",&numc);
    }
    co.numContrat=numc;
    printf("\n    __Id voitur : ");
    scanf("%d",&co.idVoiture);
    printf("\n    __Id client : ");
    scanf("%d",&co.idClient);
    printf("\n    __Date debut  ");
    printf("\n        ..Jour  : ");
    scanf("%d",&co.debut.jj);
    printf("\n        ..Mois  : ");
    scanf("%d",&co.debut.mm);
    printf("\n        ..Annee : ");
    scanf("%d",&co.debut.an);
    printf("\n    __Date fin   ");
    printf("\n        ..Jour  : ");
    scanf("%d",&co.fin.jj);
    printf("\n        ..Mois  : ");
    scanf("%d",&co.fin.mm);
    printf("\n        ..Annee : ");
    scanf("%d",&co.fin.an);
    fprintf(fco,"%d %d %d %d_%d_%d %d_%d_%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jj,co.debut.mm,co.debut.an,co.fin.jj,co.fin.mm,co.fin.an);
	}
	fclose(fco);
	Location();
	}
	
	void VisualiserContrat(void){
		FILE *fco;
		system("cls");
	    
	    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Liste des contrats      \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    fco=fopen("contrat.txt","r");
    do
    {
        //lecture dans le ficher
         fscanf(fco,"%d %d %d %d %d %d %d %d %d %d",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jj,&co.debut.mm,&co.debut.an,&co.fin.jj,&co.fin.mm,&co.fin.an);

        //affficher en terminal
        printf("Num contrat : %d",co.numContrat);
        printf("   __Id voiture : %d",co.idVoiture);
        printf("   __Id client  : %d",co.idClient);
        printf("   __Date debut : %d_%d_%d",co.debut.jj,co.debut.mm,co.debut.an);
        printf("   __Date fine  : %d_%d_%d",co.fin.jj,co.fin.mm,co.fin.an);
        printf("   __Cout       : %d",co.cout);
        printf("\n");
    }while(!feof(fco));
    fclose(fco);
    Location();
    }
	
	
	int findco(int numc){
		FILE *fco;
		fco=fopen("contrat.txt","r");
		do{
			fscanf(fco,"%d %d %d %d %d %d %d %d %d %d",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jj,&co.debut.mm,&co.debut.an,&co.fin.jj,&co.fin.mm,&co.fin.an);
			if(co.numContrat==numc)
			return 1;
		}while(!feof);
	
		return 0;
	}
	
	void LouerVoiture(void){
		
	int co=0,id;
    FILE  *fc,*fv,*fco;
    char rep[3],cin[10];
    
    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Louer voiture          \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    
    printf("\n\n         ____Entrer votre CIN : ");
    scanf("%s",cin);
    fc=fopen("client.txt","r");
    do{
        fscanf(fc,"%d %s %s %s %s %s",&c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
        if(strcmp(c.cin,cin)){
            co=1;
        break;}
        }while(!feof(fc));
        if(co==1){
            ListeVoitures();
            printf("\n\n               choisir l'ID du voiture que vous voulez louer : ");
            scanf("%d",&id);
        }else
        {
            printf("\n\n !!!! Ce client n'exit pas . !!!!\n");
            AjouterClient();
            ListeVoitures();
            printf("\n\n               choisir l'ID du voiture que vous voulez louer : ");
            scanf("%d",&id);
            printf("\n Vous etes sur que vous aurez louer cette voiture ??");
            scanf("%s",rep);
        }fclose(fc);
		fv=fopen("voiture.txt","r");
		if(rep=="oui"){
		
		while(!feof(fv)){
        if(v.idVoiture==id){
            fscanf(fv,"%s",v.EnLocation);
            if(strcmp(v.EnLocation,"non")){
                ajouuterContrat();
                strcpy(v.EnLocation,"oui");
                }
	    }else{
	    	printf("\n\t*************************************************************");
	        printf("\n\t*************Cette voiture n'est pas disponible**************");
	        printf("\n\t*************************************************************");
	        
	        break;
	    }
		}
		}else{
			choixUtilisateur();
		}
	}
	void RetournerVoiture(){
		FILE *fco,*fv;
		char ans[2];
		int idv,numc;
		system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Retourner voiture      \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		printf("\n \t Entrer id de voiture : ");
		scanf("%d",&idv);
		while(findv(idv)==0){
			printf("\n !!! le id n'est pas correct, entrer Id : ");
			scanf("%d",&idv);
		}
		printf("\n \t Vous voulez vraiment retourner cette voiture o/n ?\n");
        scanf("%s",ans);
         if(*ans=='o'|| *ans=='O'){
         	fv=fopen("Voitures","r");
         	do{
                fscanf(fv,"%s %s %s %d %d %d", v.nomVoiture, v.marque,v.couleur,&v.nbplaces,&v.prixJour,&v.idVoiture);
              if(v.idVoiture==idv)
                strcpy(v.EnLocation,"non");
              }while(!feof(fv));
              fclose(fv);
              printf("\n \t Entrer numero de votre contrat : ");
              SupprimerContrat(numc);
         }else{
         	printf("\n Retourner voiture est annuler ");
		 }
		 Location();
	}
	void ModifierContrat(){
		FILE *f,*fich;
    int numc;
    char ans[2];
    system("cls");
	printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                        \xb3 Modifier contrat         \xb3");
	printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n --Entrer le numero du contrat : \n");
    scanf("%d",&numc);
    if(findco(numc)==1){
        printf("\n Vous voulez VRaiment Modifier o/n?\n");
        scanf("%s",ans);
         if(*ans=='o'|| *ans=='O'){
              f=fopen("contrat.txt","r");
              fich=fopen("copcontrat.txt","a");
              do{
                fscanf(f,"%d %d %d %d %d %d %d %d %d %d",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jj,&co.debut.mm,&co.debut.an,&co.fin.jj,&co.fin.mm,&co.fin.an);
                if(co.numContrat==numc){
                co.numContrat=numc;
			    printf("\n    __Id voitur : ");
			    scanf("%d",&co.idVoiture);
			    printf("\n    __Id client : ");
			    scanf("%d",&co.idClient);
			    printf("\n    __Id voitur : ");
				scanf("%d",&co.idVoiture);
			    printf("\n    __Date debut  ");
			    printf("\n        ..Jour  : ");
			    scanf("%d",&co.debut.jj);
			    printf("\n        ..Mois  : ");
			    scanf("%d",&co.debut.mm);
			    printf("\n        ..Annee : ");
			    scanf("%d",&co.debut.an);
			    printf("\n    __Date fin   ");
			    printf("\n        ..Jour  : ");
			    scanf("%d",&co.fin.jj);
			    printf("\n        ..Mois  : ");
			    scanf("%d",&co.fin.mm);
			    printf("\n        ..Annee : ");
			    scanf("%d",&co.fin.an);
			    fprintf(f,"%d %d %d %d_%d_%d %d_%d_%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jj,co.debut.mm,co.debut.an,co.fin.jj,co.fin.mm,co.fin.an);
                  }
              }while(!feof(f));
              fclose(fich);
              fclose(f);
              remove("Voitures.txt");
              rename("copvoiture.txt","Voiture.txt");
              printf("\n la modification du voiture ID=%d est reussi",v.idVoiture);
         }
         else{ printf("\n   la Modification a ete annule\n");}
    }
    else printf("\n !! cette voiture n'existe Pas !!\n");
    Location();
	}
	
	void SupprimerContrat(int nco){
	FILE *fco,*fich;
    
    if(findco(nco)==1){
      fco=fopen("contrat.txt","r");
      fich=fopen("copcontrat.txt","a");
      do{
        fscanf(fco,"%d %d %d %d %d %d %d %d %d %d",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jj,&co.debut.mm,&co.debut.an,&co.fin.jj,&co.fin.mm,&co.fin.an);
        if(co.numContrat!=nco){
        fprintf(fco,"%d %d %d %d_%d_%d %d_%d_%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jj,co.debut.mm,co.debut.an,co.fin.jj,co.fin.mm,co.fin.an);
        }
      }while(!feof(fco));
      fclose(fich);
      fclose(fco);
      remove("contrat.txt");
      rename("copcontrat.txt","voiture.txt");
      printf("\n   Votre contrat est supprimer",c.idClient);
    }
    else printf("\n     !! Ce numero n'existe Pas !! \n");
    close(fco);
    Location();
	}
	
//Gestion des voitures
	
	int findv(int id){

		FILE *fp;
		fp=fopen("Voitures.txt","r");
		do{
			fscanf(fp,"%d %s %s %s %d %d %s",&v.idVoiture,v.nomVoiture,v.marque,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
			if(v.idVoiture==id)
			return 1;
		}while(!feof);
	
		return 0;
	}
	
	void ListeVoitures(){
	
		FILE *fv;
		
		system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Liste voiturs          \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		fv=fopen("Voitures.txt","r");
		if(fv==NULL){
			printf("that has been an error");
			exit(1);
		}
		else{
			do{
			//lire le contenue de fichie Voitures
			fscanf(fv," %d %s %s %s %d %d %s ",&v.idVoiture,v.nomVoiture,v.marque,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
			//afficher le contenue de fichie Voitures
			printf("\n__Id de voiture: %d",v.idVoiture);
			printf("\n         -Nom : %s",v.nomVoiture);
			printf("\n         -La marque : %s",v.marque);
			printf("\n         -Couleur : %s",v.couleur);
			printf("\n         -Numero de place : %d",v.nbplaces);
			printf("\n         -Prix jour : %dDH",v.prixJour);
			printf("\n         -la voitur en location?? : %s",v.EnLocation);
			
			}while(!feof);
		}
		fclose(fv);
		
	}
	
	void AjouterVoiture(void){
		FILE *fv;
		int idv,nbrv,i;
		fv=fopen("Voitures.txt"," a ");
		system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Ajouter voiture          \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	if(!fv){printf("that has been an error");
		exit(1);
		}
	else{
		printf("\n  Combien du voitures vous voullez ajouter :");
		scanf("%d",&nbrv);
		for(i=1;i<=nbrv;i++){
		printf("\n Voiture %d ",i);
			printf("\n--Id voitur : ");
		    scanf("%d",&idv);
		while(findv(idv)==1){
			printf("\n********Cette voiture deja exist********");
			printf("\n\n !!! Entrer autre Id : ");
			scanf("%d",&idv);
		}
		v.idVoiture=idv;
		printf("\n   --Nom de voiture             : ");
		scanf("%s",v.nomVoiture);
		printf("\n   --Marque de voiture          : ");
		scanf("%s",v.marque);
		printf("\n   --Couleur de voiture         : ");
		scanf("%s",v.couleur);
		printf("\n   --Numero de place du voiture : ");
		scanf("%d",&v.nbplaces);
		printf("\n   --Prix jour du voiture       : ");
		scanf("%d",&v.prixJour);
		printf("\n   --la voitur en location ??   : ");
		scanf("%s",v.EnLocation);
		fprintf(fv,"%d %s %s %s %d %d %s \n ",v.idVoiture,v.nomVoiture,v.marque,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
		}
	fclose(fv);
	}
	GestionVoitures();
	}
	
	void ModifierVoiture(void){
		FILE *f,*fich;
    int id;
    char ans[2];
    system("cls");
	printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                        \xb3 Modifier voiture         \xb3");
	printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n --Entrer l'ID du voiture\n");
    scanf("%d",&id);
    if(findv(id)==1){
        printf("\n Vous voulez VRaiment Modifier o/n?\n");
        getchar();
        gets(ans);
        getchar();
         if(*ans=='o'|| *ans=='O'){
              f=fopen("Voitures.txt","r");
              fich=fopen("copvoiture.txt","a");
              do{
                fscanf(f," %d %s %s %s %d %d %s",&v.idVoiture,v.nomVoiture,v.marque,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
              if(id==v.idVoiture){
                v.idVoiture=id;
                printf("\n  -Entrer le nouveau nom voiture     : ");
                scanf("%s",v.nomVoiture);
                printf("\n  -Entrer le nouveau marque voiture  : ");
                scanf("%s",v.marque);
                printf("\n  -Entrer le nouveau couleur voiture : ");
                scanf("%s",v.couleur);
                printf("\n  -Entrer le nouveau nombre du palace: ");
                scanf("%d",&v.nbplaces);
                printf("\n  -Entrer le nouveau prix de jour    :");
                scanf("%d",&v.prixJour);
                printf("\n  -                  -En location ?? :");
                scanf("%d",&v.prixJour);
                fprintf(fich,"%d %s %s %s %d %d %s",v.idVoiture,v.nomVoiture, v.marque,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
                  }
              }while(!feof(f));
              fclose(fich);
              fclose(f);
              remove("Voitures.txt");
              rename("copvoiture.txt","Voitures.txt");
              printf("\n la modification du voiture ID=%d est reussi",v.idVoiture);
         }
         else{ printf("\n   la Modification a ete annule\n");}
    }
    else printf("\n !! cette voiture n'existe Pas !!\n");
    GestionVoitures();
	}
	
	void SupprimerVoiture(void){
		FILE *f,*fich;
    char ans[2];
    int id;
        system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Supprimer voiture     \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n  --Entrer l'ID du voiture que vouez supprimer :");
    scanf("%d",&id);
    if(findv(id)==1){
        printf("\n ** Vous voulez VRaiment Supprimer o/n? : ");
        scanf("%s",ans);
        getch();
         if(*ans=='o' ||*ans=='O'){
              f=fopen("Voitures.txt","r");
              fich=fopen("copvoiture.txt","a");
              do{
                fscanf(f,"%d %s %s %s %d %d %s ",&v.idVoiture,v.nomVoiture, v.marque,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
                if(v.idVoiture!=id){
                fprintf(fich,"%d %s %s %s %d %d %s \n",v.idVoiture,v.nomVoiture, v.marque,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
                  }
              }while(!feof(f));
            fclose(fich);
              fclose(f);
              remove("voitures.txt");
              rename("copvoiture.txt","voitures.txt");
            printf("\n la Suppression du voiture ID= %d est reussi",v.idVoiture);
         }
         else{ printf("\nla Suppression a été annulé\n");}
    }
    else printf("\n !! Ce Id n'exist Pas !!\n");
     GestionVoitures();
	}
	
// Gestion Clients

	void ListeClients(void){
		FILE *fc;
    fc=fopen("client.txt","r");
    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Liste clients         \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    if(fc==NULL) printf("\n  erreur");
    else{
	    do
	    {
	        //lecture dans le ficher
	        fscanf(fc,"%d %s %s %s %s %s",&c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
	        //affficher en terminal
	        printf("\n --Id            : %d",c.idClient);
	        printf("\n   --Nom         : %s",c.nom);
	        printf("\n   --Prenom      : %s",c.prenom);
	        printf("\n   --CIN         : %s",c.cin);
	        printf("\n   --Adresse     : %s",c.adresse);
	        printf("\n   --N telephone : %s",c.telephone);
	        printf("\n");
	    }while(!feof(fc));
	}
    fclose(fc);
     GestionClients();
	}

	void AjouterClient(void){
		FILE *f;
    int idc,i,nbrc;
    f=fopen("client.txt","a");
    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Ajouter client           \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    
	printf("\n   -Entrez ID de client :");
    scanf("%d",&idc);
    while(findc(idc)==1){
        printf("\n    !! Ce client deja existe !!");
        printf("\n    -ID de clien : ");
        scanf("%d",&idc);
}
	c.idClient=idc;
    printf("\n    --le Nom      : ");
    getchar();
    gets(c.nom);
    printf("\n    --Prenom      : ");
    gets(c.prenom);
    printf("\n    --CIN         : ");
    getchar();
    gets(c.cin);
    printf("\n    --Adresse     : ");
    gets(c.adresse);
    printf("\n    --Le telephone: ");
    gets(c.telephone);
    fprintf(f," %d %s %s %s %s %s \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
    fclose(f);
    printf("\n \t votre :::");
    GestionClients();
	}
	
	void ModifierClient(void){
		FILE *f,*fich;
    int idc;
    char ans[2];
    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Modifier client          \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n   -Entrer l'ID du client\n");
    scanf("%d",&idc);
    if(findv(idc)==1){
        printf("\n  **Vous voulez VRaiment Modifier o/n ?**\n");
        getchar();
        gets(ans);
        getchar();
         if(*ans=='o'|| *ans=='O'){
              f=fopen("client.txt","r");
              fich=fopen("copclient.txt","a");
              do{
                fscanf(f,"%d %s %s %s %s %s",&c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
              if(idc==c.idClient){
                c.idClient=idc;
                printf("\n    --Nom       : ");
                scanf("%d",c.nom);
                printf("\n    --Prenom    : ");
                scanf(" %s",c.prenom);
                printf("\n    --CIN       : ");
                scanf("%s",c.cin);
                printf("\n    --Adresse   : ");
                scanf("%s",c.adresse);
                printf("\n    --Telephone : ");
                scanf("%s",c.telephone);
                fprintf(fich,"%d %s %s %s %s %s\n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
                  }
              }while(!feof(f));
                fclose(fich);
              fclose(f);
              remove("client.txt");
              rename("copclient.txt","client.txt");
            printf("\n    la modification du client  ID=%d est reussi\n",c.idClient);
         }
         else{ printf("\n  la Modification a ete annule\n");}
    }
    else printf("\n   Ce client n'existe Pas!!\n");
     GestionClients();
	}
	
	void SupprimerClient(void){
		FILE *fc,*fich;
    char ans[2];
    int idc;
    system("cls");
	    printf("\n                                        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                                        \xb3 Supprimer client         \xb3");
		printf("\n                                        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n   -Entrer l'ID du client que voulez supprimer \n");
    scanf("%d",&idc);
    if(findc(idc)==1){
        printf("\n     !! Vous voulez VRaiment Supprimer o/n ? !!\n");
        scanf("%s",ans);
         if(*ans=='o' ||*ans=='O'){
              fc=fopen("client.txt","r");
              fich=fopen("copclient.txt","a");
              do{
                fscanf(fc,"%d %s %s %s %s %s",&c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
              if(c.idClient!=idc){
                fprintf(fc,"%d %s %s %s %s %s\n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
                  }
              }while(!feof(fc));
              fclose(fich);
              fclose(fc);
              remove("client.txt");
              rename("copclient.txt","voiture.txt");
            printf("\n   la Suppression du client ID=%d est reussi",c.idClient);
         }
         else{ printf("\n   la Suppression a été annulé\n");}
    }
    else printf("\n     !! Ce id n'existe Pas !! \n");
     GestionClients();
	}
	
	int findc(int idc){

		FILE *fc;
		fc=fopen("client.txt","r");
		do{
			fscanf(fc,"%d %s %s %s %s %s",&c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
			if(c.idClient==idc)
			return 1;
		}while(!feof);
	
		return 0;
	} 
	
	int main(){
		choixUtilisateur();
		return 0;
	}
