# include <stdio.h>
# define PION_BLANC 1
# define PION_NOIR -1
# define CASE_VIDE 0
//La structure case, qui symbolise une case, elle a donc pour élément deux entiers, un pour la ligne,un autre pour la colonne
typedef struct {
    int lig,col ;
} Case ;
//La structure deplacement, qui symbolise un deplacement, cette structure possède deux éléments,deux case, une étant la case initiale, l’autre la case finale
typedef struct {
    Case case_i,case_f ;
} deplacement ;


//La structure joueur, qui symbolise un joueur, elle a pour élément le nom du joueur ainsi que la couleur des pions du joueurs :
typedef struct {
    char *nom ;
    int couleur ;
} joueur ;

typedef struct {
    int plateau[8][8] ; // Représente l’état du plateau
    int e ; // Représente l'etat de la case si elle vide ou occupée
    char  c; // Représente le le couleur de la case
} damier ;

char couleur(int i,int j){
    return ((i+j)%8)+65;
}
// une Procedure qui permet d'afficher le contenu d'une Ligne 
void affiche_ligne(int i,int plateau[8][8]) {
    int j ;
    printf(" %d ",i+1) ;
    for(j=0 ;j<8 ;j++) {
        if(plateau[i][j]=PION_BLANC){ 
                printf("| O%c",couleur(i,j)) ;
        }
        else if(plateau[i][j]=PION_NOIR){
                printf("| X%c",couleur(i,j)) ;
        }
        else        {
            
               printf("|  %c",couleur(i,j)) ;
        }
        }
    printf("| %2d\n",i+1) ;
    printf(" |---------------------------------|\n") ;
}
//une Procedure qui Permet d'afficher toute le Plateau 
void affiche_damier(int plateau[8][8]) {
    int i ;
    printf("    a   b   c   d   e   f   g   h \n") ;
    printf(" |---------------------------------|\n") ;
        for(i=0 ;i<8 ;i++){
            affiche_ligne(i,plateau) ;
        }
        printf("    a   b   c   d   e   f   g   h \n") ;
    }
    
//Pour initialiser, le damier, il suffit de donner la valeur PION NOIR et PION BLANC aux cases où les pions doivent se trouver en début de partie.
void init_damier(damier jeu) {
    int i,j ;
    //On initialise le tableau
        for(i=0 ;i<8 ;i++){
            for(j=0 ;j<8 ;j++){
                jeu.plateau[i][j] = CASE_VIDE;
                jeu.e=0;
                jeu.c=(i+j)%8+65;
            }
        }
        printf("Damier Vide\n");
        affiche_damier(jeu.plateau);
        
        //On remplie le Premier Ligne de la partie haute du damier par des pions noirs
        for(j ;j<8 ;j++){
            jeu.plateau[0][j] = PION_NOIR ;
            jeu.e = 1;
            jeu.c = (j%8+65);
        }
        //On remplie le Premier Ligne de la partie basse du damier par des pions blancs
        for(j ;j<8 ;j++){
            jeu.plateau[7][j] = PION_BLANC ;
            jeu.e = 1;
            jeu.c = (j%8+58);
            
        }
    printf("Damier a l'etat initial \n");
    affiche_damier(jeu.plateau);    
    }




int main()
{
    damier jeu;
    init_damier(jeu);
    
    return 0;
}
