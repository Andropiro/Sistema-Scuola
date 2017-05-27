#include "Genitore.h"
//#include "UserStudente.h"

class Studente : public Persona {
	
private:	
			Genitore padre;
			Genitore madre;
public:
			Studente(); 
			Studente(string nome, string cognome, string indirizzo, Genitore pad, Genitore mad);
			void setMadre(Genitore gen);
			Genitore getMadre();
			void setPadre(Genitore gen);
			Genitore getPadre();
}