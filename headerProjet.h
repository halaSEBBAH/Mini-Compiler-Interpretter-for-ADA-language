typedef enum {
	
	PUT_TOKEN,GET_TOKEN,INTEGER_TOKEN,FLOAT_TOKEN,
	
    Ada_TOKEN ,ABORT_TOKEN, ABS_TOKEN, ABSTRACT_TOKEN, ACCEPT_TOKEN, ACCESS_TOKEN, ALIASED_TOKEN, ALL_TOKEN, AND_TOKEN, ARRAY_TOKEN, AT_TOKEN,
    BEGIN_TOKEN, BODY_TOKEN,
    CASE_TOKEN, CONSTANT_TOKEN,
    DECLARE_TOKEN, DELAY_TOKEN, DELTA_TOKEN, DIGITS_TOKEN, DO_TOKEN,
    ELSE_TOKEN, ELSIF_TOKEN, END_TOKEN, ENTRY_TOKEN, EXCEPTION_TOKEN, EXIT_TOKEN,
    FOR_TOKEN, FUNCTION_TOKEN,
    GENERIC_TOKEN, GOTO_TOKEN,
    IF_TOKEN, IN_TOKEN, INTERFACE_TOKEN, IS_TOKEN,
    LIMITED_TOKEN, LOOP_TOKEN,
    MOD_TOKEN,
    NEW_TOKEN, NOT_TOKEN, NULL_TOKEN,
    OF_TOKEN, OR_TOKEN, OTHERS_TOKEN, OUT_TOKEN, OVERRIDING_TOKEN,
    PACKAGE_TOKEN, PRAGMA_TOKEN, PRIVATE_TOKEN, PROCEDURE_TOKEN, PROTECTED_TOKEN,
    RAISE_TOKEN, RANGE_TOKEN, RECORD_TOKEN, REM_TOKEN, RENAMES_TOKEN, REQUEUE_TOKEN, RETURN_TOKEN, REVERSE_TOKEN,
    SELECT_TOKEN, SEPARATE_TOKEN, SOME_TOKEN, SUBTYPE_TOKEN, SYNCHRONIZED_TOKEN,
    TAGGED_TOKEN, TASK_TOKEN, TERMINATE_TOKEN, THEN_TOKEN, TYPE_TOKEN,
    UNTIL_TOKEN, USE_TOKEN, WHEN_TOKEN, WHILE_TOKEN, WITH_TOKEN, XOR_TOKEN,PV_TOKEN, PT_TOKEN, PLUS_TOKEN, MOINS_TOKEN, MULT_TOKEN, DIV_TOKEN, VIR_TOKEN, AFF_TOKEN, INF_TOKEN, INFEG_TOKEN, SUP_TOKEN, SUPEG_TOKEN,
    DIFF_TOKEN, PO_TOKEN, PF_TOKEN, EGAL_TOKEN,ETCOM_TOKEN,ERREUR_TOKEN,NOMBER_TOKEN,ID_TOKEN,DP_TOKEN,INTERVAL_TOKEN
}CODES_LEX;

typedef  struct TSym_Cour{ CODES_LEX CODE; char NOM[20]; int VAL;}TSym_Cour;
//Class des mots spéciaux//

char* mot_cle[]={
    "put","get","integer","float","ada","abort", "abs", "abstract", "accept", "access", "aliased", "all", "and", "array", "at",
    "begin", "body",
    "case", "constant",
    "declare", "delay", "delta", "digits", "do",
    "else", "elsif", "end", "entry", "exception", "exit",
    "for", "function",
    "generic", "goto",
    "if", "in", "interface", "is",
    "limited", "loop",
    "mod",
    "new", "not", "null",
    "of", "or", "others", "out", "overriding",
    "package", "pragma", "private", "procedure", "protected",
    "raise", "range", "record", "rem", "renames", "requeue", "return", "reverse",
    "select", "separate", "some", "subtype", "synchronized",
    "tagged", "task", "terminate", "then", "type",
    "until", "use", "when", "while", "with", "xor"};


CODES_LEX code_lex[]={
	PUT_TOKEN,GET_TOKEN,INTEGER_TOKEN,FLOAT_TOKEN,
	Ada_TOKEN, ABORT_TOKEN, ABS_TOKEN, ABSTRACT_TOKEN, ACCEPT_TOKEN, ACCESS_TOKEN, ALIASED_TOKEN, ALL_TOKEN, AND_TOKEN, ARRAY_TOKEN, AT_TOKEN,
    BEGIN_TOKEN, BODY_TOKEN,
    CASE_TOKEN, CONSTANT_TOKEN,
    DECLARE_TOKEN, DELAY_TOKEN, DELTA_TOKEN, DIGITS_TOKEN, DO_TOKEN,
    ELSE_TOKEN, ELSIF_TOKEN, END_TOKEN, ENTRY_TOKEN, EXCEPTION_TOKEN, EXIT_TOKEN,
    FOR_TOKEN, FUNCTION_TOKEN,
    GENERIC_TOKEN, GOTO_TOKEN,
    IF_TOKEN, IN_TOKEN, INTERFACE_TOKEN, IS_TOKEN,
    LIMITED_TOKEN, LOOP_TOKEN,
    MOD_TOKEN,
    NEW_TOKEN, NOT_TOKEN, NULL_TOKEN,
    OF_TOKEN, OR_TOKEN, OTHERS_TOKEN, OUT_TOKEN, OVERRIDING_TOKEN,
    PACKAGE_TOKEN, PRAGMA_TOKEN, PRIVATE_TOKEN, PROCEDURE_TOKEN, PROTECTED_TOKEN,
    RAISE_TOKEN, RANGE_TOKEN, RECORD_TOKEN, REM_TOKEN, RENAMES_TOKEN, REQUEUE_TOKEN, RETURN_TOKEN, REVERSE_TOKEN,
    SELECT_TOKEN, SEPARATE_TOKEN, SOME_TOKEN, SUBTYPE_TOKEN, SYNCHRONIZED_TOKEN,
    TAGGED_TOKEN, TASK_TOKEN, TERMINATE_TOKEN, THEN_TOKEN, TYPE_TOKEN,
    UNTIL_TOKEN, USE_TOKEN, WHEN_TOKEN, WHILE_TOKEN, WITH_TOKEN, XOR_TOKEN,PV_TOKEN, PT_TOKEN, PLUS_TOKEN, MOINS_TOKEN, MULT_TOKEN, DIV_TOKEN, VIR_TOKEN, AFF_TOKEN, INF_TOKEN, INFEG_TOKEN, SUP_TOKEN, SUPEG_TOKEN,
    DIFF_TOKEN, PO_TOKEN, PF_TOKEN, EGAL_TOKEN,ETCOM_TOKEN,ERREUR_TOKEN,NOMBER_TOKEN,ID_TOKEN,DP_TOKEN,INTERVAL_TOKEN
};


char* Code_Lex[]={
	"PUT_TOKEN","GET_TOKEN","INTEGER_TOKEN","FLOAT_TOKEN",
    "Ada_TOKEN","ABORT_TOKEN", "ABS_TOKEN", "ABSTRACT_TOKEN", "ACCEPT_TOKEN", "ACCESS_TOKEN", "ALIASED_TOKEN", "ALL_TOKEN", "AND_TOKEN", "ARRAY_TOKEN", "AT_TOKEN",
    "BEGIN_TOKEN", "BODY_TOKEN",
    "CASE_TOKEN", "CONSTANT_TOKEN",
    "DECLARE_TOKEN", "DELAY_TOKEN", "DELTA_TOKEN", "DIGITS_TOKEN", "DO_TOKEN",
    "ELSE_TOKEN", "ELSIF_TOKEN", "END_TOKEN", "ENTRY_TOKEN", "EXCEPTION_TOKEN", "EXIT_TOKEN",
    "FOR_TOKEN", "FUNCTION_TOKEN",
    "GENERIC_TOKEN", "GOTO_TOKEN",
    "IF_TOKEN", "IN_TOKEN", "INTERFACE_TOKEN", "IS_TOKEN",
    "LIMITED_TOKEN", "LOOP_TOKEN",
    "MOD_TOKEN",
    "NEW_TOKEN", "NOT_TOKEN", "NULL_TOKEN",
    "OF_TOKEN", "OR_TOKEN", "OTHERS_TOKEN", "OUT_TOKEN", "OVERRIDING_TOKEN",
    "PACKAGE_TOKEN", "PRAGMA_TOKEN", "PRIVATE_TOKEN", "PROCEDURE_TOKEN", "PROTECTED_TOKEN",
    "RAISE_TOKEN", "RANGE_TOKEN", "RECORD_TOKEN", "REM_TOKEN", "RENAMES_TOKEN", "REQUEUE_TOKEN", "RETURN_TOKEN", "REVERSE_TOKEN",
    "SELECT_TOKEN", "SEPARATE_TOKEN", "SOME_TOKEN", "SUBTYPE_TOKEN", "SYNCHRONIZED_TOKEN",
    "TAGGED_TOKEN", "TASK_TOKEN", "TERMINATE_TOKEN", "THEN_TOKEN", "TYPE_TOKEN",
    "UNTIL_TOKEN", "USE_TOKEN", "WHEN_TOKEN", "WHILE_TOKEN", "WITH_TOKEN", "XOR_TOKEN","PV_TOKEN", "PT_TOKEN", "PLUS_TOKEN", "MOINS_TOKEN", "MULT_TOKEN", "DIV_TOKEN", "VIR_TOKEN", "AFF_TOKEN", "INF_TOKEN", "INFEG_TOKEN", "SUP_TOKEN", "SUPEG_TOKEN",
    "DIFF_TOKEN", "PO_TOKEN", "PF_TOKEN", "EGAL_TOKEN", "ETCOM_TOKEN", "ERREUR_TOKEN", "NOMBER_TOKEN", "ID_TOKEN","DP_TOKEN","INTERVAL_TOKEN"
};



typedef enum {
	PUT_ERR,GET_ERR,INTEGER_ERR,FLOAT_ERR,
    ABORT_ERR, ABS_ERR, ABSTRACT_ERR, ACCEPT_ERR, ACCESS_ERR, ALIASED_ERR, ALL_ERR, AND_ERR, ARRAY_ERR, AT_ERR,
    BEGIN_ERR, BODY_ERR,
    CASE_ERR, CONSTANT_ERR,
    DECLARE_ERR, DELAY_ERR, DELTA_ERR, DIGITS_ERR, DO_ERR,
    ELSE_ERR, ELSIF_ERR, END_ERR, ENTRY_ERR, EXCEPTION_ERR, EXIT_ERR,
    FOR_ERR, FUNCTION_ERR,
    GENERIC_ERR, GOTO_ERR,
    IF_ERR, IN_ERR, INTERFACE_ERR, IS_ERR,
    LIMITED_ERR, LOOP_ERR,
    MOD_ERR,
    NEW_ERR, NOT_ERR, NULL_ERR,
    OF_ERR, OR_ERR, OTHERS_ERR, OUT_ERR, OVERRIDING_ERR,
    PACKAGE_ERR, PRAGMA_ERR, PRIVATE_ERR, PROCEDURE_ERR, PROTECTED_ERR,
    RAISE_ERR, RANGE_ERR, RECORD_ERR, REM_ERR, RENAMES_ERR, REQUEUE_ERR, RETURN_ERR, REVERSE_ERR,
    SELECT_ERR, SEPARATE_ERR, SOME_ERR, SUBTYPE_ERR, SYNCHRONIZED_ERR,
    TAGGED_ERR, TASK_ERR, TERMINATE_ERR, THEN_ERR, TYPE_ERR,
    UNTIL_ERR, USE_ERR, WHEN_ERR, WHILE_ERR, WITH_ERR, XOR_ERR,PV_ERR, PT_ERR, PLUS_ERR, MOINS_ERR, MULT_ERR, DIV_ERR, VIR_ERR, AFF_ERR, INF_ERR, INFEG_ERR, SUP_ERR, SUPEG_ERR,
    DIFF_ERR, PO_ERR, PF_ERR, EGAL_ERR,ETCOM_ERR,ERREUR_ERR,NOMBER_ERR,ID_ERR,DP_ERR,INTERVAL_ERR,
    
    FACT_ERR,RELOP_ERR,INTERVAL_ID_NOMBER_ERR,IN_ID_NOMBER_ERR,INST_ERR,IF_ID_NOMBER_NOT_ERR,AND_ID_NOMBER_NOT_ERR,ID_EXIST_ERR,
    ID_NO_EXIST_ERR,ID_PROG,ORDRE_INTERVAL_ERR,ID_INEXIST_ERR,CONST_CHANGE
    
} CODE_ERR;

CODE_ERR code_err[]={
	PUT_ERR,GET_ERR,INTEGER_ERR,FLOAT_ERR,
    ABORT_ERR, ABS_ERR, ABSTRACT_ERR, ACCEPT_ERR, ACCESS_ERR, ALIASED_ERR, ALL_ERR, AND_ERR, ARRAY_ERR, AT_ERR,
    BEGIN_ERR, BODY_ERR,
    CASE_ERR, CONSTANT_ERR,
    DECLARE_ERR, DELAY_ERR, DELTA_ERR, DIGITS_ERR, DO_ERR,
    ELSE_ERR, ELSIF_ERR, END_ERR, ENTRY_ERR, EXCEPTION_ERR, EXIT_ERR,
    FOR_ERR, FUNCTION_ERR,
    GENERIC_ERR, GOTO_ERR,
    IF_ERR, IN_ERR, INTERFACE_ERR, IS_ERR,
    LIMITED_ERR, LOOP_ERR,
    MOD_ERR,
    NEW_ERR, NOT_ERR, NULL_ERR,
    OF_ERR, OR_ERR, OTHERS_ERR, OUT_ERR, OVERRIDING_ERR,
    PACKAGE_ERR, PRAGMA_ERR, PRIVATE_ERR, PROCEDURE_ERR, PROTECTED_ERR,
    RAISE_ERR, RANGE_ERR, RECORD_ERR, REM_ERR, RENAMES_ERR, REQUEUE_ERR, RETURN_ERR, REVERSE_ERR,
    SELECT_ERR, SEPARATE_ERR, SOME_ERR, SUBTYPE_ERR, SYNCHRONIZED_ERR,
    TAGGED_ERR, TASK_ERR, TERMINATE_ERR, THEN_ERR, TYPE_ERR,
    UNTIL_ERR, USE_ERR, WHEN_ERR, WHILE_ERR, WITH_ERR, XOR_ERR,PV_ERR, PT_ERR, PLUS_ERR, MOINS_ERR, MULT_ERR, DIV_ERR, VIR_ERR, AFF_ERR, INF_ERR, INFEG_ERR, SUP_ERR, SUPEG_ERR,
    DIFF_ERR, PO_ERR, PF_ERR, EGAL_ERR,ETCOM_ERR,ERREUR_ERR,NOMBER_ERR,ID_ERR,DP_ERR,INTERVAL_ERR,
    
    FACT_ERR,RELOP_ERR,INTERVAL_ID_NOMBER_ERR,IN_ID_NOMBER_ERR,INST_ERR,IF_ID_NOMBER_NOT_ERR,AND_ID_NOMBER_NOT_ERR,ID_EXIST_ERR,
    ID_NO_EXIST_ERR,ID_PROG,ORDRE_INTERVAL_ERR,ID_INEXIST_ERR,CONST_CHANGE
};


char* char_err[]={
	
"PUT_ERR","GET_ERR","INTEGER_ERR","FLOAT_ERR",
	
"ABORT_ERR", "ABS_ERR", "ABSTRACT_ERR", "ACCEPT_ERR", "ACCESS_ERR", "ALIASED_ERR", "ALL_ERR", "AND_ERR", "ARRAY_ERR", "AT_ERR",
"BEGIN_ERR", "BODY_ERR",
"CASE_ERR", "CONSTANT_ERR",
"DECLARE_ERR", "DELAY_ERR", "DELTA_ERR", "DIGITS_ERR", "DO_ERR",
"ELSE_ERR", "ELSIF_ERR", "END_ERR", "ENTRY_ERR", "EXCEPTION_ERR", "EXIT_ERR",
"FOR_ERR", "FUNCTION_ERR",
"GENERIC_ERR", "GOTO_ERR",
"IF_ERR", "IN_ERR", "INTERFACE_ERR", "IS_ERR",
"LIMITED_ERR", "LOOP_ERR",
"MOD_ERR",
"NEW_ERR", "NOT_ERR", "NULL_ERR",
"OF_ERR", "OR_ERR", "OTHERS_ERR", "OUT_ERR", "OVERRIDING_ERR",
"PACKAGE_ERR", "PRAGMA_ERR", "PRIVATE_ERR", "PROCEDURE_ERR", "PROTECTED_ERR",
"RAISE_ERR", "RANGE_ERR", "RECORD_ERR", "REM_ERR", "RENAMES_ERR", "REQUEUE_ERR", "RETURN_ERR", "REVERSE_ERR",
"SELECT_ERR", "SEPARATE_ERR", "SOME_ERR", "SUBTYPE_ERR", "SYNCHRONIZED_ERR",
"TAGGED_ERR", "TASK_ERR", "TERMINATE_ERR", "THEN_ERR", "TYPE_ERR",
"UNTIL_ERR", "USE_ERR", "WHEN_ERR", "WHILE_ERR", "WITH_ERR", "XOR_ERR","PV_ERR", "PT_ERR", "PLUS_ERR", "MOINS_ERR", 
"MULT_ERR", "DIV_ERR", "VIR_ERR", "AFF_ERR", "INF_ERR", "INFEG_ERR", "SUP_ERR", "SUPEG_ERR",
"DIFF_ERR", "PO_ERR", "PF_ERR", "EGAL_ERR","ETCOM_ERR","ERREUR_ERR","NOMBER_ERR","ID_ERR","DP_ERR","INTERVAL_ERR",
"FACT_ERR","RELOP_ERR","INTERVAL_ID_NOMBER_ERR","IN_ID_NOMBER_ERR","INST_ERR","IF_ID_NOMBER_NOT_ERR","AND_ID_NOMBER_NOT_ERR","ID_EXIST_ERR",
    "ID_NO_EXIST_ERR","ID_PROG","ORDRE_INTERVAL_ERR","ID_INEXIST_ERR","CONST_CHANGE"
};

void PROGRAM();
void PROCEDURE();
void INSTS();
void INST(); 
void TERM();
void FACT();
void CONSTS();
void VARS();
void AFF();
void LIRE();
void AFFICHER();
void SI();
void TANTQUE();
void DECL();
void CORPS();
void REPETERTANTQUE();
void POUR();
void EXPR();
void COND();
void OR();
void ORAUX();
void NOT();
void ANDAUX();
void TYPE();












int topERREUR()
{
    int i;
    for(i = 0; char_err[i] != '\0'; i++);
    return i;
}


//variables globales

char Car_Cour;
FILE* Fichier=NULL;
TSym_Cour SYM_COUR;


int topTOKEN()
{
    int i;
    for(i = 0; Code_Lex[i] != '\0'; i++);
    return i;
}

int topSPECIAUX()
{
    int i;
    for(i = 0; mot_cle[i] != '\0'; i++);
    return i;
}
/*int topERREUR()
{
    int i;
    for(i = 0; Code_Lex[i] != '\0'; i++);
    return i;
}*/


//functions

void Lire_Car(){
         Car_Cour=fgetc(Fichier);
         //printf("%s",&Car_Cour);

}
//
void AfficherToken(TSym_Cour Sym_Cour)
{   ///imperativement strictement strictement inf dans for
	int i;
	int j = topTOKEN();
	for(i=0;i<j;i++)
	{
		if(Sym_Cour.CODE==code_lex[i])
		{
			printf("%s -> %s \n",Sym_Cour.NOM,Code_Lex[i]);
			break;
		}
	}
}

// Lire Mots
void Lire_Mot(){

	int i=0,j;
	int endwithUnderScore = 0;
	while(Car_Cour>='a' && Car_Cour<='z' || Car_Cour>='A' && Car_Cour<='Z' || Car_Cour>='0' && Car_Cour<='9' ||  Car_Cour=='_' )
	{
		if(i==0)
		{
			TSym_Cour SYM_NEW;
			SYM_COUR=SYM_NEW;
			memset(SYM_COUR.NOM,'\0', sizeof(SYM_COUR.NOM));
			strcat(SYM_COUR.NOM,&Car_Cour);
		}
		else
		{
		    if(Car_Cour == '_') endwithUnderScore = 1;
		    else endwithUnderScore = 0;
			strcat(SYM_COUR.NOM,&Car_Cour);
		}
		Lire_Car();
		i++;
	}
	if(i<20)
	{
    int fin = topSPECIAUX();
	for(j=0;j<fin;j++)
    {
        if (endwithUnderScore == 1){
            SYM_COUR.CODE=ERREUR_TOKEN;
            return;
        }
        strlwr(SYM_COUR.NOM);
        if(strcmp(SYM_COUR.NOM,mot_cle[j])==0)
            {
                SYM_COUR.CODE=code_lex[j];
                break;
            }
    }
    if(j==fin)
    {
        SYM_COUR.CODE=ID_TOKEN;

    }
	}
	else
	{
		SYM_COUR.CODE=ERREUR_TOKEN;
	}
}


//Lire Nombre
void Lire_Nombre(){

	int i=0;
	while(Car_Cour>=48 && Car_Cour<=57)
	{
		if(i==0)
		{
			TSym_Cour SYM_NEW;
			SYM_COUR=SYM_NEW;
			memset (SYM_COUR.NOM, 0, sizeof (SYM_COUR.NOM));
		}
		if(i>=20)
		{
			SYM_COUR.CODE=ERREUR_TOKEN;
		}
		else
		{
			strcat(SYM_COUR.NOM,&Car_Cour);
			i++;
		}
		Lire_Car();
	}
	SYM_COUR.NOM[i]='\0';
    SYM_COUR.VAL=atoi(SYM_COUR.NOM);
	SYM_COUR.CODE=NOMBER_TOKEN;
}
//

int start = 1;
void Sym_Suiv(){
	//Separateurs



	while(Car_Cour == ' ' || Car_Cour=='\n' || Car_Cour=='\t' || Car_Cour=='\r')
	{
		Lire_Car();
	}

    //MOTS

    /*

    if we want neaffichew
    if(!start)
    {
        AfficherToken(SYM_COUR);    
    }
    start = 0;*/

	if(Car_Cour>='a' && Car_Cour<='z' || Car_Cour>='A' && Car_Cour<='Z')
	{
		Lire_Mot();
		return;
	}
	//NOMBRES
	if(Car_Cour>='0' && Car_Cour<='9')
	{
		Lire_Nombre();
		return;
	}
	//SYMBOLES
	TSym_Cour SYM_NEW;
	SYM_COUR=SYM_NEW;
	memset (SYM_COUR.NOM, '\0', sizeof (SYM_COUR.NOM));
	SYM_COUR.NOM[0]=Car_Cour;
	if(Car_Cour=='=')
    {
        SYM_COUR.CODE=EGAL_TOKEN;
        Lire_Car();return;
    }

	if(Car_Cour=='<')//60
    {
			Lire_Car();
			if(Car_Cour!='=')
			{
			    SYM_COUR.CODE=INF_TOKEN;
                return;
			}
			else{
                SYM_COUR.NOM[1]=Car_Cour;
                SYM_COUR.CODE=INFEG_TOKEN;
                Lire_Car();
                return;
            }
    }

	if(Car_Cour==';')
		{
			SYM_COUR.CODE=PV_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour=='.')
		{
		    Lire_Car();
			if(Car_Cour!= '.')
			{
			    SYM_COUR.CODE=PT_TOKEN;
                return;
			}
			else{
                SYM_COUR.NOM[1]=Car_Cour;
                SYM_COUR.CODE=INTERVAL_TOKEN;
                Lire_Car();
                return;
            }
        }
	if(Car_Cour=='+')
		{
			SYM_COUR.CODE=PLUS_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour=='-')//45
		{
		    Lire_Car();
		    if(Car_Cour!='-'){
                SYM_COUR.CODE=MOINS_TOKEN;
                return;
            }else{
            	printf("llll");
                while(1){
                    if(Car_Cour == '\r' || Car_Cour == '\n') {
                    	printf("FFFFff");
					break;}
                    Lire_Car();
                }
                printf("ddd");
                Lire_Car();
                
				return;
            }
		}


	if(Car_Cour=='*')//42
		{
			SYM_COUR.CODE=MULT_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour=='/')
		{
		    Lire_Car();
			if(Car_Cour!='=')
			{
			    SYM_COUR.CODE=DIV_TOKEN;
                return;
			}
			else{
                SYM_COUR.NOM[1]=Car_Cour;
                SYM_COUR.CODE=DIFF_TOKEN;
                Lire_Car();
                return;
            }
		}
	if(Car_Cour==',')
		{
			SYM_COUR.CODE=VIR_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour=='>')
    {
        Lire_Car();
        if(Car_Cour!='=')
        {
        SYM_COUR.CODE=SUP_TOKEN;
        return;
        }
        else{
            SYM_COUR.NOM[1]=Car_Cour;
            SYM_COUR.CODE=SUPEG_TOKEN;
            Lire_Car();return;
        }
    }
	if(Car_Cour=='(')
		{
			SYM_COUR.CODE=PO_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour==')')
		{
			SYM_COUR.CODE=PF_TOKEN;
			Lire_Car();return;
		}
	if(Car_Cour == '&')
	{/// i need to check this stuff
		SYM_COUR.CODE = ETCOM_TOKEN ;
			Lire_Car();return;
	}
	if(Car_Cour== EOF )
		{
			SYM_COUR.CODE=END_TOKEN;
				Lire_Car();return;
		}
	if(Car_Cour == ':' )
    {
			Lire_Car();
			if(Car_Cour!=61)
			{
			    SYM_COUR.CODE=DP_TOKEN;
                return;
			}
			else{
                    SYM_COUR.NOM[1]=Car_Cour;
                    SYM_COUR.CODE=AFF_TOKEN;
					Lire_Car();return;
            }
    }

	SYM_COUR.CODE=ERREUR_TOKEN;
	Lire_Car();
	return;
}

void Erreur(CODE_ERR code){
    int i;
    
    for ( i=0; i<CONST_CHANGE+1 ;i++){
    	
    	
        if (code == code_err[i]){
        	
            printf("\n***********L'erreur est --> %s",char_err[i]);
            exit(1);
        }
    }
}

//Analyseur Synthaxique
void Test_Symbole (CODES_LEX cl,CODE_ERR COD_ERR)
{   
	if (SYM_COUR.CODE==cl)  
		{   
			Sym_Suiv(); 
			//AfficherToken(SYM_COUR);   /// affichage des tokens dans l'ordre de la lecture 
		}  
	else   {
   		
	Erreur(COD_ERR); 

          }
}