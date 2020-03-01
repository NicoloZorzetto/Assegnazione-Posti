#include <iostream>
#include <string>
#include <vector>

/* CREAZIONE STRUTTURA */

struct studente{

  std::string nome;
  std::string compagno = ""; // una volta trovato il compagno il suo nome sarà conservato qui
  float punteggio_attuale = 0; // punteggio della coppia (quanto a questo studente piace il compagno attuale)
  std::vector<std::string> preferenze; // vettore che contiene l'ordine di preferenza di tutti i compagni

};

int main() {

/* DICHIARAZIONI */

  int x, y, z, generazione = 1, a=3;
  float tot;
  std::string input;
  std::vector<std::string> output;

/* RACCOLTA DATI */

  std::cout << "Inserisci numero di studenti: "; std::cin >> x;
  studente studenti[x]; // creo un array di studenti
  std::cout << "\n\n" << '\n';

  for(int i=0; i<x; i++){
    std::cout << "Inserisci nome dello studente " << i+1 << ":"; std::cin >> studenti[i].nome; // raccolgo il nome dello studente
    for(int o=0; o<x-1; o++){
      std::cout << "Inserisci le preferenze: "; std::cin >> input; // raccolgo i nomi dei compagni in ordine di preferenza
      studenti[i].preferenze.push_back(input); // li conservo in un vettore
    }
    std::cout << "\n\n" << '\n';
  }

/* COMPUTAZIONE */

  // sono 3 for loop, perché ogni generazione è composta dal quadrato del numero di studenti (perché è contenuto in ogni vettore che costituisce le preferenze) e bisogna avere almeno n+1 numero di generazioni
  for(auto& w : studenti){
    for(auto& u : studenti){
      for(auto& n : studenti){

        for(int f=0; f<u.preferenze.size(); f++){
          /* Per ogni studente controllo le preferenze e, in ordine di preferenza, faccio delle "proposte" */
          if(u.preferenze[f] == n.nome){
            for(int q=0; q<n.preferenze.size(); q++){
              if(u.nome == n.preferenze[q]){
                y = u.preferenze.size() - f; // computo il punteggio della coppia per i due appartenenti ad essa (inverso alla posizione nel vettore)
                z = n.preferenze.size() - q;
              }
            }
          }
        }

        if(y > u.punteggio_attuale and z > n.punteggio_attuale){ // controllo se entrambi preferirebbero il nuovo accoppiamento a quello che hanno ora
            for(auto& r : studenti){
              /* Se sto per formare una nuova coppia cerco gli eventuali compagni precedenti e li rendo liberi (non sono più accoppiati con nessuno) */
              if(u.nome == r.compagno or n.nome == r.compagno){
                std::cout << "sto per eliminare " << r.compagno << " compagno di " << r.nome << '\n';
                  r.compagno = "";
                  r.punteggio_attuale = 0;
              }
            }
            // Formo e conservo la nuova coppia
            std::cout << "Sto per accoppiare " << u.nome << " e " << n.nome << '\n';
            u.compagno = n.nome;
            u.punteggio_attuale = y;

            n.compagno = u.nome;
            n.punteggio_attuale = z;


        }

        // azzero i punteggi temporanei
        y = 0;
        z = 0;

        }

      /* Output generazionale - stampo numero e stato della generazione in corso */

        std::cout << "GENERAZIONE" << generazione << '\n';

        for(int t = 0; t<x; t++){
          std::cout << studenti[t].nome << "  " << studenti[t].compagno << studenti[t].punteggio_attuale << "\n";
        }

        generazione = generazione + 1;
        std::cout << "\n\n\n" << '\n';

      }
  }

/* EXTREME RANDOMIZER */

  std::vector<studente> randomizing;
  for(auto& q : studenti){
    for(auto& t : studenti){
      if(q.compagno == "" and t.compagno == ""){
        if(t.nome != q.nome){
          q.compagno = t.nome;
          t.compagno = q.nome;
          for(int i=0; i<q.preferenze.size(); i++){
            for(int u=0; u<t.preferenze.size(); u++){
              if(q.preferenze[i] == t.nome){
                q.punteggio_attuale = q.preferenze.size() - i;
              }
            }
          }
        }
      }
    }
  }

  for(auto& r : randomizing){
    std::cout << "FINITO DI RANDOMIZZARE" << '\n';
    std::cout << r.nome << " " << r.compagno << "\n\n\n";
  }

/* OUTPUT */
    for(auto& o : studenti){
      for(auto& h : studenti){
        if(h.nome == o.compagno){
          tot = (h.punteggio_attuale + o.punteggio_attuale)/2; // calcolo il punteggio della coppia (media dei due punteggi di preferenza)
        }
      }


      if(std::find(output.begin(), output.end(), o.nome) != output.end()){ // controllo il vettore 'output' per non stampare chi ho già stampato (come nome o compagno)

      }
      else{
        std::cout << o.nome << "  " << o.compagno << " " << tot <<'\n';
        std::cout << "\n\n" << '\n';
      }

      // conservo i nominativi in un vettore per non ristamparli
      output.push_back(o.nome);
      output.push_back(o.compagno);
      tot = 0;

    }



  fflush(stdin); getchar(); return 0;
}
