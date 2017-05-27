#include "Studente.h"

class Genitore : public Persona{

private:
			string email;
			string telefono;
			Studente *figli;
			int figliInseriti; //numero di figli inseriti nel sistema
			int figliTotali; //figli totali che ha la persona, che rappresenta la dimensione dell'array
			const int defaultFigli = 2;
public:
			Genitore();
			Genitore(string nome, string cognome, string indirizzo, string email, string telefono);
			~Genitore();
			string getEmail();
			void setEmail(string mail);
			string getTelefono();
			void setTelefono(string tel);
			Studente* getFigli();
			bool addFiglio(Studente figlio);
			bool removeFiglio(Studente figlio);
		
}