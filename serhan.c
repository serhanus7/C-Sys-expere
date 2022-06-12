#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/********************/
int existe(LFait * lf,int num){
    hypo *parcours=lf->tete;
    while(parcours)
    {
                   if(num==parcours->num)
                   break;
                   else
                   parcours=parcours->suivant;
    }
    
    if(!parcours) return 0;
    else return parcours->num; 
    }
/***********************/
void ajouter_fait(LFait* lf,char h[100],int nbr){
     hypo * nv=(hypo*)malloc(sizeof(hypo));
     nv->num=nbr;
     //nv->hypothese=h;
     strcpy ( nv->hypothese, h );
     nv->suivant=NULL;
     if(lf->tete==NULL){
                        lf->tete=lf->queue=nv;
                        }
     else {
          lf->queue->suivant=nv;
          lf->queue=nv;
          }
     
}
/**********************/
int appliquer(LFait *lf,pregle regle){
     int test=0;
     hypo* parcoursf=(regle.LFaitInit)->tete;
     hypo* parcoursc=(regle.Lconc)->tete;
     while(parcoursf){
                     if(existe(lf,parcoursf->num)!=0)
                     {
                     parcoursf=parcoursf->suivant;
                     test=1;
                     }
                     else {
                          test=0;
                          break;
                          }                               
     }
     if(test==1) while(parcoursc){
                                           if(existe(lf,parcoursc->num)==0){
                                                            ajouter_fait(lf,parcoursc->hypothese,parcoursc->num);

                                                           }
                                           else test=0;
                                           parcoursc=parcoursc->suivant;
                 }
                 
     
     return test;   
}

/***************************************************************/
void chainage_avant(LFait* lf,LRegle* lr){
     pregle* parcours=lr->tete;
     int test;
     //hypo* p=parcours->Lconc->tete;
     while(parcours){
                      test=appliquer(lf,*parcours);
                     if (test==1) parcours=lr->tete; 
                     else parcours=parcours->suivant; 
                }          
}
/*****************************************************************/
void afficher_LFait(LFait* lf){
     hypo* parcours;
     if(lf->tete!=NULL)
     {   
     parcours=lf->tete;       
     while(parcours){
        printf("(%i-%s)\n",parcours->num,parcours->hypothese);
        parcours=parcours->suivant;   
        }
     //printf("NULL\n");
     printf("\n\n");
     }
     else printf("La liste est vide !! \n");
}
/*********************************************************************/

void ajouter_regle(LRegle *lr,LFait *lf, int nbr){
    pregle * r;
    int test=1,nf;
    hypo *parcours;
    char chaine[100],tmp[10];
    r=(pregle*)malloc(sizeof(pregle));
    r->LFaitInit=(LFait*)malloc(sizeof(LFait));
    r->Lconc=(LFait*)malloc(sizeof(LFait));
    r->LFaitInit->tete=NULL;
    r->LFaitInit->queue=NULL;
    r->Lconc->tete=NULL;
    r->Lconc->queue=NULL;
    r->suivant=NULL;     
    printf("donner le mon de la regle : \n");
    fflush(stdin);
    scanf("%s",r->nom);
    //scanf("%s",tmp);
    while(test==1){
         printf("Voulez vous ajouter un fait initail ? (0/1)\n");
         scanf("%i",&test);
         //scanf("%s",tmp);
         if(test==1){
                     printf("Donnez le nbr du fait \n");
                     scanf("%i",&nf);
                     if(existe(lf,nf)==nf){
                        parcours=lf->tete;
                        while(parcours){
                                        if(parcours->num==nf) break;
                                        else parcours=parcours->suivant;
                                        }
                        ajouter_fait(r->LFaitInit,parcours->hypothese,nf);                  
                     }
                     else{
                     printf("donner le fait : ");
                     //scanf("%s",chaine);
                     fflush(stdin);
                     gets(chaine);
                     ajouter_fait(r->LFaitInit,chaine,nf);
                     }
         }                          
    }
    test=1;
    while(test==1){
         printf("Voulez vous ajouter une conclusion ? (0/1)\n");
         scanf("%i",&test);
         if(test==1){
                     printf("Donnez le nbr du fait (conclusion) \n");
                     scanf("%i",&nf);
                     printf("donner le fait : ");
                     fflush(stdin);
                     gets(chaine);
                     ajouter_fait(r->Lconc,chaine,nf); 
                     }                         
    }
    
    if(lr->tete==NULL){
                       lr->tete=lr->queue=r;
                       } 
    else{
                       lr->queue->suivant=r;
                       lr->queue=r;
         }
}




