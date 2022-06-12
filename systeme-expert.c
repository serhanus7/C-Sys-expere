#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prototypes.h"
#include "serhan.c"

/**********************/
int main(){
    int i=1,option;
    char chaine[100];
    LFait * lf;
    LRegle * lr;
    //pregle * r;
    pregle * parcours;
    //r=(pregle*)malloc(sizeof(pregle));
    lr=(LRegle*)malloc(sizeof(LRegle));
    lf=(LFait*)malloc(sizeof(LFait));
    /*r->LFaitInit=(LFait*)malloc(sizeof(LFait));
    r->Lconc=(LFait*)malloc(sizeof(LFait));
    r->LFaitInit->tete=NULL;
    r->LFaitInit->queue=NULL;
    r->Lconc->tete=NULL;
    r->Lconc->queue=NULL;
    r->suivant=NULL;*/
    lf->tete=NULL;
    lf->queue=NULL;
    //strcpy(r->nom,"first");
    //r->suivant=NULL;
    lr->tete=NULL;
    lr->queue=NULL;
    /*ajouter_fait(r->LFaitInit,"a de la fievre ",1);
    ajouter_fait(r->LFaitInit,"a le nez bouche ",2);
    ajouter_fait(r->Lconc,"a un rhume ",3);        
    
    ajouter_fait(lf,"a de la fievre ",1);
    ajouter_fait(lf,"a le nez bouche ",2);
    ajouter_fait(lf,"a mal au ventre  ",4);
    ajouter_fait(lf,"a des frissons ",5);
    ajouter_fait(lf,"a dla gorge rouge ",6);
    
    **************************************************/
    do{
        printf("/****************************************/\n");
        printf("1 - Ajouter un fait initial.\n");
        printf("2 - Ajouter une regle.\n");
        printf("3 - Afficher la liste des faits initiaux.\n");
        printf("4 - Afficher la liste des regles.\n");
        printf("5 - Appliquer le chainage avant.\n");
        printf("6 - Quiter.\n");
        printf("/****************************************/\n\n");
        scanf("%i",&option);
    //}while(option!=1 ||option!=2 ||option!=3 ||option!=4 ||option!=5);
    
    switch(option){
            case 2 :
                ajouter_regle(lr,lf,i);
                i++;
                break;
            case 1 :
                printf("donner le fait\n");
                fflush(stdin);
                gets(chaine);
                ajouter_fait(lf,chaine,i);                          
                i++;                                                         
                break;
            case 3 :
                afficher_LFait(lf);
                break;
            case 4:
                parcours=lr->tete;
                while(parcours){
                       printf("*********la regele %s ******\n",parcours->nom);
                       printf("La liste des faits initiaux :\n");
                       afficher_LFait(parcours->LFaitInit);
                       printf("La liste des conclusions :\n");
                       afficher_LFait(parcours->Lconc);
                       printf("****************************\n"); 
                       parcours=parcours->suivant;               
                } 
                break;
            case 5 :

                chainage_avant(lf,lr);
                break;
    }
    }while(option!=6);
    /**************************************************
    printf("Liste des faits initiaux lf \"avant le chainage\" :\n");
    afficher_LFait(lf);
    printf("Liste des faits initiaux de la seule regle r \n");
    afficher_LFait(r->LFaitInit);
    printf("Liste des conclusions de la seule regle r \n");
    afficher_LFait(r->Lconc);
    chainage_avant(lf,lr);
    printf("Liste des faits initiaux lf \"apres le chainage\" :\n");
    afficher_LFait(lf);*/
    free(lf);  
    free(lr);
    //free(r);
    system("pause");
   return 0; 
}

