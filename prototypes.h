typedef struct hypothese{
        int num;
        char hypothese[50];
        struct hypothese* suivant;
        }hypo;
typedef struct{
        hypo* tete;
        hypo* queue;
        }LFait;
        
/*********************************************/
typedef struct regle{
        char nom[10];
        LFait* LFaitInit;
        LFait* Lconc;
        struct regle* suivant;
        }pregle;
typedef struct listeregle{
        pregle* tete;
        pregle* queue;
        }LRegle;
/*********************************************/        
int existe(LFait *,int);
void ajouter_fait(LFait*,char h[100],int );
int appliquer(LFait *,pregle);
void chainage_avant(LFait* ,LRegle* );
void afficher_LFait(LFait* );
void ajouter_regle(LRegle *,LFait *,int);
