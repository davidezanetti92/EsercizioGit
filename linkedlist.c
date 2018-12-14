#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////7
#define STOP 0
#define ADD 1 
#define STAMPA 2
#define DEL 3
#define DELETA 4 
#define DELNOME 5 
#define ADDTESTA 6 
#define DELTESTA 7
#define LEN 20
/////////////////////////////////////////////////
typedef struct persona{   /* crea la struttura */ 
int eta;
char nome[LEN];
struct persona* next;
} persona;
/////////////////////////////////////////////////////////
void add(persona *old){   /*funzione per aggiunger in fono alla lista */
while(old->next!=NULL){   /*ciclo fino fine lista */
old=old->next;
}
persona *nuova = malloc(sizeof(persona));  //crea la persona
printf("Insert N: ");                              
scanf("%d", &nuova->eta);                          
printf("Insert Name: ");                           
scanf("%s", nuova->nome);                          
nuova->next=NULL;                                   
old->next=nuova;                                  
}
//////////////////////////////////////////////////
void stampa(persona *persona){            //funzione per stampatre tutti i dati
while(persona!=NULL){                     /*ciclo fino fine lista  e stampo*/
printf("%d - %s\n", persona->eta, persona->nome);
persona=persona->next;
 }
}
///////////////////////////////////////////
void del(persona *last){                 //funzione per cancellare ultima persona
persona *temp = malloc(sizeof(persona)); // creo nodo temporaneo per liberare la memoria
while(last->next!=NULL){
temp=last;
last=last->next;
}
temp->next=NULL;
free(last);
}
///////////////////////////////////////
void delEta(persona *last){
printf("Enter eta: ");
int x;
scanf("%x",&x);
persona *temp = malloc(sizeof(persona));
while(x!=last->eta){
temp = last; 
last= last->next;   
}
temp->next = last->next; 
last->next=NULL;
free(last);
}
/////////////////////////////////////////
void delNome(persona *last){
printf("Enter nome: ");
char c[LEN];
scanf("%s",c);
persona *temp = malloc(sizeof(persona));
while(strcmp(c,last->nome)!=0){
temp = last; 
last= last->next;   
}
temp->next = last->next; 
last->next=NULL;
free(last);
}
/////////////////////////////////////////
void addTesta(persona **p){
persona *new = malloc(sizeof(persona));
printf("Insert N: ");                              
scanf("%d", &new->eta);                          
printf("Insert Name: ");                           
scanf("%s", new->nome);   
new->next=*p;                          
*p=new;     
}
/////////////////////////////////////////7
void delTesta(persona **p){
persona *new = malloc(sizeof(persona));
new=(*p)->next;
free(*p);
*p=new;
}
//////////////////////////////////


int main(){
persona *radice = malloc(sizeof(persona)); //creo nodo radice
printf("Insert radice N: ");
scanf("%d", &radice->eta);
printf("Insert radice Name: ");
scanf("%s", radice->nome);
radice->next=NULL;
int x=100;
printf("\n\n");
while(x!=STOP){                            // commandi
printf("1 per add\n2 per stampa\n3 per del\n4 cancellare un numero specifivo\n0 per chiudere\n5 per cancellare il nome\n6 aggiungere in testa\n7 per cancellare testa\n\n");
scanf("%x",&x);
printf("\n");
if(x==ADD){add(radice);printf("\n");}
if(x==STAMPA){stampa(radice);printf("\n");}
if(x==DEL){del(radice);printf("\n");}
if(x==DELETA){delEta(radice);printf("\n");}
if(x==DELNOME){delNome(radice);printf("\n");}
if(x==ADDTESTA){addTesta(&radice);printf("\n");}
if(x==DELTESTA){delTesta(&radice);printf("\n");}
}
}

