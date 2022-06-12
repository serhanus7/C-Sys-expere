#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct hypothese{
        int num;
        
        struct hypothese* suivant;
        }Fait;
typedef struct{
        Fait* tete;
        Fait* queue;
        }LFait;
typedef struct regle{
	char nom;
	LFait lFinit;
	LFait conc;
	struct regle *suivant;
}pregle;
typedef struct listeregle{
        pregle* tete;
        pregle* queue;
        }LRegle;
    /******************fonction existe*******/
    int existe(LFait LF,int num){
    	Fait* parcours;
    	parcours=(LF.tete);
    	while(parcours!=NULL) {

		if(parcours->num==num) return 1;
    	parcours=parcours->suivant;
    	}
    	if (parcours==NULL) return 0;
    	
    }
    /*********regle appliquer*****/
int appliquer(LFait lf,pregle *regle)
    {
    	Fait *parcours;
    	parcours=(regle->lFinit).tete;
    	while(parcours!=NULL)
    	{
		if(existe(lf,parcours->num)==0) return 0 ;
		parcours=parcours->suivant;
    	}
    	if(parcours==NULL) return 1;
    	
    }
    /***************ajouter*******/
    LFait ajouter(LFait lf,int nbr){
    

    	 Fait *nv;
		 nv=(Fait *)malloc(sizeof(Fait));
     nv->num=nbr;
     nv->suivant=NULL;

     if(lf.tete==NULL){
                        lf.tete=lf.queue=nv;
                        }
     else {
          (lf.queue)->suivant=nv;
          lf.queue=nv;
    	
    }
    return lf;
}
    /*************************/
LRegle ajouterregle(LRegle lr){
int i;
char c;
       pregle *nv;
       nv=(pregle *)malloc(sizeof(pregle));
       
      (nv->lFinit.tete)=NULL;
      (nv->conc).tete=NULL;
      nv->suivant=NULL;
	   printf("donnez le nom de la regle ");
	   fflush(stdin);
	   scanf("%c",&c);
	   nv->nom=c;
	   while(printf("ajouter un fait intial ?\n"),fflush(stdin),scanf("%c",&c),c=='o')
	  {
	  printf("donnez un fait\n"); 
	   scanf("%d",&i);
	   nv->lFinit=ajouter(nv->lFinit,i);

}
printf("donez la conclusion\n");
scanf("%d",&i);
nv->conc=ajouter(nv->conc,i);
     if(lr.tete==NULL){
                        lr.tete=lr.queue=nv;
                        }
     else {
          (lr.queue)->suivant=nv;
          lr.queue=nv;
    	
    }
    
    return lr;

}



/*******************chainage avant***************/
LFait chainage_avant(LFait lf,LRegle lr){
           pregle *parcours;
		   parcours=lr.tete;
		   while(parcours!=NULL){
		     	
	if(appliquer(lf,parcours)==1)
	   {if (existe(lf,parcours->conc.tete->num)==0)
	       {
	        lf=ajouter(lf,parcours->conc.tete->num);
			parcours=lr.tete;   
	          continue;   
}
}
printf("ca marche\n");
parcours=parcours->suivant;
	   
	   }
return lf;
}
/******affichage liste des faits*******/
void affichage(LFait lf)
{
	Fait *parcours=lf.tete;
	while(parcours!=NULL)
	{printf("H = %d\n",parcours->num);
	parcours=parcours->suivant;
	} 
	
}
	
	int main(){
   	LFait lf;
   	LRegle lr;
   	char c;
   	lr.tete=NULL;
   	lr.queue=NULL;
   	lf.tete=NULL;
   	lf.queue=NULL;
   	int 
	   i,h,x,j;
   	for(i=1;i<=5;i++)
   	{
   	
	   lf=ajouter(lf,i);
	
}
	   printf("donnez une hypothse");
	   scanf("%d",&h);
	  x=existe(lf,h);
if(x==1) printf("l'hypothese existe\n");
else printf("l'hypothese n'existe pas\n");

while(printf("ajouter une regle  ?\n"),fflush(stdin),scanf("%c",&c),c=='o')
{
	lr=ajouterregle(lr);
}




j=appliquer(lf,lr.tete);
if(j==1) printf("la regle est applique\n");
else printf("la regle n'est pas applique\n");


lf=chainage_avant(lf,lr);
affichage(lf);


   system("pause");
return 0;
}

	   	
   	
   	
   	
   	
   	
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    																								
