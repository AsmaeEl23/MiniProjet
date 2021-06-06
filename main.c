#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

 /*********window affich********/
    GtkWidget *aflisv, *aflisc,  *fin, *buttanul, *buttnext, *buttann, *butnex, *OKF;
   GtkWidget *la1, *la2, *la3, *la4,*la5, *la6, *la7, *la8,*la9, *la10, *la11, *la12,*la13, *la14, *la15, *la16, *laF;


//les fonctions
	void choixUtilisateur(void);
//menu
	void menuClient(void);
	void menuAdmin(void);
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
	void ajv();
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

		int numContrat;
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


Voiture v;
Client cl;
// close window when the next window actived
void destroy(GtkWidget *win){
    gtk_widget_destroy(win);
    }


// menu principale
void menu();

//fonction pri
void location();
void Gvoit();
void Gcli();

//fonction du gestion voiture
void afflistvoiture();
void ajoutvoiture();
void modivoi();
void delvoi();

// foncrion de gestion de client
void affliscli();
void ajoutcli();
void modcli();
void supcli();

// fonction de location
void affcont();
void louevoi();
void retouvoit();
void modicont();
void suprcontra();

GtkWidget *window1;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *window4;
GtkWidget *window5;


//parcourus en window affiche la liste

void next(){
GtkBuilder *builder;
int m=0,k=0,i;
m++;
printf("\n%d",m);
printf("\nk %d",k);

printf("\n n:%d",m);
printf("\n%d",i);
    char a[20], b[20], *c, *d, *e, f[20], j[20], *h;
builder=gtk_builder_new_from_file("gestionvoiture.glade");
if(m<k){


   sprintf(a," Voiture n: %d.", m+1);
   sprintf(b,"%d",v.idVoiture);
   sprintf(f,"%d",v.nbplaces);
   printf("\n n est pas");
   sprintf(j,"%d DH",v.prixJour);

   gtk_label_set_text(GTK_LABEL(la1),a);

   gtk_label_set_text (la2,b);

   gtk_label_set_text (la3,v.marque);
   gtk_label_set_text (la4,v.nomVoiture);
   gtk_label_set_text (la5,v.couleur);
   gtk_label_set_text (la6,f);
   gtk_label_set_text (la7,j);
   gtk_label_set_text (la8,v.EnLocation);

   gtk_widget_show_all(aflisv);




       }
else {
        builder=gtk_builder_new_from_file("gestionvoiture.glade");
        gtk_widget_destroy(aflisv);

       fin =gtk_builder_get_object(builder,"fin");
        OKF=gtk_builder_get_object(builder,"OKF");
        laF=gtk_builder_get_object(builder,"LF");

        gtk_label_set_text (laF,"Fin d'affichage ");
        g_signal_connect_swapped (OKF, "clicked", G_CALLBACK (destroy), fin);
        gtk_widget_show_all(fin);


}


}




//location
void location(){
    GtkWidget *buloc1;
    GtkWidget *buloc2;
    GtkWidget *buloc3;
    GtkWidget *buloc4;
    GtkWidget *buloc5;
    GtkWidget *buloc6;

GtkBuilder *builder;
builder=gtk_builder_new_from_file("firstwin.glade");
gtk_widget_destroy(window2);

   window3=GTK_WIDGET(gtk_builder_get_object(builder,"win3"));

    buloc1=GTK_WIDGET(gtk_builder_get_object(builder,"buloc1"));
    g_signal_connect_swapped(buloc1,"clicked",G_CALLBACK(affcont),NULL);

    buloc2=GTK_WIDGET(gtk_builder_get_object(builder,"buloc2"));
    g_signal_connect_swapped(buloc2,"clicked",G_CALLBACK(louevoi),NULL);

    buloc3=GTK_WIDGET(gtk_builder_get_object(builder,"buloc3"));
    g_signal_connect_swapped(buloc3,"clicked",G_CALLBACK(retouvoit),NULL);

    buloc4=GTK_WIDGET(gtk_builder_get_object(builder,"buloc4"));
    g_signal_connect_swapped(buloc4,"clicked",G_CALLBACK(modicont),NULL);

    buloc5=GTK_WIDGET(gtk_builder_get_object(builder,"buloc5"));
    g_signal_connect_swapped(buloc5,"clicked",G_CALLBACK(suprcontra),NULL);

    buloc6=GTK_WIDGET(gtk_builder_get_object(builder,"buloc6"));
    g_signal_connect_swapped(buloc6,"clicked",G_CALLBACK(menu),NULL);

    gtk_widget_show_all(window3);
}
//gestion du voiture
void Gvoit(){
    GtkWidget *buv1;
    GtkWidget *buv2;
    GtkWidget *buv3;
    GtkWidget *buv4;
    GtkWidget *buv5;


GtkBuilder *builder;
builder=gtk_builder_new_from_file("firstwin.glade");

gtk_widget_destroy(window2);

    window4=GTK_WIDGET(gtk_builder_get_object(builder,"win4"));

    buv1=GTK_WIDGET(gtk_builder_get_object(builder,"buvoi1"));
    g_signal_connect_swapped(buv1,"clicked",G_CALLBACK(afflistvoiture),NULL);

    buv2=GTK_WIDGET(gtk_builder_get_object(builder,"buvoi2"));
    g_signal_connect_swapped(buv2,"clicked",G_CALLBACK(ajoutvoiture),NULL);

    buv3=GTK_WIDGET(gtk_builder_get_object(builder,"buvoi3"));
    g_signal_connect_swapped(buv3,"clicked",G_CALLBACK(modivoi),NULL);

    buv4=GTK_WIDGET(gtk_builder_get_object(builder,"buvoi4"));
    g_signal_connect_swapped(buv4,"clicked",G_CALLBACK(delvoi),NULL);

    buv5=GTK_WIDGET(gtk_builder_get_object(builder,"buvoi5"));
    g_signal_connect_swapped(buv5,"clicked",G_CALLBACK(menu),NULL);



    gtk_widget_show_all(window4);
}
void Gcli(){
    GtkWidget *buc1;
    GtkWidget *buc2;
    GtkWidget *buc3;
    GtkWidget *buc4;
    GtkWidget *buc5;
    GtkWidget *buc6;

GtkBuilder *builder;
builder=gtk_builder_new_from_file("firstwin.glade");
gtk_widget_destroy(window2);

   window5=GTK_WIDGET(gtk_builder_get_object(builder,"win5"));

    buc1=GTK_WIDGET(gtk_builder_get_object(builder,"bucli1"));
   g_signal_connect_swapped(buc1,"clicked",G_CALLBACK(affliscli),NULL);

    buc2=GTK_WIDGET(gtk_builder_get_object(builder,"bucli2"));
g_signal_connect_swapped(buc2,"clicked",G_CALLBACK(ajoutcli),NULL);

    buc3=GTK_WIDGET(gtk_builder_get_object(builder,"bucli3"));
    g_signal_connect_swapped(buc3,"clicked",G_CALLBACK(modcli),NULL);

    buc4=GTK_WIDGET(gtk_builder_get_object(builder,"bucli4"));
    g_signal_connect_swapped(buc4,"clicked",G_CALLBACK(supcli),NULL);

    buc5=GTK_WIDGET(gtk_builder_get_object(builder,"bucli5"));
    g_signal_connect_swapped(buc5,"clicked",G_CALLBACK(menu),NULL);


    gtk_widget_show_all(window5);
}
void admin(){

   GtkWidget *butad1;
   GtkWidget *butad2;
   GtkWidget *butad3;
   GtkWidget *butad4;
GtkBuilder *builder;

builder=gtk_builder_new_from_file("firstwin.glade");

gtk_widget_destroy(window1);

    window2=GTK_WIDGET(gtk_builder_get_object(builder,"win2"));

   butad1=GTK_WIDGET(gtk_builder_get_object(builder,"location"));
g_signal_connect_swapped(butad1,"clicked",G_CALLBACK(location),NULL);

    butad2=GTK_WIDGET(gtk_builder_get_object(builder,"gvoi"));
    g_signal_connect_swapped(butad2,"clicked",G_CALLBACK(Gvoit),NULL);

    butad3=GTK_WIDGET(gtk_builder_get_object(builder,"gcl"));
     g_signal_connect_swapped(butad3,"clicked",G_CALLBACK(Gcli),NULL);

    butad4=GTK_WIDGET(gtk_builder_get_object(builder,"routour"));
    g_signal_connect_swapped(butad4,"clicked",G_CALLBACK(menu),NULL);


gtk_widget_show_all(window2);
}




// menu principale
void menu(){

     GtkBuilder *builder;

  GtkWidget *button1;
   GtkWidget *button2;
   GtkWidget *button3;
   builder=gtk_builder_new_from_file("firstwin.glade");
   window1=gtk_builder_get_object(builder,"win1");

   button1=GTK_WIDGET(gtk_builder_get_object(builder,"buadmin"));
   g_signal_connect_swapped(button1,"clicked",G_CALLBACK(admin),NULL);

   button2=GTK_WIDGET(gtk_builder_get_object(builder,"buclient"));
   g_signal_connect_swapped(button2,"clicked",G_CALLBACK(admin),NULL);

   button3=GTK_WIDGET(gtk_builder_get_object(builder,"quitter"));

      g_signal_connect_swapped(button3,"clicked",G_CALLBACK(destroy),NULL);

gtk_widget_show_all(window1);

}

// definir des fcts gestion voiture
 // fonction annuler

 void annuler(GtkWidget *wind){
     gtk_widget_destroy(wind);

}
// afficher la liste des voiture
void afflistvoiture(){
GtkBuilder *builder;
GtkWidget *but;
Voiture *v;
builder=gtk_builder_new_from_file("gestionvoiture.glade");
gtk_widget_destroy(window4);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"afflisvoi"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"return"));
g_signal_connect_swapped(but,"clicked",G_CALLBACK(admin),NULL);

gtk_widget_show_all(window);

int i=0,m=0;
char a[20], b[20], *c, *d, *e, f[20], j[20], *h;
builder=gtk_builder_new_from_file("gestionvoiture.glade");
aflisv=gtk_builder_get_object(builder,"AFV");
buttanul=gtk_builder_get_object(builder,"butannul");
buttnext=gtk_builder_get_object(builder,"buttnext");
la1=gtk_builder_get_object(builder,"la1");
gtk_label_set_text(GTK_LABEL(la1),"a");

la2=gtk_builder_get_object(builder,"la2");
la3=gtk_builder_get_object(builder,"la3");
la4=gtk_builder_get_object(builder,"la4");
la5=gtk_builder_get_object(builder,"la5");
la6=gtk_builder_get_object(builder,"la6");
la7=gtk_builder_get_object(builder,"la7");
la8=gtk_builder_get_object(builder,"la8");



FILE *fv;
fv=fopen("voiture","r");

i=0;
v=(Voiture*)malloc(i*sizeof(Voiture));
if(fv==NULL)
       exit(1);

do{

   i++;

v=realloc(v, i*sizeof(Voiture));


fscanf(fv,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&v->idVoiture,v->marque,v->couleur,&v->nbplaces,&v->nbplaces,v->EnLocation);


printf("\n EREUR!!!");


    }while(!feof(fv));
int k;       k=i;
    fclose(fv);

sprintf(a," Voiture n: %d.", 0);

 printf("\n%s",a);
   sprintf(b,"%d",v[0].idVoiture);


   sprintf(f,"%d",v[0].nbplaces);

   sprintf(j,"%d DH",v[0].prixJour);

        gtk_label_set_text(GTK_LABEL(la1),a);
        gtk_label_set_text (la2,b);
        gtk_label_set_text (la3,v->marque);
        gtk_label_set_text (la4,v->nomVoiture);
        gtk_label_set_text (la5,v->couleur);
        gtk_label_set_text (la6,f);
        gtk_label_set_text (la7,j);
        gtk_label_set_text (la8,v->EnLocation);

gtk_widget_show_all(aflisv);

        g_signal_connect_swapped (buttnext, "clicked", G_CALLBACK (next), NULL);
        g_signal_connect_swapped (buttanul, "clicked", G_CALLBACK (annuler), NULL);



}


//ajoute voiture
GtkWidget *Eid,*Enom,*Emar,*Ecolo,*Eplace,*Eprix;


void ajoutvoiture(){
GtkBuilder *builder;
GtkWidget *but;

builder=gtk_builder_new_from_file("gestionvoiture.glade");
gtk_widget_destroy(window4);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"ajoutvoi"));

  Eid=GTK_WIDGET(gtk_builder_get_object(builder,"Eid"));


  Enom=GTK_WIDGET(gtk_builder_get_object(builder,"Envoi"));
  Emar=GTK_WIDGET(gtk_builder_get_object(builder,"Emar"));
  Ecolo=GTK_WIDGET(gtk_builder_get_object(builder,"Ecolo"));
  Eplace=GTK_WIDGET(gtk_builder_get_object(builder,"Epla"));
  Eprix=GTK_WIDGET(gtk_builder_get_object(builder,"Epri"));
  gtk_widget_show_all(window);






but=GTK_WIDGET(gtk_builder_get_object(builder,"valide"));
g_signal_connect_swapped(but,"clicked",G_CALLBACK(ajv),NULL);


}
void ajv(){
int idv;
char *id,*nom,*mar,*colo,*place,*prix;
FILE *fv;
GtkBuilder *builder;

       int a, e, f;
   builder=gtk_builder_new_from_file("gestionvoiture.glade");
   id=gtk_entry_get_text(GTK_ENTRY(Eid));
   sscanf(id,"%d",&a);

   nom=gtk_entry_get_text(GTK_ENTRY(Enom));

   colo=gtk_entry_get_text(GTK_ENTRY(Ecolo));

   mar=gtk_entry_get_text(GTK_ENTRY(Emar));

   place=gtk_entry_get_text(GTK_ENTRY(Eplace));
    sscanf(place,"%d",&e);

    prix=gtk_entry_get_text(GTK_ENTRY(Eprix));
    sscanf(prix,"%d",&f);

    fv=fopen("voiture.txt","a");


if(findv(a)==1){

        builder=gtk_builder_new_from_file("gestionvoiture.glade");
       gtk_widget_destroy(aflisv);
GtkWidget *fin,*OKF,*LF;
        fin=gtk_builder_get_object(builder,"fin");
        OKF=gtk_builder_get_object(builder,"OKF");
        LF=gtk_builder_get_object(builder,"LF");

        gtk_label_set_text (LF,"Cette voiture est deja existe \n'cette ID est deja existe'");
        g_signal_connect_swapped (OKF, "clicked", G_CALLBACK (destroy), fin);
        gtk_widget_show_all(fin);





}else{
       v.idVoiture=id;

       strcpy(v.marque,mar);


       strcpy(v.nomVoiture,nom);

       strcpy(v.couleur,colo);


       v.nbplaces=e;

       v.prixJour=f;

       fprintf(fv,"%d \t %s \t %s \t %s \t %d \t %d \n",v.idVoiture,v.nomVoiture,v.marque,v.couleur,v.nbplaces,v.prixJour);

   }
        fclose(fv);

}
//modifier des information sur une voiture
void modivoi(){
GtkBuilder *builder;
GtkWidget *but;

builder=gtk_builder_new_from_file("gestionvoiture.glade");
gtk_widget_destroy(window4);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"valimod"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"ok"));
g_signal_connect_swapped(but,"clicked",G_CALLBACK(ajoutvoiture),NULL);

gtk_widget_show_all(window);
//gtk_widget_destroy(window);
}

//suprimer une voiture
void delvoi(){
    GtkBuilder *builder;
   GtkWidget *but;

builder=gtk_builder_new_from_file("gestionvoiture.glade");
gtk_widget_destroy(window4);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"delvoi"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"valide"));


gtk_widget_show_all(window);
}

//definir des fcts de estion


// afficher la liste des clients
void affliscli(){
GtkBuilder *builder;
GtkWidget *but;
int i=0,m=0;
char a[20], b[20], *c, *d, *e, f[20], j[20], *h;

builder=gtk_builder_new_from_file("gestionvoiture.glade");
gtk_widget_destroy(window5);

but=GTK_WIDGET(gtk_builder_get_object(builder,"return"));
g_signal_connect_swapped(but,"clicked",G_CALLBACK(admin),NULL);




aflisc=gtk_builder_get_object(builder,"affliscli");
buttann=gtk_builder_get_object(builder,"butannuler");
butnex=gtk_builder_get_object(builder,"butnext");
la9=gtk_builder_get_object(builder,"la9");
gtk_label_set_text(GTK_LABEL(la1),"a");
la10=gtk_builder_get_object(builder,"la10");
la11=gtk_builder_get_object(builder,"la11");
la12=gtk_builder_get_object(builder,"la12");
la13=gtk_builder_get_object(builder,"la13");
la14=gtk_builder_get_object(builder,"la14");
la15=gtk_builder_get_object(builder,"la15");


/*i=0;
cl=(Client *)malloc(i*sizeof(Client));
FILE *fc;


fc=fopen("Client.txt","r");

   int t=0;


   do{

   i++;

cl=realloc(cl, i*sizeof(Client));


fscanf(fc,"%d\t%s\t%s\t%d%s\t%d\n",&cl[i-1].idClient,cl[i-1].nom,cl[i-1].prenom, &cl[i-1].cin,cl[i-1].adresse,&cl[i-1].telephone);

printf("\n EREUR!!!");


    }while(!feof(fc));
       k=i;
    fclose(fc);

sprintf(a," Cient : n%d.", 1);

 printf("\n%s",a);
   sprintf(b,"%d",cl.idClient);
   sprintf(f,"%d",cl.Cin);
   sprintf(j,"+212%d ",cl.telephone);

   gtk_label_set_text(GTK_LABEL(la9),a);

gtk_label_set_text (la10,b);

gtk_label_set_text (la11,cl[0].nom);
gtk_label_set_text (la12,cl[0].prenom);
gtk_label_set_text (la13,f);
gtk_label_set_text (la14,cl[0].Adresse);
gtk_label_set_text (la15,j);
*/

gtk_widget_show_all(affliscli);




        g_signal_connect_swapped (butnex, "clicked", G_CALLBACK (next), NULL);
        g_signal_connect_swapped (buttann, "clicked", G_CALLBACK (annuler), NULL);


}

//ajouter un client au liste
void ajoutcli(){
GtkBuilder *builder;
GtkWidget *but;

builder=gtk_builder_new_from_file("gestionclient.glade");
gtk_widget_destroy(window5);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"ajoutcli"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"valide"));

gtk_widget_show_all(window);
}

//modifier un client
void modcli(){
GtkBuilder *builder;
GtkWidget *but;

builder=gtk_builder_new_from_file("gestionclient.glade");
gtk_widget_destroy(window5);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"valimod"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"ok"));
g_signal_connect_swapped(but,"clicked",G_CALLBACK(ajoutcli),NULL);

gtk_widget_show_all(window);
}

//suprimer un client
void supcli(){
     GtkBuilder *builder;
   GtkWidget *but;

builder=gtk_builder_new_from_file("gestionclient.glade");
gtk_widget_destroy(window5);

GtkWidget *window;
window=GTK_WIDGET(gtk_builder_get_object(builder,"delcli"));

but=GTK_WIDGET(gtk_builder_get_object(builder,"valide"));


gtk_widget_show_all(window);
}

// definir des fonction de louer
void affcont(){
}
void louevoi(){
}
void retouvoit(){
}
void modicont(){
}
void suprcontra(){
}





int main(int argc,char **argv){



   gtk_init(&argc,&argv);
//appele la fonction menu qui affiche le premier window
     menu();


   gtk_main();
   return 0;
}

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
