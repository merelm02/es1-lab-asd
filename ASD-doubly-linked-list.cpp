// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

// FILE DA MODIFICARE

#include "ASD-doubly-linked-list.h"
#include "list"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
    Elem info;
    node *prev;
    node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'  */
/*************************************************/

void readFromStream(istream& str, List& l) {
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    // assumiamo che il segnale di fine input nel file sia  FINEINPUT
    while (e != FINEINPUT)  {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
    }
}

/* legge il contenuto di una lista da file */
void readFromFile(string nome_file, List& l) {
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}


/* legge il contenuto di una lista da standard input */
void readFromStdin(List& l) {
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}

/* stampa la lista */
void print(const List& l) {
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l) {   // avanza finche' non finisce la lista
      cout << q->info << "; ";
      q = q->next; 
    }
}

/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

/* crea la lista vuota */
void list::createEmpty(List& l) {
   info = 0;
   prev = NULL;
   next = NULL;
}

/* "smantella" la lista svuotandola */
void list::clear(const List& l) {
	l->next = NULL;
	l->prev = NULL;
}

/* restituisce l'elemento in posizione pos se presente; restituisce un elemento 
che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
Elem list::get(int pos, const List& l) {
                        
}

/* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
void list::set(int pos, Elem e, const List& l) {
   
}

/* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void list::add(int pos, Elem e, const List& l) {                                               
  
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem e,  const List& l) {
    node* aux = new node;
     aux->info = e;
     aux->next = emptyList;
     if (l==emptyList)
     {        
        aux->prev = emptyList;
        l = aux;
     } 
     else
     {
     List q = l;  // q va alla testa della lista 
        while (q->next != emptyList)
           q = q->next;        
     aux->prev = q;
     q->next=aux;
     }
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem e, const List& l) {
     node* aux = new node;
     aux->info = e;
     aux->next = l;
     aux->prev = emptyList;
     if (l!=emptyList) 
         l->prev=aux;
     l = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
void list::removePos(int pos, const List& l) {
	int count;
	List q;
	while(!l.empty){
		if(count == pos){
			q=l->next;
			l->prev->next = q;
			q->prev = l->prev;
			delete l;
			l=q;
		}else
			l=l->next;
		count++
	}
}

 /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
void list::removeElem(Elem e, List& l) /* cancella la prima occorrenza di e nella lista; per esercizio: creare una versione che cancella tutte le occorrenze di e dalla lista */ 
{ 
List q; 
 
if (l == emptyList)  /* se la lista è vuota, non devo cancellare niente */ 
   return;  
    
if (l->info == e)    /* se l'elemento da rimuovere è il primo, oltre a cancellarlo, l'inizio della lista, puntato da l, cambia (devo aggiornare il puntatore l, che punterà al secondo elemento) */ 
{ 
   q = l->next; 
   if (q != emptyList) 
     q->prev=emptyList; 
   delete l; 
   l = q;   
} 
 
q = l;              /* caso in cui la lista non è vuota e l'elemento da rimuovere non e' il primo */ 
 
while (q != emptyList)    // avanza finche' la lista non è stata scandita tutta o l'elemento non è stato rimosso 
 { 
 if (q->info == e)             // quando trovo l'elemento cercato 
      { 
      if (q->next != emptyList) // aggiorno i puntatori next e prev delle celle precedente e successiva, facendo attenzione a non accedere campi di un puntatore nullo 
       q->next->prev=q->prev; 
       
      if (q->prev != emptyList)  // inutile, visto che l'unico elemento con prev empty è il primo e lo abbiamo trattato a parte        
              q->prev->next=q->next; 
       
      delete q;                // cancello l'elemento q 
                } 
        else 
         q = q->next;         
 } 
}

/* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
bool list::isEmpty(const List& l) {
  return (l==emptyList);
}

 /* restituisce la dimensione della lista */
int list::size(const List& l) {
   int s = 0;
   while (l != NULL)
   {
       s++;
       l = l->next;
   }
   return res;
}
}


