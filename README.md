# Assegnazione-Posti
Un programma che forma compagni di banco in base alla preferenze degli studenti

# 1) Ho creato una struttura che mi permette di formare gli studenti
In questo modo posso creare dinamicamente delle variabili "studente" che hanno un vettore contenente i compagni in ordine di preferenza, il nome, il compagno attuale ed un punteggio che rispecchia quanto allo studente piaccia la coppia formata

# 2) In base al numero di studenti, inserito all'inizio del programma, looppo chiedendo nome e preferenze di ognuno

# 3) Per ogni studente controllo le preferenze e calcolo quanto sia conveniente
Prima guardo la prima preferenza, e guardo quanto sarebbe il punteggio (n-studenti -1 per il preferito, n-studenti -2 per il secondo preferito e così via)

# 4) Controllo se anche alla preferenza piaccia di più la nuova, ancora ipotetica, coppia
Il secondo loop mi permette di andare a cercare la preferenza e guardare all'interno delle sue preferenze in modo da vedere se anche per questa il punteggio ipotetico sia maggiore di quello precedente (se è la prima generazione è 0 quello precedente quindi ogni compagno sarà preferito al niente)

# 5) Formo la coppia
Se per entrambi la nuova coppia sarebbe migliore di quella di prima allora sostituisco l'attributo "compagno" con il rispettivo nome ed assegno a "punteggio_attuale" il punteggio della coppia relativo allo studente

# 6) Libero i compagni precedenti
In caso si sia appena formata una nuova coppia cerco gli eventuali compagni precedenti ed assegno al loro "punteggio_attuale" 0 e svuoto la stringa attributo "compagno", in modo da poterli ri-accoppiare anche con qualcuno di meno preferito perché non rimangano da soli

# 7) EXTREME RANDOMIZER
In alcuni casi non è possibile formare tutte le coppie in base alla preferenza, come nel seguente caso: 
```
Inserisci numero di studenti: 4      

Inserisci nome dello studente 1:Antonio
Inserisci le preferenze: Federico 
Inserisci le preferenze: Matteo
Inserisci le preferenze: Giovanni

Inserisci nome dello studente 2:Giovanni
Inserisci le preferenze: Antonio
Inserisci le preferenze: Matteo
Inserisci le preferenze: Federico

Inserisci nome dello studente 3:Matteo
Inserisci le preferenze: Antonio
Inserisci le preferenze: Giovanni
Inserisci le preferenze: Federico

Inserisci nome dello studente 4:Federico
Inserisci le preferenze: Giovanni
Inserisci le preferenze: Matteo
Inserisci le preferenze: Antonio
```
In questo caso il programma continuerebbe a formare e rompere le coppie, perché tutti hanno come preferito qualcuno che li ha come meno preferiti. In questo caso vengono formate delle coppie casuali, assegnando ad ogni studente che non ha ancora un compagno alla fine delle (n-studenti)^2 generazioni un altro studente che non ha ancora un compagno
