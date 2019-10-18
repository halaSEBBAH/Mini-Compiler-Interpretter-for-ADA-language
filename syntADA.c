#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "headerProjet.h"





int TAILLEMEM = 100000*1024;
int TAILLECODE = 1000000;

int MEM[1000000] ;
/// he called it poiteur de pile associé
int SP; ///pointeur de pile donc premier indice de mem

FILE* FichierSortie;

//// definition de instruction
int OFFSET = 0;

typedef enum MNEMONIQUES{
    ADD,SUB,MUL,DIV,EQL,NEQ,GTR,LSS,GEQ,LEQ, PRN,INN,INT,LDI,LDA,LDV,STO,BRN,BZE,HLT,BAR,AND,ORR
}MNEMONIQUES;

int PC;



void INTER_INST();




char * MNEchar[]={"ADD","SUB","MUL","DIV","EQL","NEQ","GTR","LSS","GEQ","LEQ","PRN","INN","INT","LDI","LDA","LDV","STO","BRN","BZE","HLT","BAR","AND","ORR"};


typedef struct INSTRUCTION{
    MNEMONIQUES MNE;
    int SUITE;
}INSTRUCTION;

int NberIDFS = 0;   

///hada huwa tableau li fih lfonction assembleur w valeur li hdaha 
//// exactly lkhedma d code assembleur li kuna kan3emlou l3am li fat f tp
INSTRUCTION PCODE[10000000];
/// pc compteur d'instruction pointeur sur le sommet de ce tableau



//// definition de la table des identificateurs
typedef enum {TPROG,TCONST,TVAR} TSYM;

typedef struct{
    char NOM[20];
    TSYM TIDF;
    int ADRESSE;
}T_TAB_IDF;


T_TAB_IDF* TAB_IDFS[10000];


void GENERER1(MNEMONIQUES M){
    if (PC == 1000000) return ;
    ++PC;
    PCODE[PC].MNE = M ;
    //printf("MNEMONIQUE %s\n",MNEchar[(int) M]);
}



void GENERER2(MNEMONIQUES M, int A){
    if (PC == 1000000) return ;
    ++PC;
    PCODE[PC].MNE = M ;
    PCODE[PC].SUITE = A ;
    //printf("MNEMONIQUE %s--%d\n",MNEchar[(int) M],A);
}


void AfficherTableSymbole(){
    printf("\n---------------------------\n");
    printf("TABLE DES SYMBOLES");
    printf("\n---------------------------\n");
    for (int i = 0; i < NberIDFS;i++)
    {
        if(TAB_IDFS[i]->TIDF == TPROG)  printf(" %s --- %s  \n",TAB_IDFS[i]->NOM,"TPROG");
        if(TAB_IDFS[i]->TIDF == TVAR)   printf(" %s --- %s \n",TAB_IDFS[i]->NOM,"TVAR");
        if(TAB_IDFS[i]->TIDF == TCONST) printf(" %s --- %s    \n",TAB_IDFS[i]->NOM,"TCONST");
    
        printf("\n---------------------------\n");
}
}

int ADR_IDF(){
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0)
        {
            return i;   
        }
    }
    Erreur(ID_INEXIST_ERR);
    return -1;
}

int ADR_IDF_NAME(char* name){
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(name,TAB_IDFS[i]->NOM)==0)
        {
            return i;   
        }
    }
    Erreur(ID_INEXIST_ERR);
    return -1;
}



void afficherTableInstructions(){
    int i =1;
    printf("\n\n\n\n");
    /*printf("PC(compteur d'instructions) = %d",PC);
    printf("\n---------------------------\n");
    printf("TABLE DES INSTRUCTIONS");
    printf("\n---------------------------\n");*/
    while(i<=PC){
        /*printf("%s ----- %d",MNEchar[(int)PCODE[i].MNE],PCODE[i].SUITE);
        printf("\n---------------------------\n");*/
        fprintf(FichierSortie,"%s-%d\n",MNEchar[(int)PCODE[i].MNE],PCODE[i].SUITE);
        i++;
    }
}


void VRF_ID_PROG()
{
    NberIDFS++;
    TAB_IDFS[NberIDFS-1]=malloc(sizeof(T_TAB_IDF));
    memset(TAB_IDFS[NberIDFS-1]->NOM, '\0', 20*sizeof (char));
    strcat(TAB_IDFS[0]->NOM,SYM_COUR.NOM);
    printf("%s\n",TAB_IDFS[0]->NOM );
    TAB_IDFS[0]->TIDF=TPROG;
}

/*
int VRF_CONST()
{
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0)
        {
            Erreur(ID_EXIST_ERR);
            return -1;  
        }
    }
    NberIDFS++;
    TAB_IDFS[NberIDFS-1]=malloc(sizeof(T_TAB_IDF));
    memset (TAB_IDFS[NberIDFS-1]->NOM, 0, 20*sizeof (char));
    //strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_COUR.NOM);
    strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_STOK.NOM);
    TAB_IDFS[NberIDFS-1]->TIDF=TCONST;
    return (NberIDFS-1);
}
*/

int VRF_CONST()
{
    for (int i = 0; i < NberIDFS; ++i)
    {
        ///printf("symCOUR%s %s %d\n",SYM_COUR.NOM,TAB_IDFS[i]->NOM,strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM));
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0)
        {
            printf("erreur");
            Erreur(ID_EXIST_ERR);
            return -1;  
        }
    }
    NberIDFS++;
    return NberIDFS;
    /*TAB_IDFS[NberIDFS-1]=malloc(sizeof(T_TAB_IDF));
    memset (TAB_IDFS[NberIDFS-1]->NOM, 0, 20*sizeof (char));
    //strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_COUR.NOM);
    strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_STOK.NOM);
    TAB_IDFS[NberIDFS-1]->TIDF=TCONST;
    return (NberIDFS-1);
    }*/
}


int VRF_VAR()
{
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0)
        {
            Erreur(ID_EXIST_ERR);
            return -1;
        }
    }
    NberIDFS++;
    return NberIDFS;
    /*TAB_IDFS[NberIDFS-1]=malloc(sizeof(T_TAB_IDF));
    memset (TAB_IDFS[NberIDFS-1]->NOM, 0, 20*sizeof (char));
    //strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_COUR.NOM);
    strcat(TAB_IDFS[NberIDFS-1]->NOM,SYM_STOK.NOM);
    TAB_IDFS[NberIDFS-1]->TIDF=TVAR;
    return NberIDFS-1;*/
}

int VRF_ID_BEGIN()
    {
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0 /*&& TAB_IDFS[i]->TIDF != TPROG*/)
        {
            return i;
        }
    }
    Erreur(ID_NO_EXIST_ERR);
    return -1;
}

/*void TEST_ID_PROG()
{
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[0]->NOM)==0)
        {
            Erreur(ID_PROG);
        }
        return;
}*/


int VRF_AFFECT()
{
    for (int i = 0; i < NberIDFS; ++i)
    {
        if(strcmp(SYM_COUR.NOM,TAB_IDFS[i]->NOM)==0)
        {
            if(TAB_IDFS[i]->TIDF==TCONST)
            {
                //printf("why we here");
                Erreur(CONST_CHANGE);
            }
            if(TAB_IDFS[i]->TIDF == TPROG){
                printf("programm id forbiden\n");   
                Erreur(CONST_CHANGE);   
            }
            else return i;
        }
    }
    Erreur(ID_NO_EXIST_ERR);
}



////  it shows for one element
void AfficherTableauSymboles(int i){
        if(TAB_IDFS[i]->TIDF == TPROG)  printf("%s --> TPROG\n",TAB_IDFS[i]->NOM );
        else if (TAB_IDFS[i]->TIDF == TCONST)   printf("%s --> TCONST\n",TAB_IDFS[i]->NOM );
        else if (TAB_IDFS[i]->TIDF == TVAR)   printf("%s --> TVAR\n",TAB_IDFS[i]->NOM );
        else printf("WTF");
}


int indiceFirst=0;



    
//PROGRAM()  PROGRAM::= IMPORT PROCEDURE
    void PROGRAM(){
        //Test_Symbole(IMPORT_TOKEN, IMPORT_ERR);
        PROCEDURE();
        
    }

    //PROCEDURE()   PROCEDURE::= procedure ID  is {DECL} begin INSTS  end ID ;   
    void PROCEDURE(){       
        Test_Symbole(PROCEDURE_TOKEN,PROCEDURE_ERR);
        /*OFFSET++;
        TAB_IDFS[OFFSET]=malloc(sizeof(T_TAB_IDF));
        memset (TAB_IDFS[OFFSET]->NOM, 0, 20*sizeof(char));
        strcat(TAB_IDFS[OFFSET]->NOM,SYM_COUR.NOM);
        TAB_IDFS[OFFSET]->ADRESSE = OFFSET;
        TAB_IDFS[OFFSET]->TIDF = TPROG;*/
        VRF_ID_PROG();
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(IS_TOKEN, IS_ERR);
        while (SYM_COUR.CODE== ID_TOKEN)
        {   
            OFFSET++;
            TAB_IDFS[OFFSET]=malloc(sizeof(T_TAB_IDF));
            memset (TAB_IDFS[OFFSET]->NOM, '\0', 20*sizeof(char));
            strcat(TAB_IDFS[OFFSET]->NOM,SYM_COUR.NOM);
            TAB_IDFS[OFFSET]->ADRESSE = OFFSET;
            VRF_CONST(); 
            
            DECL();
         }
         
        Test_Symbole(BEGIN_TOKEN,BEGIN_ERR);        
        INSTS();
        Test_Symbole(END_TOKEN,END_ERR);
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(PV_TOKEN, PV_ERR);
        GENERER1(HLT);
    }
       
    //DECL         DECL ::= CONSTS | VARS  
    void DECL(){
        Sym_Suiv();
        indiceFirst = OFFSET ;
        while(SYM_COUR.CODE==VIR_TOKEN){
            Sym_Suiv();
            OFFSET++;
            TAB_IDFS[OFFSET]=malloc(sizeof(T_TAB_IDF));
            memset (TAB_IDFS[OFFSET]->NOM, 0, 20*sizeof (char));
            strcat(TAB_IDFS[OFFSET]->NOM,SYM_COUR.NOM);
            TAB_IDFS[OFFSET]->ADRESSE = OFFSET;
            VRF_CONST(); 
            Test_Symbole(ID_TOKEN,ID_ERR);
        }

        Test_Symbole(DP_TOKEN, DP_ERR);
        switch(SYM_COUR.CODE){
            case CONSTANT_TOKEN:
                for (int i = indiceFirst ; i <= OFFSET ; i++){
                    //VRF_CONST();
                    TAB_IDFS[i]->TIDF = TCONST;
                }
                CONSTS();
                break;
            case INTEGER_TOKEN:     
                for (int i = indiceFirst ; i <= OFFSET ; i++){
                    //VRF_CONST();
                    TAB_IDFS[i]->TIDF = TVAR;
                }
                VARS();
                break;
            case FLOAT_TOKEN: 
                for (int i = indiceFirst ; i <= OFFSET ; i++){
                    //VRF_CONST();
                    TAB_IDFS[i]->TIDF = TVAR;
                }
                VARS();
                break;
            default: Erreur(DECLARE_ERR);
        }
    }
     
    //CONST  CONSTS::=ID {,ID} : constant TYPE :=NUM;

    void CONSTS()
    {  
        
        
        Sym_Suiv();

        TYPE();
        Test_Symbole(AFF_TOKEN, AFF_ERR);
        for (int i = indiceFirst ; i <= OFFSET ; i++){
            GENERER2(LDA,i);
            GENERER2(LDI, SYM_COUR.VAL);
            GENERER1(STO);
        }
        Test_Symbole(NOMBER_TOKEN,NOMBER_ERR);
        Test_Symbole(PV_TOKEN, PV_ERR);
    }
    //VARS   VARS::= {ID{,ID} : TYPE [:=NUM] ;} 
    void VARS(){
        
        
        Sym_Suiv();
        if (SYM_COUR.CODE==AFF_TOKEN)
        {Sym_Suiv();
        for (int i = indiceFirst ; i <= OFFSET ; i++){
            GENERER2(LDA,i);
            GENERER2(LDI, SYM_COUR.VAL);
            GENERER1(STO);
        }
        Test_Symbole(NOMBER_TOKEN,NOMBER_ERR);
       }
        Test_Symbole(PV_TOKEN, PV_ERR); 
    } 

  
void TYPE()
{
    switch (SYM_COUR.CODE)
   {
    case INTEGER_TOKEN:Sym_Suiv();break;
    case FLOAT_TOKEN:Sym_Suiv();  break;
    default:
         Erreur(TYPE_ERR);
    
}
}
//INSTS::=INST; { INST; }
void INSTS()
{
    do 
    {
    
    INST();
   
    Test_Symbole(PV_TOKEN,PV_ERR);
    
    
    }
    while(SYM_COUR.CODE!=END_TOKEN);
}

//INST   INST   ::= AFF | SI | TANTQUE | AFFICHER | LIRE |POUR|REPETERTANTQUE|CORPS
void INST()
{

    switch   (SYM_COUR.CODE) 
    {
        case BEGIN_TOKEN:   CORPS();
                            break;
                            
        case ID_TOKEN:       
                            AFF();
                            break;
                            
        case IF_TOKEN:       
                            SI();
                            break; 
                            
        case WHILE_TOKEN:    
                            TANTQUE();
                            break;
                                
        case FOR_TOKEN:      
                            POUR();
                            break;
                            
        case LOOP_TOKEN:     
                            REPETERTANTQUE(); 
                            break;
        
        case PUT_TOKEN:      
                            AFFICHER();   
                            break;
                            
        case  GET_TOKEN:     
                            LIRE();
                            break;      
        default :            
                            //INST();
                            Erreur(INST_ERR);   
                            break;                                      
    }

}

//CORPS   CORPS::=begin INSTS  end ;
void CORPS()
{
    Sym_Suiv();
    INSTS();
    Test_Symbole(END_TOKEN,END_ERR);
    
}

//AFFEC  AFF ::= ID := EXPR 


//EXPR  EXPR    ::=TERM { ADDOP TERM } 

void FACT()
{
    switch   (SYM_COUR.CODE) 
    {
        case ID_TOKEN : 
            GENERER2(LDA, TAB_IDFS[ADR_IDF()]->ADRESSE);
            GENERER1(LDV);
            Sym_Suiv();
            break;
        case NOMBER_TOKEN : 
            GENERER2(LDI, SYM_COUR.VAL);
            Sym_Suiv();
            break;
        case PO_TOKEN : Sym_Suiv();
                        EXPR();
                        Test_Symbole(PF_TOKEN, PF_ERR);
                        break;
        default: Erreur(FACT_ERR);break;
    }
}


void TERM()
{
    FACT();
    MNEMONIQUES OP;
    while(SYM_COUR.CODE==MULT_TOKEN || SYM_COUR.CODE==DIV_TOKEN )
    {   
        if (SYM_COUR.CODE == MULT_TOKEN){
            OP = MUL;
        }
        else {
            OP = DIV;
        }
        Sym_Suiv();
        FACT(); 
        GENERER1(OP);   
    }
}


//EXPR  EXPR    ::=TERM { ADDOP TERM } 
void EXPR()
{   
    TERM();
    MNEMONIQUES OP;
    while(SYM_COUR.CODE==PLUS_TOKEN || SYM_COUR.CODE==MOINS_TOKEN )
    {   
        if (SYM_COUR.CODE == PLUS_TOKEN){
            OP = ADD;
        }
        else {
            OP = SUB;
        }
        Sym_Suiv();
        TERM(); 
        GENERER1(OP);  
    }  
}



void AFF()
{   
   VRF_AFFECT();
    GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE);
    Sym_Suiv();
    Test_Symbole(AFF_TOKEN, AFF_ERR);
    EXPR(); 
    GENERER1(STO); 
}

 MNEMONIQUES OP;

//RELOP RELOP::=RELOP ::=     = | < | > | <= | >= |/=
void RELOP()
{
   
    switch   (SYM_COUR.CODE) 
    {   
        case EGAL_TOKEN :OP=EQL; 
                        Sym_Suiv();break;
        case SUP_TOKEN :OP=GTR;
                        Sym_Suiv();break;
        case INF_TOKEN :OP=LSS;
                        Sym_Suiv();break;
        case SUPEG_TOKEN :OP=GEQ;
                        Sym_Suiv();break;
        case INFEG_TOKEN :OP=LEQ;
                        Sym_Suiv();break;
        case DIFF_TOKEN :OP=NEQ;
                        Sym_Suiv();break;
                                                    
        default: Erreur(RELOP_ERR);break;
    }
}

/*
//POUR
void POUR(){
     
    Sym_Suiv();
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(IN_TOKEN,IN_ERR);
    switch (SYM_COUR.CODE)
    {   
        case ID_TOKEN:  
                      Sym_Suiv();
                      Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                      switch (SYM_COUR.CODE) 
                      {case ID_TOKEN:  break;
                       case NOMBER_TOKEN: break;
                       default:Erreur(INTERVAL_ID_NOMBER_ERR);
                      }
                      break;
                      
        case NOMBER_TOKEN:  
                          Sym_Suiv();
                          Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                           switch (SYM_COUR.CODE) 
                          {case ID_TOKEN:  break;
                           case NOMBER_TOKEN: break;
                          default:Erreur(INTERVAL_ID_NOMBER_ERR);
                           }
                         break;
        
        default:Erreur(IN_ID_NOMBER_ERR);                    
    }
    
  
    Sym_Suiv();
    
    Test_Symbole(LOOP_TOKEN, LOOP_ERR);
    
    INSTS();
    
    
    
    Test_Symbole(END_TOKEN,END_ERR);
    Test_Symbole(LOOP_TOKEN,LOOP_ERR);
}*/

//POUR
 void POUR(){
                        int addr, i, j, start, end, INDICE_BZE, LABEL_BRN; //indice BZE means le PC ou BZE est, LABEL BRN means where BRN will jump
                        char* varBoucle;
                        //
                        Sym_Suiv();
                        
                        OFFSET++;
                        TAB_IDFS[OFFSET]=malloc(sizeof(T_TAB_IDF));
                        memset (TAB_IDFS[OFFSET]->NOM, 0, 20*sizeof (char));
                        strcat(TAB_IDFS[OFFSET]->NOM,SYM_COUR.NOM);
                        TAB_IDFS[OFFSET]->ADRESSE = OFFSET;
                        NberIDFS++;
                        addr =  ADR_IDF();
                        varBoucle = TAB_IDFS[addr]->NOM;
                        Test_Symbole(ID_TOKEN,ID_ERR);
                        Test_Symbole(IN_TOKEN,IN_ERR);
                        switch (SYM_COUR.CODE)
                        {   
                            case ID_TOKEN: 
                                i = ADR_IDF();
                                start = MEM[i];
                                Sym_Suiv();
                                Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                switch (SYM_COUR.CODE) 
                                {
                                    case ID_TOKEN: 
                                        j = ADR_IDF();
                                        end = MEM[i];
                                        break;
                                    case NOMBER_TOKEN:
                                        end = SYM_COUR.VAL;
                                        break;
                                    default:
                                        Erreur(INTERVAL_ID_NOMBER_ERR);
                                }
                                break;           
                            case NOMBER_TOKEN: 
                                
                                start = SYM_COUR.VAL;
                                Sym_Suiv();
                                Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                switch (SYM_COUR.CODE) 
                                {
                                    case ID_TOKEN: 
                                        j = ADR_IDF();
                                        end = MEM[i];
                                        break;
                                    case NOMBER_TOKEN:
                                        end = SYM_COUR.VAL;
                                        break;
                                    default:
                                        Erreur(INTERVAL_ID_NOMBER_ERR);
                                }
                                break;
                            default:Erreur(IN_ID_NOMBER_ERR);                    
                        }
                        if (start > end){
                            Erreur(ORDRE_INTERVAL_ERR); // msg : loop range is null, loop will not execute
                        }

                        GENERER2(LDA, TAB_IDFS[ADR_IDF_NAME(varBoucle)]->ADRESSE);
                        GENERER2(LDI, start -1); // -1 pour avoir start apres incrementation 
                        Sym_Suiv();
                        LABEL_BRN = PC + 1; // l'instruction suivante
                        GENERER2(LDA, TAB_IDFS[ADR_IDF_NAME(varBoucle)]->ADRESSE);
                        GENERER2(LDA, TAB_IDFS[ADR_IDF_NAME(varBoucle)]->ADRESSE);
                        GENERER1(LDV);
                        GENERER2(LDI, 1); //incrementation (pour la premiere itération, on commence avec start -1 pour avoir start ici)
                        GENERER1(ADD);
                        GENERER1(STO);
                        GENERER2(LDI, end);
                        GENERER2(LDA, TAB_IDFS[ADR_IDF_NAME(varBoucle)]->ADRESSE);
                        GENERER1(LDV);
                        GENERER1(GEQ); // doit tester : si la fin est incluse GEQ, sinon GTR
                        GENERER1(BZE);
                        INDICE_BZE = PC;
                        Test_Symbole(LOOP_TOKEN, LOOP_ERR);
                        INSTS();
                        PCODE[INDICE_BZE].SUITE = PC + 2;
                        GENERER2(BRN, LABEL_BRN);
                        Test_Symbole(END_TOKEN,END_ERR);
                        Test_Symbole(LOOP_TOKEN,LOOP_ERR);
}


void TANTQUE(){
    int INDICE_BZE;
    int LABEL_BRN;
    LABEL_BRN=PC+1;
    Sym_Suiv();
    COND();
    GENERER1(BZE); 
    INDICE_BZE=PC; 
    Test_Symbole(LOOP_TOKEN, LOOP_ERR);
    do {    
    INST();
    GENERER2(BRN, LABEL_BRN);
    PCODE[INDICE_BZE].SUITE=PC+1; 
    Test_Symbole(PV_TOKEN, PV_ERR);
    }while(SYM_COUR.CODE != END_TOKEN);
    Sym_Suiv();
    Test_Symbole(LOOP_TOKEN,LOOP_ERR);
    
}

//REPETERTANTQUE::= loop [exit when COND;]INSTS end loop

void REPETERTANTQUE()
{   
    int INDICE_BZE;
    int LABEL_BRN;
    
    Sym_Suiv();
    if (SYM_COUR.CODE==EXIT_TOKEN )
    {
        Sym_Suiv();
        LABEL_BRN=PC+1;
        Test_Symbole(WHEN_TOKEN, WHEN_ERR);
        COND();
        GENERER1(BAR); 
        GENERER1(BZE); 
        INDICE_BZE=PC; 
        Test_Symbole(PV_TOKEN, PV_ERR);
        
    }
    
    INSTS();
    GENERER2(BRN, LABEL_BRN);
    PCODE[INDICE_BZE].SUITE=PC+1; 
    //Test_Symbole(PV_TOKEN, PV_ERR);
    
    Test_Symbole(END_TOKEN, END_ERR);
    Test_Symbole(LOOP_TOKEN, LOOP_ERR);

    
}

//LIRE
void LIRE(){
    int adr;
    Sym_Suiv();
    Test_Symbole(PO_TOKEN,PO_ERR);
    adr = ADR_IDF();
    GENERER2(LDA, TAB_IDFS[adr]->ADRESSE);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PF_TOKEN,PF_ERR);
    GENERER1(INN);
    GENERER1(STO);
}

//AFFICHER


void AFFICHER(){
    Sym_Suiv();
    Test_Symbole(PO_TOKEN,PO_ERR);     
    //OFFSET = OFFSET + 1;
    //GENERER2(LDA,TAB_IDFS[i]->ADRESSE);  
    //GENERER1(LDV); 
    EXPR();
    GENERER1(PRN);
    Test_Symbole(PF_TOKEN,PF_ERR);
}




//SI
void SI()
{   
    
    int DEBUT;
    int SSUITE;
    int FIN;
    Sym_Suiv();   
    COND();
    DEBUT=PC+1;
    GENERER1(BZE);
    
    Test_Symbole(THEN_TOKEN, THEN_ERR); 

    while(1){
        INST();        
        Test_Symbole(PV_TOKEN, PV_ERR);
        if(SYM_COUR.CODE == ELSIF_TOKEN || SYM_COUR.CODE == ELSE_TOKEN || SYM_COUR.CODE == END_TOKEN) break;
    }
           
    GENERER1(BRN);
    FIN = PC;
    
    PCODE[DEBUT].SUITE = PC+1;
    while(SYM_COUR.CODE==ELSIF_TOKEN){
        Sym_Suiv();
        COND();
        DEBUT=PC+1;
        GENERER1(BZE);
        Test_Symbole(THEN_TOKEN, THEN_ERR);          
        while(1){
            if(SYM_COUR.CODE == ELSIF_TOKEN || SYM_COUR.CODE == ELSE_TOKEN || SYM_COUR.CODE == END_TOKEN) break;
            INST();
            Test_Symbole(PV_TOKEN, PV_ERR);
            
       }PCODE[FIN].SUITE = PC+1;
        GENERER1(BRN);
        FIN = PC;
        PCODE[DEBUT].SUITE = PC+1;
    }
    if(SYM_COUR.CODE==ELSE_TOKEN){    
        PCODE[DEBUT].SUITE = PC+1;
        Sym_Suiv();
        INSTS();

    }
    PCODE[FIN].SUITE = PC+1;
    Test_Symbole(END_TOKEN,END_ERR);
    Test_Symbole(IF_TOKEN, IF_ERR);
}



void COND(){
     OR();
}

void OR(){

    NOT();
    ORAUX();
}

void ORAUX(){
    
    switch(SYM_COUR.CODE){
        case OR_TOKEN :
        
            NOT();
            ORAUX();
            break;
        
    }
}



void NOT(){

    int indiceIN ;
    MNEMONIQUES  OP2;   
    switch(SYM_COUR.CODE){
        case NOT_TOKEN :
            Sym_Suiv();
            Test_Symbole(PO_TOKEN,PO_ERR);
            NOT();
            GENERER1(BAR);
            Test_Symbole(PF_TOKEN,PF_ERR);
            break;
        case NOMBER_TOKEN:

            EXPR();
            RELOP();
            EXPR();
            GENERER1(OP);
            break;
        case ID_TOKEN :
            GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
            GENERER1(LDV);
            indiceIN = TAB_IDFS[ADR_IDF()]->ADRESSE;
            Sym_Suiv();           
            switch (SYM_COUR.CODE){
                case IN_TOKEN :
                    Sym_Suiv();
                    switch (SYM_COUR.CODE)
    
                       {   
                        case ID_TOKEN:
                                      
                                      GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                      GENERER1(LDV);
                                      GENERER1(GEQ);
                                      Sym_Suiv();
                                      Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                      switch (SYM_COUR.CODE) 
                                      {
                                       case ID_TOKEN:
                                        GENERER2(LDA,indiceIN); 
                                        GENERER1(LDV); 
                                        GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                        GENERER1(LDV);
                                        GENERER1(LEQ);
                                        break;
                                       case NOMBER_TOKEN: 
                                        GENERER2(LDA,indiceIN); 
                                        GENERER1(LDV); 
                                        GENERER2(LDI, SYM_COUR.VAL);
                                        GENERER1(LEQ);
                                       break;
                                       default:Erreur(INTERVAL_ID_NOMBER_ERR);
                                       }

                                      break;
                      
                        case NOMBER_TOKEN: 

                                        GENERER2(LDI,SYM_COUR.VAL); 
                                        GENERER1(GEQ);
                                        Sym_Suiv();
                                        Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                        switch (SYM_COUR.CODE) 
                                        {
                                        case ID_TOKEN: 
                                        GENERER2(LDA,indiceIN); 
                                        GENERER1(LDV); 
                                        GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                        GENERER1(LDV);
                                        GENERER1(LEQ); 
                                        break;
                                        case NOMBER_TOKEN: 
                                        GENERER2(LDA,indiceIN); 
                                        GENERER1(LDV); 
                                        GENERER2(LDI, SYM_COUR.VAL);
                                        GENERER1(LEQ);
                                        break;
                                        default:Erreur(INTERVAL_ID_NOMBER_ERR);
                                         }
                                        break;
                        
                            
                        default:Erreur(IN_ID_NOMBER_ERR);                    
                        }
                    Sym_Suiv(); 
                    GENERER1(AND);   
                    break;

             case PLUS_TOKEN:

                    Sym_Suiv();
                    EXPR();
                    GENERER1(ADD);
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;

            case MOINS_TOKEN:
                    Sym_Suiv();
                    TERM();
                    GENERER1(SUB);
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
            case MULT_TOKEN:
                    
                    Sym_Suiv();
                    FACT();
                    GENERER1(MUL); 
                    while(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN){
                        if (SYM_COUR.CODE == PLUS_TOKEN) OP2 = ADD; 
                        else OP2 = SUB;
                        TERM();
                        GENERER1(OP2);
                    }      
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                case DIV_TOKEN:
                    Sym_Suiv();
                    FACT();
                    GENERER1(DIV);
                    while(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN){
                         if (SYM_COUR.CODE == PLUS_TOKEN) OP2 = ADD; 
                        else OP2 = SUB;
                        TERM();
                        GENERER1(OP2);
                    }               
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                case EGAL_TOKEN:
                    RELOP();
                    EXPR(); 
                    GENERER1(OP);
                    break;
                case DIFF_TOKEN:
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                case INF_TOKEN:
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                case SUP_TOKEN:

                    RELOP();
                     
                    EXPR();
                    GENERER1(OP);
                    break;
                case SUPEG_TOKEN:
                    RELOP();
                     
                    EXPR();
                    GENERER1(OP);
                    break;
                case INFEG_TOKEN:
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                }
                break;
                case PO_TOKEN:
                    // 
                    Sym_Suiv();
                     
                    NOT();
                    Test_Symbole(PF_TOKEN,PF_ERR);
                    break;
            default:
                    
                    {
                    Erreur(IF_ID_NOMBER_NOT_ERR);
                    break;
                    }
            
    }
    ANDAUX();
}

void ANDAUX(){

    switch(SYM_COUR.CODE){

        case AND_TOKEN :
            Sym_Suiv();
            NOT();
            /*switch(SYM_COUR.CODE){
                case NOT_TOKEN :
                    Sym_Suiv();
                    Test_Symbole(PO_TOKEN,PO_ERR);
                    NOT();
                    GENERER1(BAR);
                    Test_Symbole(PF_TOKEN,PF_ERR);
                    break;
                case NOMBER_TOKEN:

                    EXPR();
                    RELOP();
                    EXPR();
                    GENERER1(OP);
                    break;
                case ID_TOKEN :
                    GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                    GENERER1(LDV);
                    indiceIN = TAB_IDFS[ADR_IDF()]->ADRESSE;
                    Sym_Suiv();           
                    switch (SYM_COUR.CODE){
                        case IN_TOKEN :
                            Sym_Suiv();
                            switch (SYM_COUR.CODE)
            
                               {   
                                case ID_TOKEN:
                                              
                                              GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                              GENERER1(LDV);
                                              GENERER1(GEQ);
                                              Sym_Suiv();
                                              Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                              switch (SYM_COUR.CODE) 
                                              {
                                               case ID_TOKEN:
                                                GENERER2(LDA,indiceIN); 
                                                GENERER1(LDV); 
                                                GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                                GENERER1(LDV);
                                                GENERER1(LEQ);
                                                break;
                                               case NOMBER_TOKEN: 
                                                GENERER2(LDA,indiceIN); 
                                                GENERER1(LDV); 
                                                GENERER2(LDI, SYM_COUR.VAL);
                                                GENERER1(LEQ);
                                               break;
                                               default:Erreur(INTERVAL_ID_NOMBER_ERR);
                                               }

                                              break;
                              
                                case NOMBER_TOKEN: 

                                                GENERER2(LDI,SYM_COUR.VAL); 
                                                GENERER1(GEQ);
                                                Sym_Suiv();
                                                Test_Symbole(INTERVAL_TOKEN,INTERVAL_ERR);
                                                switch (SYM_COUR.CODE) 
                                                {
                                                case ID_TOKEN: 
                                                GENERER2(LDA,indiceIN); 
                                                GENERER1(LDV); 
                                                GENERER2(LDA,TAB_IDFS[ADR_IDF()]->ADRESSE); 
                                                GENERER1(LDV);
                                                GENERER1(LEQ); 
                                                break;
                                                case NOMBER_TOKEN: 
                                                GENERER2(LDA,indiceIN); 
                                                GENERER1(LDV); 
                                                GENERER2(LDI, SYM_COUR.VAL);
                                                GENERER1(LEQ);
                                                break;
                                                default:Erreur(INTERVAL_ID_NOMBER_ERR);
                                                 }
                                                break;
                                
                                    
                                default:Erreur(IN_ID_NOMBER_ERR);                    
                                }
                            Sym_Suiv(); 
                            GENERER1(AND);   
                            break;

                     case PLUS_TOKEN:

                            Sym_Suiv();
                            EXPR();
                            GENERER1(ADD);
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;

                    case MOINS_TOKEN:
                            Sym_Suiv();
                            TERM();
                            GENERER1(SUB);
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                    case MULT_TOKEN:
                            
                            Sym_Suiv();
                            FACT();
                            GENERER1(MUL); 
                            while(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN){
                                if (SYM_COUR.CODE == PLUS_TOKEN) OP2 = ADD; 
                                else OP2 = SUB;
                                TERM();
                                GENERER1(OP2);
                            }      
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                        case DIV_TOKEN:
                            Sym_Suiv();
                            FACT();
                            GENERER1(DIV);
                            while(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN){
                                 if (SYM_COUR.CODE == PLUS_TOKEN) OP2 = ADD; 
                                else OP2 = SUB;
                                TERM();
                                GENERER1(OP2);
                            }               
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                        case EGAL_TOKEN:
                            RELOP();
                            EXPR(); 
                            GENERER1(OP);
                            break;
                        case DIFF_TOKEN:
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                        case INF_TOKEN:
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                        case SUP_TOKEN:

                            RELOP();
                             
                            EXPR();
                            GENERER1(OP);
                            break;
                        case SUPEG_TOKEN:
                            RELOP();
                             
                            EXPR();
                            GENERER1(OP);
                            break;
                        case INFEG_TOKEN:
                            RELOP();
                            EXPR();
                            GENERER1(OP);
                            break;
                        }
                        break;
                        case PO_TOKEN:
                            // 
                            Sym_Suiv();
                             
                            NOT();
                            Test_Symbole(PF_TOKEN,PF_ERR);
                            break;
                        break;              
                     default:
                    
                    {
                    Erreur(AND_ID_NOMBER_NOT_ERR);
                    break;
                    }*/
                    /////////////////////////////////////////////////////
        GENERER1(AND);        
        ANDAUX();
        break;
        
        case OR_TOKEN :
            
            Sym_Suiv();
             
            NOT();
            GENERER1(ORR);
            ORAUX();
            break;
    }
}



int verifyNotNull(int c){
    if (c== 0) return -1;
    return 1;
}



void INTER_PCODE(){
    PC = -1;
    while(PCODE[PC].MNE != HLT){
        INTER_INST(PCODE[PC]);
    }
}


////// interpreteur 

void INTER_INST(INSTRUCTION inst){ 
    int val1, val2, adr;
    PC++;

    switch(inst.MNE){
        case INT : SP = inst.SUITE; break;
        case LDI : MEM[++SP] = inst.SUITE; break;
        case LDA : MEM[++SP] = inst.SUITE; break;
        case ADD : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = val2 + val1;
            break;
        case SUB :
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = val2 - val1;
            break; 
        case MUL :
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = val2 * val1;
            break; 
        case DIV :
            val1 = MEM[SP--];
            val2 = MEM[SP];
            verifyNotNull(val1);
            MEM[SP] = val2 / val1;
            break; 
        case EQL : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 == val1);
            break;
        case NEQ : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 != val1);
            break; 
        case GTR : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 > val1);
            break; 
        case LSS : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 < val1);
            break; 
        case GEQ : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 >= val1);
            break; 
        case LEQ : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val2 <= val1);
            break; 
        case PRN : 
            printf("%d\n", MEM[SP--]);
            break;
        case INN : 
            adr = MEM[SP--];
            printf("saisissez  un nombre : ");
            scanf("%d", &MEM[adr]);
            break;
        case LDV : 
            adr = MEM[SP];  // MEM[SP] = MEM[MEM[SP]];
            MEM[SP] = MEM[adr];
            break;
        case STO : 
            val1 = MEM[SP--];
            adr = MEM[SP--];
            MEM[adr] = val1;
            break;
        case BRN :
            PC = inst.SUITE;
            break;
        case BZE : 
            if(MEM[SP--] == 0){
                PC = inst.SUITE;
            }
            break;
        case BAR : //change la valeur du bool (NOT)
            MEM[SP] = (MEM[SP] - 1) * -1;  // (1-1)*(-1) = 0 / (0-1)*(-1) = 1 
            break;    
        case AND : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val1 && val2);
            break; 
        case ORR : 
            val1 = MEM[SP--];
            val2 = MEM[SP];
            MEM[SP] = (val1 || val2);
            break;   
    }
}


////////

void afficherMemoire(){
    int adree;
    for(int i = 1; i < NberIDFS+1; i++){
        printf("----------------------------------\n");
        adree=(int)TAB_IDFS[i]->ADRESSE;
        printf("%d\n",adree);
        printf("|%d-------|\n",MEM[adree]);
    }
}           






    void main(){
    Fichier=fopen("testADA1.txt","r+");
    FichierSortie = fopen("PCODE.txt","w");
        Lire_Car();
    	Sym_Suiv();
        PROGRAM();
        AfficherTableSymbole();
        
        afficherTableInstructions();
        printf("\n-----------------------------------\n");
        printf("     INTERPRETEUR");
        printf("\n-----------------------------------\n");
        INTER_PCODE();
        printf("\n-----------------------------------\n");
       // afficherMemoire();
    fclose(Fichier);
    }
