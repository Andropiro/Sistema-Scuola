#include "genitore.h"
Genitore::Genitore() : Persona("", "", ""), email(""), telefono("")
{
	figli = new Studente[defaultFigli];
	figliInseriti = 0;
} 

Genitore::~Genitore(){
	delete figli;
}

// nFigli è il numero di figli che il genitore ha effettivamente
Genitore::Genitore(string nome, string cognome, string indirizzo, string mail, string tel, int nFigli) : 
	Persona(nome, cognome, indirizzo), 
	email(mail),
	telefono(tel)
{
	figli = new Studente[nFigli];
	figliInseriti = 0;
}

Studente* Genitore::getFigli(){
	return figli;
}

bool Genitore::addFiglio(Studente figlio){
	
	if(figliInseriti >= figliTotali)
		return false;
	
	figli[figliInseriti].setNome(figlio.getNome());
	figli[figliInseriti].setCognome(figlio.getCognome());
	figli[figliInseriti].setIndirizzo(figlio.getIndirizzo());
	figli[figliInseriti].setEmail(figlio.getEmail());
	figli[figliInseriti].setTelefono(figlio.getTelefono());
	
	figliInseriti++;
	return true;
}

bool Genitore::removeFiglio(Studente figlio){
	
	for(int i=0; i<figliInseriti; i++){
		if(	figlio.getNome() == figli[i].getNome() &&
			figlio.getCognome() == figli[i].getCognome() &&
			figlio.getIndirizzo() == figli[i].getIndirizzo()){
				//procedura di eliminazione: sovrascrivo all'indietro
				for(int j=i; j< (figliInseriti - 1); j++){
					figli[j] = figli[j+1];
				}
				figliInseriti--;
				return true;
			}
	}
	//non trovato
	return false;
}

void Genitore::setEmail(string mail){
	email = mail;
}

string Genitore::getEmail(){
	return email;
}

void Genitore::setTelefono(string tel){
	telefono = tel;
}

string Genitore::getTelefono(){
	return telefono;
}
