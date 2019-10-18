# Mini Compiler Interpretter for ADA language

A lexical , syntactic , semantic compiler and interpreter for a part of the **ADA** language , to whome we defined the grammar .
the

### Prerequisites

C language



### Overview: 


start with writing a test script
```
    Fichier=fopen("your test file path here.txt","r+");
```    


the result is written in this file

```
    FichierSortie = fopen("PCODE.txt","w");
``` 
    

main functions 
```
        Lire_Car();
    	Sym_Suiv();
        PROGRAM();
```
        

 
 
table of symbols stors symbles we define in programm and their type for exemle a constant is TCONT , a variable / procedure name ...
```       
       AfficherTableSymbole();
```     

it stores the micro instructions that the interpretter needs to execute in order to get the wanted result ( resembles a pile of assembly instructions 

```
        afficherTableInstructions();
```        

then print the interpretter result

``` 
        printf("\n-----------------------------------\n");
        printf("     INTERPRETEUR");
        printf("\n-----------------------------------\n");
        INTER_PCODE();
        printf("\n-----------------------------------\n");
       // afficherMemoire();
    fclose(Fichier);
    }
```



## Authors

* **MESTASI Bilal**
* **NEDDAY Asmae**
* **SEBBAH Hala**
* **TAHIR Aicha**


