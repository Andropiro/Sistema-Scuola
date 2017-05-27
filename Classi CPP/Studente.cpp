#include "Studente.h"

//costruttore ipotizzato per persona: nome, cognome, indirizzo
//genitore deve prevedere almeno un costruttore con nome, cognome, indirizzo, email, telefono
Studente::Studente() : Persona("", "", ""), madre("", "", "", "", ""), padre("", "", "", "", "")
{

} 

Studente::Studente(string nome, string cognome, string indirizzo, Genitore pad, Genitore mad) : 
	Persona(nome, cognome, indirizzo), 
	padre(pad.getNome(), pad.getCognome(), pad.getIndirizzo(), pad.getEmail(), pad.getTelefono()),
	madre(mad.getNome(), mad.getCognome(), mad.getIndirizzo(), mad.getEmail(), mad.getTelefono())
{
}

void Studente::setMadre(Genitore gen){
	madre = gen;
}

void Studente::setPadre(Genitore gen){
	padre = gen;
}

Genitore Studente::getMadre(){
	return madre;
}

Genitore Studente::getPadre(){
	return padre;
}
